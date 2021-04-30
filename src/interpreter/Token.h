//
// Created by vivallo on 4/26/21.
//

#ifndef C_IDE_TOKEN_H
#define C_IDE_TOKEN_H
#include <iostream>
#include <string>

struct Token
{
    enum TokenType
    {
        None = 256,
        Number = 257,
        Plus = 258,
        Minus = 259,
        Multiplication = 260,
    };

    Token()
        : text("")
        , row(0)
        , column (0)
        , type(None)
    {

    }

    Token(const std::string text, int row, int column, int type)
        : text(text)
        , row(row)
        , column(column)
        , type(None)
    {

    }

    ~Token()
    {
        std::cout << "Deleting token: " << text << std::endl;
    }

    // Fields
    int type;           // Token Type
    std::string text;   // Token String
    int row;            // Line Number
    int column;         // Column Number
};



#endif //C_IDE_TOKEN_H
