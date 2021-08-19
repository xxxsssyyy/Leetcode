// Created by 邢思远 on 2021/6/24 5:32 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
题目描述:
根据一棵树的前序遍历与中序遍历构造二叉树。(可以假设树中没有重复的元素)

例如，给出
前序遍历 preorder =[3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7

解题思路: 前序: 根左右  中序: 左根右
        unorderd_map 哈希表 降低时间复杂度为O(n): 快速定位index
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode *node = new TreeNode(preorder[0);
        int idx = 0;
        while (inorder[idx] != preorder[0])
            idx++;
        vector<int> L_pre(preorder.begin()+1, preorder.begin()+1+idx);
        vector<int> L_in(inorder.begin(), inorder.begin()+idx);
        node->left = helper(L_pre, L_in);
        vector<int> R_pre(preorder.begin()+1+idx, preorder.end());
        vector<int> R_in(inorder.begin()+idx+1, inorder.end());
        node->right = helper(R_pre, R_in);
        return node;
    }
    TreeNode* buildTree_hash(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> num2index;
        for (int i = 0; i < preorder.size(); i++) {
            num2index[inorder[i]] = i;
        }
        int n = preorder.size();
        return help(preorder, inorder, 0, n-1, 0 ,n-1, num2index);
    }
    TreeNode* help(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right, unordered_map<int, int> num2index) {
        if (pre_left > pre_right) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_left]);
        int node_index = num2index[preorder[pre_left]];
        int left_length = node_index - in_left;
        root->left = help(preorder, inorder, pre_left+1, pre_left+left_length, in_left, node_index-1, num2index);
        root->right = help(preorder, inorder, pre_left+left_length+1, pre_right, node_index+1, in_right, num2index);
        return root;
    }

};

