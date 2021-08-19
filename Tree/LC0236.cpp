// Created by xingsiyuan on 2021/3/4 13:48.
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
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

输入： root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出： 3(解释：节点 5 和节点 1 的最近公共祖先是节点 3 。)

解题思路:
 1. BFS宽度优先搜索：遍历每个字节，判断是不是给定两个节点的公共跟，从上往下走 , 这样做有一个问题是时间复杂度为O(n^2)
 2. 思考用dfs能不能不重复判断是否为跟节点, 而是从下往上逐渐递归
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;
        queue<TreeNode*> tt;
        tt.push(root);
        while (!tt.empty()) {
            int k = tt.size();
            while (k > 0) {
                TreeNode* node = tt.front();
                tt.pop();
                if (isAncestor(node, p) & isAncestor(node, q)) {
                    res = node;
                    if (node->left) tt.push(node->left);
                    if (node->right) tt.push(node->right);
                }
                k--;
            }
        }
        return res;
    }

    bool isAncestor(TreeNode* root, TreeNode *p) {
        if (!root) {
            return false;
        }
        if (root == p) {
            return true;
        }
        return (isAncestor(root->left, p) | isAncestor(root->right, p));
    }
};

class Solution2 {
public:
    // dfs 的方法
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }
        // 因为是递归，使用函数后可认为左右子树已经算出结果
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) {
            return root;
        }
        if (!left) return right;
        if (!right) return left;
        return NULL;
    }
};
