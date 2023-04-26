//
// Created by Joe Goose on 23/04/2023.
//

#ifndef JEWEL_APP_MAINFRAME_H
#define JEWEL_APP_MAINFRAME_H


#include <wx/wx.h>


class MainFrame : public wxFrame
{

public:
    MainFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
};


#endif //JEWEL_APP_MAINFRAME_H
