//http://www.geeksforgeeks.org/b-tree-set-1-introduction-2/
#include<iostream>
using namespace std;
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)

class BTreeNode
{
    int deg,X,*keys;//An array of keys 
	bool leaf; //Is true when node is leaf. Otherwise false
    BTreeNode **child;//An array of child pointers  
public:
	BTreeNode(int deg1, bool leaf1)
	{
		X=0; deg=deg1; leaf=leaf1;
		keys=new int[2*deg-1];
		child=new BTreeNode *[2*deg];		
	}

	void traverse()
	{
		int i;
		for(i=0;i<X;i++){if(!leaf) child[i]->traverse(); cout<< " " <<keys[i];}
		if(leaf==false) child[i]->traverse();
	}
 
	BTreeNode* search(int val)
	{
		int i=0; while(i<X && val>keys[i]) i++;
		if(keys[i]==val) return this;
		if(leaf) return NULL;
		return child[i]->search(val);
	}
 
	void insertNonFull(int val)
	{		
		if(leaf){int i=X-1; while(i>=0 && keys[i]>val) keys[i+1]=keys[i--]; keys[i+1]=val; X++;}
		else
		{
			int i=X-1; while(i>=0 && keys[i]>val) i--;
			if(child[i+1]->X==2*deg-1){splitChild(i+1,child[i+1]); if(keys[i+1]<val) i++;}
			child[i+1]->insertNonFull(val);
		}
	}
 
	void splitChild(int i, BTreeNode *y)
	{
		BTreeNode *z=new BTreeNode(y->deg,y->leaf);z->X=deg-1;
		loop(j,deg-1) z->keys[j]=y->keys[j+deg];
		if(!y->leaf) loop(j,deg) z->child[j]=y->child[j+deg]; 
		for(int j=X; j>=i+1; j--) child[j+1]=child[j]; 
		for(int j=X-1; j>=i; j--) keys[j+1]=keys[j];
		y->X=deg-1; child[i+1]=z; keys[i]=y->keys[deg-1]; X++;
	}
	friend class BTree;
};
 
class BTree
{
    BTreeNode *root; int deg;//Max number of child per node
	public: BTree(int _t){root=NULL;  deg=_t;}
    void traverse(){if(root!=NULL) root->traverse();}
    BTreeNode *search(int val){return (root==NULL)?NULL:root->search(val);}
	void insert(int val)
	{	
		if(root==NULL){root=new BTreeNode(deg, true);root->keys[0]=val; root->X=1;}
		else //If tree is not empty
		{			
			if (root->X==2*deg-1)
			{
				BTreeNode *newNode=new BTreeNode(deg,false);			
				newNode->child[0]=root;
				newNode->splitChild(0, root);
				int i = 0; if(newNode->keys[0]<val) i++;
				newNode->child[i]->insertNonFull(val); root=newNode;
			}
			else root->insertNonFull(val);
		}
	}
};
  
// Driver program to test above functions
int main()
{
    int k; BTree t(3);  
    t.insert(6); t.insert(35); t.insert(5);
    t.insert(1); t.insert(15); t.insert(17);
	t.insert(10); t.insert(20); t.insert(1);
 
    cout<<"Traversal of the constucted tree is:";cout<<endl;
	t.traverse(); cout<<endl; cout<<endl;

    k=6; cout<<"The key "<<k<<" is ";
	(t.search(k)!=NULL) ? cout<<"Present" : cout<<"Not Present"; cout<<endl;

    k=16; cout<<"The key "<<k<<" is ";
	(t.search(k)!=NULL) ? cout<<"Present" : cout<<"Not Present"; cout<<endl;
    return 0;
}