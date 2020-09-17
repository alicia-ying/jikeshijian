#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > num_with_pos;
        vector<int> results;
        int p_head, p_tail, sum;
        for (int i = 0; i < nums.size(); i += 1) {
            num_with_pos.push_back(pair<int, int>(nums[i], i));
        }
        sort(num_with_pos.begin(), num_with_pos.end());
        p_head = 0; p_tail = num_with_pos.size() - 1;
        while (p_head < p_tail) {
            sum = num_with_pos[p_head].first + num_with_pos[p_tail].first;
            if (sum == target) {
                results.push_back(num_with_pos[p_head].second);
                results.push_back(num_with_pos[p_tail].second);
                break;
            } else if (sum > target) {
                p_tail -= 1;
            } else {
                p_head += 1;
            }
        }
        return results;
    }
};

int main() {
    int a[10] = {2, 7, 11, 15};
    vector<int> n(a, a + 4);
    Solution s;
    s.twoSum(n, 9);
}
