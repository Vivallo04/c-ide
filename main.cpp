#include "include/main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
    EVT_BUTTON(10001, Main::OnButtonClicked)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "C-IDE",
                       wxPoint(30, 30),wxSize(800, 600))
{
    button1 = new wxButton(this, 10001, "Click here", wxPoint(10, 10), wxSize(150, 50));
    text1 = new wxTextCtrl(this, wxID_ANY, wxPoint(10, 70), wxSize(300, 30));
    listBox1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

Main::~Main()
{

}

void Main::OnButtonClicked(wxCommandEvent &event)
{
    listBox1 -> AppendString(text1 -> GetValue());
    event.Skip();
}
