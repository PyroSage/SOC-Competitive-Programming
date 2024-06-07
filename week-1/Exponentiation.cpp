// def power(a, b, p):
//     ans = 1
//     while b > 0:
//         if b & 1:
//             ans = ((ans % p) * (a % p)) % p 
//         a = ((a % p) * (a % p)) % p 
//         b >>= 1
//     return ans % p
 
 
// p = int(1e9 + 7)
// i = int(input())
// for _ in range(i):
//     a, b = map(int, input().split())
//     print(power(a, b, p))
    
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int power(long long a, long long b, int p) {
    long long ans = 1;
    a %= p;
    
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return ans % p;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << power(a, b, MOD) << endl;
    }
    
    return 0;
}
