#include<bits/stdc++.h>
using namespace std;

class Solution {
    int get_last_digit(long long x){
        return (x < 10) ? x : get_last_digit(x / 10);
    }
    int get_first_digit(long long x){
        return (x % 10);
    }
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = (int)nums.size();
        long long res  = 0;
        for(int i = 0; i < n; ++i){
            long long cur_sum = 0;
            for(int j = i; j < n; ++j){
                cur_sum += nums[j];
                int first_dig = get_first_digit(cur_sum);
                int last_dig = get_last_digit(cur_sum);
                res += (first_dig == last_dig) && (first_dig == x);
            }
        }
        return res;
    }
};