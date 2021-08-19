// Created by xingsiyuan on 2021/2/28 10:39.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

/*
题目描述:
你打算做甜点，现在需要购买配料。目前共有 n 种冰激凌基料和 m 种配料可供选购。而制作甜点需要遵循以下几条规则：
1.必须选择 一种 冰激凌基料。
2.可以添加 一种或多种 配料，也可以不添加任何配料。
3.每种类型的配料 最多两份 。

给你以下三个输入：
baseCosts ，一个长度为 n 的整数数组，其中每个 baseCosts[i] 表示第 i 种冰激凌基料的价格。
toppingCosts，一个长度为 m 的整数数组，其中每个 toppingCosts[i] 表示 一份 第 i 种冰激凌配料的价格。
target ，一个整数，表示你制作甜点的目标价格。
你希望自己做的甜点总成本尽可能接近目标价格 target 。

返回最接近 target 的甜点成本。如果有多种方案，返回成本相对较低 的一种。

输入： baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
输出： 17

解题思路:
1. dfs, 复杂度 O(3^n)
2. 背包问题
dp[i][j] 表示将前i件装入能否价格为j, 行按顺序更新, 可优化为 dp[j]
 */
class Solution {
private:
    int sums = 0;
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        sums = baseCosts[0];
        for (auto b : baseCosts) {
            dfs(toppingCosts, 0, target, b);
        }
        return sums;
    }

    void dfs(vector<int>& toppingCosts, int i, int target, int temp) {
        if (abs(temp - target) < abs(sums - target) || (abs(temp - target) == abs(sums - target) && temp < sums)) {
            sums = temp;
        }
        // 剪枝
        if (i >= toppingCosts.size() || temp - target > abs(sums - target)) {
            return;
        }

        dfs(toppingCosts, i+1, target, temp);
        dfs(toppingCosts, i+1, target, temp+toppingCosts[i]);
        dfs(toppingCosts, i+1, target, temp+2*toppingCosts[i]);
    }

    int closestCost2(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        toppingCosts.insert(toppingCosts.end(), toppingCosts.begin(), toppingCosts.end());
        int sum = 0;
        for (auto t: toppingCosts) {
            sum += t;
        }
        sum += *max_element(baseCosts.begin(), baseCosts.end());

        vector<bool> dp(sum+1, false);
        for (auto s :baseCosts)
            dp[s] = true;
        for (int i = 0; i < toppingCosts.size(); i++) {
            int num = toppingCosts[i];
            for (int j = sum; j >= num; j--) {
                dp[j] = dp[j] | dp[j-num];
            }
        }
        /*
        for (auto s : dp) {
            cout << s << " ";
        }
        cout << endl;
        */
        int gap = INT_MAX;
        int res = 0;
        for (int i = 1; i <= sum; i++) {
            if (dp[i] && abs(i-target) < gap) {
                res = i;
                gap = abs(i - target);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> baseCosts = {3};
    vector<int> toppingCosts = {2,5};
    int target = 9;
    cout << sol.closestCost2(baseCosts, toppingCosts, target) << endl;
    return 0;
}