#include "v1.h"
#include "mc/deps/core/math/Color.h"

using namespace bm::format::v1;

JSONColor::JSONColor(mce::Color c) {
    r = c.r;
    g = c.g;
    b = c.b;
    a = c.a;
}