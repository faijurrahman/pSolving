//http://www.geeksforgeeks.org/ternary-search-tree/
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define MAX 50
 
struct Node
{
    char data;
    unsigned isEndOfString: 1;
    struct Node *left, *eq, *right;
};

struct Node* newNode(char data)
{
    struct Node* temp = new Node;
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}
 
// Function to insert a new word in a Ternary Search Tree
void insert(struct Node** root, char *word)
{
    // Base Case: Tree is empty
    if (!(*root)) *root = newNode(*word);
 
    // If current character of word is smaller than root's character,
    // then insert this word in left subtree of root
    if ((*word) < (*root)->data) insert(&( (*root)->left ), word);
    // If current character of word is greate than root's character,
    // then insert this word in right subtree of root
    else if ((*word) > (*root)->data) insert(&( (*root)->right ), word);
    // If current character of word is same as root's character,
    else
    {
        if (*(word+1)) insert(&( (*root)->eq ), word+1);
 
        // the last character of the word
        else (*root)->isEndOfString = 1;
    }
}
 
// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node* root, char* buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);
 
        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth+1] = '\0';
            cout<< buffer <<endl;
        }
 
        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->eq, buffer, depth + 1); 
        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}

void traverseTST(struct Node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}
 
int searchTST(struct Node *root, char *word)
{
    if (!root) return 0;
    if(*word < (root)->data) return searchTST(root->left, word);
    else if(*word > (root)->data) return searchTST(root->right, word);
    else 
	{
		if(*(word+1) == '\0') return root->isEndOfString;
		return searchTST(root->eq, word+1);
	}
}
 
// Driver program to test above functions
int main()
{
    struct Node *root = NULL;
    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");
 
    cout<<"Following is traversal of ternary search tree"<<endl;
    traverseTST(root);cout<<endl;
 
    cout<<"Following are search results for cats, bu and cat respectively"<<endl;
    searchTST(root, "cats")? cout<<"Found": cout<<"Not Found";cout<<endl;
    searchTST(root, "bu")?   cout<<"Found": cout<<"Not Found";cout<<endl;
    searchTST(root, "cat")?  cout<<"Found": cout<<"Not Found";cout<<endl;
 
    return 0;
}