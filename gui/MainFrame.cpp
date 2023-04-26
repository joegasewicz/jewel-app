//
// Created by Joe Goose on 23/04/2023.
//

#include "MainFrame.h"


enum
{
    ID_MAIN_FRAME = 1
};

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Main Frame")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_MAIN_FRAME, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Status Bar");


    wxPanel *panel = new wxPanel(this, wxID_ANY);

    wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(20, 20));
    button->SetFocus();
    Center();

    Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_MAIN_FRAME);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_BUTTON, &MainFrame::OnQuit, this, wxID_ABORT);
}

void MainFrame::OnHello(wxCommandEvent &event) {
    std::cout << "Quiting..." << std::endl;
    wxLogMessage("Main frame running...");
}

void MainFrame::OnExit(wxCommandEvent &event) {
    std::cout << "Quiting..." << std::endl;
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("Main frame", "About Main Frame", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnQuit(wxCommandEvent &event)
{
    wxLogMessage("Quitting...");
    Close(true);
}