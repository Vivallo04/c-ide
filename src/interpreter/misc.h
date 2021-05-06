//
// Created by vivallo on 5/5/21.
//

#ifndef C_IDE_MISC_H
#define C_IDE_MISC_H

enum CharCode
{
    Letter,
    Digit,
    Special,
    Quote,
    WhiteSpace,
    EndofFile
    Error,
};

enum TokenCode
{
    Dummy,
    Word,
    Number,
    Period,
    EndofFile,
    Error
};

enum DataType
{
    Dummy,
    Integer,
    Real,
    Character,
    String,
};

enum DataValue
{
    int integer;
    float real;
    char character;
    char *String;
};

#endif //C_IDE_MISC_H
