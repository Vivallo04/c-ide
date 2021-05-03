#include "../../include/Communicate.h"

Communicate::Communicate(const wxString &title) : wxFrame(NULL, wxID_ANY,
                                                          title, wxDefaultPosition, wxSize(400, 400))
{
        parentPanel = new wxPanel(this, wxID_ANY);
        wxBoxSizer *box = new wxBoxSizer(wxHORIZONTAL);

        leftPanel = new LeftPanel(parentPanel);
        rightPanel = new RightPanel(parentPanel);

        box ->Add(leftPanel, wxEXPAND | wxALL, 5);
        box -> Add(rightPanel, wxEXPAND | wxALL, 5);

        parentPanel -> SetSizer(box);
        this ->Centre();
}
