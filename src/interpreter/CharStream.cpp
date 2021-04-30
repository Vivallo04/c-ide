//
// Created by vivallo on 4/26/21.
//

#include "CharStream.h"

int CharStream::CurrentRow()
{
    return this -> row;
}

int CharStream::CurrentColumn()
{
    return this -> column;
}

char CharStream::CurrentChar() const
{
    if (text.empty())
    {
        return EOF;
    }
    if (column > text.length())
        return EOF;
    else
        return text[column - 1];  //Column start from 1
}

char CharStream::NextChar()
{
    ++column;
    return CurrentChar();
}
