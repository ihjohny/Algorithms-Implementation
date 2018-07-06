//2d grad some cell is blocked and so on
#include<iostream>
#include<queue>
#define pii pair<int,int>
using namespace std;
int fx[4]={1,-1,0,0};
int fy[4]={0,0,1,-1};
int visited[100][100];
int ddistance[100][100];
int cell[100][100];
int row,col;
void bfs(int x,int y)
{
	visited[x][y]=1;
	queue<pii>q;
	q.push(pii(x,y));
	while(!q.empty())
	{
		pii top=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=top.first+fx[i];
			int ty=top.second+fy[i];
			if(tx>=0&&tx<row&&ty>=0&&ty<col&&cell[tx][ty]!=-1&&visited[tx][ty]==0)
			{
				visited[tx][ty]=1;
				ddistance[tx][ty]=ddistance[top.first][top.second]+1;
				q.push(pii(tx,ty));
			}
		}
	}
}
int main()
{
	return 0;
}
