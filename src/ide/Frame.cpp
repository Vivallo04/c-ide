//
// Created by vivallo on 4/8/21.
//
#include "wx/wx.h"
#include "../../include/Frame.h"
#include "wx/splitter.h"

#define ID_TextBox 201

/* In order to create a stastic event table(one that's created at compile time)
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


Frame::Frame(const wxString &title, const wxSize &size) : wxFrame(NULL, wxID_ANY, title)
{
    wxSplitterWindow *splitterWindow = new wxSplitterWindow(this, wxID_ANY,
                                                            wxDefaultPosition, wxDefaultSize,
                                                            wxSP_BORDER | wxSP_LIVE_UPDATE);

    wxSplitterWindow *rightSplitter = new wxSplitterWindow(splitterWindow, wxID_ANY,
                                                           wxDefaultPosition, wxDefaultSize,
                                                           wxSP_BORDER | wxSP_LIVE_UPDATE);

    wxPanel *left = new wxPanel(splitterWindow);
    wxPanel *right = new wxPanel(rightSplitter);
    wxPanel *bottom = new wxPanel(rightSplitter);

    left -> SetBackgroundColour(wxColour(200, 100, 100));
    right -> SetBackgroundColour(wxColour(100, 200, 100));
    bottom -> SetBackgroundColour(wxColour(200, 200, 100));

    rightSplitter -> SetMinimumPaneSize(400);
    rightSplitter -> SplitHorizontally(right, bottom);

    splitterWindow -> SetMinimumPaneSize(900);
    splitterWindow -> SplitVertically(left, rightSplitter);

    wxTextCtrl *textControl = new wxTextCtrl;
    textControl = new wxTextCtrl(left, ID_TextBox, wxT(""), wxDefaultPosition,
                                 wxSize(1080, 800),wxTE_MULTILINE | wxTE_RICH,
                                 wxDefaultValidator, wxTextCtrlNameStr);

    //sizer -> Add(textControl, 1, wxEXPAND, 5);
    wxLogMessage(wxT("Application Initialized"));

    CreateMenuBar();
    // Create a status bar, just for fun ;)
    CreateStatusBar(2);
    CreateExtraWindows();
    SetStatusText(wxT("Welcome to C! IDE"));
    SetMinSize(wxSize(1280, 720));
}

void Frame::OnQuit(wxCommandEvent &event)
{
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

void Frame::CreateExtraWindows()
{

}

void Frame::CreateMenuBar()
{

    // Create a menu bar
    wxMenu *fileMenu = new wxMenu();

    // The "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu();

    wxMenu *aboutMenu = new wxMenu();

    helpMenu -> Append(wxID_ABOUT, wxT("&About...\tF1"),
                       wxT("Show about dialog"));
    helpMenu -> AppendSeparator();

    fileMenu -> Append(wxID_EXIT, wxT("E&xit\tAlt-x"),
                       wxT("Quit this program"));
    fileMenu -> AppendSeparator();

    aboutMenu ->Append(wxID_ANY, wxT("A"), wxT(""));



    //Now append the newly created menu to the menu bar
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar -> Append(fileMenu, wxT("&File"));
    menuBar -> Append(helpMenu, wxT("&Help"));

    // Attach this menu bar to the frame
    SetMenuBar(menuBar);
}
