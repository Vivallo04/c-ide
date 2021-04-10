/**
 * Name: App.cpp
 * Purpose: C! IDE, an IDE for the pseudo language C!
 * Author: Andr´es Vivallo
 */
#include "wx/wx.h"
#include "../include/App.h"
#include "../include/Frame.h"

/**
 * Application Workflow:
 * 1. Depending on the platform, the main, WinMain or equivalent function runs.
 * wxWidgets initializes its internal data structures and creates and instance
 * of App.
 * 2. wxWidgets calls App::OnInit, which creates an instance of Frame.
 * 3. The Frame constructor creates the window via the wxFrame constructor and
 * adds an icon, menu bar and status bar, etc.
 * 4. App::OnInit shows the frame and returns true.
 * 5. wxWidgets starts the event loop, waiting for event and dispatching them to
 * the appropriate handlers.
 */


// Implements App & wxGetApp
// Entry point
DECLARE_APP(App)
IMPLEMENT_APP(App)

App::App()
{

}

App::~App()
{

}

bool App::OnInit()
{
    // Create the main windows application
    Frame *frame = new Frame(wxT("C! IDE"));

    // Show it
    frame -> Show(true);
    // Start the event loop
    return true;
}