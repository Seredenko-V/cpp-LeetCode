#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (int value : vec) {
        out << value << ' ';
    }
    return out;
}

// Reverse String
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
/******************************************************
* Write a function that reverses a string. The input string is given as an array of characters s.

* You must do this by modifying the input array in-place with O(1) extra memory.
*******************************************************/

// Сложность: O(N / 2)
// Runtime: 11 ms - runtime beats 94.81 % of cpp submissions.
// Memory Usage: 23.5  MB - memory usage beats 95.72 % of cpp submissions.
void reverseString(vector<char>& s) {
    if (s.empty()) {
        return;
    }
    const uint32_t kSizeStr = static_cast<uint32_t>(s.size());
    for (uint32_t i = 0; i < kSizeStr / 2; ++i) {
        swap(s[i], s[kSizeStr - 1 - i]);
    }
}

void Tests() {
    {
        vector<char> str{'h','e','l','l','o'};
        vector<char> expected_str{'o','l','l','e','h'};
        reverseString(str);
        assert(expected_str == str);
    }{
        vector<char> str{'H','a','n','n','a','h'};
        vector<char> expected_str{'h','a','n','n','a','H'};
        reverseString(str);
        assert(expected_str == str);
    }{
        vector<char> str{'H'};
        vector<char> expected_str{'H'};
        reverseString(str);
        assert(expected_str == str);
    }{
        vector<char> str{'A','A','A','A'};
        vector<char> expected_str = str;
        reverseString(str);
        assert(expected_str == str);
    }{
        vector<char> str;
        reverseString(str);
        assert(str.empty());
    }
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    return 0;
}
