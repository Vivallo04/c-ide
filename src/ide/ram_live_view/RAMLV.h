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
private:
    wxGrid *grid;

public:
    explicit RAMLV(wxPanel *parent);
    void CreateGrid(wxPanel *parent);
    void PopulateGrid(wxGrid *grid, long *address, std::string name, int *value, int ref_num);
    wxGrid *GetGrid();
};


#endif //C_IDE_RAMLV_H
