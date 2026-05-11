#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct Fraction {
    int _numerator;   // числитель
    int _denominator; // знаменатель

    // Конструктор по умолчанию (ДЗ SW_4 + РК_1)
    Fraction();
    
    // Конструктор с параметрами (ДЗ SW_4 + РК_1)
    Fraction(int numerator, int denominator);
};

// Вспомогательная функция: Алгоритм Евклида для нахождения НОД
int gcd(int a, int b);

// Сокращение дроби (ДЗ SW_4)
int fracReduction(Fraction& frac);

// Сложение дробей (РК_1)
Fraction sum(const Fraction& fr1, const Fraction& fr2);

// Вычитание дробей (РК_1)
Fraction sub(const Fraction& fr1, const Fraction& fr2);

// Умножение дробей (РК_1)
Fraction mul(const Fraction& fr1, const Fraction& fr2);

// Деление дробей (РК_1)
Fraction div(const Fraction& fr1, const Fraction& fr2);

// Переопределение оператора вывода << для Fraction
std::ostream& operator<<(std::ostream& os, const Fraction& frac);

#endif // FRACTION_H
