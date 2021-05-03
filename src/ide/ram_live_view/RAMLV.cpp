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
    grid = new wxGrid(parent, wxID_ANY,
                              wxPoint(0, 0),
                              wxSize(323, 720));

    // Set the grid dimensions
    grid -> CreateGrid(14, 4);

    // Set Row and Column sizes
    grid -> SetRowSize(1, 2);
    grid -> SetColSize(0, 10);
    //grid -> EnableGridLines(false);
    grid -> SetColLabelValue(0, wxT("Addres"));
    grid -> SetColLabelValue(1, wxT("Name"));
    grid -> SetColLabelValue(2, wxT("Value"));
    grid -> SetColLabelValue(3, wxT("Reference"));


    for (size_t i = 0; i < grid -> GetNumberRows(); i++)
    {
        for (size_t j = 0; j < grid -> GetNumberCols(); j++)
        {
            grid -> SetReadOnly(i, j);
            grid -> DisableRowResize(i);
            grid -> DisableColResize(j);
        }
    }

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
