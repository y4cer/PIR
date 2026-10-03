#include <NTL/ZZ.h>
#include <iostream>

int main()
{
    // ZZ хранит целые числа произвольной длины.
    NTL::ZZ factorial{1};
    for (long i = 2; i <= 50; ++i) {
        factorial *= i;
    }
    std::cout << "50! = " << factorial << '\n';

    // Большие константы задаём строками, чтобы избежать переполнения.
    const NTL::ZZ a = NTL::to_ZZ("12345678901234567890");
    const NTL::ZZ b = NTL::to_ZZ("9876543210");
    std::cout << "gcd(" << a << ", " << b << ") = "
              << NTL::GCD(a, b) << '\n';

    const NTL::ZZ base{2};
    const NTL::ZZ exponent{100};
    const NTL::ZZ modulus{17};
    std::cout << "2^100 mod 17 = "
              << a * a * a * a * a * a * a * a * a << '\n';

    return 0;
}
