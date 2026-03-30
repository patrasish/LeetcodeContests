#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int NAX = (1 << 10);
public:
    int minCost(vector<vector<int>>& grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        vector<vector<vector<bool>>>dp(n, vector<vector<bool>>(m, vector<bool>(NAX)));
        dp[n-1][m-1][grid[n-1][m-1]] = true;
        for(int c = m - 2, cur_xor = grid[n-1][m-1]; c >= 0; --c){
            cur_xor ^= grid[n-1][c];
            dp[n-1][c][cur_xor] = true;
        }
        for(int r = n - 2, cur_xor = grid[n-1][m-1]; r >= 0; --r){
            cur_xor ^= grid[r][m-1];
            dp[r][m-1][cur_xor] = true;
        }
        for(int r = n - 2; r >= 0; --r){
            for(int c = m - 2; c >= 0; --c){
                for(int x = 0; x < NAX; ++x){
                    int temp = x ^ grid[r][c];
                    dp[r][c][temp] = dp[r+1][c][x] || dp[r][c+1][x];
                }
            }
        }
        for(int res = 0; res < NAX; ++res){
            if(dp[0][0][res])
                return res;
        }
        return -1;
    }
};