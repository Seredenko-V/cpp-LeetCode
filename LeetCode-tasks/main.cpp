#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Reverse Integer
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
/******************************************************
* Нужно развернуть цифры числа, которое записано в виде строки.
* Если изменение числа приводит к выходу значения за пределы
* диапазона 32-битных целых чисел со знаком [-2^31, 2^31 - 1],
* нужно вернуть 0.
*******************************************************/

// Сложность: O(N)
// Runtime: 5 ms - runtime beats 13.72 % of cpp submissions.
// Memory Usage: 6.5  MB - memory usage beats ??? % of cpp submissions.
int reverse(int x) {
    if (x <= numeric_limits<int>::min() || x > numeric_limits<int>::max()) {
        return 0;
    }
    int64_t result = 0;
    int num_digits = 0;
    for (int i = 1; num_digits != 9; ++i) {
        const int kCurrentDigit = pow(10, i);
        if (x % kCurrentDigit != x) {
            ++num_digits;
        } else {
            break;
        }
    }
    if (x < 0) {
        for (int i = 1; i <= num_digits + 1; ++i) {
            const int64_t kCurrentDigit = pow(10, i);
            int64_t tmp_value = x % kCurrentDigit;
            tmp_value /= pow(10, i - 1);
            tmp_value *= pow(10, num_digits - i + 1);
            result -= tmp_value;
        }
    } else {
        for (int i = 1; i <= num_digits + 1; ++i) {
            const int64_t kCurrentDigit = pow(10, i);
            int64_t tmp_value = x % kCurrentDigit;
            tmp_value /= pow(10, i - 1);
            tmp_value *= pow(10, num_digits - i + 1);
            result += tmp_value;
        }
    }
    if (x < 0) {
        result = -result;
    }
    // переполнение
    if (result > numeric_limits<int>::max() || result < numeric_limits<int>::min()) {
        return 0;
    }
    return static_cast<int>(result);
}

void Tests() {
    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);
    assert(reverse(120) == 21);
    assert(reverse(132000) == 231);
    assert(reverse(numeric_limits<int>::min()) == 0);
    assert(reverse(1'534'236'469) == 0);
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    return 0;
}
