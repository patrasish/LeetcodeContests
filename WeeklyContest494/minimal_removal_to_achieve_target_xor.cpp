#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int NAX = 10000;
    const int NOT_CALCULATED = -2;
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(ind < 0)     // it means we are with no elements
            return (target == 0) ? 0 : -1;
        if(dp[ind][target] != NOT_CALCULATED)
            return dp[ind][target];
        int take = solve(ind - 1, target ^ nums[ind], nums, dp);
        if(take != -1)
            ++take;
        int not_take = solve(ind - 1, target, nums, dp);
        int res = max(take, not_take);
        return dp[ind][target] = res;
    }
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = (int)nums.size();
        // our startegy is to find maximum size of the subset such that the xor of the subset = target
        // n - size(subset) = minimum removal of elements
        vector<vector<int>>dp(n, vector<int>(2 * NAX, NOT_CALCULATED)); // the memory allocation indicates that maximum xor value can't exceed 2 * NAX
        int res = solve(n-1, target, nums, dp);
        return (res == -1) ? -1 : n - res;


    }
};