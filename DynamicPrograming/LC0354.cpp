// Created by xingsiyuan on 2021/3/10 19:13.
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
给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
注意：不允许旋转信封。

输入： envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出： 3
解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

解题思路:
1.动态规划 把问题转化为 两个维度的最长严格递增子序列的长度
 首先将一个维度固定(比如将宽度固定) dp[i] 表示以第i个信封结尾的最大升序数组长度

2. plus: 最开始想的一个naive错误的方法,
    贪心策略: 首先对所有信封从小到大排序, 每次挑选相同宽度, 高度满足题意最小的(这种方法会导致 [4, 300]这种数阻碍了后面宽度小的一群数)
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0) {
            return 0;
        }
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n+1, 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                // 两个维度上严格递增
                if (envelopes[j-1][0] < envelopes[i-1][0] && envelopes[j-1][1] < envelopes[i-1][1])
                   dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

};

int main() {
    Solution sol;
    int T;
    /*
    cin >> T;
    while (T--) {
        int L;
        cin >> L;
        vector<vector<int>> envelopes(L);
        for (int i = 1; i <= L; i++) {
            int temp;
            cin >> temp;
            envelopes[i-1].push_back(temp);
        }
        for (int i = 1; i <= L; i++) {
            int temp;
            cin >> temp;
            envelopes[i-1].push_back(temp);
        }
        cout << sol.maxEnvelopes(envelopes);
    }
     */
    vector<vector<int>> envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    cout << sol.maxEnvelopes(envelopes);
    return 0;
}

