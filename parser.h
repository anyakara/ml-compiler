#include "lexer.h"

class ParseTreeNode {
public:
    Token token;
    std::vector<ParseTreeNode*> children;
    ParseTreeNode(Token token) : token(token) {}
};

class Parser {
public:
    Parser(Lexer &lexer) : lexer(lexer), currentToken(lexer.nextToken()), root(nullptr) {}
    void parse() {
        root = expression();
    }
    void printParseTree(ParseTreeNode* node, int depth = 0) {
        if (!node) return;
        for (int i = 0; i < depth; i++) std::cout << "  ";
        std::cout << "Type: " << node->token.type << " Value: " << node->token.value << std::endl;
        for (auto child : node->children) printParseTree(child, depth + 1);
    }
    void print() {
        printParseTree(root);
    }

private:
    Lexer &lexer;
    Token currentToken;
    ParseTreeNode* root;
    void advance() {
        currentToken = lexer.nextToken();
    }
    ParseTreeNode* factor() {
        if (currentToken.type == Token::NUMBER || currentToken.type == Token::IDENTIFIER) {
            ParseTreeNode* node = new ParseTreeNode(currentToken);
            advance();
            return node;
        } 
        else if (currentToken.type == Token::PAREN_OPEN) {
            advance();
            ParseTreeNode* node = expression();
            if (currentToken.type == Token::PAREN_CLOSE) {
                advance();
            }
            return node;
        }
        return nullptr;
    }

    ParseTreeNode* term() {
        ParseTreeNode* node = factor();
        while (currentToken.type == Token::OPERATOR && (currentToken.value == "*" || currentToken.value == "/")) {
            Token op = currentToken;
            advance();
            ParseTreeNode* opNode = new ParseTreeNode(op);
            opNode->children.push_back(node);
            opNode->children.push_back(factor());
            node = opNode;
        }
        return node;
    }

    ParseTreeNode* expression() {
        ParseTreeNode* node = term();
        while (currentToken.type == Token::OPERATOR && (currentToken.value == "+" || currentToken.value == "-")) {
            Token op = currentToken;
            advance();
            ParseTreeNode* opNode = new ParseTreeNode(op);
            opNode->children.push_back(node);
            opNode->children.push_back(term());
            node = opNode;
        }
        return node;
    }
};

// int main() {
//     std::string input = "3 + 5 * (2 - 8)";
//     Lexer lexer(input);
//     Parser parser(lexer);
//     parser.parse();
//     parser.print();
//     return 0;
// }
