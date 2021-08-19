// Created by 邢思远 on 2021/7/29 3:15 下午.
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
给你二叉树的根结点 root ，请你将它展开为一个单链表：
1. 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
2. 展开后的单链表应该与二叉树 先序遍历 顺序相同。


输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]

解题思路:
 要求空间复杂度为O(1)
 找左子树最右面的节点(排在最后的), 这个节点的右指针指向根的右子节点, 这样循环下去
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left != NULL) {
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;

            }
            curr = curr->right;
        }
    }
};
