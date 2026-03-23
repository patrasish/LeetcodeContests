#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        // 1,000, 999,999 -> 1
        // 1,000,000, 9,999,999 -> 2
        // ---------------
        long long cur = 1000;
        int coeff = 1;
        long long res = 0;
        while(n >= cur){
            long long next = 1LL * cur * 1000;
            long long contri = min(next - 1, n) - cur + 1;
            res += 1LL * contri * coeff;
            ++coeff;
            cur = next;
        }
        return res;
    }
};
