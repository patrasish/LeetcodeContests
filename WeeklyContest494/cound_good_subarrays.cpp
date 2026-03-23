#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        // here we'll use contribution technique
        // i.e. for each element how many subarrays exist such that the xor of that subarray
        // equals to current element
        // lets focus on element i
        // suppose there is a good subarray contain's element i and the or of that good subarray is nums[i]
        // then this subarray contributes 1 to the answer w.r.t element i
        // now let say element i contributes x number of good subarrays
        // then out of this x subarrays there should not exist an elemetn j
        // such that there exists a bit where nums[j] is set and nums[i] is not set
        // so for every element we have to look for how far left and how far right we can go
        // and also we have to encounter the overcounting part

        int n = (int)nums.size();
        vector<int>next_same(n, n);
        {
            map<int, int> last_occurance;
            for(int i = n-1; i >= 0; --i){
                int x = nums[i];
                auto itr = last_occurance.find(x);
                if(itr != last_occurance.end())
                    next_same[i] = itr->second;
                last_occurance[x] = i;
            }
        }
        vector<vector<int>>pref(n, vector<int>(30, -1));
        vector<vector<int>>suff(n, vector<int>(30, n));
        for(int bit = 0; bit < 30; ++bit){
            if(nums[0] & (1 << bit))
                pref[0][bit] = 0;
        }
        for(int bit = 0; bit < 30; ++bit){
            if(nums[n-1] & (1 << bit))
                suff[n-1][bit] = n - 1;
        }
        for(int i = 1; i < n; ++i){
            for(int bit = 0; bit < 30; ++bit){
                if(nums[i] & (1 << bit))
                    pref[i][bit] = i;
                else
                    pref[i][bit] = pref[i-1][bit];
            }
        }
        for(int i = n - 2; i >= 0; --i){
            for(int bit = 0; bit < 30; ++bit){
                if(nums[i] & (1 << bit))
                    suff[i][bit] = i;
                else
                    suff[i][bit] = suff[i+1][bit];
            }
        }

        long long good_subarrs = 0;
        for(int i = 0; i < n; ++i){
            int l = -1, r = next_same[i];
            for(int bit = 0; bit < 30; ++bit){
                if((nums[i] & (1 << bit)) == 0){
                    l = max(l, pref[i][bit]);
                    r = min(r, suff[i][bit]);
                }
            }
            l = i - l;
            r = r - i;
            long long contri = 1LL * l * r;
            good_subarrs += contri;
        }
        return good_subarrs;
    }
};