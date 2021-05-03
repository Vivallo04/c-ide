//
// Created by vivallo on 5/3/21.
//
#include "RAMLV.h"
#include "wx/wx.h"
#include "wx/grid.h"


RAMLV::RAMLV(wxFrame *parent)
{
    CreateGrid(parent);
}



void RAMLV::CreateGrid(wxFrame *parent)
{
    // Create a wxGrid object
    wxGrid *grid = new wxGrid(parent, -1,
                              wxPoint(0, 0),
                              wxSize(200, 400));

    // Set the grid dimensions
    grid -> CreateGrid(10, 4);

    // Set Row and Column sizes
    grid -> SetRowSize(0, 10);
    grid -> SetColSize(0, 25);
}

void RAMLV::PopulateGrid(wxGrid *grid, long *address, std::string name, int *value, int ref_num)
{
    for(int i = 0; i < grid -> GetNumberRows(); i++)
    {

    }
}
