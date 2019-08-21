//俄罗斯方块
#if 0
/*
题目描述
小易有一个古老的游戏机，上面有着经典的游戏俄罗斯方块。因为它比较古老，所以规则和一般的俄罗斯方块不同。
荧幕上一共有 n 列，每次都会有一个 1 x 1 的方块随机落下，在同一列中，后落下的方块会叠在先前的方块之上，当一整行方块都被占满时，这一行会被消去，并得到1分。
有一天，小易又开了一局游戏，当玩到第 m 个方块落下时他觉得太无聊就关掉了，小易希望你告诉他这局游戏他获得的分数。
输入描述:

第一行两个数 n, m
第二行 m 个数，c1, c2, ... , cm ， ci 表示第 i 个方块落在第几列
其中 1 <= n, m <= 1000, 1 <= ci <= n

输出描述:

小易这局游戏获得的分数

示例1
输入

3 9
1 1 2 2 2 3 1 2 3

输出

2

思路:
	设置哈希数组 , 统计每一列的个数 . 只要所有列都有数据 , 那么得分就是所有列中的最低值

*/

int func(vector<int>& arr, int n, int m)
{
	vector<int> follow;
	follow.resize(n,0);
	int size = arr.size();
	for (int i = 0; i < size; ++i)
	{
		++follow[arr[i] - 1];
	}

	int _min = follow[0];
	for (int i = 0; i < n; ++i)
	{
		if (follow[i] == 0)
			return 0;
		_min = min(_min, follow[i]);
	}

	return _min;

}


int main()
{
	int m = 0;
	int n = 0;
	cin >> n >> m;

	vector<int> tmp;
	for (int i = 0; i < m; ++i)
	{
		int _val;
		cin >> _val;
		tmp.push_back(_val);
	}

	cout << func(tmp, n, m);

	return 0;

}

#endif