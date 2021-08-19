// Created by xingsiyuan on 2021/3/10 10:59.
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
给你n笔订单，每笔订单都需要快递服务。
请你统计所有有效的 收件/配送 序列的数目，确保第 i 个物品的配送服务delivery(i) 总是在其收件服务pickup(i) 之后。
由于答案可能很大，请返回答案对 10^9 + 7 取余的结果。

输入： n = 2
输出： 6
所有可能的序列包括：
(P1,P2,D1,D2)，(P1,P2,D2,D1)，(P1,D1,P2,D2)，(P2,P1,D1,D2)，(P2,P1,D2,D1) 和 (P2,D2,P1,D1)。
(P1,D2,P2,D1) 是一个无效的序列，因为物品 2 的收件服务（P2）不应在物品 2 的配送服务（D2）之后。

解题思路:
 1.递推的想法, dp[i]表示有i个物品的排列数目。 从dp[i-1]到dp[i]相当于在原来 2i-2个数字中插入两个数字, 并保持顺序正确


*/

class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9+7;
        long dp = 1;
        for (int i = 2; i <= n; i++) {
            dp = ((2*i-1)*i*dp) % mod;
        }
        return dp;
    }
};

