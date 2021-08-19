// Created by 邢思远 on 2021/6/28 2:20 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

/*
题目描述:
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
解题思路:
 1. 堆排序，建立一个K大小的小根堆
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int K = 4;
    cout << sol.findKthLargest(nums, K) << endl;
    return 0;
}
