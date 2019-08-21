//看花
#if 0
/*


小明有一个花园，花园里面一共有m朵花，对于每一朵花，都是不一样的，小明用1～m中的一个整数表示每一朵花。

他很喜欢去看这些花，有一天他看了n次，并将n次他看花的种类是什么按照时间顺序记录下来。

记录用a[i]表示，表示第i次他看了a[i]这朵花。

小红很好奇，她有Q个问题,问[l,r]的时间内，小明一共看了多少朵不同的花儿，小明因为在忙着欣赏他的花儿，
所以想请你帮他回答这些问题。

输入描述:

输入两个数n,m;(1<=n<=2000,1<=m<=100);分别表示n次看花，m表示一共有m朵花儿。

接下来输入n个数a[1]~a[n]，a[i]表示第i次，小明看的花的种类;

输入一个数Q(1<=Q<=1000000);表示小红的问题数量。

输入Q行 每行两个数l,r(1<=l<=r<=n);表示小红想知道在第l次到第r次，小明一共看了多少不同的花儿。


输出描述:

一共Q行

每一行输出一个数 表示小明在[l,r]的时间内看了多少种花。


输入例子1:

5 3
1 2 3 2 2
3
1 4
2 4
1 5


输出例子1:

3
2
3

*/
//case通过率为20.00%
void func(vector<vector<int>>& time, vector<int>& tmp, int q)
{
	int arr[101] = { 0 };
	int size = tmp.size();
	int count = 0;
	vector<int> flowers;
	for (int i = 0; i < size; ++i)
	{
		if (!arr[tmp[i]])
		{
			++count;
			arr[tmp[i]] = 1;
		}
		flowers.push_back(count);
	}
	
	for (int i = 0; i < q; ++i)
	{
		int l = time[i][0] -1;
		int r = time[i][1] - 1;
		if (flowers[r] - flowers[l] <= 1)
		{
			count = 0;
			int brr[101] = { 0 };
			int len = r - l + 1;
			for (int i = 0; i < len; ++i)
			{
				if (!brr[tmp[l]])
				{
					++count;
					brr[tmp[l++]] = 1;
				}
				else
					++l;
			}
			cout << count << endl;
		}
		else
			cout << flowers[r] - flowers[l] + 1 << endl;
	}
}

//case通过率为86.67%
#if 0
void func(vector<vector<int>> &time,vector<int> &tmp, int q)
{
	int size = time.size();
	int lock = 0;
	int i = 0; 
	int l = time[i][0] - 1;
	int r = time[i++][1] - 1;
	int count = 0;
	bool arr[101] = { false };

	while ( l <= r +1)
	{
		if (l == r + 1)
		{
			cout << count << endl;
			++lock;
			if (lock == size)
				break;
			l = time[i][0] - 1;
			r = time[i++][1] -1;
			count = 0;
			memset(arr, false, sizeof(arr));
		}
		if (!arr[tmp[l]])
		{
			++count;
			arr[tmp[l++]] = true;
		}
		else
			++l;
	}

#if 0
	////case通过率为86.67%
	for (int i = 0; i < q; ++i)
	{
		int l = time[i][0] -1;
		int r = time[i][1] - 1;
		int count = 0;
		int arr[101] = { 0 };
		int len = r - l + 1;
		for (int i = 0; i < len; ++i)
		{	
			if (!arr[tmp[l]])
			{
				++count;
				arr[tmp[l++]] = 1;
			}
			else
				++l;
		}

		cout << count << endl;
	}
#endif
}
#endif

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<int> tmp;
	for (int i = 0; i < n; ++i)
	{
		int flower = 0;
		cin >> flower;
		tmp.push_back(flower);
	}

	int q = 0;
	cin >> q;
	vector<vector<int>> time;
	for (int i = 0; i < q; ++i)
	{
		vector<int> _val;
		int r = 0;
		int l = 0;
		cin >> l >> r;
		_val.push_back(l);
		_val.push_back(r);
		time.push_back(_val);
	}

	func(time , tmp,q);


	return 0;
}

#endif