#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        int S = 1;
        while(S * S < n) ++S;
        unordered_map<long long, int> cnt[S];
        vector<long long>lazy(S, 0LL);
        vector<long long>nums2(n);
        for(int i = 0; i < n; ++i) nums2[i] = (long long)nums[i];
        for(int i = 0; i < n; ++i){
            cnt[i/S][nums2[i]] += 1;
        }
        vector<int>res;
        for(auto& query : queries){
            int op = query[0];
            if(op == 1){
                int l = query[1], r = query[2], val = query[3];
                while(l <= r){
                    int block = l / S;
                    if(((l % S) == 0) && (l + S - 1 <= r)){
                        lazy[block] += val;
                        l += S;
                    }
                    else{
                        --cnt[block][nums2[l]];
                        if(cnt[block][nums2[l]] == 0)
                            cnt[block].erase(nums2[l]);
                        nums2[l] += val;
                        ++cnt[block][nums2[l]];
                        ++l;
                    }
                }
            }
            else{
                int contri = 0;
                long long total = (long long)query[1];
                for(int x : nums1){
                    for(int i = 0; i < S; ++i){
                        long long target = total - x - lazy[i];
                        auto it = cnt[i].find(target);
                        if(it != cnt[i].end())
                            contri += it->second;
                    }
                }
                res.push_back(contri);
            }
        }
        return res;
    }
};