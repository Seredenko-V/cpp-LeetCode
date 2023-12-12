#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

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
// Runtime: 0 ms - runtime beats 100.00 % of cpp submissions.
// Memory Usage: 6.7  MB - memory usage beats ??? % of cpp submissions.
int reverse(int x) {
    if (x <= numeric_limits<int>::min() || x > numeric_limits<int>::max()) {
        return 0;
    }
    string str = to_string(x);
    if (x < 0) {
        str.push_back('-');
    }
    std::reverse(str.begin(), str.end());
    int result = 0;
    try {
        result = stoi(str);
    } catch (const out_of_range& /*exception*/) {
        return 0;
    }
    return result;
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
