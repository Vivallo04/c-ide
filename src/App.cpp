#include "../include/App.h"

wxIMPLEMENT_APP(App);

App::App()
{

}

App::~App()
{

}

bool App::OnInit()
{
    main_frame1 = new Main();
    main_frame1 -> Show();
    return true;
}