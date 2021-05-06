//
// Created by vivallo on 5/3/21.
//
#include "LoggingFrame.h"

/**
 * Setup the logger so that wxWidgets identifies it
 * as a global logging where to print out all the logs.
 */
void LoggingFrame::SetLoggingWindow()
{
    wxLog::SetActiveTarget(new wxLogTextCtrl(log));
}

/**
 * Returns logger object
 * @return log
 */
void *LoggingFrame::GetLoggingWindow() const
{
    return log;
}


/**
 * Constructor
 * Create a wxTextCtrl object for the logging window.
 */
LoggingFrame::LoggingFrame(wxPanel *parent)
{
    log = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition,
                                     wxSize(420, 150), wxTE_MULTILINE | wxTE_READONLY);
    SetLoggingWindow();
}
