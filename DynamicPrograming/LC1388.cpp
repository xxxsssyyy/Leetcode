// Created by xingsiyuan on 2021/3/10 16:43.
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
给你一个披萨，它由 3n 块不同大小的部分组成，现在你和你的朋友们需要按照如下规则来分披萨：
你挑选 任意一块披萨。Alice 将会挑选你所选择的披萨逆时针方向的下一块披萨。
Bob 将会挑选你所选择的披萨顺时针方向的下一块披萨。重复上述过程直到没有披萨剩下。
每一块披萨的大小按顺时针方向由循环数组 slices表示。
请你返回你可以获得的披萨大小总和的最大值。

输入： slices = [1,2,3,4,5,6]
输出： 10
解释：选择大小为 4 的披萨，Alice 和 Bob 分别挑选大小为 3 和 5 的披萨。然后你选择大小为 6 的披萨，Alice 和 Bob 分别挑选大小为 2 和 1 的披萨。你获得的披萨总大小为 4 + 6 = 10 。

解题思路:
 1. 需要证明 这种分披萨的方法 和 在任意一种在长度为3n的环状序列上选择n个不相邻数的方法 是等价的
    动态规划 dp[i][j]表示前i个部分中选取j个部分获得披萨大小总和的最大值
    这个题目是环形的, 因此第一个披萨和最后一个披萨不能同时选取转化为从 2~3n 和从 1~3n-1两个中的最大值
    dp[i][j] = max(dp[i-1][j], dp[i-2][j-1]+slices[i-1])
    不拿第j个 和 拿第j个 两种情况的最大值
*/

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        vector<int> v1(slices.begin()+1, slices.end());
        vector<int> v2(slices.begin(), slices.end()-1);
        return max(MaxSumInArray(v1), MaxSumInArray(v2));
    }
    int MaxSumInArray(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp(n+1, vector<int>((n+1)/3+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= (n+1)/3; j++) {
                dp[i][j] = max(dp[i-1][j], dp[max(i-2, 0)][j-1]+slices[i-1]);
            }
        }
        return dp[n][(n+1)/3];
    }
};
