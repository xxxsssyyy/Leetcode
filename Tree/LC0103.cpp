// Created by xingsiyuan on 2021/3/4 11:10.
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
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

输入： [3,9,20,null,null,15,7]
输出： [
  [3],
  [20,9],
  [15,7]
]

解题思路:
 1.宽度优先搜索+翻转标志

*/


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            vector<int> temp;
            depth++;
            int k = q.size();
            while (k > 0) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                k--;
            }
            if (depth % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};