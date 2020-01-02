//
// Created by Roger Generoso Masós on 01/01/2020.
//

#include "CalcListener.h"

using namespace std;

void CalcListener::enterInput(CalculantlrParser::InputContext *context) {
    cout << "entered on input" << endl;

    stk = stack<int>();

    CalculantlrBaseListener::enterInput(context);
}

void CalcListener::exitInput(CalculantlrParser::InputContext *context) {

    cout << stk.top() << endl;
    CalculantlrBaseListener::exitInput(context);
}

void CalcListener::enterToMultOrDiv(CalculantlrParser::ToMultOrDivContext *context) {
    CalculantlrBaseListener::enterToMultOrDiv(context);
}

void CalcListener::exitToMultOrDiv(CalculantlrParser::ToMultOrDivContext *context) {
    CalculantlrBaseListener::exitToMultOrDiv(context);
}

void CalcListener::enterBinaryMinusOp(CalculantlrParser::BinaryMinusOpContext *context) {
    CalculantlrBaseListener::enterBinaryMinusOp(context);
}

void CalcListener::exitBinaryMinusOp(CalculantlrParser::BinaryMinusOpContext *context) {

    int right = stk.top();
    stk.pop();
    int left = stk.top();
    stk.pop();

    stk.push(left - right);

    CalculantlrBaseListener::exitBinaryMinusOp(context);
}

void CalcListener::enterPlusOp(CalculantlrParser::PlusOpContext *context) {
    CalculantlrBaseListener::enterPlusOp(context);
}

void CalcListener::exitPlusOp(CalculantlrParser::PlusOpContext *context) {

    int right = stk.top();
    stk.pop();
    int left = stk.top();
    stk.pop();

    stk.push(left + right);

    CalculantlrBaseListener::exitPlusOp(context);
}

void CalcListener::enterToAtom(CalculantlrParser::ToAtomContext *context) {
    CalculantlrBaseListener::enterToAtom(context);
}

void CalcListener::exitToAtom(CalculantlrParser::ToAtomContext *context) {
    CalculantlrBaseListener::exitToAtom(context);
}

void CalcListener::enterMultOp(CalculantlrParser::MultOpContext *context) {
    CalculantlrBaseListener::enterMultOp(context);
}

void CalcListener::exitMultOp(CalculantlrParser::MultOpContext *context) {

    int right = stk.top();
    stk.pop();
    int left = stk.top();
    stk.pop();

    stk.push(left*right);

    CalculantlrBaseListener::exitMultOp(context);
}

void CalcListener::enterDivOp(CalculantlrParser::DivOpContext *context) {
    CalculantlrBaseListener::enterDivOp(context);
}

void CalcListener::exitDivOp(CalculantlrParser::DivOpContext *context) {

    int right = stk.top();
    stk.pop();
    int left = stk.top();
    stk.pop();

    stk.push(div(left, right).quot);

    CalculantlrBaseListener::exitDivOp(context);
}

void CalcListener::enterInt(CalculantlrParser::IntContext *context) {
    CalculantlrBaseListener::enterInt(context);
}

void CalcListener::exitInt(CalculantlrParser::IntContext *context) {

    int a = stoi(context->getText());
    stk.push(a);

    CalculantlrBaseListener::exitInt(context);
}

void CalcListener::enterUnaryMinusOp(CalculantlrParser::UnaryMinusOpContext *context) {
    CalculantlrBaseListener::enterUnaryMinusOp(context);
}

void CalcListener::exitUnaryMinusOp(CalculantlrParser::UnaryMinusOpContext *context) {

    int right = stk.top();
    stk.pop();
    int left = stk.top();
    stk.pop();

    stk.push(left-right);

    CalculantlrBaseListener::exitUnaryMinusOp(context);
}

void CalcListener::enterParenthesisOp(CalculantlrParser::ParenthesisOpContext *context) {
    CalculantlrBaseListener::enterParenthesisOp(context);
}

void CalcListener::exitParenthesisOp(CalculantlrParser::ParenthesisOpContext *context) {
    CalculantlrBaseListener::exitParenthesisOp(context);
}

void CalcListener::enterEveryRule(antlr4::ParserRuleContext *context) {
    CalculantlrBaseListener::enterEveryRule(context);
}

void CalcListener::exitEveryRule(antlr4::ParserRuleContext *context) {
    CalculantlrBaseListener::exitEveryRule(context);
}

void CalcListener::visitTerminal(antlr4::tree::TerminalNode *node) {
    CalculantlrBaseListener::visitTerminal(node);
}

void CalcListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
    CalculantlrBaseListener::visitErrorNode(node);
}
