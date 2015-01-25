#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
#include <iomanip>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
#define _N 10
double dp[3][_N][_N];

struct point
{
    public: double x,y;	
	point(double a, double b){x=a;y=b;} point(){}
	void setPoint(double a, double b){x=a;y=b;}
	double dist(point p){ return sqrt(pow(x-p.x,2)+pow(y-p.y,2));}
	double dot(point A, point B){point OA(A.x-x,A.y-y), OB(B.x-x,B.y-y); return(OA.x*OB.x+OA.y*OB.y);}
	double cross(point A, point B){point OA(A.x-x,A.y-y), OB(B.x-x,B.y-y); return(OA.x*OB.y - OA.y*OB.x);}
	bool onSegment(point A, point B){bool ok=(x<=max(A.x,B.x) && x>=min(A.x,B.x) && y<=max(A.y,B.y) && y>=min(A.y,B.y)); return ok?1:0;}
	bool operator <(const point &p) const{ return x<p.x || (x==p.x && y<p.y);}
};

class chessBoard
{

public:
	int X, Y; 
	vector<point> movXY;	
	vector<vector<int>> board;	

	chessBoard(){initCB(8,8);}
	void initCB(int dimX, int dimY)
	{
		X=dimX, Y=dimY; board.resize(X); loop(i,Y) board[i].resize(Y,0);
		int mX[8]={1,1,-1,-1,2,2,-2,-2}, mY[8]={2,-2,2,-2,1,-1,1,-1};
		loop(i,8){ movXY.push_back(point(mX[i],mY[i])); }
	}

	point nextMove(point curPos, int i)
	{ if(i<8){ return point(curPos.x+movXY[i].x,curPos.y+movXY[i].y); }}

	bool isLimit(point move){return isLimit(move.x,move.y);}
	bool isLimit(int x, int y){if((0<=x && x<X) && (0<=y && y<Y)) return true; return false;}

	void clearCB(){loop(i,X) loop(j,Y) board[i][j]=0;}
	void printCB(){loop(i,X){loop(j,Y) cout<<setw(2)<<board[i][j]<<" "; cout<<endl;}}
};

class ChessKnight 
{

	public:
	double probability(int x, int y, int n) 
	{
		double ans = 0;
		chessBoard cb; 
		ZERO(dp);


		bool cur=1;
		x--,y--; dp[cur^1][x][y]=1;
		while(n--)
		{
			ZERO(dp[cur]);
			loop(i,8) loop(j,8) if(dp[cur^1][i][j])
			{
				loop(k,8)
				{
					point nMove=cb.nextMove(point(i,j),k);
					if(cb.isLimit(nMove)) dp[cur][(int)nMove.x][(int)nMove.y]+=dp[cur^1][i][j]/8.0;
					else ans+=dp[cur^1][i][j]/8.0;
				}
			}
			cur^=1;
		}

		return 1-ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.1875; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; double Arg3 = 1.0; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 10; double Arg3 = 0.0522148497402668; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 50; double Arg3 = 8.356427906809618E-7; verify_case(3, Arg3, probability(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    ChessKnight ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
