// Created by 邢思远 on 2021/7/29 2:33 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

/*
题目描述:
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

输入: nums = [1], k = 1
输出: [1]

解题思路:
 步骤 (1) 哈希表存储频次 (2) {频次, num} 作为大根堆的数据结构, 按照频次进行堆排序 (3) 从堆中取k个数
*/

struct cmp1 {
    bool operator() (pair<int, int> x, pair<int, int> y) {
        return x.first < y.first;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2count;
        for (auto p: nums) {
            num2count[p]++;
        }
        // priority_queue 默认是从大向小排序, 默认比较函数是x < y
        // 这里建一个大根堆, 元素为 {频次, num}
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> q;
        for (auto p: num2count) {
            q.push({p.second, p.first});
        }
        vector<int> results;
        while (k > 0) {
            pair<int, int> temp = q.top();
            q.pop();
            results.push_back(temp.second);
            k--;
        }
        return results;
    }
};
