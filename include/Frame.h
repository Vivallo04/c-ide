//
// Created by vivallo on 4/8/21.
//
#include "wx/wx.h"
#ifndef C_IDE_FRAME_H
#define C_IDE_FRAME_H


class Frame : public wxFrame
{
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

private:
    // This class handles events
    DECLARE_EVENT_TABLE()
};

#endif //C_IDE_FRAME_H
