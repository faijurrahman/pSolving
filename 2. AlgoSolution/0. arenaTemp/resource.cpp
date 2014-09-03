#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
 
// Macros
 
#define ld    long double
#define ll    long long
#define MIN(x,y)  ((x)<(y)?(x):(y))
#define MAX(x,y)  ((x)>(y)?(x):(y))
#define ABS(x)    ((x)>0?(x):-(x))
#define PI    3.14159265358979323846
#define EPSILON   0.0000000001
 
// General parsing/formatting
 
ll toInt(string s) {stringstream in(s, ios_base::in); ll result; in >> result; return result;}
ld toDouble(string s) {stringstream in(s, ios_base::in); ld result; in >> result; return result;}
string toString(ll n) {stringstream out(ios_base::out); out << n; return out.str();}
string toString(ld d, int precision = -1) {stringstream out(ios_base::out); if (precision >= 0) {out.precision(precision); out.setf(ios::fixed);} out << d; return out.str();}
string toString(int n) {return toString((ll)(n));}
string toString(char ch) {string s="?"; s[0]=ch; return s;}
string toString(const string &s) {return s;}
string toString(pair<int,int> u) {return toString("(") + toString(u.first) + "," + toString(u.second) + ")";}
int getNumWords(string s) {stringstream in(s, ios_base::in); int result=0; string t; while (in>>t) result++; return result;}
string getWord(string s, int i) {stringstream in(s, ios_base::in); string t; for (;i>=0;i--) in >> t; return t;}
 
// Basic math
 
bool isEqual(ld v1, ld v2) {return ABS(v1-v2)<EPSILON;}
bool isLess(ld v1, ld v2) {return v1-v2<-EPSILON;}
ll gcd(ll n1, ll n2) {return n2==0? ABS(n1) : gcd(n2,n1%n2);}
ll lcm(ll n1, ll n2) {return n1==0 && n2==0? 0 : ABS(n1*n2)/gcd(n1,n2);}
 
// Real code
 
class ChessMetric {
  public:
  
  long long howMany(int size, vector <int> start, vector <int> end, int numMoves) {
    int sx=start[0];
    int sy=start[1];
    int ex=end[0];
    int ey=end[1];
    ll numWays[100][100];
    int i, j;
    
//    numWays.resize(size);
    for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
    numWays[i][j] = 0;
    numWays[sy][sx] = 1;
    
    while (numMoves > 0) {
      ll newWays[100][100];
      for (i = 0; i < size; i++)
      for (j = 0; j < size; j++)
      {
        newWays[i][j] = 0;
        for (int y = i-2; y <= i+2; y++)
        for (int x = j-2; x <= j+2; x++)
        if (x >= 0 && y >= 0 && x < size && y < size) {
          int dy = y-i;
          int dx = x-j;
          if (dx*dx + dy*dy == 8 || dx*dx + dy*dy == 4 || dx*dx + dy*dy == 0) continue;
          newWays[i][j] += numWays[y][x];
        }
      }
      
      for (i = 0; i < size; i++)
      for (j = 0; j < size; j++)
      numWays[i][j] = newWays[i][j];
      numMoves--;
    }
      
    return numWays[ey][ex];
  }
};