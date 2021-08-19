// Created by xingsiyuan on 2021/2/24 14:49.
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
给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入： l1 = [2,4,3], l2 = [5,6,4]
输出： [7,0,8] （解释：342 + 465 = 807.）

解题思路:


*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ret = new ListNode(1);
        ListNode *temp = ret;
        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            temp->next = new ListNode((carry+a+b) % 10);
            carry = (carry + a + b) / 10;
            temp = temp->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry) {
            temp->next = new ListNode(carry);
        }
        return ret->next;
    }
};
