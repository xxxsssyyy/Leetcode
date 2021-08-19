// Created by xingsiyuan on 2021/3/10 20:35.
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
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

解题思路:
1.动态规划, dp[i]表示以第i个数字结尾的最长上升子序列的长度, dp[i] = max (dp[k-1]+1)  if nums[i]>nums[k] for k from 1 to i-1
 时间复杂度为O(N^2)
    最终的返回值为 max(dp[i]) i from 1 to n
2. 贪心 + 二分查找
 维护一个数组 d[i]d[i]
 以输入序列 [0, 8, 4, 12, 2][0,8,4,12,2] 为例：
    第一步插入 0，d = [0]；
    第二步插入 8，d = [0, 8]；
    第三步插入 4，d = [0, 4]；
    第四步插入 12，d = [0, 4, 12]；
    第五步插入 2，d = [0, 2, 12]。

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // 初始值要都设定为1, 因为每个数组单独以自己结尾构成 长度为1 的升序序列
        vector<int> dp(n+1, 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i-1] > nums[j-1])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
