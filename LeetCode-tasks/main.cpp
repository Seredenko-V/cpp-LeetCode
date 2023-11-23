#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique_pos = 0;
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size - 1; ++i) {
            while (nums[i] == nums[i + 1]) {
                ++i;
                if (i == size - 1) {
                    break;
                }
            }
            if (i == size - 1 || nums[i] > nums[i + 1]) {
                break;
            }
            for (int j = i; j < size; ++j) {
                nums[unique_pos + j - i] = nums[j];
            }
            i = unique_pos++;
        }
        nums.resize(++unique_pos); // в меньшую сторону за O(1)
        return unique_pos;
    }
};

int main() {

    return 0;
}
