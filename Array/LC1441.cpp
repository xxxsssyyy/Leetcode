// Created by xingsiyuan on 2021/3/7 14:54.
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
给你一个目标数组 target 和一个整数 n。每次迭代，需要从 list = {1,2,3..., n} 中依序读取一个数字。
请使用下述操作来构建目标数组 target ：
Push：从 list 中读取一个新元素， 并将其推入数组中。
Pop：删除数组中的最后一个元素。
如果目标数组构建完成，就停止读取更多元素。
题目数据保证目标数组严格递增，并且只包含 1 到 n 之间的数字。

请返回构建目标数组所用的操作序列。
题目数据保证答案是唯一的。

输入：target = [1,3], n = 3
输出：["Push","Push","Pop","Push"]

解题思路: 规则处理

*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int j = 0, k = target.size();
        for (int i = 1; i <= n; i++) {
            if (j >= k) break;
            if (target[j] != i) {
                res.push_back("Push");
                res.push_back("Pop");
            }
            else {
                res.push_back("Push");
                j++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> target = {2,3,4};
    vector<string> res = sol.buildArray(target, 4);
    for (auto s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}