#include "ast.h"

ASTNode* constantFolding(ASTNode* node) {
    if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
        if (auto* left = dynamic_cast<NumberNode*>(binOp->left)) {
            if (auto* right = dynamic_cast<NumberNode*>(binOp->right)) {
                int result = (binOp->op == "+") ? left->value + right->value : left->value * right->value;
                return new NumberNode(result);
            }
        }
    }
    return node;
}
