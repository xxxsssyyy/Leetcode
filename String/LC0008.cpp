// Created by xingsiyuan on 2021/2/25 15:48.
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
请你来实现一个myAtoi(string s)函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
函数myAtoi(string s) 的算法如下：
读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−2^31, 2^31− 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −2^31 的整数应该被固定为 −2^31 ，大于 2^31−1 的整数应该被固定为 2^31−1 。
返回整数作为最终结果。

输入： s = "42"
输出： 42

输入：s = "   -42"
输出：-42

输入：s = "4193 with words"
输出：4193

输入：s = "words and 987"
输出：0

输入：s = "-91283472332"
输出：-2147483648(由于 -91283472332 小于范围 [-2^31, 2^31 - 1] 的下界，最终结果被截断为 -2^31 = -2147483648 )

解题思路:
1.贪心写转换规则(处理空格、符号、数字)
2.有限状态机
*/

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        bool has_sign = false;
        bool has_num = false;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                // 不为前序无用空格
                if (has_num || has_sign) break;
            }
            else if (s[i] == '+' || s[i] == '-') {
                // 不在最前面出现符号
                if (has_num || has_sign) break;
                if (s[i] == '-') sign = -1;
                has_sign = true;
            }
            else if (s[i] < '0' || s[i] > '9') {
                break;
            }
            else {
                has_num = true;
                // 判断是否越界
                int k = s[i] - '0';
                //cout << k << " " << res << " " << (INT_MAX - k) / 10 << endl;

                if (res > INT_MAX/10 || (res == INT_MAX/10 && s[i] > '7')) {
                    // 判断下一次计算是否会越界
                    return sign == 1 ? INT_MAX : INT_MIN;
                }

                res = res * 10 + k;
            }
        }
        return res*sign;
    }
};

int main() {
    Solution sol;
    int a = sol.myAtoi("   -42");
    cout << a << endl;
    return 0;
}
