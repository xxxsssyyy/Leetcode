// Created by 邢思远 on 2021/6/25 3:47 下午.
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
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
进阶：
你可以在O(nlogn) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

输入：head = [4,2,1,3]
输出：[1,2,3,4]

输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

解题思路: 归并排序

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || head->next == NULL) {
            return head;
        }
        // 快慢指针
        ListNode *p1 = head, *p2 = head;
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        // 剪链
        p2 = p1->next;
        p1->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(p2);
        ListNode *p = merge_sort(left, right);
        return p;
    }
    ListNode* merge_sort(ListNode* p1, ListNode* p2) {
        ListNode* t = new ListNode(0);
        ListNode  *temp = t;
        while (p1 && p2) {
            if (p1->val >= p2->val) {
                temp->next = p2;
                p2 = p2->next;
                temp = temp->next;
            }
            else {
                temp->next = p1;
                p1 = p1->next;
                temp = temp->next;
            }
        }
        temp->next = p1 ? p1 : p2;
        return t->next;
    }
};
