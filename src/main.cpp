#include "lwe/lwe.h"

#include <NTL/ZZ.h>
#include <iostream>

using namespace std;

int main() {
    NTL::ZZ factorial(1);
    for (long i = 2; i <= 50; ++i) {
        factorial *= i;
    }
    cout << "50! = " << factorial << '\n';
    NTL::PrimeSeq seq;
    string bb;

    for (int i = 0; i < 1000; i++) {
        cout << seq.next() << endl;
    }

    auto lwe = LWE::Lwe();
    cout << lwe.f(5);

    return 0;
}
