// Created by xingsiyuan on 2021/3/5 18:19.
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
给你一个链表数组，每个链表都已经按升序排列。 请你将所有链表合并到一个升序链表中，返回合并后的链表。

输入： lists = [[1,4,5],[1,3,4],[2,6]]
输出： [1,1,2,3,4,4,5,6]

解题思路:
1. 借鉴两个链表合并
2. 使用优先队列的方法， 时间复杂度为 O(nlogk) ， n为链表中节点的个数
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 小根堆回调函数, 优先队列默认为从大到小
    struct cmp{
        bool operator()(ListNode* a, ListNode *b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* p = new ListNode(1);
        ListNode* res = p;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (auto l : lists) {
            if (l) q.push(l);
        }
        while (!q.empty()) {
            ListNode* node = q.top();
            p->next = node;
            p = p->next;
            q.pop();
            if (node->next) {
                q.push(node->next);
            }
        }
        return res->next;
    }
};

int main() {
    Solution sol;
    vector<ListNode*> a = {};
    ListNode *p = sol.mergeKLists(a);

    return 0;
}
