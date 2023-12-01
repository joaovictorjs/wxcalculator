#pragma once 

#include <wx/font.h>

namespace Fonts {
    bool load_font();

    static wxFontInfo current = wxFontInfo(12).FaceName("Poppins");
}
