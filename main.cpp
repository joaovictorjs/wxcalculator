#include <wx/wx.h>
#include "fonts.h"

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
        wxDefaultSize,
        wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER ^ wxMAXIMIZE_BOX
        ){
    this->SetFont(Fonts::current);
    auto s = new wxStaticText(this, wxID_ANY, "123 ABC abc + - =");
}

bool Application::OnInit() {
    if(!Fonts::load_font()) return false;

    auto window = new Window();
    window->Show(true);
    return true;
}

wxIMPLEMENT_APP(Application);
