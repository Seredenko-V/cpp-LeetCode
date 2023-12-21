#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// First Unique Character in a String
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
/******************************************************
* Дана строка s, найдите в ней первый неповторяющийся символ и верните его индекс.
* Если он не существует, верните -1.
*******************************************************/

// Сложность: O(2*N)
// Runtime: 38 ms - runtime beats 30.97 % of cpp submissions.
// Memory Usage: 11.1  MB - memory usage beats 34.28 % of cpp submissions.
int firstUniqChar(string s) {
    unordered_map<char, uint16_t> nums_symbols;
    for (size_t i = 0; i < s.size(); ++i) {
        ++nums_symbols[s[i] - 'a'];
    }
    for (size_t i = 0; i < s.size(); ++i) {
        if (nums_symbols[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

void Tests() {
    assert(firstUniqChar("leetcode"s) == 0);
    assert(firstUniqChar("loveleetcode"s) == 2);
    assert(firstUniqChar("aabb"s) == -1);
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    return 0;
}
