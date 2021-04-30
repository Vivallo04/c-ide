//
// Created by vivallo on 4/26/21.
//

#ifndef C_IDE_ABSTRACTSYNTAXTREE_H
#define C_IDE_ABSTRACTSYNTAXTREE_H
#include "VisitorPattern.h"
#include "Token.h"
#include <memory>
#include <vector>
#include <iostream>

class AbstractNode
{
public:
    ABSTRACT_ACCEPT_METHOD_DECL
    // Fields
    std::shared_ptr<Token> token;
    std::vector<std::shared_ptr<AbstractNode>> children;

    // Methods
    AbstractNode(std::shared_ptr<Token> token) : token(token)
    {
        std::cout << "Creating AST Node: " << token -> text << std::endl;
    }

    void AddChild(std::shared_ptr<AbstractNode> child)
    {
        children.push_back(child);
    }


    virtual ~AbstractNode();
};

class BinaryExpression : public AbstractNode
{
public:
    CONCRETE_ACCEPT_METHOD_DECL

    BinaryExpression(std::shared_ptr<Token> token) : AbstractNode(token)
    {
    }

    virtual ~BinaryExpression(){}
};


class NumberLiteral : public AbstractNode
{
public:
    CONCRETE_ACCEPT_METHOD_DECL

    NumberLiteral(std::shared_ptr<Token> token) : AbstractNode(token)
    {

    }

    ~NumberLiteral(){}
};

#endif //C_IDE_ABSTRACTSYNTAXTREE_H
