// Created by 邢思远 on 2021/8/1 6:51 下午.
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
给定一个二叉树的根节点 root，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。

解题思路:
 1.从每一个节点开始进行dfs, 时间复杂度为O(n^2)
 2.前缀和: 路径和=targetsum 一定是当前节点到根节点的和 减去 路径中一个节点到根节点的和为targetsum, 用一个unordered_map 保存，key = 前缀和, value = 出现次数
          实现上要进行回溯
*/

class Solution {
private:
    int res = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return res;
    }
    void dfs(TreeNode* node, int temp) {
        if (temp == node->val) {
            res++;
        }
        if (node->left) {
            dfs(node->left, temp - node->val);
        }
        if (node->right) {
            dfs(node->right, temp - node->val);
        }
    }
};
