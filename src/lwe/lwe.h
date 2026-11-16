#pragma once

#include <NTL/ZZ_p.h>
#include <NTL/mat_lzz_p.h>
#include <NTL/vec_lzz_p.h>

namespace LWE {

struct public_key {
    NTL::mat_zz_p A;
    NTL::vec_zz_p b;
};

struct private_key {
    NTL::vec_zz_p s;
};

struct key_pair {
    private_key priv;
    public_key pub;
};

struct ciphertext {
    NTL::vec_zz_p u;
    NTL::zz_p v;
};

struct plaintext {
    bool m;
};

class LP {
  public:
    LP(long q, long n, long B);

    key_pair keygen();

    ciphertext encrypt(const plaintext &pt, const public_key &pub);

    plaintext decrypt(const ciphertext &ct, const private_key &priv);

  private:
    long q; // modulus
    long n;
    long B;

    NTL::zz_pContext context;
    NTL::vec_zz_p sample_short_vector(long n);
    NTL::zz_p sample_short_value();
    bool round(NTL::zz_p m);
};

} // namespace LWE
