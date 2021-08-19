// Created by 邢思远 on 2021/6/29 9:19 上午.
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
给你一个长度为n的整数数组nums，其中n > 1，返回输出数组output，其中 output[i]等于nums中除nums[i]之外其余各元素的乘积。

输入: [1,2,3,4]
输出: [24,12,8,6]

解题思路:
 left[i]表示第i个元素左边数字的乘积, right[i]表示第i个元素右边数字的乘积
 left[i] = left[i-1]*nums[i]

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1]*nums[i-1];
        }
        for (int i = n-2; i >= 0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }
        for (int i = 0; i < n; i++) {
            left[i] = left[i] * right[i];
        }
        return left;
    }
};
