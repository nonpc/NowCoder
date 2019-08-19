//被3整除
#if 0
/*
题目描述

小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。

并且小Q对于能否被3整除这个性质很感兴趣。

小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
输入描述:

输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。

输出描述:

输出一个整数, 表示区间内能被3整除的数字个数。

示例1
输入

2 5

输出

3

说明

12, 123, 1234, 12345...
其中12, 123, 12345能被3整除。


*/

/*
解题思路 : 
		能被3整除的数满足一个特点 , 所有位数的加和能整除3 . 
		所以问题就变成了 , 怎么求这么长一串数字的加和 , 
		如果加一个超过十的数还要在分成两位 , 显得有些麻烦
		那么稍微编的复杂一些 , 将对应的每一位进行加和 , 例如 , 12345678910 , 下一位是加上11 , 变成1234567891011
		计算这个数的总和就是1+2+3+4+5+6+7+8+9+10+11 ; 而不是将10 , 11分解成 1+0和 1+1
		如果加上的这个数都不能被3整除 , 那拆分加和也不能被整除 . 简单来说就是把 多位看成是一位 
		累加的过程中 , 如果这个数 mod 3 == 0 , 则记录 
		最后返回记录的总数
		区间的话 , 先计算出这个数能不能被3 整除  , 然后在进行累加
		这里需要注意的就是 , 记录总数的 sum 要设置为 long long 类型 , 以防位数不够造成计算错误
*/

/*
通过70%
用例:
217982186 436746452

对应输出应该为:

145842845

你的输出为:

72921701
*/

#include<iomanip>
double func(int start, int end)
{
	double count = 0;
	int i = 0;
	long long sum = 0;
	//起始数;
	for (i = 1; i <= start; ++i)
		sum += i;
	if (sum % 3 == 0)
		++count;
	for (i = start + 1; i <= end; ++i)
	{
		sum += i;
		if (sum % 3 == 0)
			++count;
	}
	
	return count;
}

int main()
{
	int start = 0;
	int end = 0;
	cin >> start >> end;
	if (start == 0 || end == 0)
		return 0;
	double n = func(start, end);
	cout << setprecision(n) << n << endl;

	return 0;
}

#endif
