#ifndef C_IDE_COMMUNICATE_H
#define C_IDE_COMMUNICATE_H
#include "wx/wx.h"
#include "Panels.h"
#include <wx/wxprec.h>

class Communicate : public wxFrame
{
public:
    Communicate(const wxString &title);

    LeftPanel *leftPanel;
    RightPanel *rightPanel;
    wxPanel *parentPanel;
};


#endif //C_IDE_COMMUNICATE_H
