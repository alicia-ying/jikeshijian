#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool comp(pair<int, int> x, pair<int, int> y) {
    return x.first == y.first ? x.second < y.second : x.first < y.first;
}

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {
            return false;
        }
        if (nums.size() == 0) {
            return false;
        }
        vector<pair<int, int> > nums_with_pos;
        for (int i = 0; i < nums.size(); i += 1) {
            nums_with_pos.push_back(pair<int, int>(nums[i], i));
        }
        sort(nums_with_pos.begin(), nums_with_pos.end(), comp);
        for (int i = 0; i < nums_with_pos.size() - 1; i += 1) {
            if (nums_with_pos[i].first == nums_with_pos[i + 1].first and nums_with_pos[i + 1].second - nums_with_pos[i].second <= k)
                return true;
        }
        return false;
    }
};