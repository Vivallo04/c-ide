//
// Created by vivallo on 4/8/21.
//
#include "wx/wx.h"
#include "../../include/Frame.h"
#include "log4cxx/logger.h"
/**
 * In order to create a stastic event table(one that's created at compile time)
 * you need to:
 * 1. Declare a new class that is derived directly or indirectly from wxEvtHandler
 * 2. Add a member function for each event that must be handled.
 * 3. Declare the event table in the class with DECLARE_EVENT_TABLE
 * 4. Implement the event table in the source file with BEGIN_EVENT_TABLE,
 * END_EVENT_TABLE
 * 5. Add event table entries to the table(such as EVT_BUTTON), mapping each
 * event to the appropriate member function.
 */


// Event table for Frame
BEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(wxID_ABOUT, Frame::OnAbout)
    EVT_MENU(wxID_EXIT, Frame::OnQuit)
    EVT_SIZE(Frame::OnSize)
    EVT_BUTTON(wxID_OK, Frame::OnButtonOK)
END_EVENT_TABLE()

static log4cxx::LoggerPtr logger;

Frame::Frame(const wxString &title, const wxSize &size) : wxFrame(NULL, wxID_ANY, title)
{
    // Set the frame icon
    /*SetIcon(NULL);*/


    // Create a menu bar
    wxMenu *fileMenu = new wxMenu;

    // The "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu -> Append(wxID_ABOUT, wxT("&About...\tF1"),
                     wxT("Show about dialog"));

    fileMenu -> Append(wxID_EXIT, wxT("E&xit\tAlt-x"),
                     wxT("Quit this program"));

    //Now append the newly created menu to the menu bar
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar -> Append(fileMenu, wxT("&File"));
    menuBar -> Append(helpMenu, wxT("&Help"));

    // Attach this menu bar to the frame
    SetMenuBar(menuBar);

    // Create a status bar, just for fun ;)
    CreateStatusBar(2);
    SetStatusText(wxT("Welcome to C! IDE"));
    SetMinSize(wxSize(1000, 800));
}

void Frame::OnQuit(wxCommandEvent &event)
{
    // Call the destructor
    LOG4CXX_INFO(logger, "Exiting application");
    // Destroy the frame
    Close();
}

void Frame::OnAbout(wxCommandEvent &event)
{
    wxString message;
    message.Printf(wxT("Hello and welcome to C! IDE"),
                   wxVERSION_STRING);
    wxMessageBox(message, wxT("About C! IDE"),
                 wxOK | wxICON_INFORMATION, this);
}

void Frame::OnButtonOK(wxCommandEvent &event)
{
    wxButton *button = new wxButton(this, wxID_OK, wxT("OK"),
                                    wxPoint(200, 200));
}

void Frame::OnSize(wxSizeEvent &event)
{
    wxTopLevelWindowBase::OnSize(event);
}
