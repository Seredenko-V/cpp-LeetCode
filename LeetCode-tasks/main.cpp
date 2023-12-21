#include <cassert>
#include <iostream>
#include <string>
#include <map>

using namespace std;

// First Unique Character in a String
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
/******************************************************
* Дана строка s, найдите в ней первый неповторяющийся символ и верните его индекс.
* Если он не существует, верните -1.
*******************************************************/

// Сложность: O(2*N)
// Runtime: 65 ms - runtime beats 5.10 % of cpp submissions.
// Memory Usage: 11.2  MB - memory usage beats 17.10 % of cpp submissions.
int firstUniqChar(string s) {
    map<char, pair<int, int>> elems;
    for (size_t i = 0; i < s.size(); ++i) {
        elems[s[i]].first = i;
        ++elems[s[i]].second;
    }
    int pos_first_unique = -1;
    for (const pair<const char, pair<int, int>>& elem : elems) {
        const pair<int, int>& stat = elem.second;
        if (stat.second == 1 && (stat.first < pos_first_unique || pos_first_unique == -1)) {
            pos_first_unique = stat.first;
        }
    }
    return pos_first_unique;
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
