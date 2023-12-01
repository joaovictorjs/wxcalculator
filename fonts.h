#pragma once 

#include <wx/font.h>

namespace Fonts {
    bool load_font();

    static wxFontInfo current = wxFontInfo(20).FaceName("Space Grotesk");
}
