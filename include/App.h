#ifndef C_IDE_APP_H
#define C_IDE_APP_H
#include "wx/wx.h"
#include "Frame.h"

class App: public wxApp
{
public:
    App();
    ~App();
    virtual bool OnInit();

private:
    Frame *frame = nullptr;
};

#endif //C_IDE_APP_H
