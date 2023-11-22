#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
// решение НЕ на месте
void rotate(vector<int>& nums, int k) {
    if (nums.empty() || k == 0) {
        return;
    }
    k = k % nums.size();
    vector<int> result(nums.size());
    for (int i = nums.size() - k; i < nums.size(); ++i) {
        result[i - (nums.size() - k)] = nums[i];
    }
    for (int i = 0; i < nums.size() - k; ++i) {
        result[i + k] = nums[i];
    }
    nums = result;
}

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (int value : vec) {
        out << value << ' ';
    }
    return out;
}

void Test() {
    {
        constexpr int k = 3;
        vector<int> nums{1,2,3,4,5,6,7};
        vector<int> expected{5,6,7,1,2,3,4};
        rotate(nums, k);
        assert(nums == expected);
    }{
        vector<int> nums{1,2,3,4,5,6,7};
        vector<int> expected = nums;
        int k = nums.size();
        rotate(nums, k);
        assert(nums == expected);
    }{
        constexpr int k = 2;
        vector<int> nums{-1,-100,3,99};
        vector<int> expected{3,99,-1,-100};
        rotate(nums, k);
        assert(nums == expected);
    }{
        constexpr int k = 0;
        vector<int> nums{25,15,8,23,0};
        vector<int> expected = nums;
        rotate(nums, k);
        assert(nums == expected);
    }{
        constexpr int k = 2;
        vector<int> nums{-1};
        vector<int> expected = nums;
        rotate(nums, k);
        assert(nums == expected);
    }
}

int main() {
    Test();
    return 0;
}
