// Created by xingsiyuan on 2021/2/24 9:44.
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
给定一个大小为n的整数数组，找出其中所有出现超过 n/3 次的元素。
进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。


输入： [1,1,1,3,3,2,2,2]
输出： [1,2]

解题思路:
1.哈希表, 时间复杂度 O(n), 空间O(n)
2.贪心(投票法), 时间复杂度 O(n), 空间O(1), 任意一个数组出现次数大于 n/3 的众数最多有两个

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        map<int, int> num2fre;
        for (auto n : nums) {
            num2fre[n]++;
        }
        for (auto p : num2fre) {
            if (p.second > nums.size()/3) {
                res.push_back(p.first);
            }
        }
        return res;
    }

    vector<int> majorityElement2(vector<int>& nums) {
        vector<int> res;
        int a = 0, b = 0, na = 0, nb = 0;
        for (auto i : nums) {
            if (i == a) {
                na++;
            }
            else if (i == b) {
                nb++;
            }
            else if (na == 0) {
                a = i;
                na += 1;
            }
            else if (nb == 0) {
                b = i;
                nb += 1;
            }
            else {
                na--;
                nb--;
            }
        }
        na = 0, nb = 0;
        for (auto i : nums) {
            if (i == a) na++;
            else if (i == b) nb++; // 必须用else if保证每个数只算到一个候选人头上
        }
        if (na > nums.size()/3) {
            res.push_back(a);
        }
        if (nb > nums.size()/3) {
            res.push_back(b);
        }
        return res;
    }
};