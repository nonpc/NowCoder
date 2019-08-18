//迷路的牛牛
#if 0
/*

牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，
但是他需要知道自己面向哪个方向，请你帮帮他。
输入描述:

每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示转方向的次数N(N<=1000)。
接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。

输出描述:

输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。

示例1
输入

3
LRR

输出

E
*/


char ac[] = { 'N' , 'E' ,'S','W '};
char bc[] = {' N ' , 'W ', 'S' , 'E' };
void func(string str,int len)
{
	if (str.length() != len)
		return;
	if (str.length() <= 0 || str == " ")
		return;
	int right = 0;
	int left = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == 'R')
			++right;
		if (str[i] == 'L')
			++left;
	}
	int index = -1;
	if (right > left)
	{
		index = (right - left) % 4;
		cout << ac[index] << endl;
	}else if (right < left)
	{
		index = (left - right) % 4;
		cout << bc[index];
	}else if (right == left)
		cout << 'N' << endl;
}

int main()
{
	int len;
	cin >> len;
	string arr;
	cin >> arr;
	func(arr,len);
	//RRRLLLRLRLRL
	return 0;
}

#endif
