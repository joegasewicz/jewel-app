//
// Created by Joe Goose on 23/04/2023.
//

#include "Gui.h"


bool Gui::OnInit()
{
//    Button *btnapp = new Button(wxT("Button"));
//    btnapp->Show(true);
    MainFrame *f = new MainFrame();
    f->Show();
    return true;
}