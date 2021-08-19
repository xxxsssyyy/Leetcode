// Created by 邢思远 on 2021/6/23 7:40 下午.
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
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

输入： [3,9,20,null,null,15,7]
输出： [
        [3],
        [9,20],
        [15,7]
      ]

解题思路: 用队列存储

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty()) {
            int k = qe.size();
            vector<int> temp;
            while (k > 0) {
                TreeNode* node = qe.front();
                qe.pop();
                temp.push_back(node->val);
                if (node->left) qe.push(node->left);
                if (node->right) qe.push(node->right);
                k--;
            }
            res.push_back(temp);
        }
        return res;
    }
};
