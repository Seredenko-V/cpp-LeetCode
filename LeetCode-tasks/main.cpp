#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Valid Palindrome
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/
/******************************************************
* Фраза является палиндромом, если после преобразования всех заглавных букв в строчные и
* удаления всех небуквенно-цифровых символов она читается одинаково и вперед, и назад.
* Буквенно-цифровые символы включают буквы и цифры.

* Учитывая строку s, верните true, если это палиндром, или false в противном случае.
*******************************************************/

string GetPreparedStr(const string& s) {
    string ready_str(s.size(), '#');
    size_t count_symbols = 0;
    for (char symbol : s) {
        if (isalnum(symbol)) {
            ready_str[count_symbols++] = tolower(symbol);
        }
    }
    ready_str.resize(count_symbols);
    return ready_str;
}

// Сложность: O(2*N)
// Runtime: 4 ms - runtime beats 80.37 % of cpp submissions.
// Memory Usage: 7.7  MB - memory usage beats 47.87 % of cpp submissions.
bool isPalindrome(string s) {
    if (s.size() < 2) {
        return true;
    }
    string ready_str = GetPreparedStr(s);
    size_t half = ready_str.size() / 2;
    for (size_t i = 0; i < half; ++i) {
        if (ready_str[i] != ready_str[ready_str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

void Tests() {
    assert(isPalindrome("A man, a plan, a canal: Panama"s));
    assert(!isPalindrome("race a car"s));
    assert(isPalindrome(" "s));
    assert(isPalindrome("12321"s));
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    return 0;
}
