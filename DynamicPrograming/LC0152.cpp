// Created by 邢思远 on 2021/6/24 9:40 下午.
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
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
解题思路:
 正负值讨论, 从前到后分别维护 最大正数 和 最小的负数

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int MAX = INT_MIN;
        int imax = 1, imin = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            MAX = max(MAX, imax);
        }
        return MAX;
    }
};
