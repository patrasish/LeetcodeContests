#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = (int)nums.size(), diff = n;
        for(int i = 0, last_one = -n, last_two = -n; i < n; ++i){
            int x = nums[i];
            if(x == 1){
                diff = min(diff, i - last_two);
                last_one = i;
            }
            if(x == 2){
                diff = min(diff, i - last_one);
                last_two = i;
            }
        }
        return (diff < n) ? diff : -1;
    }
};