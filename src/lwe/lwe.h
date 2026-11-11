#include <NTL/ZZ_p.h>
#include <NTL/mat_lzz_p.h>

using namespace NTL;

namespace LWE {

class LP {
  public:
    long q; // modulus
    long m;
    long n;
    long B;

    LP(long q, long m, long n, long B);

    int f(int a);
};

} // namespace LWE
