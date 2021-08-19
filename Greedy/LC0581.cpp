// Created by 邢思远 on 2021/8/3 11:39 上午.
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
给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
请你找出符合题意的 最短 子数组，并输出它的长度。

示例 1：
输入：nums = [2,6,4,8,10,9,15]
输出：5
解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

示例 2：
输入：nums = [1,2,3,4]
输出：0

解题思路: 贪心：从左边找第一个存在右边有比当前数大的位置, 从右边找第一个存在左边比当前数小的位置

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int right_min = 10e5+1;
        int left_max = -10e5-1;

        int left = 0, right = 0;
        for (int i = n-1; i >= 0; i--) {
            right_min = min(right_min, nums[i]);
            if (nums[i] > right_min) {
                left = i;
            }
        }
        for (int i = 0; i < n; i++) {
            left_max = max(left_max, nums[i]);
            if (nums[i] < left_max) {
                right = i;
            }
        }

        return right - left + 1;

    }
};

int main() {
    Solution sol;
    // vector<int> nums = {2,6,4,8,10,9,15};
    vector<int> nums = {};
    cout << sol.findUnsortedSubarray(nums) << endl;
    return 0;
}
