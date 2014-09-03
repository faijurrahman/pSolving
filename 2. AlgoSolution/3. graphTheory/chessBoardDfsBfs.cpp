//http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include<iomanip>
#include<iostream>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define DIMX 8
#define DIMY DIMX

class chessBoard
{
private:
	int X, Y; 
	vector<int> moveX, moveY;	
	vector<vector<int>> board;	

	bool isLimit(int x, int y)
	{
		if((0<=x && x<X) && (0<=y && y<Y)) return true;
		return false;
	}

public:
	chessBoard(int dimX, int dimY)
	{
		X = dimX, Y = dimY;
		board.resize(X);
		loop(i,Y) board[i].resize(Y,0);
		int mX[8] = {1,	1,	-1,	-1,	2,	2,	-2,	-2};
		int mY[8] = {2,	-2,	2,	-2,	1,	-1,	1,	-1};
		loop(i,8) 
		{ 
			moveX.push_back(mX[i]); 
			moveY.push_back(mY[i]);
		}

		target=64;
		nextX=0, nextY=0;
	}

	bool bfsTraverse()
	{
		int count = 1;
		board[0][0] = count++;

		queue<pair<int,int>> q;
		q.push(make_pair(0,0));
		while(!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			loop(i,8)
			{
				int nextX = x+moveX[i];
				int nextY = y+moveY[i];
				if(isLimit(nextX,nextY) && !board[nextX][nextY])
				{
					q.push(make_pair(nextX,nextY));
					board[nextX][nextY] = count++;
					if(count-1 == X*Y) return true;
				}
			}
		}
		return false;
	}

	int target;
	int nextX, nextY;
	stack<pair<int,int>> s;	
	bool dfsTraverseRecur(int stage)
	{
		if(stage == target) return true;

		board[nextX][nextY] = stage;
		s.push(make_pair(nextX,nextY));
		while(!s.empty())
		{
			int x = s.top().first;
			int y = s.top().second;
			s.pop();

			loop(i,8)
			{
				nextX = x+moveX[i];
				nextY = y+moveY[i];
				if(isLimit(nextX,nextY) && !board[nextX][nextY] && dfsTraverseRecur(stage+1))
				{
					return true;
				}
			}
		}
		return false;
	}

	void clearChessBoard()
	{
		loop(i,X) loop(j,Y) board[i][j] = 0;
	}

	void printChessBoard()
	{
		loop(i,X) 
		{
			loop(j,Y) cout<<setw(2)<<board[i][j]<<" "; 
			cout<<endl;
		}
	}
};

int main()
{
	chessBoard objChessBoard(DIMX,DIMY);

	cout << endl << "BFS Chess Board" << endl;
	objChessBoard.clearChessBoard();
	objChessBoard.bfsTraverse();
	objChessBoard.printChessBoard();

	cout << endl << "DFS Chess Board" << endl;
	objChessBoard.clearChessBoard();
	objChessBoard.dfsTraverseRecur(1);
	objChessBoard.printChessBoard();
	return 0;
}