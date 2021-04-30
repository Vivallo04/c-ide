//
// Created by vivallo on 4/26/21.
//

#ifndef C_IDE_VISITORPATTERN_H
#define C_IDE_VISITORPATTERN_H

#define ABSTRACT_VISIT_METHOD_DECL(classname) \
    virtual void visit(classname *) = 0;

#define CONCRETE_VISIT_METHOD_DECL(classname) \
    void visit(classname *);

#define ABSTRACT_ACCEPT_METHOD_DECL \
    virtual void accept(Visitor *visitor);

#define CONCRETE_ACCEPT_METHOD_DECL \
    void accept(Visitor *visitor);

#define CONCRETE_ACCEPT_METHOD_IMPL(classname) \
    void classname::accept(Visitor *visitor)   \
    {                                          \
        return visitor -> visit(this);         \
    }

class BinaryExpression;
class NumberLiteral;

class Visitor
{
public:
    ABSTRACT_VISIT_METHOD_DECL(BinaryExpression)
    ABSTRACT_VISIT_METHOD_DECL(NumberLiteral)
};

#endif //C_IDE_VISITORPATTERN_H
