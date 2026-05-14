#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = (int)nums.size(), N = 2 * n;
        vector<int>ans(N);
        for(int l = 0, r = N - 1; l < r; ++l, --r) ans[l] = ans[r] = nums[l];
        return ans;
    }
};

