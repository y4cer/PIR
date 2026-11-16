#include "lwe.h"
#include <NTL/mat_lzz_p.h>
#include <NTL/vec_lzz_p.h>
#include <utility>

using namespace NTL;

namespace LWE {

#ifdef DEBUG
using std::cout;
using std::endl;
#endif

vec_zz_p LP::sample_short_vector(long n) {
    vec_zz_p res;
    res.SetLength(n);

    for (auto &e : res) {
        e = sample_short_value();
    }
    return res;
}

zz_p LP::sample_short_value() {
    zz_p res = to_zz_p(RandomBnd(2 * B + 1) - B);
    return res;
}

bool LP::round(zz_p m) {
    zz_pPush guard(context);

    long x = rep(m);
    if (x > q / 2) {
        x -= q;
    }

    const long limit = (q - 1) / 4;

    return x >= -limit && x <= limit ? 0 : 1;
}

LP::LP(long q, long n, long B) : q(q), n(n), B(B), context(q) {
    zz_pPush guard(context);
#ifdef DEBUG
    vec_zz_p s = sample_short_vector(n);
    vec_zz_p e = sample_short_vector(n);
    vec_zz_p r = random_vec_zz_p(n);

    cout << q << " " << n << " " << B << endl;
    cout << "s: " << s << endl;
    cout << "e: " << e << endl;
    cout << "r: " << r << endl;
#endif
}

key_pair LP::keygen() {
    zz_pPush guard(context);

    mat_zz_p A;
    A.SetDims(n, n);

    for (long i = 0; i < n; i++) {
        A[i] = random_vec_zz_p(n);
    }

    auto s = sample_short_vector(n);
    auto e = sample_short_vector(n);

    vec_zz_p b = A * s + e;

    return {
        .priv = {.s = std::move(s)},
        .pub =
            {
                .A = std::move(A),
                .b = std::move(b),
            },
    };
}

ciphertext LP::encrypt(const plaintext &pt, const public_key &pub) {

    zz_pPush guard(context);

    auto r = sample_short_vector(n);
    auto e1 = sample_short_vector(n);
    auto e2 = sample_short_value();

    auto u = transpose(pub.A) * r + e1;
    auto v = pub.b * r + e2 + (q / 2 + q % 2) * pt.m;

    return {.u = std::move(u), .v = v};
}

plaintext LP::decrypt(const ciphertext &ct, const private_key &priv) {
    zz_pPush guard(context);
    zz_p m = ct.v - priv.s * ct.u;

    return {round(m)};
}

} // namespace LWE
