// Created by 邢思远 on 2021/8/10 5:08 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
题目描述:
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：
对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：
输入：s = "a", t = "a"
输出："a"

解题思路: 双指针 + 滑动窗口

*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_char2count, s_char2count;
        string res;
        int count = 0;
        for (auto p : t) {
            t_char2count[p]++;
        }
        int i = 0, j = 0;
        while (j < s.length()) {
            s_char2count[s[j]]++;
            if (s_char2count[s[j]] <= t_char2count[s[j]]) {
                count++;
            }

            while (count == t.size() && s_char2count[s[i]] > t_char2count[s[i]]) {
                s_char2count[s[i]]--;
                i++;
            }
            if (count == t.length() && (res.empty() || j-i+1 < res.size())) {
                res = s.substr(i, j-i+1);
            }
            j++;
        }
        return res;
    }
};
