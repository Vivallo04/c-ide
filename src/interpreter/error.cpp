//
// Created by vivallo on 5/5/21.
//
#include "error.h"
#include "include.h"
#include <stdio.h>
#include <iostream>
#include "error.h"
#include <cstring>

int errorCount = 0;

static std::string abortMessage[] = {
        "NULL",
        "Invalid command line argument",
        "Failed to open the source file",
        "Failed to open intermediate form file",
        "Failed to open assembly file",
        "Too many syntax errors",
        "Stack Overflow",
        "Code segment overflow",
        "Nesting too deep",
        "Runtime error",
        "Unimplemented Feature",
};

void abortTranslation(AbortCode code)
{
    std::cerr << "*** Fate translation error: " << abortMessage[-code] << std::endl;
    exit(code);
}