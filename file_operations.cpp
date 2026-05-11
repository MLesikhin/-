#include "file_operations.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

void fillFile(const char* fileName, int min, int max, char delimeter, int cols, int countElements) {
    std::ofstream file(fileName);
    
    if (!file.is_open()) return;
    
    for (int i = 0; i < countElements; i++) {
        int randomNum = min + rand() % (max - min + 1);
        file << randomNum;
        
        // После последнего элемента строки не ставим разделитель
        if ((i + 1) % cols != 0 && i != countElements - 1) {
            file << delimeter;
        }
        
        // Переход на новую строку после заполнения cols столбцов
        if ((i + 1) % cols == 0 && i != countElements - 1) {
            file << '\n';
        }
    }
    
    file.close();
}
