// Created by xingsiyuan on 2021/3/10 14:25.
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
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组nums中。
现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。这里的 i - 1 和 i + 1 代表和i相邻的两个气球的序号。
如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
求所能获得硬币的最大数量。

输入： nums = [3,1,5,8]
输出： 167
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5 + 3*5*8 + 1*3*8 + 1*8*1 = 167

解题思路:
 1.区间dp  dp[i][j]是指开区间(i, j)所能获得硬币的最大数量 dp[i][j] = max(nums[i]*nums[k]*nums[j]+dp[i][k]+dp[k][j]);  k from i+1 to j-1
    时间复杂度为O(n^3)
*/

/**
 * dp版本代码，最外层的循环，i为什么是n-1 -> 0，而不能反过来？
 * (i,j) 0 1  2   3   4   ...   n-2   n-1   n   n+1
 * 0     0 1  2   3   4   ...                   n+1
 * 1       1  2   3   4   ...                   n+1
 * 2          2   3   4   ...                   n+1
 * 3              3   4   ...                   n+1
 * 4                  4                         n+1
 * .                      .                     .
 * .                         .                  .
 * n-2                          n-2   n-1   n   n+1
 * n-1                                n-1   n   n+1
 * n
 * n+1
 *
 * 须从下往上算，即先算dp[n-1][n+1]：
 * 根据递推关系，算dp[i][j]时依赖的dp[i][k]和dp[k][j]，其中i<k<j。
 * 1、如果从上往下计算，依赖的dp[k][j]根本就还未算出（k比i大），比如算dp[0][3]时，依赖的dp[1][3]还是个未知数。
 * 2、从下往上就不一样，算dp[i][j]时，依赖的dp[i][k]，位于同一行左侧，已计算过；
 *                                    依赖的dp[k][j]，因为k>i，位于更下面的行，也已计算过。
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // 插入两个哨兵
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+2; j <= n+1; j++) {
                for (int k = i+1; k < j; k++) {
                    int temp = nums[i]*nums[k]*nums[j]+dp[i][k]+dp[k][j];
                    dp[i][j] = max(dp[i][j], temp);
                }
            }
        }
        return dp[0][n+1];
    }
};
