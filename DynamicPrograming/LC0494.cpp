// Created by 邢思远 on 2021/8/3 2:13 下午.
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
给你一个整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加'+' 或 '-' ，然后串联起所有整数，可以构造一个表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

示例 1：
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

示例 2：
输入：nums = [1], target = 1
输出：1

解题思路:
 (1) 目标和 = x - y (x为正数和, y为负数和) (2) 总和 = x + y
 上面式子转化为 (目标和+总和)/2 = x
 因此问题转化为nums数组0-1背包可以组成x的组合个数

 dp[i][j] 表示前i个数 组成和为j的组合个数
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (target > sum || (sum + target) % 2 == 1) {
            return 0;
        }
        int n = (sum + target) / 2;
        vector<vector<int>> dp(nums.size()+1, vector<int> (n+1, 0));

        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i-1][j];
                if (j - nums[i-1] >= 0) {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }

            }
        }

        return dp[nums.size()][n];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    cout << sol.findTargetSumWays() << endl;
    return 0;
}
