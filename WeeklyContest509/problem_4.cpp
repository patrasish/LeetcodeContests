#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = (int)nums.size();
        {
            vector<int>temp((n << 1) | 1);
            for(int i = 0; i < n; ++i){
                int j = (i << 1) | 1;
                temp[j] = nums[i];
            }
            nums = move(temp);
        }
        n = (n << 1) | 1;
        vector<int>radius(n);
        radius[0] = 1;
        for(int i = 1, boundary = 0, center = 0; i < n; ++i){
            if(i < boundary){
                int mirror = (center << 1) - i;
                radius[i] = min(boundary - i + 1, radius[mirror]);
            }
            while((i - radius[i] >= 0) && (i + radius[i] < n) && (nums[i-radius[i]] == nums[i+radius[i]])) ++radius[i];
            if(i + radius[i] - 1 > boundary){
                boundary = i + radius[i] - 1;
                center = i;
            }
        }
        vector<long long>pref_sum(n);
        long long res = 0;
        for(int i = 1; i < n; ++i) pref_sum[i] = pref_sum[i-1] + nums[i];
        for(int i = 1; i < n; ++i){
            int R = radius[i], l = i - R, r = i + R - 1;
            long long contri = pref_sum[r];
            if(l >= 0)
                contri -= pref_sum[l];
            res = max(res, contri);
        }
        return res;
    }
};