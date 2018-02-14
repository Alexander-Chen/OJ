/*
例6.2 胜利大逃亡
特殊判题: 否
内存限制: 32 兆
时间限制; 2 秒
题目描述:
Ignatius 被魔王抓走了，有一天魔王出差去了，这可是Ignatius 逃亡的好机会.
魔王住在一个城堡里,城堡是一个A*B*C 的立方体,可以被表示成A 个B*C 的矩
阵，刚开始Ignatius 被关在(0,0,0)的位置,离开城堡的门在(A-1,B-1,C-1)的位置,现
在知道魔王将在T分钟后回到城堡,Ignatius每分钟能从一个坐标走到相邻的六个
坐标中的其中一个.现在给你城堡的地图,请你计算出Ignatius 能否在魔王回来前
离开城堡(只要走到出口就算离开城堡，如果走到出口的时候魔王刚好回来也算逃
亡成功)，如果可以请输出需要多少分钟才能离开，如果不能则输出-1。
输入:
输入数据的第一行是一个正整数K,表明测试数据的数量.每组测试数据的第
一行是四个正整数A,B,C 和T( 1<=A,B,C<=50,1<=T<=1000),它们分别代表城堡的
大小和魔王回来的时间.然后是A 块输入数据(先是第0 块,然后是第1块,第2
块...每块输入数据有B行，每行有C 个正整数，代表迷官的布局,其中0代表路,1
代表墙。
输出:
对于每组测试数据,如果Ignatius 能够在魔王回来前离开城堡,那么请输出他
最少需要多少分钟,否则输出-1.
样例输入:
1
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0 
0 1 1 0
0 1 1 0
样例输出：
11
*/

#include<stdio.h>
#include<queue>
using namespace std;
bool mark[50][50][50];//标记数组
int maze[50][50][50]; //保存立方体信息
struct N { //状态结构体
	int x, y, z;
	int t;
};
queue<N> Q;
int go[][3] = {
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
int BFS(int a, int b, int c)
{
	while (Q.empty() == false) {
		N now = Q.front();
		Q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nz = now.z + go[i][2];
			if (nx<0 || nx>a || ny < 0 || ny >= b || nz < 0 || nz >= c)
				continue;
			if (maze[nx][ny][nz] == 1) continue;
			if (mark[nx][ny][nz] == true) continue;
			N tmp;
			tmp.x = nx;
			tmp.y = ny;
			tmp.z = nz;
			tmp.t = now.t + 1;
			Q.push(tmp);
			mark[nx][ny][nz] = true;
			if (nx == a - 1 && ny == b - 1 && nz == c - 1)
				return tmp.t; 
		}
	}
	return -1;
}
int main()
{
	int T;
	scanf_s("%d", &T);
	while (T--)
	{
		int a, b, c, t;
		scanf_s("%d%d%d%d", &a, &b, &c,&t);
		for(int i=0;i<a;i++)
		{
			for (int j=0;j< b; j++)
			{
				for (int k = 0; k < c; k++)
				{
					scanf_s("%d", &maze[i][j][k]);
					mark[i][j][k] = false;
			  }
		  }
		}
		while (Q.empty() == false)
			Q.pop();
		mark[0][0][0] = true;
		N tmp;
		tmp.t = tmp.y = tmp.x = tmp.z = 0;
		Q.push(tmp);
		int rec = BFS(a, b, c);
		if (rec <= t)
			printf("%d\n", rec);
		else printf("-1\n");
	}
	system("pause");

	return 0;
}

