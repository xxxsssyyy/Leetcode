// Created by 邢思远 on 2021/8/9 6:05 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool cmp(vector<int>& p1, vector<int>& p2) {
    return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto p: intervals) {
            cout << p[0] << " " << p[1] << endl;
        }
        int count = 0;
        int i = 0;
        while (i < intervals.size()) {
            count++;
            int j = i+1;
            while (j < intervals.size() && intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]) {
                j++;
            }
            i = j;
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {{1,2},{1,4},{3,4}};
    cout << sol.removeCoveredIntervals(intervals) << endl;
    return 0;
}
