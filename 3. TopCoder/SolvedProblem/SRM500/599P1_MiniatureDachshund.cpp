//C Header
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>

//STL Header
//#include<array>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<forward_list>
#include<unordered_map>
#include<unordered_set>

//Essential Header
#include<algorithm>
#include<numeric>
#include<string>

//IO Header
#include<iostream>
#include<fstream> 
#include<sstream>

using namespace std;

//Some Definition
#define LOOP(i,a,b) for(int i=(a);i<(b);i++)
#define loop(i,n) LOOP(i,0,n)

#define All(container) container.begin(),container.end()
#define rAll(container) container.rbegin(),container.rend()


class MiniatureDachshund {

	public:
	int maxMikan(vector <int> mikan, int weight) {
		int n=mikan.size();
		sort(All(mikan));
		loop(i,n) 
		{
			weight+=mikan[i];
			if(weight>5000)	return i;
		}
		return n;
	}
};


    
