#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>cnt(101);
        vector<int>res;
        for(int x : nums){
            if(cnt[x] < k)
                res.push_back(x);
            ++cnt[x];
        }
        return res;
    }
};