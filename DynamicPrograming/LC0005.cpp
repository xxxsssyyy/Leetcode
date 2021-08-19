// Created by xingsiyuan on 2021/2/24 18:44.
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
给你一个字符串 s，找到 s 中最长的回文子串。

输入： s = "babad"
输出： "bab" ("aba" 同样是符合题意的答案。)

解题思路:
1.动态规划 O(N^2), 空间O(N^2)
2.中心扩展法 O(N^2), 空间O(1)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        string res = s.substr(0, 1);
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (j - i == 1 && s[i] == s[j]) {
                    dp[i][j] = true;
                }
                else if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                }
                else {
                    dp[i][j] = false;
                }
                if (dp[i][j] && res.length() < j-i+1) {
                    res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
    // 中心扩展法
    string longestPalindrome2(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            pair<int, int> p1 = ExpendFromCenter(s, i, i);
            pair<int, int> p2 = ExpendFromCenter(s, i, i+1);
            if (p1.second - p1.first > right - left) {
                left = p1.first;
                right = p1.second;
            }
            if (p2.second - p2.first > right - left) {
                left = p2.first;
                right = p2.second;
            }
        }
        return s.substr(left, right-left+1);
    }

    pair<int, int> ExpendFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left+1, right-1}; // return make_pair(left, right);
    }
};

int main() {

}