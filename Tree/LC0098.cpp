// Created by xingsiyuan on 2021/3/4 11:33.
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
给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
1.节点的左子树只包含小于当前节点的数。
2.节点的右子树只包含大于当前节点的数。
3.所有左子树和右子树自身必须也是二叉搜索树。


输入： [5,1,4,null,null,3,6】
输出： false

解题思路:

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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode *node, long int lower, long int upper) {
        if (!node) {
            return true;
        }
        if (node->val <= lower || node->val >= upper) {
            return false;
        }
        return (helper(node->left, lower, node->val) & helper(node->right, node->val, upper));
    }
};
