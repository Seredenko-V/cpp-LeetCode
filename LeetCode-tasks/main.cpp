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

// Runtime: 20 ms - runtime beats 43.88 % of cpp submissions
// Memory Usage: 19.5 MB - memory usage beats 65.31 % of cpp submissions.
void moveZeroes(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }
    uint16_t id_no_zero = 0u; // т.к. 1 <= nums.length <= 10'000
    // перестановка ненулевых значений в начало массива
    for (uint16_t i = 0; i < static_cast<uint16_t>(nums.size()); ++i) {
        if (nums[i] != 0) {
            nums[id_no_zero++] = nums[i];
        }
    }
    // дописывание нулей справа
    for (uint16_t i = id_no_zero; i < static_cast<uint16_t>(nums.size()); ++i) {
        nums[i] = 0;
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
        vector<int> nums{2,0,0,0,0};
        vector<int> expected_nums = nums;;
        moveZeroes(nums);
        assert(expected_nums == nums);
    }{
        vector<int> nums{0};
        vector<int> expected_nums{0};
        moveZeroes(nums);
        assert(expected_nums == nums);
    }{
        vector<int> nums{0,0,0,0,0,0,0,0,0};
        vector<int> expected_nums = nums;
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
