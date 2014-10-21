//geeksquiz.com/binary-search-tree-set-1-search-and-insertion/
#include<iostream>
using namespace std;
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
  
struct node
{
    int key;
    struct node *left, *right;
};
 
class BST
{ 
	struct node *root;
	public: BST(){root=NULL;}
	void insert(int key){insert(root,key);}
	void preOrder(void){print_order(root,1);}
	void inOrder(void){print_order(root,2);}
	void postOrder(void){print_order(root,3);}

	private: void print_order(struct node *node, int option)
	{
		if(node!=NULL)
		{
			if(option==1) cout<<node->key<<" "; //Pre-order
			print_order(node->left,option); 
			if(option==2) cout<<node->key<<" "; //In-order
			print_order(node->right,option);
			if(option==3) cout<<node->key<<" "; //Post-order
		}
	}
	struct node* newNode(int item)
	{
		struct node *nwN = new node(); nwN->key=item; nwN->left=nwN->right=NULL;
		return nwN;
	}
  	struct node* insert(struct node* node, int key)
	{
		if(node==NULL) return node==root?root=newNode(key):node=newNode(key);
		if(key<node->key) node->left=insert(node->left,key);
		else if(key>node->key) node->right=insert(node->right,key);   
		return node;
	}
};
  
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    cout<<endl<<" Binary Search Tree Operation Menu"<<endl;
    cout<<" ----------------------------- "<<endl;
    cout<<" 1. Insertion/Creation "<<endl;
	cout<<" 2. Pre-Order Traversal "<<endl;
    cout<<" 3. In-Order Traversal "<<endl;
    cout<<" 4. Post-Order Traversal "<<endl;
    cout<<" 5. Data Removal "<<endl;
    cout<<" 6. Default Data Insertion "<<endl;
    cout<<" 7. Exit "<<endl;

	BST bst=BST();
	int ch,tmp;

    while(1)
    {
       cout<<"Enter your choice : ";
       cin>>ch; cout<<endl;

       switch(ch)
       {
			case 1: 
					cout<<"Enter Number to be inserted : ";
					cin>>tmp;bst.insert(tmp);cout<<endl;
					break;
			case 2: 
					cout<<"Pre-Order Traversal ";
					bst.inOrder();cout<<endl;
					break;
			case 3: 
					cout<<"In-Order Traversal: ";
					bst.inOrder();cout<<endl;
					break;
			case 4: 
					cout<<"Post-Order Traversal ";
					bst.inOrder();cout<<endl;
					break;
			case 5: 
					cout<<"Enter data to be deleted : "; cout<<"Not Implemented yet"<<endl;
					//cin>>tmp;bst.remove(tmp); cout<<endl;
					break;
			case 6: 
					cout<<"Default data are: 50 20 40 70 60 80"<<endl;
					bst.insert(50);bst.insert(20);bst.insert(40);
					bst.insert(70);bst.insert(60);bst.insert(80);
					break;
			case 7:
					return 0;
                    
       }
    }
    return 0;
}
