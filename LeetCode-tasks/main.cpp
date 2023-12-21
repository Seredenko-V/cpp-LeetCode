#include <cassert>
#include <iostream>
#include <string>
#include <map>

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
// Runtime: 14 ms - runtime beats 19.95 % of cpp submissions.
// Memory Usage: 7.8  MB - memory usage beats 44.04 % of cpp submissions.
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    map<char, uint32_t> letters_s, letters_t;
    for (size_t i = 0; i < s.size(); ++i) {
        ++letters_s[s[i]];
        ++letters_t[t[i]];
    }
    return letters_s == letters_t;
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
