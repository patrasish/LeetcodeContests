#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = (int)1e9 + 7;
    typedef pair<int, int> pii;
    int get_m(const vector<int>& value, const vector<int>& decay, int m){
        int n = (int)value.size();
        int cur = 0;
        for(int i = 0; i < n; ++i){
            cur += (value[i] / decay[i]) + ((value[i] % decay[i]) > 0);
            if(cur >= m)
                return m;
        }
        return cur;
    }
    bool chk(const vector<int>& value, const vector<int>& decay, int mid, int m){
        int n = (int)value.size();
        int contri = 0;
        for(int i = 0; i < n; ++i){
            int cur_contri = max(0, (value[i] - mid + decay[i]) / decay[i]);
            contri += cur_contri;
            if(contri >= m)
                return true;
        }
        return false;
    }
    pii get_contri(int a, int d, int mini){
        if(a < mini)
            return make_pair(0, 0);
        int n = max(0, (a - mini + d) / d);
        int contri1 = (1LL * a * n) % MOD;
        int contri2 = ((1LL * n * (n - 1)) / 2) % MOD;
        contri2 = (1LL * contri2 * d) % MOD;
        int contri = contri1 + contri2;
        if(contri >= MOD)
            contri -= MOD;
        return make_pair(contri, n);
    }
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        m = get_m(value, decay, m);
        int l = 1, r = (int)1e9, mini = 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(chk(value, decay, mid, m)){
                mini = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        int n = (int)value.size(), res = 0;
        for(int i = 0; i < n; ++i){
            pii p = get_contri(value[i], decay[i] + 1, mini);
            res += p.first;
            if(res >= MOD)
                res -= MOD;
            m -= p.second;
        }
        int additional = (1LL * mini * m) % MOD;
        res += additional;
        if(res >= MOD)
            res -= MOD;
        return res;
        
    }
};