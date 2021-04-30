//
// Created by vivallo on 4/26/21.
//

#ifndef C_IDE_CHARSTREAM_H
#define C_IDE_CHARSTREAM_H
#include <cstring>
#include <iostream>

class CharStream
{
private:
    std::string text;
    int row;
    int column;

public:
    explicit CharStream(const std::string &text)
        : text(text)
        , row(1)
        , column(1)
    {
    }


    int CurrentRow();
    int CurrentColumn();

    // Return the source character at the current position
    char CurrentChar() const;

    // Consume the current source character and return the next one
    char NextChar();
};


#endif //C_IDE_CHARSTREAM_H
