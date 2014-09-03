#include<string>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define pb push_back
#define mp make_pair

#define MOD 1000000007
#define _N 8
int board[_N][_N];

struct xy
{
	int x,y;
	xy(int _x, int _y){ x=_x, y=_y;}
	bool isValid(){ return x>=0 && x<_N && y>=0 && y<_N;}
	bool operator ==(xy pos){ return pos.x==x && pos.y==y;}
	xy operator +(xy pos){ pos.x+=x,pos.y+=y; return pos;}	
};

int xMove[] = {1,1,-1,-1,2,2,-2,-2};
int yMove[] = {2,-2,2,-2,1,-1,1,-1};
vector<xy> Move;

int V=_N*_N;
xy src=xy(0,0), dest=xy(7,7); 

bool bfs(void)
{
	bool seen[8][8]; ZERO(seen); FILL(board,-1);

    queue<xy> q;
	q.push(src); seen[src.x][src.y]=true; board[src.x][src.y]=0;
    while(!q.empty())
    {
		xy u=q.front(); q.pop(); 
		for(xy m:Move) 
		{
			xy v(m+u);
			if(v.isValid() && !seen[v.x][v.y])
			{
				q.push(v); seen[v.x][v.y]=true;
				board[v.x][v.y]=board[u.x][u.y]+1;
				if(v==dest) return true;
			}		
		}
    }
    return false;
} 

bool dfs(void)
{   
	bool seen[8][8]; ZERO(seen); //ZERO(board);
	loop(i,_N) loop(j,_N) board[i][j]=INT_MAX;
 
    stack<xy> s; 
	s.push(src); seen[src.x][src.y]=true; board[src.x][src.y]=0;
    while(!s.empty())
    {
		xy u=s.top(); s.pop();  		
		for(xy m:Move) 
		{
			xy v(m+u);
			if(v.isValid() && board[v.x][v.y]>board[u.x][u.y]+1)
			{
				s.push(v); seen[v.x][v.y]=true; 
				board[v.x][v.y]=board[u.x][u.y]+1;	
				//if(v==dest) return true;    
			}		
		}

    }
    return false;
} 


// Driver program to test above function
int main()
{
	loop(i,8) Move.pb(xy(xMove[i],yMove[i]));
	bool res = bfs();
	bool ans = dfs();
	return 0;
}