//http://www.algolist.net/Data_structures/Hash_table/Chaining
#include<iostream>
using namespace std;
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)

class hashNode 
{
      public: int key, val; hashNode *next;
      hashNode(int key0, int val0){key=key0; val=val0; next=NULL;}
};
 
class hashMap 
{
	public: hashNode **table; int X;
	hashMap(int sz){X=sz; table=new hashNode*[X]; loop(i,X) table[i]=NULL;}
	int hash(int key){return key%X;}

	int get(int key) 
	{
		hashNode *entry=table[hash(key)];
		if(entry!=NULL) while(entry!=NULL && entry->key!=key) entry=entry->next;		
		return entry!=NULL?entry->val:-1;
	}
 
	void insert(int key, int val) 
	{
		hashNode *entry=table[hash(key)];
		if(entry==NULL) table[hash(key)] = new hashNode(key,val);
		else 
		{   while(entry->next!=NULL) entry=entry->next;
			if(entry->key==key) entry->val=val;
			else entry->next = new hashNode(key,val);
		}
	}
 
	void remove(int key) 
	{
		hashNode *pEntry=NULL, *entry=table[hash(key)];
		if(entry!=NULL) 
		{	while(entry->next!=NULL && entry->key!=key){pEntry=entry; entry=entry->next;}
			if(entry->key==key) 
			{
				if(pEntry==NULL){hashNode *nEntry=entry->next; delete entry; table[hash(key)]=nEntry;} 
				else{hashNode *next=entry->next; delete entry; pEntry->next=next;}
			}
		}
	}
};


// Driver Program to test above functions
int main()
{

    cout<<endl<<"Hash Table Operation Menu"<<endl;
    cout<<" ----------------------------- "<<endl;
    cout<<" 1. Insertion "<<endl;
	cout<<" 2. Show val "<<endl;
    cout<<" 3. Data Removal "<<endl;
    cout<<" 4. Exit "<<endl;

	hashMap hMap=hashMap(128);
	int ch,key,val;

    while(1)
    {
       cout<<endl<<"Enter your choice : ";
       cin>>ch; //cout<<endl;

       switch(ch)
       {
			case 1: 
					cout<<"Enter Key val Pair: ";
					cin>>key>>val;hMap.insert(key,val);
					break;
			case 2: 
					cout<<"Enter Key to Show val: "; 
					cin>>key; cout<<"HashTable["<<key<<"] = "<<hMap.get(key)<<endl;
					break;
			case 3: 
					cout<<"Enter Key to remove: "; 
					cin>>key;hMap.remove(key);
					break;
			case 4:
					return 0;
                    
       }
    }
    return 0;
}
