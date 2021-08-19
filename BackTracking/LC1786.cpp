// Created by xingsiyuan on 2021/3/8 10:32.
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
现有一个加权无向连通图。给你一个正整数 n ，表示图中有 n 个节点，并按从 1 到 n 给节点编号；另给你一个数组 edges ，
其中每个 edges[i] = [ui, vi, weighti] 表示存在一条位于节点 ui 和 vi 之间的边， 这条边的权重为 weighti 。
从节点 start 出发到节点 end 的路径是一个形如 [z0, z1, z2, ..., zk] 的节点序列，满足 z0 = start 、zk = end 且在所有符合 0 <= i <= k-1 的节点 zi 和 zi+1 之间存在一条边。
路径的距离定义为这条路径上所有边的权重总和。用 distanceToLastNode(x) 表示节点 n 和 x 之间路径的最短距离。受限路径 为满足 distanceToLastNode(zi) > distanceToLastNode(zi+1)
的一条路径，其中 0 <= i <= k-1 。

返回从节点 1 出发到节点 n 的 受限路径数 。由于数字可能很大，请返回对 10^9 + 7 取余 的结果。

输入：n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
输出：3

解题思路:
 1.第一步求出每个节点到尾部节点的最短距离 第二步使用记忆化搜索得到满足条件的解
 2.第一步求出每个节点到尾部节点的最短距离 第二步拓扑排序

*/

class Solution {
private:
    int mod = pow(10, 9) + 7;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dist(n+1, INT_MAX);
        dist[n] = 0;
        vector<vector<pair<int, int>>> graph(n+1);
        priority_queue<pair<int, int>> heap;
        vector<int> visited(n+1, false);
        for (auto p : edges) {
            int u = p[0], v = p[1], w = p[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        // 堆中存储 (与起始点的距离, 节点index)
        heap.push({0, n});
        while (!heap.empty()) {
            auto [d, i] = heap.top(); heap.pop();
            d = -d;
            if (visited[i]) continue;
            visited[i] = true;
            for (auto [v, w] : graph[i]) {
                if (d+w < dist[v]) {
                    dist[v] = d+w;
                    heap.push({-dist[v], v});
                }
            }
        }
        vector<int> ans_count(n+1, -1);
        return dfs(n, dist, graph, ans_count);

    }
    int dfs(int i, vector<int> dist, vector<vector<pair<int, int>>> graph, vector<int>& ans_count) {
        if (i == 1) return 1;
        if (ans_count[i] != -1) return ans_count[i];
        int ans = 0;
        for (auto [v, w] : graph[i]) {
            if (dist[v] > dist[i]) {
                ans = (ans + dfs(v, dist, graph, ans_count)) % mod;
            }
        }
        ans_count[i] = ans;
        return ans;
    }
};


class Solution2 {
private:
    int mod = pow(10, 9) + 7;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dist(n+1, INT_MAX);
        dist[n] = 0;
        vector<vector<pair<int, int>>> graph(n+1);
        priority_queue<pair<int, int>> heap;
        vector<int> visited(n+1, false);
        for (auto p : edges) {
            int u = p[0], v = p[1], w = p[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        // 堆中存储 (与起始点的距离, 节点index)
        heap.push({0, n});
        while (!heap.empty()) {
            auto [d, i] = heap.top(); heap.pop();
            d = -d;
            if (visited[i]) continue;
            visited[i] = true;
            for (auto [v, w] : graph[i]) {
                if (d+w < dist[v]) {
                    dist[v] = d+w;
                    heap.push({-dist[v], v});
                }
            }
        }
        vector<int> dp(n+1, 0), q(n);
        dp[n] = 1;
        for (int i = 0; i < n; i++) q[i] = i+1;
        // 匿名函数
        sort(q.begin(), q.end(), [&](int x, int y) {return dist[x] < dist[y];});
        for (auto u : q) {
            for (auto [v, w] : graph[u]) {
                if (dist[v] < dist[u]) {
                    dp[u] = (dp[u] + dp[v]) % mod;
                }
            }
        }
        return dp[1];
    }

};