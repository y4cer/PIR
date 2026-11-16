#include "lwe/lwe.h"

#include <NTL/ZZ.h>
#include <NTL/lzz_p.h>
#include <iostream>

using namespace std;

#define DEBUG

int main() {
    long q = 297, n = 20, B = 2;
    auto lwe = LWE ::LP(q, n, B);

    auto key_pair = lwe.keygen();

    NTL::zz_pPush guard(q);

    LWE::plaintext pt = {.m = false};

    auto ct = lwe.encrypt(pt, key_pair.pub);
    auto pt_ = lwe.decrypt(ct, key_pair.priv);

    cout << "pt.m: " << pt.m << endl;
    cout << "pt_.m: " << pt_.m << endl;

    return 0;
}
