// Created by xingsiyuan on 2021/3/8 15:59.
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
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

输入： head = [1,2,3,4]
输出： [2,1,4,3]

解题思路:
1.双指针swap

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *ret = new ListNode(-1);
        ret->next = head;
        ListNode *pre = ret, *a1, *a2;
        while (head) {
            if (!head->next) {
                pre->next = head;
                break;
            }
            a1 = head->next;
            a2 = a1->next;
            pre->next = a1;
            a1->next = head;
            head->next = a2;
            pre = head;
            head = a2;
        }
        return ret->next;

    }
};
