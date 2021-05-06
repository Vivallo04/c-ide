#include <wx/generic/panelg.h>
#include "wx/wx.h"
#include "Console.h"


Console::Console(wxFrame *parent)
{
    std_output = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition,
                                wxSize(420, 150), wxTE_MULTILINE | wxTE_READONLY);
}
