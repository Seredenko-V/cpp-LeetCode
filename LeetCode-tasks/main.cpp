#include <cassert>
#include <iostream>
#include <string>
#include <algorithm>

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
// Runtime: 16 ms - runtime beats 9.26 % of cpp submissions.
// Memory Usage: 7.7  MB - memory usage beats 78.65 % of cpp submissions.
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
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
