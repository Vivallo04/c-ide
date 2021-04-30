//
// Created by vivallo on 4/26/21.
//

#ifndef C_IDE_INTERPRETER_H
#define C_IDE_INTERPRETER_H
#include "VisitorPattern.h"


class Interpreter : public Visitor
{
public:
    CONCRETE_VISIT_METHOD_DECL(BinaryExpression)
    CONCRETE_VISIT_METHOD_DECL(NumberLiteral)

    double answer() const;

private:
    double ans; // the latest result
};


#endif //C_IDE_INTERPRETER_H
