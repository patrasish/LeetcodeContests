#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        auto is_lower = [](char ch){
            return ((ch >= 'a') && (ch <= 'z'));
        };
        auto is_upper = [](char ch){
            return ((ch >= 'A') && (ch <= 'Z'));
        };
        auto is_digit = [](char ch){
            return ((ch >= '0') && (ch <= '9'));
        };
        set<char>uni_chars;
        for(char ch : password) uni_chars.insert(ch);
        int res = 0;
        for(char ch : uni_chars){
            if(is_lower(ch)) res += 1;
            else if(is_upper(ch)) res += 2;
            else if(is_digit(ch)) res += 3;
            else res += 5;
        }
        return res;
    }
};