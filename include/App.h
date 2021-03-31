#ifndef C_IDE_APP_H
#define C_IDE_APP_H
#include "wx/wx.h"
#include "../include/main.h"

class App: public wxApp
{
public:
    App();
    ~App();

private:
    Main *main_frame1 = nullptr;

public:
    virtual bool OnInit();
};


#endif //C_IDE_APP_H
