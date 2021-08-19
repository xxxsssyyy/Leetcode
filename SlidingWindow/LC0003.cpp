// Created by xingsiyuan on 2021/3/4 10:36.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<map>
using namespace std;

/*
题目描述:
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

输入： s = "abcabcbb"
输出： 3

解题思路:
 1.窗口滑动, index标记不重复的位置, max_length不断更新最优解, 用哈希表存储字符上一个位置

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int index = 0;
        map<char, int> char2index;

        for (int i = 0; i < s.length(); i++) {
            // 有这个字符
            if (char2index.count(s[i]) && char2index[s[i]]+1 >= index) {
                index = char2index[s[i]]+1;
            }
            char2index[s[i]] = i;
            max_length = max(max_length, i-index+1);
            //cout << index << " " << max_length << endl;
        }
        return max_length;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abba") << endl;
    return 0;
}
