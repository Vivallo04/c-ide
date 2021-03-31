#ifndef C_IDE_MAIN_H
#define C_IDE_MAIN_H
#include "wx/wx.h"

#endif //C_IDE_MAIN_H

class Main: public wxFrame
{
public:
    Main();
    ~Main();

public:
    wxButton *button1 = nullptr;
    wxTextCtrl *text1 = nullptr;
    wxListBox *listBox1 = nullptr;

    wxDECLARE_EVENT_TABLE();
};