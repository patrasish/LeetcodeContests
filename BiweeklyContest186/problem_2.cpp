#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = (int)nums.size(), res = 0;
        priority_queue<int> pq;
        for(int l = 0, r = 0; r < n; ++r){
            if(r - l >= k)
                pq.push(nums[l++]);
            if(!pq.empty())
                res = max(res, nums[r] + pq.top());
        }
        return res;
    }
};
