#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// First Unique Character in a String
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
/******************************************************
* Дана строка s, найдите в ней первый неповторяющийся символ и верните его индекс.
* Если он не существует, верните -1.
*******************************************************/

// Сложность: O(2*N)
// Runtime: 26 ms - runtime beats 72.68 % of cpp submissions.
// Memory Usage: 11  MB - memory usage beats 83.11 % of cpp submissions.
int firstUniqChar(string s) {
    constexpr uint16_t kSizeAlphabet = 26u;
    vector<uint16_t> nums_symbols(kSizeAlphabet, 0);
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
