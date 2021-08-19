// Created by 邢思远 on 2021/6/22 4:10 下午.
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
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

输入： 二叉树 [1,2,2,3,4,4,3]
输出： 1

输入： 二叉树 [1,2,2,null,3,null,3]
输出： 0
解题思路:
 对称问题，用两个指针比较区思考
 1. 递归，以指针形式考虑, 举例: 左侧指针的左 与 右侧指针的右 进行比较
 2. 循环

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric_circulation(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> qe;
        qe.push(root->left);
        qe.push(root->right);
        while (!qe.empty()) {
            TreeNode* p = qe.front(); qe.pop();
            TreeNode* q = qe.front(); qe.pop();
            if (!p && !q) continue;
            if ((!p || !q) || (p->val != q->val)) return false;
            qe.push(p->left);
            qe.push(q->right);
            qe.push(p->right);
            qe.push(q->left);
        }
        return true;
    }
};


