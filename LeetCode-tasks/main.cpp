#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (int value : vec) {
        out << value << ' ';
    }
    return out;
}

// Two Sum
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
/******************************************************
* Given an array of integers nums and an integer target, return
* indices of the two numbers such that they add up to target.
*
* You may assume that each input would have exactly one solution,
* and you may not use the same element twice.
*
* You can return the answer in any order.
*******************************************************/

// Сложность: O(N^2)
// Runtime: 276 ms - runtime beats 33.98 % of cpp submissions.
// Memory Usage: 10.4 MB - memory usage beats 95.56 % of cpp submissions.
vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.size() < 2) {
        return {};
    }
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {};
}

void Tests() {
    {
        vector<int> nums{2,7,11,15};
        constexpr int kTarger = 9;
        vector<int> expected_nums{0,1};
        assert(expected_nums == twoSum(nums, kTarger));
    }{
        vector<int> nums{3,2,4};
        constexpr int kTarger = 6;
        vector<int> expected_nums{1,2};
        assert(expected_nums == twoSum(nums, kTarger));
    }{
        vector<int> nums{3,3};
        constexpr int kTarger = 6;
        vector<int> expected_nums{0,1};
        assert(expected_nums == twoSum(nums, kTarger));
    }{
        vector<int> nums{5};
        constexpr int kTarger = 6;
        assert(twoSum(nums, kTarger).empty());
    }{
        vector<int> nums{3,2,4,-5};
        constexpr int kTarger = -3;
        vector<int> expected_nums{1,3};
        assert(expected_nums == twoSum(nums, kTarger));
    }{
        vector<int> nums{-23,-4,-9,-7,0};
        constexpr int kTarger = -30;
        vector<int> expected_nums{0,3};
        assert(expected_nums == twoSum(nums, kTarger));
    }{
        vector<int> nums{-23,-4,-9,-7,0};
        constexpr int kTarger = -4;
        vector<int> expected_nums{1,4};
        assert(expected_nums == twoSum(nums, kTarger));
    }
    cerr << "Tests has passed\n"s;
}

int main() {
    Tests();
    return 0;
}
