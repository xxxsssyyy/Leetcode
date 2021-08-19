// Created by 邢思远 on 2021/7/29 11:58 上午.
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
给定一个包含n + 1 个整数的数组nums ，其数字都在 1 到 n之间（包括 1 和 n），可知至少存在一个重复的整数。
假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。
你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。

输入：nums = [1,3,4,2,2]
输出：2

输入：nums = [3,1,3,4,2]
输出：3

解题思路:
 抽屉原理 + 二分法
 假设重复的数是i, 则count(nums[k] <= i) > i
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (auto p: nums) {
                if (p <= mid) {
                    count++;
                }
            }
            if (count <= mid) { // 在右边
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
