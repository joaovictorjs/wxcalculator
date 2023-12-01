#pragma once

#include <wx/window.h>
#include <wx/colour.h>
#include "colours.h"

class Button : public wxWindow {
    private:
        bool is_hovering, is_pressing;
        wxString label, value;
        wxColour text, normal, hover, active;
    public:
        Button(
                wxWindow* parent,
                int id,
                const wxString& label,
                const wxString& value, 
                const wxColour& text = Colours::text,
                const wxColour& normal = Colours::background,
                const wxColour& hover = Colours::hover,
                const wxColour& active = Colours::active
              );

        void on_paint(wxPaintEvent& evt);
        void on_enter_window(wxMouseEvent& evt);
        void on_leave_window(wxMouseEvent& evt);
        void on_left_down(wxMouseEvent& evt);
        void on_left_up(wxMouseEvent& evt);
};
