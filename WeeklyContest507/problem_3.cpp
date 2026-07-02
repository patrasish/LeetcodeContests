#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef pair<int, int> pii;
    const int INF = INT_MAX;
    struct Node{
        int node_id;
        int cost;
        int conseq;
        Node(int a = -1, int b = -1, int c = -1) : node_id{a}, cost{b}, conseq{c}{}
    };
    struct Comp{
        bool operator()(const Node& a, const Node& b){
            return a.cost > b.cost;
        }
    };
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pii>>adj(n);
        for(auto edge : edges){
            int from = edge[0], to = edge[1], weight = edge[2];
            adj[from].push_back(make_pair(to, weight));
        }
        priority_queue<Node, vector<Node>, Comp> pq;
        vector<vector<bool>>is_checked(n, vector<bool>(k+1));
        vector<vector<int>>dp(n, vector<int>(k+1, INF));
        dp[0][1] = 0;
        pq.push(Node(0, 0, 1));
        while(!pq.empty()){
            Node t = pq.top(); pq.pop();
            int cur_node = t.node_id, cur_cost = t.cost, cur_conseq = t.conseq;
            if(cur_node == n - 1)
                return cur_cost;
            if(is_checked[cur_node][cur_conseq])
                continue;
            is_checked[cur_node][cur_conseq] = true;
            for(auto[next_node, weight] : adj[cur_node]){
                int next_cost = cur_cost + weight, next_conseq = (labels[cur_node] == labels[next_node]) ? 1 + cur_conseq : 1;
                if((next_conseq <= k) && (next_cost < dp[next_node][next_conseq])){
                    pq.push(Node(next_node, next_cost, next_conseq));
                    dp[next_node][next_conseq] = next_cost;
                }
            }
        }
        return -1;
    }
};