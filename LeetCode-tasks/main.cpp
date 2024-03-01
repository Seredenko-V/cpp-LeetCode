#include <iostream>
#include <cassert>

using namespace std;

// Числа Фибоначчи.
// https://new.contest.yandex.ru/42734/problem?id=6789665/2023_04_06/WwderYQo8t

// Дано целое число n, необходимо вычислить n-е число Фибоначчи.
// F0 = 0, F1 = 1, Fn = F(n-1) + F(n-2), n >= 2

size_t GetFib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    size_t F0 = 0;
    size_t F1 = 1;
    size_t Fn = 0;
    for (int i = 2; i <= n; ++i) {
        Fn = F0 + F1;
        F0 = F1;
        F1 = Fn;
    }
    return Fn;
}

namespace tests {
    void Test() {
        assert(GetFib(0) == 0);
        assert(GetFib(1) == 1u);
        assert(GetFib(10) == 55u);
        assert(GetFib(45) == 1'134'903'170u);
        cerr << "Test passed"s << endl;
    }

} // namespace tests


int main() {
    tests::Test();
    int n = 0;
    cin >> n;
    cout << GetFib(n) << endl;
    return 0;
}
