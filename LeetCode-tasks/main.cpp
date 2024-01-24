#include <cassert>
#include <iostream>
#include <cstdint>

using namespace std;

// Определить количество возможных перестановок
// https://new.contest.yandex.ru/48556/problem?id=215/2023_04_06/xAmHQ1PYv2

uint64_t Factorial(uint8_t n) {
    uint64_t fact = 1u;
    for (uint8_t i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

void Tests() {
    assert(Factorial(0) == 1);
    assert(Factorial(1) == 1);
    assert(Factorial(3) == 6);
    assert(Factorial(5) == 120);
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    int n = 0;
    cin >> n;
    cout << Factorial(n);
    return 0;
}
