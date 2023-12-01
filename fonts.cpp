#include "fonts.h"

namespace Fonts {
    bool load_font() {
        return wxFont::AddPrivateFont("space_grotesk.ttf");
    }
}
