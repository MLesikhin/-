#include "box.h"
#include <fstream>

void writeToFile(const char* fileName, const struct Box& box) {
    std::ofstream out(fileName, std::ios::binary);
    if (!out.is_open()) return;
    
    out.write(reinterpret_cast<const char*>(&box), sizeof(Box));
    out.close();
}

void readFromFile(const char* fileName, struct Box& box) {
    if (&box == nullptr) return;
    
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) return;
    
    in.read(reinterpret_cast<char*>(&box), sizeof(Box));
    in.close();
} 
