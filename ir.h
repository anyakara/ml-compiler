#pragma once

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
