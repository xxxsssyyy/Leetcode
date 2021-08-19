// Created by 邢思远 on 2021/6/29 5:11 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;

/*
题目描述:
给定正整数 n，找到若干个完全平方数（比如1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

输入：n = 12
输出：3
解释：12 = 4 + 4 + 4

输入：n = 13
输出：2
解释：13 = 4 + 9

解题思路:
 动态规划: dp[i]表示正整数 i 由完全平方数组成的最少数量
         dp[i] = 1 + min(dp[i-j*j]) for j in [1, sqrt(i)]

*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int h = sqrt(i);
            int temp = INT_MAX;
            for (int j = 1; j <= h; j++) {
                temp = min(temp, dp[i-j*j] + 1);
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};
