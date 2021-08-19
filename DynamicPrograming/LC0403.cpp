// Created by xingsiyuan on 2021/3/10 9:31.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_set>
#include<set>
using namespace std;

/*
题目描述:
一只青蛙想要过河。 假定河流被等分为x个单元格，并且在每一个单元格内都有可能放有一石子（也有可能没有）。 青蛙可以跳上石头，但是不可以跳入水中。
给定石子的位置列表（用单元格序号升序表示），请判定青蛙能否成功过河（即能否在最后一步跳至最后一个石子上）。开始时，青蛙默认已站在第一个石子上，并可以假定它第一步只能跳跃一个单位（即只能从单元格1跳至单元格2）。
如果青蛙上一步跳跃了k个单位，那么它接下来的跳跃距离只能选择为k - 1、k或k + 1个单位。另请注意，青蛙只能向前方（终点的方向）跳跃。

请注意：
1.石子的数量 ≥ 2 且< 1100；
2.每一个石子的位置序号都是一个非负整数，且其 < 2^31；
3.第一个石子的位置永远是0。

输入：[0,1,3,5,6,8,12,17]
输出：true

解题思路:
 1. 动态规划 dp[i] 表示i的位置维护一个set, 表示从上一步到达此步使用的步数, 最终返回dp[stones[stones.size()-1]]的位置set是否为空即可, 时间复杂度不超过O(n^2)

*/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int numstone = stones.size();
        int n = stones[numstone-1];

        if ((1+numstone)*numstone / 2 < n) return false;
        vector<unordered_set<int>> loc_steps(n+1);

        loc_steps[1].insert(1);
        for (int i = 1; i < numstone; i++) {
            for (auto k : loc_steps[stones[i]]) {
                if (stones[i]+k+1 <= n) {
                    loc_steps[stones[i]+k+1].insert(k+1);
                    //cout << stones[i] << " insert to " <<  stones[i] + k + 1 << endl;
                }

                if (stones[i]+k <= n) {
                    loc_steps[stones[i]+k].insert(k);
                    //cout << stones[i] << " insert to " <<  stones[i] + k << endl;
                }
                if (k > 1 && stones[i]+k-1 <= n) {
                    loc_steps[stones[i]+k-1].insert(k-1);
                    //cout << stones[i] << " insert to " <<  stones[i] + k - 1 << endl;
                }

            }
        }
        return !loc_steps[n].empty();
    }


};

int main() {
    vector<int> input_array;
    int num;

    while (1) {
        cin >> num;
        input_array.push_back(num);
        if (cin.get() == '\n')		break;		//读完数字读间隔符（空格、回车），遇回车结束
        //if (getchar() == '\n')		break;
    }

    //vector<int> nums = {0, 1, 3, 5, 6, 8, 12, 17};
    Solution sol;
    cout << sol.canCross(input_array);
    return 0;
}

