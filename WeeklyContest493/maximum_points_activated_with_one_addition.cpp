#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>parent;
    vector<int>sz;
    int get_root(int node){
        return parent[node] = (node == parent[node]) ? node : get_root(parent[node]);
    }
    void unite(int node1, int node2){
        int root1 = get_root(node1);
        int root2 = get_root(node2);
        if(root1 == root2)
            return;
        if(sz[root1] < sz[root2]) swap(root1, root2);
        sz[root1] += sz[root2];
        parent[root2] = root1;
    }
public:
    int maxActivated(vector<vector<int>>& points) {
        // here we treat each point as a node and try to implement dsu
        // so we'll iterate over the point
        // if a point shares a row or a column with an already traversed node, then we'll unite
        // this node with that node
        int n = (int)points.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
        map<int, int> x_hash, y_hash;
        for(int node = 0; node < n; ++node){
            int x = points[node][0], y = points[node][1];
            if(x_hash.find(x) == x_hash.end())
                x_hash[x] = node;
            else
                unite(x_hash[x], node);
            if(y_hash.find(y) == y_hash.end())
                y_hash[y] = node;
            else
                unite(y_hash[y], node);
        }

        int maxi1 = 0, maxi2 = 0;
        for(int node = 0; node < n; ++node){
            if(parent[node] == node){
                if(sz[node] > maxi1){
                    maxi2 = maxi1;
                    maxi1 = sz[node];
                }
                else if(sz[node] > maxi2)
                    maxi2 = sz[node];
            }
        }
        int res = 1 + maxi1 + maxi2;
        return res;
    }
};