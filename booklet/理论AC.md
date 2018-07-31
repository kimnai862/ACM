# 理论AC

[TOC]

## 1 [Codeforces Beta Round #1](http://codeforces.com/contest/1) （3/3）

### A [Theatre Square](http://codeforces.com/contest/1/problem/A)  

给定n,m,a  求n$\times$m的矩形覆盖最少需要几块a$\times$a的正方形，可超出，不可重叠

答案：((n+a-1)/a)*((m+a-1)/a)

### B [Spreadsheet](http://codeforces.com/contest/1/problem/B) 

给定两种位置表示方法BC23(R23C55)其中一种，转化为另外一种

答案：模拟

### C [Ancient Berland Circus](http://codeforces.com/contest/1/problem/C)

给定某一正多边形其中三个点，求该正多边形最小面积

答案：显然可以选两条直线算出正多边形中点，面积与多边形点数成正比，二分乱搞即可

## 2 [Codeforces Beta Round #2](http://codeforces.com/contest/2) （3/3）

### A [Winner](http://codeforces.com/contest/2/problem/A)

给定若干个人的成绩，求游戏结束后最先取得最大成绩的人

答案：模拟记录即可

### B [The least round way](http://codeforces.com/contest/2/problem/B)  

给定一个n$\times$n的矩阵，每个格子有一个非负整数，问从(1,1)到(n,n)中经过最少0的其中一种方案是什么

答案：dp记录到该节点最少需要经过几个0，再记录一下路径即可

### C [Commentator problem](http://codeforces.com/contest/2/problem/C)  

给定三个互不相交的圆，求一点使得从这点到各个圆的切线角度一样并且最大

答案：考虑选择其中两个圆，求出一点集，

​	设点为($x_{}$,$y_{}$) ，两个圆为($x_{1}$,$y_{1}$,$r_{1}$)、（$x_{2}$,$y_{2}$,$r_{2}$）

​	点到两个圆心的距离分别为$d_{1}$,$d_{2}$

​	由相似可得

​		 $ d_{1} /r_{1}=d_{2}/r_{2}$

​		 $\frac{(x_{}-x_{1})^2+(y_{}-y_{1})^2}{r_{1}^2}=\frac{(x_{}-x_{2})^2+(y_{}-y_{2})^2}{r_{2}^2}$

显然如果这两个圆半径相等则为直线，半径不等则为一个圆

任取两个点集求交集即可

## 3 [Codeforces Beta Round #3](http://codeforces.com/contest/3) （4/4） 

### A [Shortest path of the king](http://codeforces.com/contest/3/problem/A)

一个8$\times$8的棋盘，	给定起点和终点，每次可以选择8个方向，求最短路和其中一种方案

答案：乱搞即可

### B [Lorry](http://codeforces.com/contest/3/problem/B)

车有两种不同的规格，一种占1立方米的空间，另一种占2立方米的空间。给你n辆车的规格以及载运能力，

问在有限的空间中最大的载运能力是多少，输出其中一种方案

答案：显然贪心即可

### C [Tic-tac-toe](http://codeforces.com/contest/3/problem/C)

给你一个井字棋游戏的状态图，让你判断该状态是否合法或者下一步谁下或者谁赢

答案： 模拟即可

### D [Least Cost Bracket Sequence](http://codeforces.com/contest/3/problem/D)

给一个由")","(","?"组成的序列，每个”?”变成左右括号的代价都不一样，问变成合法序列的最小代价，否则输出-1

答案：我们可以先将所有“?”变成右括号，这样问题转化为有若干个右括号可以变化为左括号，然后维护一个优先队列，当需要转化时，选取转换代价最小的括号即可

## 4 [Codeforces Beta Round #4 (Div. 2 Only)](http://codeforces.com/contest/4) （4/4）

### A [Watermelon](http://codeforces.com/contest/4/problem/A) 

给一个数，问能否拆分成两个偶数的和

答案：显然除2以外偶数加偶数等于偶数

### B [Before an Exam](http://codeforces.com/contest/4/problem/B)  

给定n天，每一天可用时间不能小于$a_{i}$,大于$b_{i}$,现在有n天的总用时sum，问能否找到一个合法的用时方案并输出

n<30,sum<240

答案：我们可以维护i至n天至少需要用时x小时，最多能用时y小时，显然每一天至少花费用时为max(t-y,$a_{i}$)，尽可能贪心花费最多用时即可

### C [Registration System](http://codeforces.com/contest/4/problem/C)

每一放入一个串，如果之前从未出现过，则输出OK，否则输出该串+之前出现的次数

答案：模拟

### D [Mysterious Present](http://codeforces.com/contest/4/problem/D)  

给你一个w$\ast$h的卡片，有n(n<2000)个规格不同的信封，问最多可以套几个信封

答案：排序之后dp到第i个信封时最多可以套几个信封即可

## 5 [Codeforces Beta Round #5](http://codeforces.com/contest/5) （5/5）

### A [Chat Servers Outgoing Traffic](http://codeforces.com/contest/5/problem/A)

一个聊天室，每次可以加一人或减一人或者由其中一人向所有人发送消息，求所有发送消息的长度之和

答案：模拟

### B [Center Alignment](http://codeforces.com/contest/5/problem/B)

给你n个字符串，将其中心对称后输出

答案：模拟

### C [Longest Regular Bracket Sequence](http://codeforces.com/contest/5/problem/C)

给你一个括号序列，求最长合法子串的个数

答案：当遇到左括号时，将其放入栈，当遇到右括号时，从栈顶拿出一个，此时查找栈顶元素前一个是否是右括号，显然如果是合法子串的右端则可以拼接，记录即可

### D [Follow Traffic Rules](http://codeforces.com/contest/5/problem/D)

给你一个加速度a，最大速度v，某一点位置p，在p处允许最大速度limitv，求从起点到终点最小耗费时间

答案：计算模拟即可

### E [Bindian Signalizing](http://codeforces.com/contest/5/problem/E)

给你一个n个数字组成的环，对于任意两个数字i,j当且仅当存在至少一条弧满足该弧上点的最大值小于等于min(a[i],a[j])时pair(i,j)合法，问有多少个合法的pair

答案：将数组复制一次即可模拟圆，然后用单调栈即可维护区间最大值，细节处理即可

## 6 [Codeforces Beta Round #6 (Div. 2 Only)](http://codeforces.com/contest/6) （5/5）

### A [Triangle](http://codeforces.com/contest/6/problem/A)

给你四个数字代表四条边的长度，问是否能组成三角形或者退化的三角形

答案：枚举两条边合在一起模拟即可

### B [President's Office](http://codeforces.com/contest/6/problem/B)  

给一个n$\ast$m的矩形，每个字母代表一种颜色，“·”代表是一个空格，求某一个颜色相邻的颜色种数

答案：模拟即可

### C [Alice, Bob and Chocolate](http://codeforces.com/contest/6/problem/C)

给n个巧克力，Alice和Bob从两端开吃，每个巧克力耗时不同，求最后两人各吃到的巧克力数

答案：模拟即可

### D [Lizards and Basements 2](http://codeforces.com/contest/6/problem/D)

有一排弓箭手，每次主角可以向其中一个弓箭手的位置发生火球，中心会受到a点伤害，两边会受到b点伤害，求消灭所有弓箭手所需的最少火球

答案：爆搜或者dp  (x,i,j,k)表示前x-2个弓箭手已被消灭第x个弓箭手左右三个的生命为i,j,k时最少需要发射的火球个数，答案即为(n,0,0,0)

### E [Exposition](http://codeforces.com/contest/6/problem/E) 

给定一组数列，求最长的区间使得区间最大值与最小值的差不大于k，输出方案数

答案：首先二分区间，然后对于固定的区间可以用单调队列维护区间最大值和最小值

## 7 [Codeforces Beta Round #7](http://codeforces.com/contest/7) （5/5）

### A [Kalevitch and Chess](http://codeforces.com/contest/7/problem/A)

给一个被画了若干笔的棋盘，问最少画了几笔，一次一行或一列

答案：暴力

### B [Memory Manager](http://codeforces.com/contest/7/problem/B)

描述了一个内存的使用，要求对若干访问返回对应的值

答案：模拟

### C [Line](http://codeforces.com/contest/7/problem/C)

给定一条直线Ax+By+C=0，求是否在一定范围内有整数点

答案：扩展欧几里得即可

### D [Palindrome Degree](http://codeforces.com/contest/7/problem/D)

给一个串，一个串是k回文串当且仅当其长度为n/2前缀和后缀是k-1回文串，求一个串所有前缀的k和

答案：字符串hash，对每个前缀log(k)时间求解即可

### E [Defining Macros](http://codeforces.com/contest/7/problem/E)

用define定义若干表达式后，问最后的表达式是否合法

答案：乱搞即可

## 8 [Codeforces Beta Round #8](http://codeforces.com/contest/8) （5/5）

### A [Train and Peter](http://codeforces.com/contest/8/problem/A)

给定一个主串和两个子串，问两个子串是一次顺序或逆序不重叠出现

答案：子串较小，模拟即可

### B [Obsession with Robots](http://codeforces.com/contest/8/problem/B)

给一个代表行径方向的字符串，问机器人是否有问题

答案：显然最短路不会有环，模拟判断即可

### C [Looking for Order](http://codeforces.com/contest/8/problem/C)  

给定一个起点和n个其余点，至多访问两个点后必须会起点一次，问访问完n个点并回到起点的最短耗时是多少，并输出其中一种方案

答案：n<=24,数位dp即可

### D [Two Friends](http://codeforces.com/contest/8/problem/D)

给定三个点A,B,C,有三条曲线AP,BP,CP,给定限制AP+BP-AB<=X,AP+CP-AC<=Y，求AP最大值

答案：显然BP，CP为直线，二分AP，对于固定的AP，我们可以分别得到以A，B，C为圆心的圆。检查三个圆是否有公共面积即可

### E [Beads](http://codeforces.com/contest/8/problem/E)

将所有二进制中，满足其字典序小于其逆序，01翻转后的序，逆序后01翻转的序的01串提取出来，按字典序排序后，求其第k个字典序

答案：n<50,考虑按位求字典序，假设已经知道其前i-1个位置，采用数位dp的方法计算假设第i位为0的方法数x,如果x>k,则第i位为0，否则第i位为1并且k-=x

## 9  [Codeforces Beta Round #9 (Div. 2 Only)](http://codeforces.com/contest/9) 

### A [Die Roll](http://codeforces.com/contest/9/problem/A)

给定两个骰子扔出的值，问扔一次骰子赢的概率是多少

答案：简单题。。。

### B [Running Student](http://codeforces.com/contest/9/problem/B)

已知x轴正方向的若干点和平面中的一点P,从原点到若干点的速度为v,从若干点到P的速度为s，求从原点到P的最少时间

答案：枚举从哪一点到P，更新最小值即可

### C [Hexadecimal's Numbers](http://codeforces.com/contest/9/problem/C)

小于n的只用01表示的数字有多少个

答案：显然这样的数字只有$2^{len(n)}$个，枚举排序查找即可

### D [How many trees?](http://codeforces.com/contest/9/problem/D) 

