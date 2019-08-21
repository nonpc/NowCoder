//Bittttttts
#if 0
/*
现在有q个询问，每次询问想问你在[l,r]区间内，k进制表示中，k-1的数量最多的数是哪个数。比如当k=2时，9的二进制就是1001，那么他就有2个1.

输入描述：

第一行一个q，表示有q组询问。

接下来q行，每行三个整数k,l,r,分别表示进制数,查询的数字,以及查询的范围。

满足1<=q<=100000,2<=k<=16,1<=l<=r<=10^16

输出描述：

对于每组询问，输出答案。如果有多个答案，请输出最小的。

输入例子1：

1
8 1 100

输出例子1：

63

long long的最大值：9 223 372 036 854 775 807（>10^18）

*/

//66???
void func(vector<vector<long long>> &str , int p)
{
	long long count = 0;
	long long k = 0, l = 0, r = 0;
	for (int i = 0; i < p; ++i)
	{
		k = str[i][0];
		l = str[i][1];
		r = str[i][2];

		long long tmp = l;
		long long mod = l;
		while  (mod <= r)
		{
			if (tmp == 0)
			{
				tmp = ++mod;
			}
			if (tmp % k == l)
				++count;
			tmp /= k; 
		}
		cout << count << endl;
		count = 0;
	}
}

int main()
{
	int p = 0;
	cin >> p;
		
	long long k = 0;
	long long l = 0; 
	long long r = 0;
	vector<vector<long long>> tmp;
	for (int i = 0; i < p; ++i)
	{
		vector<long long> _data;
		cin >> k >> l >> r;
		_data.push_back(k);
		_data.push_back(l);
		_data.push_back(r);
		tmp.push_back(_data);
	}

	func(tmp, p);


	return 0;
}

#endif