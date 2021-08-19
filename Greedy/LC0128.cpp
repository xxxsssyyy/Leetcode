// Created by 邢思远 on 2021/6/23 7:57 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*
题目描述:
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？

输入： nums = [100, 4, 200, 1, 3, 2]
输出： 4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

解题思路:
        首先用 集合容器 对 nums 去重, 基本想法两次遍历会做了重复的事情
        枚举的数 x 一定是在数组中不存在前驱数 x-1 的, 有一些知道了规则贪心的意思
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 去重
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }
        int longest_count = 0;
        for (const int& num : num_set) {
            // 枚举不存在x-1的
            if (!num_set.count(num - 1)) {
                int current_num = num;
                int temp_count = 1;
                while (num_set.count(current_num+1)) {
                    current_num += 1;
                    temp_count += 1;
                }
                longest_count = max(longest_count, temp_count);
            }
        }
        return longest_count;
    }
};

