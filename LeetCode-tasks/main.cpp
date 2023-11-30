#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (int value : vec) {
        out << value << ' ';
    }
    return out;
}

// Plus One
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/
/******************************************************
* Input: digits = [1,2,3]
* Output: [1,2,4]
* Explanation: The array represents the integer 123.
* Incrementing by one gives 123 + 1 = 124.
* Thus, the result should be [1,2,4].
*******************************************************/

// runtime beats 100.00 % of cpp submissions
// memory usage beats 96.34 % of cpp submissions
vector<int> plusOne(vector<int>& digits) {
    if (digits.empty()) {
        return {};
    }
    bool is_overflow = true;
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
        digits[i] = ++digits[i] % 10;
        if (digits[i] != 0) {
            is_overflow = false;
            break;
        }
    }
    if (is_overflow) {
        digits[0] = 1;
        digits.push_back(0);
    }
    return digits;
}

void Tests() {
    {
        vector<int> digits{1,2,3};
        vector<int> expected_digits{1,2,4};
        assert(expected_digits == plusOne(digits));
    }{
        vector<int> digits{4,3,2,1};
        vector<int> expected_digits{4,3,2,2};
        assert(expected_digits == plusOne(digits));
    }{
        vector<int> digits{9};
        vector<int> expected_digits{1,0};
        assert(expected_digits == plusOne(digits));
    }{
        vector<int> digits{9,9,9};
        vector<int> expected_digits{1,0,0,0};
        assert(expected_digits == plusOne(digits));
    }{
        vector<int> digits{1};
        vector<int> expected_digits{2};
        assert(expected_digits == plusOne(digits));
    }{
        vector<int> digits;
        assert(plusOne(digits).empty());
    }
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    return 0;
}
