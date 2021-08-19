// Created by xingsiyuan on 2021/3/7 12:40.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

/*
题目描述:
有 n 个网络节点，标记为1到 n。
给你一个列表times，表示信号经过 有向边的传递时间。times[i] = (ui, vi, wi)，其中ui是源节点，vi是目标节点， wi是一个信号从源节点传递到目标节点的时间。
现在，从某个节点K发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回-1 。

输入： times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
输出： 2

解题思路:

(1)准备工作
Dijkstra 算法流程详解: https://www.cnblogs.com/littlewrong/p/9196060.html
Dijkstra是一种宽度优先搜索的方法（按照距离的深度，保持距离原点近的节点先进行搜索）
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        vector<int> dist(n+1, INT_MAX); // 距离起始点的最短距离
        vector<bool> st(n+1, false); // 是否已得到最短距离
        priority_queue<pair<int, int>> heap;
        for (auto p : times) {
            int u = p[0], v = p[1], w = p[2];
            graph[u].push_back({v, w});
            //graph[v].push_back({u, w});
        }
        // 到当前点距离，当前点id
        heap.push({0, k});
        dist[k] = 0;
        while (!heap.empty()) {
            auto [d, i] = heap.top(); heap.pop();
            d = -d;
            if (st[i]) continue;
            st[i] = true;
            for (auto [v, w] : graph[i]) {
                if (dist[v] > d+w) {
                    dist[v] = d+w;
                    heap.push({-dist[v], v});
                }
            }
        }
        int res = *max_element(dist.begin()+1, dist.end());
        return (res == INT_MAX ? -1 : res);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    //
    cout << sol.networkDelayTime(times, 4, 2) << endl;
    return 0;
}
