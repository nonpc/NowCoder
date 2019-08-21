//圈地运动
#if 0
/*
	题目描述

圈地运动，就是用很多木棍摆在地上组成一个面积大于0的多边形。小明喜欢圈地运动，于是他需要去小红店里买一些木棍，期望全出一块地来。
小红想挑战一下小明，所以给小明设置了一些障碍。障碍分别是：
1）如果小明要买第i块木棍的话，他就必须把前i-1块木棍都买下来；2）买了的木棍都必须用在圈地运动中。
那么请问小明最少买多少根木棍，才能使得木棍围成的图形是个面积大于0的多边形呢？

输入

第一行一个数n，表示木棍个数，第二行n个数，第i个数表示第i个木棍的长度ai，i<=n<=10000,1<=ai<=10000。

输出

输出一个数，表示最少需要的木棍个数，如果无解输出-1。

样例输入

3
6 8 10

样例输出

3

解题思路
n个木棍能够围成一个多边形的条件是，这n个木棍中最长的木棍长度要小于其余n-1个木棍的长度总和。
所以，遍历一遍这些木棍，找到一个最长的木棍和其余木棍的总和就可以了 , 注意 数组有可能只有前半部分满足。
另外，当木棍个数小于3以及遍历完都没有符合条件的数据时，输出-1。

*/
long long func(vector<long long>& str)
{
	int size = str.size();
	if (size < 3)
		return -1;
	long long  _max = 0;
	long long sum = 0;
	long long count = 0;
	//1 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 2180 3481 2613 82 5212 
	//5589 6408 6736 8888 7749 8395 8270 1518 6766 1748
	for (int i = 0; i < size; ++i)
	{
		_max = max(_max, str[i]);
		sum += str[i];
		++count;
		if (_max < (sum - _max))
			break;
	}
	sum -= _max;
	if (_max > sum)
		return -1;
	else
		return count;
}

int main()
{
	int nums = 0;
	cin >> nums;
	vector<long long> tmp;
	long long test;
	for (int i = 0; i < nums; ++i)
	{
		cin >> test;
		tmp.push_back(test);
	}

	cout << func(tmp) << endl;

	return 0;
}

#endif