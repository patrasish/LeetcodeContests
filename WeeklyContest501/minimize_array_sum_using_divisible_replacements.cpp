#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MX = (int)1e5;
public:
    long long minArraySum(vector<int>& nums) {
        long long res = 0;
        vector<int>contri(MX+1, -1);
        sort(nums.begin(), nums.end());
        for(int x : nums){
            if(contri[x] == -1){
                for(int i = x; i <= MX; i += x){
                    if(contri[i] == -1)
                        contri[i] = x;
                }
            }
            res += contri[x];
        }
        return res;
    }
};