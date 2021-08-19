// Created by 邢思远 on 2021/6/28 8:50 下午.
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
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：4

输入：matrix = [["0","1"],["1","0"]]
输出：1

解题思路:
 1. 暴力方法: 时间复杂度太高了
 2. 动态规划方法: dp[i][j]表示以其为右下角的最大正方形边长, 最终输出dp矩阵中最大的值
    dp[i][j] = 0 if matrix[i][j] == 0
    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // O(n^4) 复杂度太高了
        int m = matrix.size(), n = matrix[0].size();
        int l = min(m, n);
        for (int k = l; k >= 1; k--) {
            for (int i = 0; i <= m-k; i++) {
                for (int j = 0; j <= n-k; j++) {
                    int temp = 0;
                    for (int a = i; a < i+k; a++) {
                        for (int b = j; b < j+k; b++) {
                            if (matrix[a][b] == '1')
                                temp += 1;
                        }
                    }
                    cout << temp << endl;
                    if (temp == k*k)
                        return temp;
                }
            }
        }
        return 0;
    }
    int maximalSquare_dp(vector<vector<char>>& matrix) {
        // 时间复杂度 O(n^2)
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        int max_L = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] == 0;
                }
                else if (i < 1 || j < 1) {
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                }
                else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                }
                cout << dp[i][j] << " ";
                max_L = max(max_L, dp[i][j]);
            }
            cout << endl;
        }
        return max_L*max_L;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << sol.maximalSquare_dp(matrix) << endl;
    return 0;
}