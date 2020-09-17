#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1, pos2 = n - 1, final_pos = n + m - 1;
        while (pos1 >= 0 && pos2 >= 0) {
            if (nums1[pos1] > nums2[pos2]) {
                nums1[final_pos] = nums1[pos1];
                nums1[pos1] = 0;
                pos1 -= 1;
            } else {
                nums1[final_pos] = nums2[pos2];
                pos2 -= 1;
            }
            final_pos -= 1;
        }
        while (pos2 >= 0) {
            nums1[final_pos] = nums2[pos2];
            pos2 -= 1;
            final_pos -= 1;
        }
    }
};