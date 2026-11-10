#include "lwe.h"

namespace LWE {

int LP::f(int a) { return a + 1; }

LP::LP(long q, long m, long n, long B) {
    std::cout << q << m << n << B;
    std::cout << 123;
}

} // namespace LWE
