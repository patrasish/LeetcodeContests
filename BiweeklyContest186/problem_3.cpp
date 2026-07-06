#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = (int)s1.size(), res = 0;
        for(int i = 0; i < n; ++i){
            if((s1[i] != s2[i]) && (s1[i] == '0')){
                ++res;
                s1[i] = '1';
            }
        }
        if(n == 1)
            return (s1 == s2) ? res : -1;
        int t = 0;
        while(t < n){
            if(s1[t] == s2[t]){
                ++t;
                continue;
            }
            int j = t;
            while((j < n) && (s1[j] != s2[j])) ++j;
            int d = j - t;
            res += (d + 1) / 2 + (d & 1);
            t = j;
        }
        return res;
    }
};