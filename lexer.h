#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class Token {
public:
    enum Type { IDENTIFIER, NUMBER, OPERATOR, PAREN_OPEN, PAREN_CLOSE, END };
    Type type;
    std::string value;
    Token(Type type, std::string value) : type(type), value(value) {}
};

class Lexer {
public:
    Lexer(const std::string &src) : src(src), index(0) {}
    
    Token nextToken() {
        while (index < src.size() && std::isspace(src[index])) index++;
        if (index >= src.size()) return Token(Token::END, "");
        char current = src[index];
        if (std::isalpha(current)) {
            std::string id;
            while (index < src.size() && std::isalnum(src[index])) id += src[index++];
            return Token(Token::IDENTIFIER, id);
        }
        if (std::isdigit(current)) {
            std::string num;
            while (index < src.size() && std::isdigit(src[index])) num += src[index++];
            return Token(Token::NUMBER, num);
        }
        if (current == '(') {
            index++;
            return Token(Token::PAREN_OPEN, "(");
        }
        if (current == ')') {
            index++;
            return Token(Token::PAREN_CLOSE, ")");
        }
        if (std::string("+-*/=").find(current) != std::string::npos) {
            index++;
            return Token(Token::OPERATOR, std::string(1, current));
        }
        return Token(Token::END, "");
    }

private:
    std::string src;
    size_t index;
};