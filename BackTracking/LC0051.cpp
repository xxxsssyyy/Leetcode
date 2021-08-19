// Created by xingsiyuan on 2021/2/23 21:22.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*
题目描述:
n皇后问题 研究的是如何将 n个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的n皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
(!! 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。)

输入： n = 4
输出： [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

解题思路:
1.标准回溯算法: 时间复杂度O(N!), 空间O(N)
2.利用位运算优化 记录皇后信息的空间复杂度为O(1), 前提是 N 的位数低于int位数(4个字节 32位)

*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens(n, -1);
        unordered_set<int> columns;
        unordered_set<int> lines1, lines2;
        backtrack(res, queens, n, 0, columns, lines1, lines2);
        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<int>& queens, int n, int row, unordered_set<int>& columns,
                   unordered_set<int>& lines1, unordered_set<int>& lines2) {
        if (row == n) {
            vector<string> temp = generate_array(queens, n);
            res.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            // 判断列是否重叠
            if (columns.find(i) != columns.end()) {
                continue;
            }
            // 判断斜线是否重叠
            if (lines1.find(i+row) != lines1.end() || lines2.find(i-row) != lines2.end()) {
                continue;
            }
            columns.insert(i);
            lines1.insert(i+row);
            lines2.insert(i-row);
            queens[row] = i;
            backtrack(res, queens, n, row+1, columns, lines1, lines2);
            columns.erase(i);
            lines1.erase(i+row);
            lines2.erase(i-row);
            queens[row] = -1;
        }
    }

    vector<string> generate_array(vector<int> queens, int n) {
        vector<string> ret;
        for (auto p : queens) {
            string temp(n, '.');
            temp[p] = 'Q';
            ret.push_back(temp);
        }
        return ret;
    }
};


int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> res = sol.solveNQueens(n);
    for (int i = 0; i < res.size(); i++) {
        for (auto strs : res[i]) {
            cout << strs << endl;
        }
        cout << endl;
    }

    return 0;
}