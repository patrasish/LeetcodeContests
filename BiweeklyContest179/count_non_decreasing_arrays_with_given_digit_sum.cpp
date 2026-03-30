#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = (int)1e9 + 7;
    const int MAXI = 5000;
    const int MAX_DIG_SUM = 36;

    int get_digit_sum(int x){
        int digit_sum = 0;
        while(x > 0){
            int unit_dig = x % 10;
            x /= 10;
            digit_sum += unit_dig;
        }
        return digit_sum;
    }
    void add_self(int& self, int val){
        self += val;
        if(self >= MOD)
            self -= MOD;
        return;
    }
public:
    int countArrays(vector<int>& digitSum) {
        {
            int t = *max_element(digitSum.begin(), digitSum.end());
            if(t > MAX_DIG_SUM)
                return 0;
        }
        int n = (int)digitSum.size();
        vector<vector<int>> adj(MAX_DIG_SUM + 1);
        for(int i = 0; i <= MAXI; ++i) adj[get_digit_sum(i)].push_back(i);
        vector<vector<int>>dp(n, vector<int>(MAXI+1));
        for(int x : adj[digitSum[0]]) dp[0][x] = 1;
        for(int i = 1; i <= MAXI; ++i) add_self(dp[0][i], dp[0][i-1]);
        for(int i = 1; i < n; ++i){
            int cur_dig_sum = digitSum[i];
            for(int x : adj[cur_dig_sum])
                dp[i][x] = dp[i-1][x];
            for(int val = 1; val <= MAXI; ++val) add_self(dp[i][val], dp[i][val-1]);
        }
        return dp[n-1][MAXI];
    }
};