//http://www.geeksforgeeks.org/b-tree-set-1-insert-2/
#include<iostream>
using namespace std;
 
// A BTree node
class BTreeNode
{
    int t, n; 
	bool leaf; // Is true when node is leaf. Otherwise false
    int *keys;  // An array of keys
    BTreeNode **C; // An array of child pointers  
public:
	BTreeNode::BTreeNode(int t1, bool leaf1)
	{
		n=0; t=t1; leaf=leaf1;
		keys=new int[2*t-1];
		C=new BTreeNode *[2*t];		
	}

	void traverse()
	{
		int i;
		for(i=0;i<n;i++)
		{
			if (leaf == false) C[i]->traverse();
			cout << " " << keys[i];
		}
		if(leaf==false) C[i]->traverse();
	}
 
	BTreeNode *search(int k)
	{
		int i = 0;
		while (i<n && k>keys[i]) i++;
		if (keys[i]==k) return this;
		if (leaf==true) return NULL;
		return C[i]->search(k);
	}
 
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
 
    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);
	friend class BTree;
};
 
// A BTree
class BTree
{
    BTreeNode *root; 
    int t; 
public:
    BTree(int _t){root=NULL;  t=_t;}
    void traverse(){if(root!=NULL) root->traverse();}
    BTreeNode *search(int k){return (root==NULL)?NULL:root->search(k);}

	// The main function that inserts a new key in this B-Tree
	void insert(int k)
	{
		// If tree is empty
		if(root==NULL)
		{
			root = new BTreeNode(t, true);
			root->keys[0]=k; root->n=1; 
		}
		else // If tree is not empty
		{
			// If root is full, then tree grows in height
			if (root->n == 2*t-1)
			{
				// Allocate memory for new root
				BTreeNode *s = new BTreeNode(t, false);
 
				// Make old root as child of new root
				s->C[0] = root;
 
				// Split the old root and move 1 key to the new root
				s->splitChild(0, root);
 
				// New root has two children now.  Decide which of the
				// two children is going to have new key
				int i = 0;
				if (s->keys[0] < k) i++;
				s->C[i]->insertNonFull(k);
				root = s;
			}
			else root->insertNonFull(k);
		}
	}
};
 
 
// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
void BTreeNode::insertNonFull(int k)
{
    int i=n-1;
    if(leaf==true)
    {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater keys to one place ahead
        while(i>=0 && keys[i]>k)
        {
            keys[i+1]=keys[i]; i--;
        }
 
        // Insert the new key at found location
        keys[i+1]=k; n++;
    }
    else
    {
        // Find the child which is going to have the new key
        while(i>=0 && keys[i]>k) i--;
 
        // See if the found child is full
        if(C[i+1]->n==2*t-1)
        {
            // If the child is full, then split it
            splitChild(i+1,C[i+1]);
 
            // After split, the middle key of C[i] goes up and
            // C[i] is splitted into two.  See which of the two
            // is going to have the new key
            if(keys[i+1]<k) i++;
        }
        C[i+1]->insertNonFull(k);
    }
}
 
// A utility function to split the child y of this node
// Note that y must be full when this function is called
void BTreeNode::splitChild(int i, BTreeNode *y)
{
    // Create a new node which is going to store (t-1) keys
    // of y
    BTreeNode *z=new BTreeNode(y->t,y->leaf);
    z->n=t-1;
 
    // Copy the last (t-1) keys of y to z
    for (int j=0; j<t-1; j++) z->keys[j]=y->keys[j+t];
 
    // Copy the last t children of y to z
    if(y->leaf==false) for(int j = 0; j < t; j++) z->C[j]=y->C[j+t];
 
    // Reduce the number of keys in y
    y->n=t-1;
 
    // Since this node is going to have a new child,
    // create space of new child
    for(int j=n; j>=i+1; j--) C[j+1]=C[j];
 
    // Link the new child to this node
    C[i+1]=z;
 
    // A key of y will move to this node. Find location of
    // new key and move all greater keys one space ahead
    for(int j=n-1; j>=i; j--) keys[j+1]=keys[j];
    keys[i]=y->keys[t-1];
    n++;
}
 
// Driver program to test above functions
int main()
{
    int k; BTree t(3); 
    t.insert(6); t.insert(7); t.insert(5);
    t.insert(12); t.insert(15); t.insert(17);
	t.insert(10); t.insert(20); t.insert(30);
 
    cout<<"Traversal of the constucted tree is:";cout<<endl;
	t.traverse(); cout<<endl; cout<<endl;

    k=6; cout<<"The key "<<k<<" is ";
	(t.search(k)!=NULL) ? cout<<"Present" : cout<<"Not Present"; cout<<endl;

    k=16; cout<<"The key "<<k<<" is ";
	(t.search(k)!=NULL) ? cout<<"Present" : cout<<"Not Present"; cout<<endl;
    return 0;
}