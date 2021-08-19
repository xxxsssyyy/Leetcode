// Created by xingsiyuan on 2021/3/4 9:41.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

/*
题目描述:
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

输入： intervals = [[1,3],[2,6],[8,10],[15,18]]
输出： [[1,6],[8,10],[15,18]]

解题思路:
1.贪心算法：想清楚合并规则

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int i = 0, j;

        while (i < intervals.size()) {
            vector<int> temp = intervals[i];
            j = i+1;
            // 这里的判断条件比较关键
            while (j < intervals.size() && temp[1] >= intervals[j][0]) {
                temp[1] = max(intervals[j][1], temp[1]);
                j+=1;
            }
            res.push_back(temp);
            i=j;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> inputs = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = sol.merge(inputs);
    for (auto a : res) {
        cout << "[" << a[0] << "," << a[1] << "]" << " ";
    }
    cout << endl;
    return 0;
}