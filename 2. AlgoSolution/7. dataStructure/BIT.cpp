//geeksquiz.com/binary-search-tree-set-1-search-and-insertion/
#include<vector>
#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
  
class BIT
{ 
	public: int X; vector<long long> tree;
	BIT(int x){resize(x);}
	void resize(int x){X=x; tree.resize(X+1); loop(i,X+1) tree[i]=0;}

	void addVal(int idx, long long val)
	{ 
		for(int i=idx+1; 0<i && i<=X; i+=(i&-i)) tree[i]+=val;
	}

	int getVal(int idx)
	{
		int i=idx+1, sum=tree[i], XX=i-(i&-i);
		if(--i>0) for(; 0<i && i!=XX; i-=(i&-i)) sum-=tree[i];
		return sum;
	}

	void setVal(int idx, long long val)
	{
		addVal(idx,val-=getVal(idx));
	}

	long long getSum(int idx)
	{
		long long sum=0;
		for(int i=idx+1; 0<i && i<=X; i-=(i&-i)) sum+=tree[i];
		return sum;
	}

	void scale(long long c)
	{ 
		loop(i,X+1) tree[i]/=c;
	}

	int findIndex(long long cumFreq)
	{
		int i=0, mask=X;
		while(0<mask && i<X)
		{   
			int j=i+mask; mask>>=1;
			if(cumFreq>=tree[j])
			{ 
				i=j; 
				cumFreq-=tree[j];
			}
		}
		return cumFreq>=0?i-1:-1;
	}
};

/*
class BIT2D
{ 
	public: int X,Y; vector<int,int> tree;
	BIT2D(int x, int y){X=x; Y=y; tree.resize(X); loop(i,X) tree[i].resize(Y);}
	BIT2D(vector<int,int> tre){tree=tre; X=tree.size(); Y=tree[0].size();}

	long long read(int i){long long sum=0;while(i>0){sum+=tree[i];i-=(i&-i);}return sum;}
	void scale(int c){ LOOP(i,1,X+1) tree[i]/=c;}
	int readSingle(int i)
	{
		int sum=tree[i], z=i-(i & -i); i--;
		if(i>0) while(i!=z){ sum-=tree[i]; i-=(i & -i);}
		return sum;
	}

	void update(int x , int y , int val)
	{  
		int y1; while(x<=X){y1=y; while(y1<=Y){ tree[x][y1]+=val; y1+=(y1&-y1);} x+=(x&-x);}
	}
};
*/


// Driver Program to test above functions
int main()
{
    cout<<endl<<"Binary Indexed Tree Operation Menu"<<endl;
    cout<<" ----------------------------- "<<endl;
    cout<<" 1. Add Value of a Index "<<endl;
    cout<<" 2. Find Value of a Index "<<endl;
    cout<<" 3. Find Summation by Index "<<endl;
    cout<<" 4. Find Index by Value"<<endl;
    cout<<" d/D. Use Default data "<<endl;   
	cout<<" e/E. Exit "<<endl<<endl;

	class BIT bit(100); int key,key2,val; char ch;
    while(1)
    {
       cout<<"Enter your choice : ";cin>>ch;
       switch(ch)
       {
			case '1': 
					cout<<"Enter Index Value pair: ";cin>>key>>val;
					bit.addVal(key,val);cout<<endl;
					break;
			case '2': 
					cout<<"Enter Index: ";cin>>key;
					cout<<"Value: "<<bit.getVal(key)<<endl<<endl;
					break;
			case '3': 
					cout<<"Enter Index: ";cin>>key;
					cout<<"Summation: "<<bit.getSum(key)<<endl<<endl;
					break;
			case '4': 
					cout<<"Enter Value: ";cin>>val;
					cout<<"Random Index: "<<bit.findIndex(val)<<endl<<endl;
					break;
			case 'd':
			case 'D':
					cout<<"Default Index-Value pairs:(0,10), (1,20), (2,30), (3,40), (4,50), (5,60)"<<endl<<endl;
					bit.addVal(0,10);bit.addVal(1,20);bit.addVal(2,30);
					bit.addVal(3,40);bit.addVal(4,50);bit.addVal(5,60);
					break; 
			case 'e':
			case 'E':
					return 0;                   
       }
    }
    return 0;
}
