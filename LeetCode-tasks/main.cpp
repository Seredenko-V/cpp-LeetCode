#include <cassert>
#include <iostream>
#include <string>
#include <set>

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
// Runtime: 61 ms - runtime beats 0 % of cpp submissions.
// Memory Usage: 24.2  MB - memory usage beats 0 % of cpp submissions.
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    multiset<char> letters_s, letters_t;
    for (size_t i = 0; i < s.size(); ++i) {
        letters_s.insert(s[i]);
        letters_t.insert(t[i]);
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
