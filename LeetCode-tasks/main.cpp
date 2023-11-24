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

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/

// решение с помощью std::sort
int singleNumber(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums.front();
    }
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i += 2) {
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }
    }
    return -1;
}

void Test() {
    {
        vector<int> nums{2,2,1};
        assert(singleNumber(nums) == 1);
    }{
        vector<int> nums{4,1,2,1,2};
        assert(singleNumber(nums) == 4);
    }{
        vector<int> nums{1};
        assert(singleNumber(nums) == 1);
    }{
        vector<int> nums{2,6,7,3,2,4,7,6,4};
        assert(singleNumber(nums) == 3);
    }
}

int main() {
    Test();
    return 0;
}
