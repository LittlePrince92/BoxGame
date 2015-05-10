#include<cstdio>
using namespace std;
char sen[102][102];
int n, m, s;

int ipx, ipy;
int ibx, iby;
int itx, ity;

int px, py;
int bx, by;
int tx, ty;

void creatSen()
{
	char ch;
	scanf("%d %d %d\n", &n, &m, &s);
	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			scanf("%c", &ch);
			sen[i][j] = ch - '0';
			switch (ch - '0')
			{
			case 1:
				ipx = i;
				ipy = j;
				break;
			case 3:
				ibx = i;
				iby = j;
				break;
			case 2:
				itx = i;
				ity = j;
				break;
			}
		}
		getchar();
	}
	//行界设置为墙
	for (int j = 0; j < n + 2; ++j)
	{
		sen[0][j] = 4;
		sen[m + 1][j] = 4;
	}
	//列界设置为墙
	for (int i = 0; i < m + 2; ++i)
	{
		sen[i][0] = 4;
		sen[i][n + 1] = 4;
	}
}

void changeState(char &op)
{
	switch (op)
	{
	case 'r':
		if (py + 1 == by&&px == bx)
		{
			if (sen[bx][by + 1] == 4)
				;
			else
			{
				sen[px][py] = 0;
				sen[bx][by] = 1;
				by++;
				py++;
				sen[bx][by] = 3;
			}
		}
		else if (sen[px][py + 1] == 0)
		{
			sen[px][py] = 0;
			py++;
			sen[px][py] = 1;
		}
		break;
	case 'l':
		if (py - 1 == by&&px == bx)
		{
			if (sen[bx][by - 1] == 4)
				;
			else
			{
				sen[px][py] = 0;
				sen[bx][by] = 1;
				by--;
				py--;
				sen[bx][by] = 3;
			}
		}
		else if (sen[px][py - 1] == 0)
		{
			sen[px][py] = 0;
			py--;
			sen[px][py] = 1;
		}
		break;
	case 'u':
		if (py == by&&px - 1 == bx)
		{
			if (sen[bx - 1][by] == 4)
				;
			else
			{
				sen[px][py] = 0;
				sen[bx][by] = 1;
				bx--;
				px--;
				sen[bx][by] = 3;
			}
		}
		else if (sen[px - 1][py] == 0)
		{
			sen[px][py] = 0;
			px--;
			sen[px][py] = 1;
		}
		break;
	case 'd':
		if (py == by&&px + 1 == bx)
		{
			if (sen[bx + 1][by] == 4)
				;
			else
			{
				sen[px][py] = 0;
				sen[bx][by] = 1;
				bx++;
				px++;
				sen[bx][by] = 3;
			}
		}
		else if (sen[px + 1][py] == 0)
		{
			sen[px][py] = 0;
			px++;
			sen[px][py] = 1;
		}
		break;
	}
}
inline void setInitial()
{
	px = ipx, py = ipy;
	bx = ibx, by = iby;
	tx = itx, ty = ity;
}
inline void printState()
{
	printf("px=%d py=%d ", px, py);
	printf("bx=%d by=%d ", bx, by);
	printf("tx=%d ty=%d \n", tx, ty);
}

void InPut()
{
	int opcount;
	char op;
	for (int i = 0; i < s; i++)
	{
		setInitial();
		//		printState();

		scanf("%d ", &opcount);
		for (int j = 0; j < opcount; j++)
		{
			scanf("%c", &op);
			changeState(op);
			//			printState();
		}
		getchar();

		if (bx == tx&&by == ty)
			printf("YES\n");
		else
			printf("NO\n");
	}
}


int main()
{
	creatSen();
	InPut();
	return 0;
}