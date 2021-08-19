// Created by 邢思远 on 2021/6/25 10:27 上午.
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
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
在选修某些课程之前需要一些先修课程。 先修课程按数组prerequisites 给出，其中prerequisites[i] = [ai, bi] ，
表示如果要学习课程 ai 则 必须 先学习课程 bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

示例 1：
输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。

示例 2：
输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。

解题思路:
  这道题是判断是否为【有向无环图】
  1.宽度优先搜索方法: (1) 建立有向图 (2)宽度搜索从入度为0的开始, 不断减少可到达节点的入度,
    如果有节点未能进入和弹出队列(则visited计数记录不到)

  拓扑排序原理： 对 DAG 的顶点进行排序，使得对每一条有向边 (u, v)，均有 u（在排序记录中）比 v 先出现。
              亦可理解为对某点 v 而言，只有当 v 的所有源点均出现了，v 才能出现。


*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegrees(numCourses, 0);
        for (auto p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }
        queue<int> qq;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                qq.push(i);
            }
        }
        int visited = 0;
        while (!qq.empty()) {
            int u = qq.front();
            qq.pop();
            visited++;
            for (int v : edges[u]) {
                --indegrees[v];
                if (indegrees[v] == 0) {
                    qq.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};

