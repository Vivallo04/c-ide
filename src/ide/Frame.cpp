//
// Created by vivallo on 4/8/21.
//
#include "wx/wx.h"
#include "../../include/Frame.h"
#include "wx/splitter.h"
#include "./ram_live_view/RAMLV.h"
#include "./application_log/LoggingFrame.h"
#include "./code_editor/CodeEditor.h"


/* In order to create a static event table(one that's created at compile time)
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

    wxPanel *left   = new wxPanel(splitterWindow);
    wxPanel *right  = new wxPanel(rightSplitter);
    wxPanel *bottom = new wxPanel(rightSplitter);

    left -> SetBackgroundColour(wxColour(200, 100, 100));
    right -> SetBackgroundColour(wxColour(100, 200, 100));
    bottom -> SetBackgroundColour(wxColour(0, 0, 0));

    rightSplitter -> SetMinimumPaneSize(400);
    rightSplitter -> SplitHorizontally(right, bottom);

    splitterWindow -> SetMinimumPaneSize(1000);
    splitterWindow -> SplitVertically(left, rightSplitter);



    // Add the RAM LIVE VIEW Panel
    RAMLV *ramlv = new RAMLV(right);

    //Add the code editor space
    CodeEditor *codeEditor = new CodeEditor(left);

    //Add the logging frame
    LoggingFrame *logFrame = new LoggingFrame(bottom);

    //TODO: 1- solve log out from the new LoggingFrame class
    // 2- add the interpreter, save files and create new ones.
    // 3- Create a connection between mserver and the C! IDE using sockets
    // 4- Remember to create a separate thread for mserver.


    CreateMenuBar();

    // Create a status bar, just for fun ;)
    CreateStatusBar(2);
    CreateExtraWindows();
    SetStatusText(wxT("Welcome to C! IDE"));
    SetMinSize(wxSize(1366, 768));
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
    wxLogMessage("All setup");
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
    wxMenu *runButton = new wxMenu();
    wxMenu *logMenu = new wxMenu();

    helpMenu -> Append(wxID_ABOUT, wxT("&About...\tF1"),
                       wxT("Show about dialog"));
    helpMenu -> AppendSeparator();

    fileMenu -> Append(wxID_EXIT, wxT("E&xit\tAlt-x"),
                       wxT("Quit this program"));
    fileMenu -> AppendSeparator();

    runButton -> Append(wxID_ANY, wxT("&Run C! code\tShift-F10"),
                        wxT("RUN"));
    runButton -> AppendSeparator();

    logMenu -> Append(wxID_ANY, wxT("&Save as\tAlt-1"),
                      wxT("Save logs into a text file"));
    logMenu -> AppendSeparator();


    //Now append the newly created menu to the menu bar
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar -> Append(fileMenu,  wxT("&File"));
    menuBar -> Append(helpMenu,  wxT("&Help"));
    menuBar -> Append(runButton, wxT("&Run"));
    menuBar -> Append(logMenu,   wxT("&Log"));


    // Attach this menu bar to the frame
    SetMenuBar(menuBar);
}
