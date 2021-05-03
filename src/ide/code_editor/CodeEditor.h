//
// Created by vivallo on 5/3/21.
//

#ifndef C_IDE_CODEEDITOR_H
#define C_IDE_CODEEDITOR_H
#include "wx/wx.h"

class CodeEditor
{
private:
    wxTextCtrl *textControl;
    wxFont *JetbrainsMono;
public:
    explicit CodeEditor(wxPanel *parent);
    void SetCodeEditorFont();
};


#endif //C_IDE_CODEEDITOR_H
