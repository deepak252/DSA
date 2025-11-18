#include <bits/stdc++.h>
using namespace std;

/*
    ============================
    Fermat's Little Theorem (FLT)
    ============================

    If p is a prime number and gcd(a, p) = 1, then:

        a^(p-1) ≡ 1 (mod p)

    This means:
        - When you raise any number 'a' (not divisible by p) 
          to the power (p-1) and take modulo p,
          the result is always 1.

    Equivalent reformulation:
        a^p ≡ a (mod p)
        (this holds for ALL integers a, even when p divides a)

    FLT is used for:
        - Modular arithmetic
        - Computing modular inverses:
              a^(-1) ≡ a^(p-2) (mod p)
        - Cryptography (RSA, Diffie-Hellman)

    In this program:
        - We verify FLT for several primes p
        - For each prime we test all values of a from 1..1000
          except those divisible by p
*/

long long powMod(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;

    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


/**
 * a^(p-1) ≡ 1 (mod p)
 */

// void flt1() {
//     vector<long long> primes = {2, 3, 5, 7, 11, 13, 17};

//     for (auto p : primes) {
//         for (long long a = 1; a <= 1000; a++) {
//             if (a % p != 0) { // gcd(a,p)=1
//                 long long res = powMod(a, p - 1, p);
//                 cout<<res<<" ";
//                 // if (res != 1) {
//                 //     cout << "FLT FAILED for a=" << a
//                 //          << " p=" << p
//                 //          << " got=" << res << "\n";
//                 //     return;
//                 // }
//             }
//         }
//     }

//     cout << "All FLT tests passed.\n";
// }

/**
 * Test Fermat's Little Theorem form:
 *      a^p ≡ a (mod p)
 *
 * This form works for ALL integers a (even when a is divisible by p).
 * Useful for primality tests and theoretical verification.
 */
void flt2() {
    vector<long long> primes = { (long long)1e9 + 7 };

    for (auto p : primes) {
        for (long long a = 1; a <= 1000; a++) {

            long long res = powMod(a, p, p);  // compute a^p mod p

            // For the identity a^p ≡ a (mod p), result must equal a % p
            if (res != (a % p)) {
                cout << "FLT FAILED for a=" << a
                     << " p=" << p
                     << " got=" << res
                     << " expected=" << (a % p)
                     << "\n";
                return;
            }
        }
    }

    cout << "All FLT tests passed.\n";
}

int main() {
    flt2();
    return 0;
}
