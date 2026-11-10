#include "lwe/lwe.h"

#include <NTL/ZZ.h>
#include <iostream>

using namespace std;

int main() {
    auto lwe = LWE ::LP(1, 2, 3, 4);
    cout << lwe.f(5);

    return 0;
}
