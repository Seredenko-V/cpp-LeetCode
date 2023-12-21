#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Valid Anagram
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/
/******************************************************
* Даны две строки s и t, верните true, если t является анаграммой s, и false в противном случае.
*
* Анаграмма — это слово или фраза, образованная перестановкой букв другого слова или фразы,
* обычно с использованием всех исходных букв ровно один раз.
*******************************************************/

// Сложность: O(2*N)
// Runtime: 7 ms - runtime beats 73.21 % of cpp submissions.
// Memory Usage: 7.7  MB - memory usage beats 78.65 % of cpp submissions.
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    static constexpr uint16_t kSizeAlphabet = 26u;
    vector<int> num_symbols(kSizeAlphabet);
    for (char symbol : s) {
        ++num_symbols[symbol - 'a'];
    }
    for (char symbol : t) {
        if (--num_symbols[symbol - 'a'] < 0) {
            return false;
        }
    }
    return true;
}

void Tests() {
    assert(isAnagram("anagram"s, "nagaram"s));
    assert(!isAnagram("rat"s, "car"s));
    assert(isAnagram("a"s, "a"s));
    assert(!isAnagram("a"s, "b"s));
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    return 0;
}
