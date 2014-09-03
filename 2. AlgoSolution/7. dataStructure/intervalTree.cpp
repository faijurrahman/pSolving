//http://www.geeksforgeeks.org/interval-tree/
#include <iostream>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)

struct Interval
{
    int low, high;
};
 
struct intvNode
{
    int max;
    Interval *intv; 
    intvNode *left, *right;
};
 
intvNode *newNode(Interval intv)
{
    intvNode *temp = new intvNode;
    temp->intv = new Interval(intv);
    temp->max = intv.high;
    temp->left = temp->right = NULL;
	return temp;
};
 
intvNode *insert(intvNode *root, Interval intv)
{
    if(root==NULL) return newNode(intv);
    if(intv.low<root->intv->low) root->left=insert(root->left,intv);
    else root->right=insert(root->right,intv);

    if(root->max<intv.high) root->max=intv.high; 
    return root;
}
 
bool doOVerlap(Interval intv1, Interval intv2)
{
    if (intv1.low<=intv2.high && intv2.low<=intv1.high) return true;
    return false;
}
 
Interval *intervalSearch(intvNode *root, Interval intv)
{
    if(root==NULL) return NULL;
    if(doOVerlap(*(root->intv),intv)) return root->intv;

    if(root->left!=NULL && root->left->max>=intv.low) return intervalSearch(root->left,intv);
    else return intervalSearch(root->right,intv);
}
 
void inorder(intvNode *root)
{
    if(root==NULL) return;
    inorder(root->left); 
    cout << "["<<root->intv->low<< ", "<<root->intv->high<< "]"<< " max = "<<root->max<<endl;
    inorder(root->right);
}
 
// Driver program to test above functions
int main()
{
    Interval ints[] = { {15, 20}, {10, 30}, {17, 19},
						{ 5, 20}, {12, 15}, {30, 40}
					  };

    int X = sizeof(ints)/sizeof(ints[0]);
    intvNode *root = NULL;
    loop(i,X) root=insert(root,ints[i]);
 
    cout << "Inorder traversal of constructed Interval Tree is\n";
    inorder(root);cout<<endl;
 
    Interval x = {6, 7};
    cout << "Searching for interval [" << x.low << "," << x.high << "]"<<endl;
    Interval *res = intervalSearch(root, x);
    if (res == NULL) cout << "No Overlapping Interval"<<endl;
    else cout << "Overlaps with [" << res->low << ", " << res->high << "]"<<endl;
	
}