//
// Created by vivallo on 4/26/21.
//

#include "AbstractSyntaxTree.h"
#include <iostream>

CONCRETE_ACCEPT_METHOD_IMPL(BinaryExpression)
CONCRETE_ACCEPT_METHOD_IMPL(NumberLiteral)

AbstractNode::~AbstractNode()
{
    std::cout << "Deleting Node" << std::endl;
}
