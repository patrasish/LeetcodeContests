#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string whole_str;
        for(string chunk : chunks) whole_str += chunk;
        map<string, int> cnt;
        int ind = 0, n = (int)whole_str.size();
        while(ind < n){
            while((ind < n) && (whole_str[ind] == ' ')) ++ind;
            if(ind == n) break;
            int t = ind;
            string cur;
            bool flag = true;
            while((t < n) && (whole_str[t] != ' ') && (flag == true)){
                char ch = whole_str[t];
                if(ch == '-'){
                    bool cond1 = (t > 0) && (whole_str[t-1] >= 'a') && (whole_str[t-1] <= 'z');
                    bool cond2 = (t < n - 1) && (whole_str[t+1] >= 'a') && (whole_str[t+1] <= 'z');
                    if(cond1 && cond2)
                        cur.push_back(ch);
                    else
                        flag = false;
                }
                else
                    cur.push_back(whole_str[t]);
                ++t;
            }
            ind = t;
            ++cnt[cur];
        }
        int q = (int)queries.size();
        vector<int>res(q);
        for(int i = 0; i < q; ++i) res[i] = cnt[queries[i]];
        return res;
    }
};