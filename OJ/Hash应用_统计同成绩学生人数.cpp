#include<stdio.h>
int main()
{
	int n;
	while (scanf_s("%d", &n) != EOF && n != 0)
	{
		int Hash[101] = { 0 };
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf_s("%d", &x);
			Hash[x]++;
		}
		int x;
		scanf_s("%d",&x);
		printf("%d\n", Hash[x]);
	}
	return 0;
}