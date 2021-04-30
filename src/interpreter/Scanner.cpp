//
// Created by vivallo on 4/26/21.
//

#include "Scanner.h"
#include <iostream>

/**
 * Private
 */
void Scanner::InitToken()
{
    token = std::make_shared<Token>("",
            charStream -> CurrentRow(),
            charStream -> CurrentColumn(),
            Token::None);
}

void Scanner::SetText(std::string text)
{
    token -> text = text;
}

void Scanner::SetType(int type)
{
    token -> type = type;
}

void Scanner::EnterChar()
{
    token -> text.append(1, CurrentChar());
}

bool Scanner::IntegerLiteral()
{
    if (!isdigit(CurrentChar()))
        return false;
    while (isdigit(CurrentChar()))
    {
        EnterChar();
        NextChar();
    }
    return true;
}

bool Scanner::NumberLiteral()
{
    // Default Type
    SetType(Token::Number);

    if (isdigit(CurrentChar()))
    {
        IntegerLiteral();
        if (CurrentChar() == '.')
        {
            // Set type <float>
            EnterChar();
            NextChar();

            if (isdigit(CurrentChar()))
            {
                IntegerLiteral();
            }
        }
    } else if (CurrentChar() == '.')
    {
        EnterChar();
        NextChar();
        if (!IntegerLiteral())
            return false;
    } else
    {
        return false;
    }

    if (CurrentChar() == 'e' || CurrentChar() == 'E')
    {
        EnterChar();
        NextChar();

        if (CurrentChar() == '+' || CurrentChar() == '-')
        {
            EnterChar();
            NextChar();
        }
        if (!IntegerLiteral())
        {
            return false;
        }
    }
    return true;
}


/**
 * Public
 */
std::shared_ptr<Token> Scanner::CurrentToken() const
{
    return token;
}

std::shared_ptr<Token> Scanner::NextToken()
{
    SkipWhiteSpace();
    InitToken();

    char character;
    if ((character = CurrentChar() != EOF))
    {
        switch (character)
        {
            case '+':
                SetType(Token::Plus);
                EnterChar();
                NextChar();
                break;

            case '-':
                SetType(Token::Minus);
                EnterChar();
                NextChar();
                break;

            //case 'int':
            //case 'long':
            //case 'char':
            //case 'float':
            //case 'double':
            //case 'struct':
            //case 'reference':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                NumberLiteral();
                break;
            default:
                throw "Invalid Character";
        }
    } else
    {
        SetType(EOF);
        SetText("EOF");
    }
    std::cout << "Scanning Token: " << token -> text << "| type: "
              << token -> type << std::endl;

    return token;
}

char Scanner::CurrentChar() const
{
    return charStream -> CurrentChar();
}

char Scanner::NextChar()
{
    return charStream -> NextChar();
}

bool Scanner::IsWhiteSpace(char character) const
{
    return (character == ' ' || character == '\t' || character == '\n'
            || character == '\r');
}

void Scanner::SkipWhiteSpace()
{
    while (IsWhiteSpace(CurrentChar()))
    {
        NextChar();
    }
}
