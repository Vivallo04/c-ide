//
// Created by vivallo on 5/3/21.
//

#include "CodeEditor.h"
#define ID_TextBox 201
#include "wx/wx.h"
#include <iostream>


/**
 * Constructor
 * Create a TextCtrl so that is able to receive user input.
 * @param parent: Parent has to be left in Frame constructor.
 */
CodeEditor::CodeEditor(wxPanel *parent)
{
    // Parent must be left
    textControl = new wxTextCtrl(parent, ID_TextBox, wxT(""), wxDefaultPosition,
                                 wxSize(1280, 800),wxTE_MULTILINE | wxTE_RICH,
                                 wxDefaultValidator, wxTextCtrlNameStr);
    SetCodeEditorFont();
}

/**
 * Set up a new monospaced font and it to the text editor.
 */
void CodeEditor::SetCodeEditorFont()
{
    wxFont font = wxFont(wxSize(20, 20), wxFontFamily::wxFONTFAMILY_TELETYPE,
                         wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_NORMAL);
    textControl -> SetFont(font);
}

void CodeEditor::ReadLine()
{
    wxString line;

    for(int i = 0; i < textControl -> GetNumberOfLines(); i++)
    {
        line = textControl -> GetLineText(i);
        std::cout << line << std::endl;
    }
}
