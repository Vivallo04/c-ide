//
// Created by vivallo on 5/3/21.
//

#ifndef C_IDE_RAMLV_H
#define C_IDE_RAMLV_H

#include "wx/wx.h"
#include <wx/gtk/frame.h>
#include <iostream>
#include <cstring>
#include <wx/generic/grid.h>

class RAMLV
{
public:
    RAMLV(wxFrame *parent);
    void CreateGrid(wxFrame *parent);
    void PopulateGrid(wxGrid *grid, long *address, std::string name, int *value, int ref_num);
};


#endif //C_IDE_RAMLV_H
