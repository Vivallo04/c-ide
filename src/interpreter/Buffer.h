//
// Created by vivallo on 5/5/21.
//

#ifndef C_IDE_BUFFER_H
#define C_IDE_BUFFER_H
#include "include.h"
#include "fstream"
#include <cstdio>
#include <cstring>
#include "misc.h"
#include "error.h"

extern char eofChar;
extern int inputPosition;
extern int listFlag;
extern int level;

const int maxInputBufferSize = 256;

/**
 * Super Class
 */
class TextInBuffer
{
protected:
    std::fstream file;
    char *const FileName;
    char text[maxInputBufferSize];
    char *Char;

    virtual char GetLine() = 0;

public:
    TextInBuffer(const char *InputFileName, AbortCode code);

    virtual ~TextInBuffer()
    {
        file.close();
        delete FileName;
    }

    char _Char() const {return *Char;}
    char GetChar();
    char PutBackChar();
};

class SourceBuffer : public TextInBuffer
{
    virtual char GetLine();

public:
    SourceBuffer(const char *SourceFileName);
};

class TextOutBuffer
{
public:
    char text[maxInputBufferSize + 16];
    virtual void PutLine() = 0;
    void PutLine(const char *Text)
    {
        std::strcpy(text, Text);
        PutLine();
    }
};

class ListBuffer : public TextOutBuffer
{
    char *SourceFileName;
    char date[26];
    int pageNumber;
    int lineCount;

    void PrintPageHeader();

public:
    virtual  ~ListBuffer()
    {
        delete SourceFileName;
    }

    void Initialize(const char *fileName);
    virtual void PutLine();
    void PutLine(const char *Text)
    {
        TextOutBuffer::PutLine(Text);
    }

    void PutLine(const char *Text, int lineNumber, int nestingLevel)
    {
        sprintf(text, "%4d %d: %s", lineNumber, nestingLevel, Text);
        PutLine();
    }
};

extern ListBuffer list;


#endif //C_IDE_BUFFER_H
