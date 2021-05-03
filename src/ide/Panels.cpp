#include "../../include/Panels.h"
#include <wx/stattext.h>
#include "../../include/Communicate.h"


LeftPanel::LeftPanel(wxPanel *parent) : wxPanel(parent, -1, wxPoint(-1, -1),
                                                wxSize(400, 400), wxBORDER_SUNKEN)
{
    count = 0;
    this -> m_parent = parent;

    // Button RUN
    this -> run = new wxButton(this, ID_PLUS, wxT("RUN"),
                               wxPoint(5, 5));


}


/**
 * Constructor
 * @param parent
 */
RightPanel::RightPanel(wxPanel *parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
                                                  wxSize(400, 400), wxBORDER_SUNKEN)
{
    text = new wxStaticText(this, -1, wxT("Hello"), wxPoint(50, 50));
}


void RightPanel::OnSetText(wxCommandEvent &event)
{

}
