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

// Move Zeroes
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
/******************************************************
* Given an integer array nums, move all 0's to the end of it while maintaining the relative
* order of the non-zero elements.
* Note that you must do this in-place without making a copy of the array.
*******************************************************/

// Runtime: 1698 ms - very bad
// Memory Usage: 19.7 MB - memory usage beats 36.65 % of cpp submissions.
void moveZeroes(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        for (size_t j = 0; j < nums.size() - i - 1; ++j) {
            if (nums[j] == 0 && nums[j] != nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void Tests() {
    {
        vector<int> nums{0,1,0,3,12};
        vector<int> expected_nums{1,3,12,0,0};
        moveZeroes(nums);
        assert(expected_nums == nums);
    }{
        vector<int> nums{0,0,0,1,0};
        vector<int> expected_nums{1,0,0,0,0};
        moveZeroes(nums);
        assert(expected_nums == nums);
    }{
        vector<int> nums{0};
        vector<int> expected_nums{0};
        moveZeroes(nums);
        assert(expected_nums == nums);
    }{
        vector<int> nums;
        moveZeroes(nums);
        assert(nums.empty());
    }{
        vector<int> nums{7,1,8,3,12};
        vector<int> expected_nums = nums;
        moveZeroes(nums);
        assert(expected_nums == nums);
    }
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    return 0;
}
