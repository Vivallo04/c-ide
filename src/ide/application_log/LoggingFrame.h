//
// Created by vivallo on 5/3/21.
//
#ifndef C_IDE_LOGGINGFRAME_H
#define C_IDE_LOGGINGFRAME_H

#include "wx/wx.h"
#include <wx/gtk/textctrl.h>

class LoggingFrame
{
private:
    wxTextCtrl *log;

public:
    explicit LoggingFrame(wxPanel *parent);
    void SetLoggingWindow();
    void *GetLoggingWindow() const;
};


#endif //C_IDE_LOGGINGFRAME_H
