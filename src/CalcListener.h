//
// Created by Roger Generoso Masós on 01/01/2020.
//

#ifndef CALCULATOR_CALCLISTENER_H
#define CALCULATOR_CALCLISTENER_H

#include "CalculantlrBaseListener.h"

using namespace calculantlr;
using namespace std;

class CalcListener : public CalculantlrBaseListener {

    stack<int> stk;

public:
    void enterInput(CalculantlrParser::InputContext *context) override;

    void exitInput(CalculantlrParser::InputContext *context) override;

    void enterToMultOrDiv(CalculantlrParser::ToMultOrDivContext *context) override;

    void exitToMultOrDiv(CalculantlrParser::ToMultOrDivContext *context) override;

    void enterBinaryMinusOp(CalculantlrParser::BinaryMinusOpContext *context) override;

    void exitBinaryMinusOp(CalculantlrParser::BinaryMinusOpContext *context) override;

    void enterPlusOp(CalculantlrParser::PlusOpContext *context) override;

    void exitPlusOp(CalculantlrParser::PlusOpContext *context) override;

    void enterToAtom(CalculantlrParser::ToAtomContext *context) override;

    void exitToAtom(CalculantlrParser::ToAtomContext *context) override;

    void enterMultOp(CalculantlrParser::MultOpContext *context) override;

    void exitMultOp(CalculantlrParser::MultOpContext *context) override;

    void enterDivOp(CalculantlrParser::DivOpContext *context) override;

    void exitDivOp(CalculantlrParser::DivOpContext *context) override;

    void enterInt(CalculantlrParser::IntContext *context) override;

    void exitInt(CalculantlrParser::IntContext *context) override;

    void enterUnaryMinusOp(CalculantlrParser::UnaryMinusOpContext *context) override;

    void exitUnaryMinusOp(CalculantlrParser::UnaryMinusOpContext *context) override;

    void enterParenthesisOp(CalculantlrParser::ParenthesisOpContext *context) override;

    void exitParenthesisOp(CalculantlrParser::ParenthesisOpContext *context) override;

    void enterEveryRule(antlr4::ParserRuleContext *context) override;

    void exitEveryRule(antlr4::ParserRuleContext *context) override;

    void visitTerminal(antlr4::tree::TerminalNode *node) override;

    void visitErrorNode(antlr4::tree::ErrorNode *node) override;
};


#endif //CALCULATOR_CALCLISTENER_H
