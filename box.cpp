#include "box.h"

Box::Box() : len(10), width(10), height(10) {
    volume = len * width * height;
}

Box::Box(int value) : len(value), width(value), height(value) {
    volume = len * width * height;
}

Box::Box(int l, int w, int h) : len(l), width(w), height(h) {
    volume = len * width * height;
}

std::ostream& operator<<(std::ostream& os, const Box& b) {
    os << "len = " << b.len << ", width = " << b.width
       << ", height = " << b.height << ", volume = " << b.volume << '\n';
    return os;
}
