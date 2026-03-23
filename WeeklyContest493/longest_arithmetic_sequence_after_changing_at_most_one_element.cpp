#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int>pref_dp(n), suff_dp(n);
        // pref_dp[i] = max_len of subarr ending at i and all consequtive diff is same
        // suff_dp[i] = max_len of subarr starting at i and all consequtive diff is same
        pref_dp[0] = suff_dp[n-1] = 1;
        pref_dp[1] = suff_dp[n-2] = 2;
        for(int i = 2; i < n; ++i){
            int diff1 = nums[i-2] - nums[i-1], diff2 = nums[i-1] - nums[i];
            pref_dp[i] = (diff1 == diff2) ? 1 + pref_dp[i-1] : 2;
        }
        for(int i = n - 3; i >= 0; --i){
            int diff1 = nums[i] - nums[i+1], diff2 = nums[i+1] - nums[i+2];
            suff_dp[i] = (diff1 == diff2) ? 1 + suff_dp[i+1] : 2;
        }
        int res = *max_element(pref_dp.begin(), pref_dp.end());
        res = max(res, *max_element(suff_dp.begin(), suff_dp.end()));
        // now lets change one element and see the changes

        // changing first element
        res = max(res, 1 + suff_dp[1]);
        // changing last element
        res = max(res, 1 + pref_dp[n-2]);
        // changing second element
        res = max(res, 1 + suff_dp[2] + ((2 * (nums[2] - nums[3])) == (nums[0] - nums[2])));
        // changing second-last element
        res = max(res, 1 + pref_dp[n-3] + ((2 * (nums[n-4] - nums[n-3])) == (nums[n-3] - nums[n-1])));
        // changing rest of the elements
        for(int i = 2; i < n - 2; ++i){
            int contri = 1 + max(pref_dp[i-1], suff_dp[i+1]);
            int diff = nums[i-1] - nums[i+1];
            if(diff & 1){
                res = max(res, contri);
                continue;
            }
            diff /= 2;
            int l_diff = nums[i-2] - nums[i-1], r_diff = nums[i+1] - nums[i+2];
            if((l_diff == diff) && (diff == r_diff))
                contri = pref_dp[i-1] + 1 + suff_dp[i+1];
            else if(l_diff == diff)
                contri = max(contri, pref_dp[i-1] + 2);
            else if(r_diff == diff)
                contri = max(contri, 2 + suff_dp[i+1]);
            res = max(res, contri);
        }
        return res;
    }
};