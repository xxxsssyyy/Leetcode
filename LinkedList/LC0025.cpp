// Created by xingsiyuan on 2021/2/23 14:07.
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
给你一个链表，每k个节点一组进行翻转，请你返回翻转后的链表。
k是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。

输入： 1->2->3->4->5, 2
输出： 2->1->4->3->5

解题思路: 按k反转链表, 然后接上即可


*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k < 0) {
            return head;
        }
        ListNode* pre = NULL;
        ListNode* aft;
        int count = 0;
        ListNode* ret = new ListNode(100), *temp = ret;

        while (head) {
            aft = head->next;
            head->next = pre;
            pre = head;
            head = aft;
            count++;
            //cout << count << endl;
            if (count == k) {
                //cout << "pre: " << pre->val << " temp: " << temp->val << endl;
                temp->next = pre;
                while (count > 0) {
                    temp = temp->next;
                    count--;
                    //cout << temp->val << endl;
                }
                pre = NULL;
            }
        }
        // 剩余再翻转回来
        head = pre;
        pre = NULL;
        while (head) {
            aft = head->next;
            head->next = pre;
            pre = head;
            head = aft;
        }
        temp->next = pre;
        return ret->next;
    }
};

int main() {
    Solution sol;
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);
    ListNode *p7 = new ListNode(7);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    ListNode *x = sol.reverseKGroup(p1, 4);
    while (x) {
        cout << x->val << " ";
        x = x->next;
    }
    cout << endl;
    return 0;
}