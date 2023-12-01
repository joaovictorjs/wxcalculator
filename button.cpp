#include "button.h"
#include <wx/dcbuffer.h>

Button::Button(
                wxWindow* parent,
                int id,
                const wxString& label,
                const wxString& value, 
                const wxColour& text,
                const wxColour& normal,
                const wxColour& hover,
                const wxColour& active
              ) : wxWindow(parent, id, wxDefaultPosition, wxSize(50, 50)) {
        is_hovering = false;
        is_pressing = false;
        this->label = label;
        this->value = value;
        this->text = text;
        this->normal = normal;
        this->hover = hover;
        this->active = active;

        Bind(wxEVT_PAINT, &Button::on_paint, this);
        Bind(wxEVT_ENTER_WINDOW, &Button::on_enter_window, this);
        Bind(wxEVT_LEAVE_WINDOW, &Button::on_leave_window, this);
        Bind(wxEVT_LEFT_DOWN, &Button::on_left_down, this);
        Bind(wxEVT_LEFT_UP, &Button::on_left_up, this);
}

void Button::on_paint(wxPaintEvent& evt){
        this->SetBackgroundStyle(wxBG_STYLE_PAINT);
        wxAutoBufferedPaintDC dc(this);
        dc.SetBackground(Colours::background);
        dc.Clear();

        dc.SetPen(*wxTRANSPARENT_PEN);
        dc.SetBrush(is_pressing ? active : is_hovering ? hover : normal);

        dc.DrawRoundedRectangle(wxPoint(0, 0), GetSize(), 4);

        auto ts = dc.GetTextExtent(label); 
        dc.SetTextForeground(text);
        dc.DrawText(label, (GetSize().GetWidth() / 2) - (ts.GetWidth() / 2), (GetSize().GetHeight() / 2) - (ts.GetHeight() / 2));
}

void Button::on_enter_window(wxMouseEvent& evt){
        is_hovering = true;
        SetCursor(wxCursor(wxCURSOR_HAND));
        Refresh();
}

void Button::on_leave_window(wxMouseEvent& evt){
        is_hovering = false;
        Refresh();
}

void Button::on_left_down(wxMouseEvent& evt){
        is_pressing = true;
        Refresh();
}

void Button::on_left_up(wxMouseEvent& evt){
        is_pressing = false;
        Refresh();
}

