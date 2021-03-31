#include "include/main.h"


Main::Main() : wxFrame(nullptr, wxID_ANY, "C-IDE",
                       wxPoint(30, 30),wxSize(800, 600))
{
    button1 = new wxButton(this, wxID_ANY, "Click here", wxPoint(10, 10), wxSize(150, 50));
    //text1 = new wxTextCtrl(this, wxID_ANY, wxPoint(10, 70), wxSize(300, 30));
    listBox1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

Main::~Main()
{

}
