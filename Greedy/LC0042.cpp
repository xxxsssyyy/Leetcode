// Created by xingsiyuan on 2021/2/26 15:15.
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
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

输入： height = [4,2,0,3,2,5]
输出： 9

解题思路:
审题: 总雨水
1. 贪心算法+左右双扫描: 每个槽位所存储的水量取决于其两侧最高柱子中最小的那个
left[i]表示索引i左边的最高高度, right[i]表示右边
left[i] = max(left[i-1], height[i-1])

2. 不借助额外空间: 双指针法
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i-1]);
        }
        for (int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i+1]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            count = count + max(0, min(left[i], right[i])-height[i]);
        }
        return count;
    }

    int trap2(vector<int>& height) {
        int left = 0, right = height.size()-1, left_max = 0, right_max = 0;
        int count;
        while (left <= right) {
            if (left_max > right_max) {
                count = count + max(0, right_max - height[right]);
                right_max = max(right_max, height[right]);
                right--;
            }
            else {
                count = count + max(0, left_max - height[left]);
                left_max = max(left_max, height[left]);
                left++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap2(nums) << endl;
    return 0;
}