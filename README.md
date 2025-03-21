# ML Compiler
## Overview

This project is a minimal compiler for mathematical expressions and ML-style syntax, written in C++. It consists of:
* Lexer: Tokenizes the input source code.
* Parser: Builds a parse tree from tokens.
* AST Generator: Converts the parse tree into an Abstract Syntax Tree (AST).
* IR Generator: Transforms the AST into an Intermediate Representation (IR).
* Optimizer: Performs basic optimizations like constant folding.
* Code Generator: (Optional) Converts IR into executable machine code or LLVM IR.

## Features
* Supports basic arithmetic expressions (+, -, *, /) with correct operator precedence and parentheses handling.
* Builds an Abstract Syntax Tree (AST) for further processing.
* Generates Intermediate Representation (IR) for execution.
* Can run with JIT Compilation (LLVM) or machine code generation.

## Installation & Compilation
### Prerequisites
C++17 or later (```g++```, ```clang++```)
(Optional) LLVM for IR execution

### Compile the Compiler
```g++ -std=c++17 -o my_compiler lexer.cpp parser.cpp ast.cpp ir.cpp optimizer.cpp main.cpp```

### Run the Compiler
```./my_compiler source.ml```

If using LLVM:
```
./my_compiler source.ml > output.ll
lli output.ll
```

## Example Usage
### Input (source.ml)
```
x = 5 + 3 * (2 + 1)
```
### Generated IR Output
```
%t1 = add 2, 1
%t2 = mul 3, %t1
%t3 = add 5, %t2
store %t3, x
```
### Expected Execution Output
```
14
```
### Next Steps
* Add user-defined functions and variable declarations.
* Implement looping & branching (if, for, while).
* Extend ML-style syntax support.