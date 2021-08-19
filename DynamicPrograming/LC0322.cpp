// Created by 邢思远 on 2021/7/28 10:59 上午.
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
给你一个整数数组 coins，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回-1 。
你可以认为每种硬币的数量是无限的。

输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1

输入：coins = [2], amount = 3
输出：-1

解题思路: 动态规划

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int Max = amount+1;
        vector<int> dp(amount+1, Max);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= coins[j-1]) // 注意这里j-1
                    dp[i] = min(dp[i], dp[i-coins[j-1]]+1);
            }
        }
        return dp[amount] == Max ? -1 : dp[amount];
    }
};
