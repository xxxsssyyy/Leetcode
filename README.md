## 链表
[23.合并K个升序链表](LinkedList/LC0023.cpp) :用优先队列    
[24.两两交换链表中的节点](LinkedList/LC0024.cpp)  
[25.K个一组翻转链表](LinkedList/LC0025.cpp)  
[138.复制带随机指针的链表](LinkedList/LC0138.cpp) :与剑指offer25相同  
[148.排序链表](LinkedList/LC0148.cpp) :归并排序     
  
## 排序
[215.数组中最大的第K个元素](Sort/LC0215.cpp)    
[347.前K个高频元素](Sort/LC0347.cpp) :取数据中topk频次的元素(哈希表+堆排序)     
[1288.删除被覆盖的区间](Sort/LC1288.cpp):按照第一个元素排序,第二个元素降序+贪心思想      

## 回溯与枚举
回溯法又叫尝试法，顾名思义，就是穷举所有可能的排列，看看那种排列符合答案，既然是穷举，那么回溯最原始的目的就是找到一个问题所有的解，
比如有多少种排列可能，有多少种子集，多少种组合情况等等。当然在我们只想找到一种答案时也可以修改部分代码实现。  
* 回溯  
[17.电话号码的字母组合](BackTracking/LC0017.cpp)    
**[51.n皇后](BackTracking/LC0051.cpp)**  

---
* 枚举(dfs..)  
[200.岛屿数量](BackTracking/LC0200.cpp)  
[1774.最接近目标价格的甜点成本](BackTracking/LC1774.cpp)  :可转化为0-1背包问题优化时间复杂度
---
* 图算法  
**[207.课程表](BackTracking/LC0207.cpp)**  :判断是否为有向无环图(拓扑排序)  
**[743.网络延迟时间](BackTracking/LC0743.cpp)** : 堆优化的Dijkstra算法  
[1784.从第一个节点出发到最后一个节点的受限路径数](BackTracking/LC1786.cpp) : 堆优化的Dijkstra算法+拓扑排序  

## 动态规划
**[5.最长回文子串](DynamicPrograming/LC0005.cpp)** :推荐使用中心扩展法   
[139.单词拆分](DynamicPrograming/LC0139.cpp) :判断字符串能否被字典中出现的单词组成      
[152.乘积最大子数组](DynamicPrograming/LC0152.cpp) :分别维护正负最大值    
[198.打家劫舍](DynamicPrograming/LC0198.cpp) :打家劫舍  
**[221.最大正方形](DynamicPrograming/LC0221.cpp)** :dp[i][j]表示以其为右下角的最大正方形面积   
[238.除自身以外数组的乘积](DynamicPrograming/LC0238.cpp)  
[279.完全平方数字](DynamicPrograming/LC0279.cpp) :dp[i]表示数字i由完全平方数组成的最少数量    
**[300.最长递增子序列](DynamicPrograming/LC0300.cpp)**  dp[i]表示以第i个数字结尾的最长上升子序列的长度  
**[312.戳气球](DynamicPrograming/LC0312.cpp)** :区间DP(dp要从后往前写)  
[322.零钱兑换](DynamicPrograming/LC0322.cpp) :完全背包    
[354.俄罗斯套娃信封问题](DynamicPrograming/LC0354.cpp) :是300题的二维扩展  
[403.青蛙过河](DynamicPrograming/LC0403.cpp)  :维护set的dp  
**[416.分割等和子集](DynamicPrograming/LC0416.cpp)** :0-1背包问题  
**[879.盈利计划](DynamicPrograming/LC0879.cpp)** :0-1背包问题(解集的数目问题, 一般要采用三维的dp)  
[1143.最长公共子序列](DynamicPrograming/LC1143.cpp)  
[1359.有效的快递序列数目](DynamicPrograming/LC1359.cpp) :插入的递推  
[1388.3n块披萨](DynamicPrograming/LC1388.cpp)  :不相邻子集的最大值  
[1411.给Nx3网格图涂色的方案数](DynamicPrograming/LC1411.cpp) :对一行整体考虑, 考虑ABA和ABC两种情况  

## 贪心
[42.接雨水](Greedy/LC0042.cpp)  :也可以使用双指针法  
[56.合并区间](Greedy/LC0056.cpp)  
[128.最长连续序列](Greedy/LC0128.cpp)  
[229.求众数2](Greedy/LC0229.cpp)  
[392.判断子序列](Greedy/LC0392.cpp):大数据发散问题    
**[406.根据身高重建队列](Greedy/LC0406.cpp)**:数对两个方向排序+贪心算法    
[581.最短无序连续子数组](Greedy/LC0581.cpp)  
[1775.通过最少操作次数使数组的和相等](Greedy/LC1775.cpp)  

## 分治, 二分法 DivideAndConquer
**[33.搜索旋转排序数组](DivideAndConquer/LC0033.cpp)**  :可多复习的一道常考题  
**[287.寻找重复数](DivideAndConquer/LC0287.cpp)** :空间复杂度O(1)  

## 滑动窗口
[3.无重复的最长子串](SlidingWindow/LC0003.cpp)  
[76.最小覆盖子串](SlidingWindow/LC0076.cpp) :滑动窗口+哈希表实现    

## 二叉树
**[98.验证二叉搜索树](Tree/LC0098.cpp)** :多复习(递归方法or中序遍历)    
**[101.对称二叉树](Tree/LC0101.cpp)** :多复习(递归&&循环两种方法, 对称问题，用两个指针比较区思考)  
[102.二叉树的层序遍历](Tree/LC0102.cpp)  :宽度优先搜索  
[103.二叉树的锯齿形层序遍历](Tree/LC0103.cpp)  :宽度优先搜索  
[105.从前序与中序遍历序列构造二叉树](Tree/LC0105.cpp) :从前序与中序遍历序列构造二叉树  
**[114.二叉树展开为链表](Tree/LC0114.cpp)** :按照先序遍历展开为单向链表, 空间O(1)    
**[236.二叉树的最近公共祖先](Tree/LC0236.cpp)** :DFS的方法要复习  
[437.路径总和3](Tree/LC0437.cpp)  

## 字符串
[8.字符串转换为整数(atoi)](String/LC0008.cpp) :写规则or有限状态机

## 数组
**[15.三数之和](Array/LC0015.cpp)** :排序后双指针法  
[344.反转字符串](Array/LC0344.cpp)  
**[560.和为K的子数组](Array/LC0560.cpp)**:前缀和思想   
[1441.用栈操作构建数组](Array/LC1441.cpp)

## 栈
**[739.每日温度](Stack/LC0739.cpp)** :单调栈   

## 数学
**[2.两数相加](Math/LC0002.cpp)**  

## 数据结构设计
**[146.LRU缓存机制](Design/LC0146.cpp)** :双向链表+哈希表
