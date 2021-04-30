//
// Created by vivallo on 4/26/21.
//

#include "Interpreter.h"
#include "AbstractSyntaxTree.h"
#include <stdlib.h>

void Interpreter::visit(BinaryExpression *binaryExpression)
{
    binaryExpression -> children[0] ->accept(this);
    double a = ans;

    binaryExpression -> children[1] ->accept(this);
    double b = ans;

    if (binaryExpression -> token -> text == "+")
    {
        ans = a + b;
    } else if (binaryExpression -> token -> text == "-")
    {
        ans = a - b;
    } else
    {
        throw "Undefined Operation.";
    }
}


void Interpreter::visit(NumberLiteral *integer)
{
    ans = atof(integer -> token -> text.c_str());
}


double Interpreter::answer() const
{
    return ans;
}
