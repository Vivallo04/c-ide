#ifndef C_IDE_PANELS_H
#define C_IDE_PANELS_H
#include "wx/wx.h"
#include "wx/panel.h"

class LeftPanel : public wxPanel
{
public:
    LeftPanel(wxPanel *parent);

    wxButton *run;
    int count;
};

class RightPanel : public wxPanel
{
public:
    RightPanel(wxPanel *parent);
    void OnSetText(wxCommandEvent &event);

    wxStaticText *text;
};

const int ID_PLUS = 101;
const int ID_MINUS = 102;


#endif //C_IDE_PANELS_H
