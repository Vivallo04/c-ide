//
// Created by vivallo on 5/5/21.
//

#include "Buffer.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <time.h>
#include "common.h"


char eofChar = 0x7f;
int inputPosition;

int listFlag = true;

/**
 *
 * @param InputFileName
 * @param code
 */
TextInBuffer::TextInBuffer(const char *InputFileName, AbortCode code)
                          : FileName(new char[strlen(InputFileName)])
{
    strcpy(FileName, InputFileName);

    file.open(FileName, std::ios::in);
    if (!file.good())
    {
        AbortTranslation(code);
    }
}

/**
 *
 * @return
 */
char TextInBuffer::GetChar()
{
    const int tabSize = 8;
    char ch;

    if (*Char == eofChar)
    {
        return eofChar;
    } else if (*Char == '\0')
    {
        return eofChar;
    } else
    {
        ++Char;
        ++inputPosition;
        ch = *Char;
    }

    if (ch == '\t')
    {
        inputPosition += tabSize - inputPosition % tabSize;
    }
    return ch;
}


/**
 *
 * @return
 */
char TextInBuffer::PutBackChar()
{
    --Char;
    --inputPosition;
    return *Char;
}

/**
 *
 * @param SourceFileName
 */
SourceBuffer::SourceBuffer(const char *SourceFileName)
             : TextInBuffer(SourceFileName, abortSourceFileOpenFailed)
{
    if (listFlag)
    {
        list.Initialize(SourceFileName);
    }
    GetLine();
}


/**
 *
 * @return
 */
char SourceBuffer::GetLine()
{
    extern int lineNumber;
    extern int currentNestingLevel;

    if (file.eof())
    {
        Char = &eofChar;
    } else
    {
        file.getline(text, maxInputBufferSize);
        Char = text;
        if (listFlag)
        {
            list.PutLine(text, currentLineNumber++, ++currentNestingLevel);
        }
    }
    inputPosition = 0;
    return *Char;
}

const int maxPrintLineLength = 80;
const int maxLinesPerPage = 50;


ListBuffer list;


/**
 *
 */
void ListBuffer::PrintPageHeader()
{
    const char formFeedChar = '\f';
    std::cout << formFeedChar << "Page " << ++pageNumber << " " << SourceFileName <<
    " " << date << std::endl;

    lineCount = 0;
}

/**
 *
 * @param fileName
 */
void ListBuffer::Initialize(const char *fileName)
{
    text[0] = '\0';
    pageNumber = 0;

    SourceFileName = new char[strlen(fileName) + 1];
    strcpy(SourceFileName, fileName);

    time_t timer;
    time(&timer);
    strcpy(date, asctime(localtime(&timer)));

    date[strlen(date) - 1] = '\0';
    PrintPageHeader();
}


/**
 *
 */
void ListBuffer::PutLine()
{
    if (listFlag && (lineCount == maxLinesPerPage))
    {
        PrintPageHeader();
    }

    text[maxPrintLineLength] = '\0';
    std::cout << text << std::endl;
    text[0] = '\0';
    lineCount++;
}