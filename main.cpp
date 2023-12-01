#include <wx/wx.h>
#include "fonts.h"
#include "colours.h"
#include "button.h"

class Application : public wxApp {
    public:
        bool OnInit() override;
};

class Window : public wxFrame {
    public:
        Window();
};

Window::Window() : wxFrame(
        nullptr, 
        wxID_ANY,
        "wxcalculator",
        wxDefaultPosition,
        wxSize(0, 0),
        wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER ^ wxMAXIMIZE_BOX
        ){
    this->SetFont(Fonts::current);
    this->SetBackgroundColour(Colours::background);

    auto column = new wxBoxSizer(wxVERTICAL);

    auto display = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250, 200));
    display->SetBackgroundColour(Colours::surface);
    column->Add(display, 0, wxEXPAND);
    
    auto keyboard = new wxGridSizer(5, 4, 10, 10);
    column->Add(keyboard, 0, wxEXPAND | wxALL, 15);  

    keyboard->Add(new Button(this, wxID_ANY, wxT("C"), "", Colours::primary));
    keyboard->Add(new Button(this, wxID_ANY, wxT("←"), "", Colours::primary));
    keyboard->Add(new Button(this, wxID_ANY, wxT("%"), "", Colours::primary));
    keyboard->Add(new Button(this, wxID_ANY, wxT("÷"), "", Colours::primary));

    keyboard->Add(new Button(this, wxID_ANY, wxT("7"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("8"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("9"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("×"), "", Colours::primary));

    keyboard->Add(new Button(this, wxID_ANY, wxT("4"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("5"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("6"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("+"), "", Colours::primary));

    keyboard->Add(new Button(this, wxID_ANY, wxT("3"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("2"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("1"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("-"), "", Colours::primary));

    keyboard->Add(new Button(this, wxID_ANY, wxT("+⁄−"), "", Colours::primary));
    keyboard->Add(new Button(this, wxID_ANY, wxT("0"), ""));
    keyboard->Add(new Button(this, wxID_ANY, wxT("."), ""));
    auto p_hover {Colours::primary.ChangeLightness(150)};
    auto p_active {Colours::primary.ChangeLightness(120)};
    keyboard->Add(new Button(this, wxID_ANY, wxT("="), "", Colours::background, Colours::primary, p_hover, p_active));

    this->SetSizerAndFit(column);
}

bool Application::OnInit() {
    if(!Fonts::load_font()) return false;

    auto window = new Window();
    window->Show(true);
    return true;
}

wxIMPLEMENT_APP(Application);
