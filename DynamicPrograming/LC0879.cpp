// Created by xingsiyuan on 2021/3/9 13:57.
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
集团里有 n 名员工，他们可以完成各种各样的工作创造利润。
第i种工作会产生profit[i]的利润，它要求group[i]名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。
工作的任何至少产生minProfit 利润的子集称为盈利计划。并且工作的成员总数最多为 n 。
有多少种计划可以选择？因为答案很大，所以 返回结果模10^9 + 7的值。

输入： n = 5, minProfit = 3, group = [2,2], profit = [2,3]
输出： 2

解题思路:
1. 有多少种选择, 实际上是一个解集的问题
 动态规划, dp[i][j][k] 表示前i个方案, j个工人, 达到k的利益的方案数, 实际上也是一个0-1背包的问题
2. 维度压缩可以减少内存空间
*/

//
//

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int S = 0;
    for (auto p : profit) S += p;
    if (S < minProfit) return 0;
    vector<vector<vector<long>>> dp(group.size()+1, vector<vector<long>>(n+1, vector<long>(minProfit+1, 0)));
    // 什么都不需要就满足题解
    for (int i = 0; i <= group.size(); i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j][0] = 1;
        }
    }

    for (int i = 1; i <= group.size(); i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= minProfit; k++) {
                // 对第i个方案有选与不选两种选择
                dp[i][j][k] = dp[i-1][j][k];
                // 选第i个方案要满足能达到第i个方案需要的人数
                if (j >= group[i-1])
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-group[i-1]][max(k-profit[i-1], 0)])%1000000007;

            }
        }
    }

    return dp[group.size()][n][minProfit];
}


int main() {
    int m, n, minProfit, T;
    cin >> T;
    while (T--) {
        cin >> m >> n >> minProfit;
        vector<int> group, profit;
        for (int i = 1; i <= m; i++) {
            int temp;
            cin >> temp;
            group.push_back(temp);
        }
        for (int i = 1; i <= m; i++) {
            int temp;
            cin >> temp;
            profit.push_back(temp);
        }
        cout << profitableSchemes(n, minProfit, group, profit);
    }
    return 0;
}