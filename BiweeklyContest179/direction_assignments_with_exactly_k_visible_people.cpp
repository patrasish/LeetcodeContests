#include <bits/stdc++.h>
using namespace std;

class Calculator{
    const int MOD = (int)1e9 + 7;
    int n;
    vector<int>factorial;
    vector<int>inv_factorial;
    int get_power(int a, int p){
        if(p == 0)
            return 1;
        int res = get_power(a, (p >> 1));
        res = (1LL * res * res) % MOD;
        if(p & 1)
            res = (1LL * res * a) % MOD;
        return res;
    }
    void init(){
        factorial[0] = 1;
        for(int i = 1; i <= n; ++i) factorial[i] = (1LL * factorial[i-1] * i) % MOD;
        inv_factorial[n] = get_power(factorial[n], MOD - 2);
        for(int i = n - 1; i >= 0; --i)
            inv_factorial[i] = (1LL * (i + 1) * inv_factorial[i+1]) % MOD;
    }
public:
    Calculator(int _n){
        n = _n;
        factorial.resize(n+1);
        inv_factorial.resize(n+1);
        init();
    }
    int get_factorial(int n, int r){
        int res = (1LL * inv_factorial[r] * inv_factorial[n - r]) % MOD;
        res = (1LL * res * factorial[n]) % MOD;
        return res;
    }
};


class Solution {
    const int MOD = (int)1e9 + 7;
    void add_self(int& self, int val){
        self += val;
        if(self >= MOD)
            self -= MOD;
    }
public:
    int countVisiblePeople(int n, int pos, int k) {
        int l_available = pos, r_available = n -1 - pos, res = 0;
        Calculator calc = Calculator(n);
        for(int l_req = 0; l_req <= k; ++l_req){
            int r_req = k - l_req;
            if((l_req <= l_available) && (r_req <= r_available)){
                int l_contri = calc.get_factorial(l_available, l_req);
                int r_contri = calc.get_factorial(r_available, r_req);
                int contri = (2LL * l_contri * r_contri) % MOD;
                add_self(res, contri);
            }
        }
        return res;
    }
};