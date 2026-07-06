#include<bits/stdc++.h>
using namespace std;

class Solution {
    int get_dig_range(int x){
        int mini = 11, maxi = -1, dig_range = 0;
        while(x > 0){
            int dig = x % 10;
            mini = min(mini, dig);
            maxi = max(maxi, dig);
            dig_range = max(dig_range, maxi - mini);
            x /= 10;
        }
        return dig_range;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int max_dig_range = 0, res = 0;
        for(int x : nums){
            int dig_range = get_dig_range(x);
            if(dig_range > max_dig_range){
                max_dig_range = dig_range;
                res = x;
            }
            else if(dig_range == max_dig_range)
                res += x;
        }
        return res;
    }
};