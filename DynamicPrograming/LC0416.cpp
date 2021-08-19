// Created by xingsiyuan on 2021/2/28 15:11.
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
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

输入： [1, 5, 11, 5]
输出： true (解释: 数组可以分割成 [1, 5, 5] 和 [11].)

解题思路:
1.动态规划, 转为为0,1背包问题, 先算一下总和, 然后对于一个数组, 每个元素都有选和不选的两种选择, 目标是使选的部分和为 总的一半 target/2
 创建dp[n][target/2]的数组 dp[i][j]表示前[0,..,i]的元素能够构成和为j的组合, 最后返回 dp[n][target/2]

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto s : nums) {
            sum += s;
        }
        if (sum % 2 == 1 || *max_element(nums.begin(), nums.end()) > sum/2) {
            return false;
        }
        vector<vector<bool>> dp(n, vector<bool>(sum/2+1, false));
        for (int i = 0; i<n; i++)
            dp[i][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum/2; j++) {
                if (j-nums[i] < 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][sum/2];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100};
    cout << sol.canPartition(nums) << endl;
    return 0;
}

