#pragma once
#include <string>

class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class BinaryOpNode : public ASTNode {
public:
    std::string op;
    ASTNode* left;
    ASTNode* right;
    BinaryOpNode(std::string op, ASTNode* left, ASTNode* right)
        : op(op), left(left), right(right) {}
};

class NumberNode : public ASTNode {
public:
    int value;
    NumberNode(int value) : value(value) {}
};


class IRNode {
public:
    virtual ~IRNode() = default;
};

class IRBinaryOp : public IRNode {
public:
    std::string op;
    std::string left, right, result;
    IRBinaryOp(std::string op, std::string left, std::string right, std::string result)
        : op(op), left(left), right(right), result(result) {}
};
