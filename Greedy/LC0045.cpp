// Created by xingsiyuan on 2021/3/5 9:40.
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
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

输入： [2,3,1,1,4]
输出： 2

解题思路:
 1.贪心方法

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_pos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n-1; i++) {
            if (max_pos >= i) {
                max_pos = max(max_pos , i+nums[i]);
                if (i == end) {
                    end = max_pos;
                    step++;
                }
            }
        }
        return step;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << sol.jump(nums) << endl;
    return 0;
}