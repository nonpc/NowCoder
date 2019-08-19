//牛牛找工作
#if 0
/*
题目描述
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，
牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，
牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
输入描述:

每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。

输出描述:

对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

示例1
输入

3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

输出

100
1000
1001

*/


//暴力法
/*
存入能力 和对应的工资
用每个"朋友"的能力去遍历能力组 , 并记录最大的工资数
时间消耗太大 , 不能通过
*/
#if 0
#include<iostream>
#include<vector>
using namespace std;


vector<int> power;
vector<int> money;
vector<int> friends;

int func(int MyPower, int size)
{
	int _max = -1;
	for (int i = 0; i < size; ++i)
	{
		if (MyPower >= power[i])
			_max = max(_max, money[i]);
	}
	return _max;
}

int main()
{
	int humen = 0;
	int nums = 0;
	cin >> nums >> humen;
	int _money = 0;
	int _power = 0;
	for (int i = 0; i < nums; ++i)
	{
		cin >> _power >> _money;
		power.push_back(_power);
		money.push_back(_money);
	}
	int f_power = 0;
	for (int i = 0; i < humen; ++i)
	{
		cin >> f_power;
		friends.push_back(f_power);
	}

	int size = power.size();
	for (int i = 0; i < humen; ++i)
		cout << func(friends[i], size) << endl;


	return 0;
}
#endif

//map表法
/*
使用map , 将能力作为键 , 工资作为值储存.
将人的能力作为键 , 工资置为 0  , 也储存到map中 
更新map , 将这个能力范围之内最大的工资数作为值保存
最后输出"朋友"能够获得的最大工资数
*/
#if 0
int main()
{
	map<int, int> _works;
	vector<int> _friends;
	int humen = 0;
	int nums = 0;
	cin >> nums >> humen;
	int _money = 0;
	int _power = 0;
	for (int i = 0; i < nums; ++i)
	{
		cin >> _power >> _money;
		_works.insert(make_pair(_power, _money));
	}
	
	int f_power = 0;
	for (int i = 0; i < humen; ++i)
	{
		cin >> f_power;
		_works.insert(make_pair(f_power, 0));
		_friends.push_back(f_power);
	}

	int size = _works.size();
	
	int _max = -1;
	map<int, int>::iterator it = _works.begin();
	map<int, int>::iterator it2 = _works.end();
	while (it != it2)
	{
		_max = max(_max, it->second);
		it->second = _max;
		++it;
	}

	for (int i = 0; i < humen; ++i)
		cout<<_works[_friends[i]]<<endl;


	return 0;
}

#endif

#endif