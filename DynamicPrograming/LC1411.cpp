// Created by xingsiyuan on 2021/3/8 16:17.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

/*
题目描述:

你有一个 n x 3 的网格图 grid ，你需要用 红，黄，绿 三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。
给你网格图的行数 n, 请你返回给 grid 涂色的方案数。由于答案可能会非常大，请你返回答案对 10^9 + 7 取余的结果

输入： 1
输出： 12

解题思路:
dp 思想: 把每行的格子排布分为两种情况, 一种为ABA形, 一种为ABC形
a[i]代表第i行为ABA形的数目, b[i]代表第i行为ABC形的数目
*/

class Solution {
private:
    int max = pow(10, 9) + 7;
public:
    int numOfWays(int n) {
        int a = 6, b = 6;
        for (int i = 2; i <= n; i++) {
            // LL是c11新特性, 代表类型为long long int
            int a_new = (3LL*a + 2LL*b) % max;
            int b_new = (2LL*a + 2LL*b) % max;
            a = a_new;
            b = b_new;
        }
        return (a+b) % max;
    }
};

