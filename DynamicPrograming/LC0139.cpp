// Created by 邢思远 on 2021/6/24 4:10 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*
题目描述:
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
说明：
1.拆分时可以重复使用字典中的单词。
2.你可以假设字典中没有重复的单词。

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

解题思路: 动态规划 dp[i] 表示s的前i位是否可以被组成 dp[i] = (dp[j] == 1), 用 unordered_set 保证每次 find 的时间复杂度为 O(1)

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // unordered_set 时间复杂度为 O(1)
        unordered_set<string> word_set;
        for (auto word : wordDict) word_set.insert(word);
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        // 复杂度O(n^2)
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] == 1 && word_set.find(s.substr(j, i-j)) != word_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << sol.wordBreak(s, wordDict) << endl;
    return 0;
}
