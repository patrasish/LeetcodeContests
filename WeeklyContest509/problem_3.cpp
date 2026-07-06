#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr int maxi = 1000000;
    static constexpr int mod = 1000000007;

    inline static vector<vector<int>> prime_factors;
    inline static bool initialized = false;

    static void init() {
        if (initialized) return;
        initialized = true;

        prime_factors.resize(maxi + 1);

        for (int i = 2; i <= maxi; ++i) {
            if (prime_factors[i].empty()) {
                for (int j = i; j <= maxi; j += i)
                    prime_factors[j].push_back(i);
            }
        }
    }

public:
    int divisibleGame(std::vector<int>& nums) {
        init();

        int n = nums.size();
        int max_score = -1, k = -1;

        vector<int> factors_contri(maxi + 1, 0);
        vector<int> touched;

        for (int l = 0; l < n; ++l) {
            int cur_sum = 0;

            for (int r = l; r < n; ++r) {
                int x = nums[r];
                cur_sum += x;

                if (x == 1) continue;

                for (int f : prime_factors[x]) {
                    if (factors_contri[f] == 0)
                        touched.push_back(f);

                    factors_contri[f] += nums[r];

                    int score_contri = 2 * factors_contri[f] - cur_sum;

                    if (score_contri <= 0) continue;

                    if (score_contri > max_score) {
                        max_score = score_contri;
                        k = f;
                    } else if (score_contri == max_score && f < k) {
                        k = f;
                    }
                }
            }

            for (int f : touched)
                factors_contri[f] = 0;

            touched.clear();
        }

        if (k == -1)
            return mod - 2;

        return (1LL * max_score * k) % mod;
    }
};
