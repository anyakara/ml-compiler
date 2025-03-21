/**
 * @file main.cpp
 * @author ananya karra (ananya.karra@gmail.com)
 * @brief builds parse tree for simple expressions expanding on lexer built below. supports identifiers, numbers,
 and basic operators, structuring them hierarchically. we support handling parentheses, operator precedence, and
 other possibly more complex grammar rules down the line.
 * @version 0.1
 * @date 2025-03-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include "lexer.h"
#include "parser.h"
#include "ast.h"
#include "ir.h"
#include "optimizer.h"
#include <iostream>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file>\n";
        return 1;
    }

    std::string sourceCode = readFile(argv[1]);  // Read source file
    Lexer lexer(sourceCode);
    Parser parser(lexer);
    
    ASTNode* ast = parser.parse();  // Parse source to AST
    ast = optimize(ast);            // Optimize AST (constant folding, etc.)

    IRGenerator irGen;
    IRNode* ir = irGen.generate(ast);  // Convert AST to IR

    if (JIT_MODE) {
        JITCompiler jit;
        jit.execute(ir);  // Run via Just-In-Time compilation
    } else {
        CodeGen codegen;
        codegen.generateExecutable(ir, "output.o");  // Generate machine code
    }

    return 0;
}
