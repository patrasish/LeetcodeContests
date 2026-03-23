#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = (int)nums1.size();
        if(n == 1)
            return true;
        // the final parity of the array = the parity of the smallest element
        // because it's parity can't be changed
        // in order to change the parity there should exist another element which is smaller than this smallest one
        // so there are two cases
        int mini = *min_element(nums1.begin(), nums1.end());
        int final_parity = mini & 1;
        // case1: final_parity is odd.

        // if final_parity is odd, then it is always possible to build nums2
        // if nums1[i] = odd then nums2[i] = nums1[i]
        // if nums1[i] = even then nums2[i] = nums1[i] - nums1[k] (nums1[k] = mini)
        if(final_parity == 1)
            return true;

        // case2: final_parity is even.


        // suppose all the element are even, in this case it is always possible to build nums2
        // suppose there is an odd element
        // lets concentrate on the smallest odd element and try to find out how we can change it's parity
        // now in order to change it's parity we need to subract some smaller value
        // and all the smaller values are even so the parity wouldn't change 
        // in this case it is not possible to change the parity

        for(int x : nums1){
            if(x & 1)
                return false;
        }
        return true;
    }
};