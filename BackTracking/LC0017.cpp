// Created by xingsiyuan on 2021/3/3 18:19.
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
给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入： digits = "23"
输出： ["ad","ae","af","bd","be","bf","cd","ce","cf"]

解题思路:
1.返回所有可能组合，判定为枚举法，并且需要进行回溯

*/

class Solution {
private:
    unordered_map<char, vector<char>> num2chars = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
    };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> res;
        string temp = "";
        dfs(res, digits, temp, 0);
        return res;
    }
    void dfs(vector<string>& res, string digits, string& temp, int i) {
        if (i == digits.length()) {
            res.push_back(temp);
            return;
        }
        vector<char> tt = num2chars[digits[i]];
        for (int j = 0; j < tt.size(); j++) {
            temp.push_back(tt[j]);
            dfs(res, digits, temp, i+1);
            // 回溯
            temp.pop_back();
        }
    }
};