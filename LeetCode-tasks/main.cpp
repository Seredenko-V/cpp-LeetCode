#include <iostream>
#include <cassert>
#include <cstdint>

using namespace std;

// Огромное число Фибоначчи. Решение 1: Период Пизано
// https://new.contest.yandex.ru/47496/problem?id=215/2023_03_10/AH1EGu1ioL

// Даны целые числа n и m, необходимо найти остаток от деления n-го числа Фибоначчи на m.
// 1 <= n <= 1e14, 2 <= m <= 1e3.

// Период Пизано необходим, чтобы уменьшить индекс искомого числа Фибоначчи
size_t DetermPizanoPeriod(int m) {
    if (m < 2) {
        return 0;
    }
    size_t current = 0;
    size_t next = 1;
    size_t period = 0;
    while (true) {
        size_t old_next = next;
        next = (current + next) % m;
        current = old_next;
        ++period;
        if (current == 0 && next == 1) {
            break;
        }
    }
    return period;
}

size_t GetFibMod(size_t n, uint16_t modul) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    size_t F0 = 0;
    size_t F1 = 1;
    size_t Fn = 0;
    for (size_t i = 2; i <= n; ++i) {
        Fn = (F0 + F1) % modul;
        F0 = F1;
        F1 = Fn;
    }
    return Fn;
}

size_t DetermFibRemainderOfDiv(size_t n, uint16_t m) {
    return GetFibMod(n % DetermPizanoPeriod(m), m);
}

namespace tests {
    void TestDetermPizanoPeriod() {
        assert(DetermPizanoPeriod(2) == 3u);
        assert(DetermPizanoPeriod(3) == 8u);
        assert(DetermPizanoPeriod(4) == 6u);
        assert(DetermPizanoPeriod(5) == 20u);
        assert(DetermPizanoPeriod(6) == 24u);
        cerr << "TestDetermPizanoPeriod passed"s << endl;
    }

    void TestGetFibMod() {
        assert(GetFibMod(0u, 2u) == 0u); // всегда 0
        assert(GetFibMod(1u, 42u) == 1u); // всегда 1
        assert(GetFibMod(11u, 2u) == 1u);
        assert(GetFibMod(11u, 3u) == 2u);
        assert(GetFibMod(11u, 5u) == 4u);
        cerr << "TestGetFibMod passed"s << endl;
    }

    void TestDetermFibRemainderOfDiv() {
        assert(DetermFibRemainderOfDiv(1u, 239u) == 1u);
        assert(DetermFibRemainderOfDiv(115u, 1000u) == 885u);
        assert(DetermFibRemainderOfDiv(2'816'213'588u, 239u) == 151u);
        cerr << "TestDetermFibRemainderOfDiv passed"s << endl;
    }

    void RunAllTests() {
        TestDetermPizanoPeriod();
        TestGetFibMod();
        TestDetermFibRemainderOfDiv();
        cerr << ">>> All tests passed <<<"s << endl;
    }
} // namespace tests


int main() {
    tests::RunAllTests();
    size_t n = 0;
    uint16_t m = 0;
    cin >> n >> m;
    cout << DetermFibRemainderOfDiv(n, m) << endl;
    return 0;
}
