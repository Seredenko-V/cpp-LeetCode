#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
// с использованием std::sort
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (int value : vec) {
        out << value << ' ';
    }
    return out;
}

void Test() {
    {
        vector<int> nums{1,2,3,4,5,6,7};
        assert(!containsDuplicate(nums));
    }{
        vector<int> nums{-1,-100,3,99};
        assert(!containsDuplicate(nums));
    }{
        vector<int> nums{25,15,8,23,0,8};
        assert(containsDuplicate(nums));
    }{
        vector<int> nums{-1};
        assert(!containsDuplicate(nums));
    }{
        vector<int> nums{1,1,1,1,1,1};
        assert(containsDuplicate(nums));
    }
}

int main() {
    Test();
    return 0;
}
