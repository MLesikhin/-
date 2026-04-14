#include "fraction.h"
#include <cstdlib> // для std::abs

// Наибольший общий делитель
int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        // обработка ошибки: знаменатель не может быть 0
        den = 1;
        num = 0;
    } else {
        num = numerator;
        den = denominator;
        normalize();
    }
}

void Fraction::normalize() {
    if (den == 0) return;
    if (den < 0) {   // переносим знак в числитель
        num = -num;
        den = -den;
    }
    int g = gcd(num, den);
    num /= g;
    den /= g;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) { // перегружаем оператор вывода
    os << f.num << " / " << f.den;
    return os;
}

Fraction sum(const Fraction& fr1, const Fraction& fr2) {
    int new_num = fr1.num * fr2.den + fr2.num * fr1.den;
    int new_den = fr1.den * fr2.den;
    return Fraction(new_num, new_den);
}

Fraction sub(const Fraction& fr1, const Fraction& fr2) {
    int new_num = fr1.num * fr2.den - fr2.num * fr1.den;
    int new_den = fr1.den * fr2.den;
    return Fraction(new_num, new_den);
}

Fraction mul(const Fraction& fr1, const Fraction& fr2) {
    int new_num = fr1.num * fr2.num;
    int new_den = fr1.den * fr2.den;
    return Fraction(new_num, new_den);
}

Fraction div(const Fraction& fr1, const Fraction& fr2) {
    // деление на ноль не проверяется для простоты
    int new_num = fr1.num * fr2.den;
    int new_den = fr1.den * fr2.num;
    return Fraction(new_num, new_den);
}
