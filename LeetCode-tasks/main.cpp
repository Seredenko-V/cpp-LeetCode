#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
// решение на месте, без копирования вектора

uint32_t GetGCD(int first, int second) noexcept {
    if (first == 0 || second == 0) {
        return 1;
    }
    if (first < second) {
        swap(first, second);
    }
    while (first % second != 0) {
        first = first % second;
        swap(first, second);
    }
    return std::abs(second);
}

void rotate(vector<int>& nums, int k) {
    size_t size = nums.size();
    k = k % size;
    if (nums.empty() || k == 0) {
        return;
    }
    for (int start = 0; start < GetGCD(size, k); ++start) {
        int index = start;
        int prev = nums[start];
        while (true) {
            int new_index = (index + k) % size;
            if (new_index == start) {
                nums[new_index] = prev;
                break;
            }
            int current = nums[new_index];
            nums[new_index] = prev;
            index = new_index;
            prev = current;
        }
    }
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
    }{
        constexpr int k = 3;
        vector<int> nums{1,2,3,4,5,6};
        vector<int> expected{4,5,6,1,2,3};
        rotate(nums, k);
        assert(nums == expected);
    }{
        constexpr int k = 1;
        vector<int> nums{1,2,3};
        vector<int> expected{3,1,2};
        rotate(nums, k);
        assert(nums == expected);
    }{
        constexpr int k = 4;
        vector<int> nums{1,2,3,4,5,6};
        vector<int> expected{3,4,5,6,1,2};
        rotate(nums, k);
        assert(nums == expected);
    }
}

int main() {
    Test();
    return 0;
}
