#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = (int)nums.size(), key = nums[n/2];
        bool has_appeared = false;
        for(int x : nums){
            if(x != key) continue;
            if(has_appeared)
                return false;
            has_appeared = true;
        }
        return true;
    }
};