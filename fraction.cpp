#include "fraction.h"

// Конструктор по умолчанию (ДЗ SW_4 + РК_1)
Fraction::Fraction() : _numerator(0), _denominator(1) {}

// Конструктор с параметрами (ДЗ SW_4 + РК_1)
Fraction::Fraction(int numerator, int denominator) 
    : _numerator(numerator), _denominator(denominator) {}

// Алгоритм Евклида для нахождения НОД
int gcd(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Сокращение дроби (ДЗ SW_4)
int fracReduction(Fraction& frac) {
    if (frac._denominator == 0) {
        return -1;
    }
    
    int divisor = gcd(frac._numerator, frac._denominator);
    frac._numerator /= divisor;
    frac._denominator /= divisor;
    
    // Обеспечим, чтобы знаменатель был положительным
    if (frac._denominator < 0) {
        frac._numerator = -frac._numerator;
        frac._denominator = -frac._denominator;
    }
    
    return 0;
}

// Сложение дробей (РК_1)
Fraction sum(const Fraction& fr1, const Fraction& fr2) {
    Fraction result;
    result._numerator = fr1._numerator * fr2._denominator + fr2._numerator * fr1._denominator;
    result._denominator = fr1._denominator * fr2._denominator;
    fracReduction(result);
    return result;
}

// Вычитание дробей (РК_1)
Fraction sub(const Fraction& fr1, const Fraction& fr2) {
    Fraction result;
    result._numerator = fr1._numerator * fr2._denominator - fr2._numerator * fr1._denominator;
    result._denominator = fr1._denominator * fr2._denominator;
    fracReduction(result);
    return result;
}

// Умножение дробей (РК_1)
Fraction mul(const Fraction& fr1, const Fraction& fr2) {
    Fraction result;
    result._numerator = fr1._numerator * fr2._numerator;
    result._denominator = fr1._denominator * fr2._denominator;
    fracReduction(result);
    return result;
}

// Деление дробей (РК_1)
Fraction div(const Fraction& fr1, const Fraction& fr2) {
    Fraction result;
    result._numerator = fr1._numerator * fr2._denominator;
    result._denominator = fr1._denominator * fr2._numerator;
    fracReduction(result);
    return result;
}

// Переопределение оператора вывода << для Fraction
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac._numerator << " / " << frac._denominator;
    return os;
}
