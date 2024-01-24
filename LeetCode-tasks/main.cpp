#include <cassert>
#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <string>

using namespace std;

// Определить количество сочетаний
// https://new.contest.yandex.ru/48556/problem?id=215/2023_04_06/yrA534pVxW

uint64_t Factorial(int n) {
    uint64_t fact = 1u;
    for (uint8_t i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

uint64_t NumCombinations(int n, int k) {
    if (n < k) {
        return 0;
    }
    if (n > 7 || k > 7) {
        return 0;
    }
    if (n < 1 || k < 1) {
        return 0;
    }
    return Factorial(n) / (Factorial(k) * Factorial(n - k));
}

void Tests() {
    assert(NumCombinations(3, 2) == 3);
    assert(NumCombinations(7, 5) == 21);
    assert(NumCombinations(1, 1) == 1);
    cerr << "Tests passed\n"s;
}

int main() {
    Tests();
    int n = 0, k = 0;
    cin >> n >> k;
    cout << NumCombinations(n, k);
    return 0;
}
