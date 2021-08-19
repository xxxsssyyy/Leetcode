// Created by xingsiyuan on 2021/3/3 16:59.
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
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了旋转，使数组变为
 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始计数）。
 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为[4,5,6,7,0,1,2] 。

给你旋转后的数组 nums 和一个整数 target ，如果nums中存在这个目标值target，则返回它的索引，否则返回-1。



输入： nums = [4,5,6,7,0,1,2], target = 0
输出： 4

解题思路:

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 左面有序
            if (nums[left] <= nums[mid]) {
                // C++中表达式中大于小于不能一起写
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
            // 右边有序
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {3,1};
    cout << sol.search(nums, 1) << endl;
    return 0;
}