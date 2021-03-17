#include<bits/stdc++.h>
using namespace std;

// mirror of binary tree using recusrsion 
// just make post order traversal and swap the letf and right node

struct node
{
    struct node *left;
    int data;
    struct node *right;

}*head = NULL;

struct node *CreateNode(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;


}
void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void invert(struct node *temp)
{
    if(temp!=NULL)
    {
        invert(temp->left);
        invert(temp->right);

        swap(temp->left,temp->right);
    }
}
int main()
{

    head = CreateNode(1);               
    head->left = CreateNode(3);          
    head->right = CreateNode(2);        
    head->right->left = CreateNode(5);
    head->right->right = CreateNode(4);
    cout << "Tree element before inverting: \n";
     preorder(head);
     cout << "" << endl;
    cout << "Tree element after inverting: \n";
     invert(head);
     preorder(head);
    return 0;
}