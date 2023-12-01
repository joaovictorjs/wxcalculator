#include "fonts.h"

namespace Fonts {
    bool load_font() {
        return wxFont::AddPrivateFont("poppins_regular.ttf");
    }
}
