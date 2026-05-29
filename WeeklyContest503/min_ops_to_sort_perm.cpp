#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool is_imp(const vector<int>& nums){
        size_t n = nums.size();
        for(size_t i = 0; i < n; ++i){
            int cur = nums[i],
                      next = (i == n-1) ? nums[0] : nums[i+1],
                      prev = (i == 0) ? nums[n-1] : nums[i-1];
            int l = (cur == 0) ? n - 1 : cur - 1,
                r = (cur == n - 1) ? 0 : cur + 1;
            bool chk1 = (l == prev) && (r == next);
            swap(l, r);
            bool chk2 = (l == prev) && (r == next);
            bool chk = chk1 || chk2;
            if(!chk)
                return true;
        }
        return false;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(is_sorted(nums.begin(), nums.end()))
            return 0;
        if(is_imp(nums))
            return -1;
        int y = distance(nums.begin(), find(nums.begin(), nums.end(), n-1));
        return 1 + min(y, n - y);
        

    }
};
