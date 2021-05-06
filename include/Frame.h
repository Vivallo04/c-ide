//
// Created by vivallo on 4/8/21.
//
#include "wx/wx.h"
#include "../src/ide/ram_live_view/RAMLV.h"
#include "../src/ide/code_editor/CodeEditor.h"
#include "../src/ide/application_log/LoggingFrame.h"

#ifndef C_IDE_FRAME_H
#define C_IDE_FRAME_H



class Frame : public wxFrame
{
private:
    RAMLV *ramlv;
    CodeEditor *codeEditor;
    LoggingFrame *logFrame;

public:
    // Constructor
    Frame(const wxString &title, const wxSize &size);

    // Event handlers
    void OnQuit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSize(wxSizeEvent &event);
    void OnButtonOK(wxCommandEvent &event);
    void CreateMenuBar();
    void CreateExtraWindows();
    void SetLoggingWindow(wxPanel *parent);
    void ExecuteEditor();

private:
    // This class handles events
    DECLARE_EVENT_TABLE()
};

#endif //C_IDE_FRAME_H
