//
// Created by vivallo on 4/26/21.
//

#ifndef C_IDE_SCANNER_H
#define C_IDE_SCANNER_H
#include "CharStream.h"
#include "Token.h"
#include <iostream>
#include <memory>

class Scanner
{
public:
    explicit Scanner(CharStream *charStream) : charStream(charStream)
    {
        NextToken();
    }

    std::shared_ptr<Token> CurrentToken() const;
    std::shared_ptr<Token> NextToken();

    char CurrentChar() const;

    //Call charStream's CurrentChar() method
    char NextChar();

    bool IsWhiteSpace(char character) const;
    void SkipWhiteSpace();

private:

    CharStream *charStream;            // Source Code
    std::shared_ptr<Token> token;      // Current Token

    // Initialize the token pointer
    void InitToken();

    // Set current token's text
    void SetText(std::string text);

    // Set current token's type
    void SetType(int type);

    // Append current char to current token's text
    void EnterChar();

    // Scanning unsigned integer literal
    bool IntegerLiteral();

    // Scanning unsigned number literal
    bool NumberLiteral();

};


#endif //C_IDE_SCANNER_H
