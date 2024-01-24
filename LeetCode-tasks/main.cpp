#include <cassert>
#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <string>

using namespace std;

// Определить количество сочетаний с повторениями
// https://new.contest.yandex.ru/48556/problem?id=215/2023_04_06/WoW7IdbfFr

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

uint64_t NumCombinationsWithRepeats(int n, int k) {
    if (n > 4 || k > 4) {
        return 0;
    }
    if (n < 1 || k < 1) {
        return 0;
    }
    return NumCombinations(n + k - 1, k);
}

void Tests() {
    assert(NumCombinationsWithRepeats(4, 4) == 35);
    assert(NumCombinationsWithRepeats(4, 3) == 20);
    assert(NumCombinationsWithRepeats(2, 2) == 3);
    assert(NumCombinationsWithRepeats(1, 1) == 1);
    assert(NumCombinationsWithRepeats(2, 4) == 5);
    cerr << "Tests passed\n"s;
}

int main() {
    Tests();
    int n = 0, k = 0;
    cin >> n >> k;
    cout << NumCombinationsWithRepeats(n, k);
    return 0;
}
