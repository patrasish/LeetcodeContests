#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int net_h = 0, net_v = 0, additional = 0;
        for(char ch : moves){
            net_h += (ch == 'R');
            net_h -= (ch == 'L');
            net_v += (ch == 'U');
            net_v -= (ch == 'D');
            additional += (ch == '_');
        }
        int res = abs(net_h) + abs(net_v) + additional;
        return res;
    }
};