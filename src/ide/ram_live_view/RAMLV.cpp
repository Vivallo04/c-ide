//
// Created by vivallo on 5/3/21.
//
#include "RAMLV.h"
#include "wx/wx.h"
#include "wx/grid.h"


RAMLV::RAMLV(wxPanel *parent)
{
    CreateGrid(parent);
}



void RAMLV::CreateGrid(wxPanel *parent)
{
    // Create a wxGrid object
    wxGrid *grid = new wxGrid(parent, wxID_ANY,
                              wxPoint(0, 0),
                              wxSize(323, 720));

    // Set the grid dimensions
    grid -> CreateGrid(14, 3);

    // Set Row and Column sizes
    grid -> SetRowSize(0, 2);
    grid -> SetColSize(0, 10);
    grid -> CanEnableCellControl();
}

void RAMLV::PopulateGrid(wxGrid *grid, long *address, std::string name, int *value, int ref_num)
{
    for(int i = 0; i < grid -> GetNumberRows(); i++)
    {
        for (int j = 0; j < grid -> GetNumberCols(); j++)
        {

        }
    }
}

wxGrid *RAMLV::GetGrid() {
    return grid;
}
