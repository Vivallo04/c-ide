//
// Created by vivallo on 5/5/21.
//

#ifndef C_IDE_ERROR_H
#define C_IDE_ERROR_H

extern int errorCount;

enum AbortCode
{
    abortInvalidCommandLineArgs = - 1,
    abortSourceFileOpenFailed = -2,
    abortIFormFileOpenFailed = -3,
    abortAssemblyFileOpenFailed = -4,
    abortTooManySyntaxErrors = -5,
    abortStackOverflow = -6,
    abortCodeSegmentOverflow = -7,
    abortNestingTooDeep = -8,
    abortRunTimeError = -9,
    abortUnimplementedFeature = -10,
};

void AbortTranslation(AbortCode code);


#endif //C_IDE_ERROR_H
