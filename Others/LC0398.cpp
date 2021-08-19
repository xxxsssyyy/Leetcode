// Created by xingsiyuan on 2021/3/2 21:30.
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
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。
注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。 空间O(1) 时间O(n)

输入： int[] nums = new int[] {1,2,3,3,3}
输出： pick(3), 输出2, 3, 4的概率均为1/3

解题思路:
蓄水池抽样：从N个元素中随机的等概率的抽取k个元素，其中N无法确定。
从N中随机取k的问题： https://zhuanlan.zhihu.com/p/84556091
 这道题是从N中随机取一个的问题
*/

class Solution {
public:
    vector<int> nums_new;
    Solution(vector<int>& nums) {
        nums_new = nums;
    }

    int pick(int target) {
        int index = -1;
        int count = 0;
        for (int i = 0; i < nums_new.size(); i++) {
            if (nums_new[i] == target) {
                count++;
                int a = rand()%count;
                if (a == 0) {
                    index = i;
                }
            }
        }
        return index;
    }
};
