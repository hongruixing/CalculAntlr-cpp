#include <iostream>
#include <string>

// antlr4 runtime
#include "antlr4-runtime.h"

// generated lexer and parser
#include <CalculantlrLexer.h>
#include <CalculantlrParser.h>

// custom listener
#include "CalcListener.h"

using namespace std;
using namespace antlr4;
using namespace calculantlr;
using namespace tree;

void execute_expression(const std::string &expr) {
    ANTLRInputStream input(expr);
    CalculantlrLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CalculantlrParser parser(&tokens);

    tree::ParseTree *tree = parser.input();
    CalcListener listener;

    ParseTreeWalker *walker = new ParseTreeWalker();
    walker->walk(&listener, tree);
}

int main() {
    std::string prefix = ">>> ";

    // parse and interpet the expression readen from the standard input
    std::cout << prefix;
    std::string line;
    while( std::getline(std::cin,line) ) {
        execute_expression(line);
        std::cout << prefix;
    }

    return 0;
}