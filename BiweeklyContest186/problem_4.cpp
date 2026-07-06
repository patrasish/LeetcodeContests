#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)1e9 + 7;
    int dp[100][101][101][2];
    int cnt(string& s, char ch, int n){
        int res = 0;
        for(int i = 0; i < n; ++i)
            res += (ch == s[i]);
        return res;
    }
    void init(){
        for(int i = 0; i < 100; ++i){
            for(int j = 0; j <= 100; ++j){
                for(int k = 0; k <= 100; ++k)
                    dp[i][j][k][0] = dp[i][j][k][1] = -1;
            }
        }
    }
    void add_self(int& self, int value){
        self += value;
        if(self >= mod)
            self -= mod;
    }
    void sub_self(int& self, int value){
        self -= value;
        if(self < 0)
            self += mod;
    }
    int solve(string& target, string& s1, string& s2, int pos, int pos1, int pos2, int last){
        if(pos == 0)
            return (last == 0) ? cnt(s1, target[0], pos1) : cnt(s2, target[0], pos2);
        if(((pos1 == 0) && (last == 0)) || ((pos2 == 0) && (last == 1)))
            return 0;
        if(dp[pos][pos1][pos2][last] != -1)
            return dp[pos][pos1][pos2][last];
        int res = 0;
        if(last == 0){
            int not_take = solve(target, s1, s2, pos, pos1 - 1, pos2, 0);
            int take = 0;
            if(s1[pos1-1] == target[pos]){
                take = solve(target, s1, s2, pos - 1, pos1 - 1, pos2, 0);
                add_self(take, solve(target, s1, s2, pos - 1, pos1 - 1, pos2, 1));
            }
            add_self(res, take); add_self(res, not_take);
        }
        else{
            int not_take = solve(target, s1, s2, pos, pos1, pos2 - 1, 1);
            int take = 0;
            if(s2[pos2-1] == target[pos]){
                take = solve(target, s1, s2, pos - 1, pos1, pos2 - 1, 1);
                add_self(take, solve(target, s1, s2, pos - 1, pos1, pos2 - 1, 0));
            }
            add_self(res, take); add_self(res, not_take);
        }
        return dp[pos][pos1][pos2][last] = res;
    }
    int helper(const string& s1, const string& s2){
        int n1 = (int)s1.size(), n2 = (int)s2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2 + 1));
        for(int i = 0; i <= n2; ++i) dp[0][i] = 1;
        for(int i = 1; i <= n1; ++i){
            for(int j = 1; j <= n2; ++j){
                dp[i][j] = dp[i][j-1];
                if(s1[i-1] == s2[j-1])
                    add_self(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[n1][n2];
    }
public:
    int interleaveCharacters(string word1, string word2, string target) {
        init();
        int n = (int)target.size(), n1 = (int)word1.size(), n2 = (int)word2.size();
        int res = solve(target, word1, word2, n-1, n1, n2, 0);
        add_self(res, solve(target, word1, word2, n-1, n1, n2, 1));
        sub_self(res, helper(target, word1));
        sub_self(res, helper(target, word2));
        
        return res;
    }
};