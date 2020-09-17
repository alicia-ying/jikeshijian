#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();
        vector<int> result;
        while (iter1 != nums1.end() && iter2 != nums2.end()) {
            if (*iter1 < *iter2) {
                iter1 += 1;
            } else if (*iter1 > *iter2) {
                iter2 += 1;
            } else {
                result.push_back(*iter1);
                iter1 += 1;
                iter2 += 1;
            }
        }
        return result;
    }
};