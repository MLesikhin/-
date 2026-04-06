#ifndef BOX_H
#define BOX_H

#include <iostream>

struct Box {
    int len;
    int width;
    int height;
    int volume;

    // Конструктор по умолчанию: все стороны = 10
    Box();

    // Конструктор с одним параметром: все стороны = value
    explicit Box(int value);

    // Конструктор с тремя параметрами: len, width, height
    Box(int l, int w, int h);

    // Дружественная функция для перегрузки оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Box& b);
};

#endif // BOX_H  
