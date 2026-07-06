#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n1 = (int)s.size(), n2 = (int)t.size();
        if(n1 == 1)
            return true;
        vector<int>pref(n1, -1), suff(n1, -1);
        for(int i = 0, j = 0; (i < n1) && (j < n2); ++i){
            while((j < n2) && (s[i] != t[j])) ++j;
            if(j < n2) pref[i] = j++;
        }
        for(int i = n1 - 1, j = n2 -1; (i >= 0) && (j >= 0); --i){
            while((j >= 0) && (s[i] != t[j])) --j;
            if(j >= 0) suff[i] = j--;
        }
        
        if((suff[0] >= 0) || ((pref[n1-2] >= 0) && (pref[n1-2] < n2 -1)) || (suff[1] > 0))
            return true;
        
        for(int i = 1; i < n1 - 1; ++i){
            int l = pref[i-1], r = suff[i+1];
            if((l >= 0) && (r >= 0) && (r - l > 1))
                return true;
        }
        return false;
    }
};