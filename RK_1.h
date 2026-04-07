#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct Fraction {
    int num;   // числитель
    int den;   // знаменатель (всегда > 0)

    // Конструктор по умолчанию: 0/1
    Fraction();

    // Конструктор с параметрами
    Fraction(int numerator, int denominator);

    // Приведение дроби к несократимому виду
    void normalize();

    // Дружественная функция для вывода
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};

// Арифметические операции
Fraction sum(const Fraction& fr1, const Fraction& fr2);
Fraction sub(const Fraction& fr1, const Fraction& fr2);
Fraction mul(const Fraction& fr1, const Fraction& fr2);
Fraction div(const Fraction& fr1, const Fraction& fr2);

#endif // FRACTION_H
