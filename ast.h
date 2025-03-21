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
