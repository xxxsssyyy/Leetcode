// Created by 邢思远 on 2021/8/2 10:04 上午.
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
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
一个字符串的子序列是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

示例 1：
输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace" ，它的长度为 3 。

示例 3：
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。

解题思路:
    dp[i][j]表示 text1前i个字符 和 text2前j个字符 的最长子序列长度
    if text1[i] == text2[j]:
        dp[i][j] = dp[i-1][j-1]+1
    else:
        dp[i][j] = max(dp[i-1][j], dp[i][j-1])
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int M = text1.length(), N = text2.length();
        vector<vector<int>> dp(M+1, vector<int> (N+1));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[M][N];
    }
};

