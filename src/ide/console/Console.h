//
// Created by vivallo on 4/12/21.
//
#include "wx/wx.h"
#ifndef C_IDE_CONSOLE_H
#define C_IDE_CONSOLE_H


class Console
{
public:
    explicit Console(wxPanel *parent);

private:
    Console(wxFrame *parent);

    wxTextCtrl *std_output;

};


#endif //C_IDE_CONSOLE_H
