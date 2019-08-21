//城市修建
#if 0
/*
有一个城市需要修建，给你N个民居的坐标X,Y，问把这么多民居全都包进城市的话，城市所需最小面积是多少（注意，城市为平行于坐标轴的正方形）

输入描述:

第一行为N，表示民居数目（2≤N≤1000）

输出描述:

城市所需最小面积


输入例子1:

2
0 0
2 2


输出例子1:

4


输入例子2:

2
0 0
0 3


输出例子2:

9

思路 :记录横纵坐标的差值 , 找到差值最大的那个 , 然后进行正方形面积的求解
忠告 : 面试题告别int的使用 , 直接就用 long long  , 不然算法正确 , 精度不够 , 找错也是个麻烦事

*/
long long func(vector<long long>& str)
{
	int size = str.size();
	if (size < 2)
		return 0;
	if (size < 4)
	{
		return str[0] > str[1] ? str[0] * str[0] : str[1] * str[1];
	}
	long long _min1 = str[0];
	long long _min2 = str[1];
	long long _max1 = str[0];
	long long _max2 = str[1];
	for (int i = 2 , j = 3; i < size-1; i += 2 , j += 2)
	{
		_min1 = min(_min1, str[i]);
		_max1 = max(_max1, str[i]);
		_min2 = min(_min2, str[j]);
		_max2 = max(_max2,str[j]);
	}

	long long left = (_max1 - _min1);
	long long right = (_max2 - _min2);

	return left > right ? left * left : right * right;
}

int main()
{

	int n = 0;
	cin >> n;
	if (n <= 0)
		return 0;
	vector<long long> tmp;
	long long left = 0;
	long long right = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> left >> right;
		tmp.push_back(left);
		tmp.push_back(right);
	}

	cout << func(tmp) << endl;
		

	return 0;
}

#endif