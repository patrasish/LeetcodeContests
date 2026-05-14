#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef pair<int, long long> pil;
    const long long INF = (long long)1e15;
    struct Compare{
        bool operator()(const pil& a, const pil& b){
            return a.second > b.second;
        }
    };
    void helper(int start_node, vector<vector<pil>>& adj, vector<long long>& cost){
        int n = (int)cost.size();
        vector<bool>is_relaxed(n);
        priority_queue<pil, vector<pil>, Compare> pq;
        cost[start_node] = 0;
        pq.push(make_pair(start_node, 0));
        while(!pq.empty()){
            pil p = pq.top(); pq.pop();
            int cur_node = p.first;
            long long cur_cost = p.second;
            if(is_relaxed[cur_node]) continue;
            is_relaxed[cur_node] = true;
            for(pil next : adj[cur_node]){
                int next_node = next.first;
                long long net_cost = next.second + cur_cost;
                if(net_cost < cost[next_node]){
                    cost[next_node] = net_cost;
                    pq.push(make_pair(next_node, net_cost));
                }
            }
        }
        
    }
    int get_ans(int start_node, vector<int>& price, vector<vector<pil>>& forward, vector<vector<pil>>& backward){
        int n = (int)forward.size();
        vector<long long>forward_cost(n, INF), backward_cost(n, INF);
        helper(start_node, forward, forward_cost);
        helper(start_node, backward, backward_cost);
        long long ans = price[start_node];
        for(int node = 0; node < n; ++node){
            long long cur_cost = forward_cost[node] + backward_cost[node] + price[node];
            ans = min(ans, cur_cost);
        }
        return (int)ans;
    }
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pil>>forward(n), backward(n);
        for(vector<int>& road : roads){
            int shop1 = road[0], shop2 = road[1], cost = road[2], tax = road[3];
            forward[shop1].push_back(make_pair(shop2, cost));
            forward[shop2].push_back(make_pair(shop1, cost));
            backward[shop1].push_back(make_pair(shop2, 1LL * cost * tax));
            backward[shop2].push_back(make_pair(shop1, 1LL * cost * tax));
        }
        vector<int>ans(n);
        for(int shop = 0; shop < n; ++shop){
            ans[shop] = get_ans(shop, prices, forward, backward);
        }
        return ans;
    }
};