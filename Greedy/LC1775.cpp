// Created by xingsiyuan on 2021/2/28 11:09.
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
给你两个长度可能不等的整数数组nums1 和nums2。两个数组中的所有值都在1到6之间（包含1和6）。
每次操作中，你可以选择 任意数组中的任意一个整数，将它变成 1到 6之间 任意的值（包含 1和 6）。
请你返回使 nums1中所有数的和与nums2中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 -1。

输入： nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
输出： 3

解题思路:
1.贪心算法：对两个数组的可增加量和可减少量进行排序，按照排序进行(可以统一排序也可以用双指针法)

*/

bool compare(int a, int b) {
    return b < a;
}
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        if (l1*6 < l2 || l2*6 < l1) {
            return -1;
        }
        int sum = 0;
        for (auto p : nums1) {
            sum += p;
        }
        for (auto p : nums2) {
            sum -= p;
        }
        vector<int> gaps;
        int count = 0;
        for (auto p : nums1) {
            if (sum > 0) {
                gaps.push_back(p-1);
            }
            else {
                gaps.push_back(6-p);
            }
        }
        for (auto p : nums2) {
            if (sum > 0) {
                gaps.push_back(6-p);
            }
            else {
                gaps.push_back(p-1);
            }
        }
        sort(gaps.begin(), gaps.end(), compare);
        for (auto a : gaps) {
            cout << a << " ";
        }
        cout << endl;

        sum = abs(sum);
        int i = 0;
        while (sum > 0 && i <= gaps.size()) {
            sum -= gaps[i];
            i += 1;
        }
        return i;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3,3,2,4,2,6,2};
    vector<int> nums2 = {6,2,6,6,1,1,4,6,4,6,2,5,4,2,1};
    cout << sol.minOperations(nums1, nums2) << endl;
    return 0;
}
