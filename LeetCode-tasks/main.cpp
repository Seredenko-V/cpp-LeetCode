#include <iostream>
#include <cassert>
#include <cstdint>

using namespace std;

// Последняя цифра числа Фибоначчи.
// https://new.contest.yandex.ru/47496/problem?id=215/2023_03_10/QRFPRBlJWb

// Дано число n, необходимо найти последнюю цифру n-го числа Фибоначчи.
// 0 <= n <= 1e6

uint16_t GetLastDigitFib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    uint16_t F0 = 0;
    uint16_t F1 = 1;
    uint16_t Fn = 0;
    for (int i = 2; i <= n; ++i) {
        Fn = (F0 + F1) % 10;
        F0 = F1;
        F1 = Fn;
    }
    return Fn;
}

namespace tests {
    void TestGetLastDigitFib() {
        assert(GetLastDigitFib(0) == 0);
        assert(GetLastDigitFib(1) == 1u);
        assert(GetLastDigitFib(3) == 2u);
        assert(GetLastDigitFib(139) == 1u);
        assert(GetLastDigitFib(91239) == 6u);
        cerr << "TestGetLastDigitFib passed"s << endl;
    }

} // namespace tests


int main() {
    tests::TestGetLastDigitFib();
    int n = 0;
    cin >> n;
    cout << GetLastDigitFib(n) << endl;
    return 0;
}
