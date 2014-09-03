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
#define pb push_back
#define mp make_pair

#define MOD 1000000007
#define _N 8
int board[_N][_N];
int xMove[] = {1,1,-1,-1,2,2,-2,-2};
int yMove[] = {2,-2,2,-2,1,-1,1,-1};
vector<pair<int,int>> Move;
bool isValid(pair<int,int> pos)
{
	return pos.first>=0 && pos.first<8 && pos.second>=0 && pos.second<8;
}

int V=_N*_N;
pair<int,int> src=mp(0,0), dest=mp(7,7); 

bool bfs(void)
{
    //vector<bool> seen; seen.resize(V,false);
	bool seen[8][8]; ZERO(seen); ZERO(board);
	int step=1;

	//queue<int> q;
    queue<pair<int,int>> q;

    //q.push(src); seen[src]=true;
    q.push(src); seen[src.first][src.second]=true; board[src.first][src.second]=step;

    while(!q.empty())
    {
		//int u=s.top(); s.pop();
		pair<int,int> u=q.front(); q.pop(); 
		step++;

		//loop(v,V) if(!seen[v] && isConnected(u,v))
		for(pair<int,int> m:Move) 
		{
			pair<int,int> v;
			v.first = m.first + u.first;
			v.second = m.second + u.second;

			if(isValid(v) && !seen[v.first][v.second])
			{
				//q.push(v); seen[v]=true;
				q.push(v); seen[v.first][v.second]=true; board[v.first][v.second]=step;
				if(v==dest) return true;
			}		
		}
    }
    return false;
} 

bool dfs(void)
{   
    //vector<bool> seen; seen.resize(V,false);
	bool seen[8][8]; ZERO(seen); ZERO(board);
	int step=1;

    //stack<int> s; 
    stack<pair<int,int>> s; 

    //s.push(src); seen[src]=true;
	s.push(src); seen[src.first][src.second]=true; board[src.first][src.second]=step;

    while(!s.empty())
    {
        //int u=s.top(); s.pop();
		pair<int,int> u=s.top(); s.pop();     
		step++;

        //loop(v,V) if(!seen[v] && isConnected(u,v))
		for(pair<int,int> m:Move) 
		{
			pair<int,int> v;
			v.first = m.first + u.first;
			v.second = m.second + u.second;
			
			if(isValid(v) && !seen[v.first][v.second])
			{
				//s.push(v); seen[v]=true;
				s.push(v); seen[v.first][v.second]=true; board[v.first][v.second]=step;
				if(v==dest) return true; 
			}		
		}
    }	
    return false;
} 


// Driver program to test above function
int main()
{
	loop(i,8) Move.pb(mp(xMove[i],yMove[i]));
	bool res = bfs();
	bool ans = dfs();
	return 0;
}