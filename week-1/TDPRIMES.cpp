#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

int main() {
    const int n = 1e8;
    int sieve_size = (n + 1) / 2; // Only consider odd numbers
    std::vector<bool> is_prime(sieve_size, true);
    is_prime[0] = false; // 1 is not a prime number
    std::vector<int> prime;

    clock_t start = clock();

    for (int i = 1; ((i * i * 2)+ (2 * i + 1)) <= n; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i * (i + 1); j < sieve_size; j += 2 * i + 1) {
                is_prime[j] = false;
            }
        }
    }

    prime.push_back(2); // Add 2, the only even prime number
    for (int i = 1; i < sieve_size; ++i) {
        if (is_prime[i]) {
            prime.push_back(2 * i + 1); // Convert index back to the actual number
        }
    }

    for (size_t i = 0; i < prime.size(); i += 100) {
        std::cout << prime[i] << std::endl;
    }

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << elapsed << " seconds" << std::endl;

    return 0;
}
