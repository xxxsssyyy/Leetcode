// Created by 邢思远 on 2021/7/29 3:57 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
题目描述:
给定一个整数数组和一个整数k，你需要找到该数组中和为k的连续的子数组的个数。

示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

解题思路:
    1. 因为是连续子数组: 暴力解法 双循环 O(N^2)
    2. 前缀和+哈希表优化(注意数组中有负数的情况)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // mp代表前缀和哈希表, index前面的前缀和: 数值
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto num : nums) {
            pre += num;
            if (mp.find(pre-k) != mp.end()) {
                count += mp[pre-k];
            }
            mp[pre]++;
        }
        return count;
    }
};
