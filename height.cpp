#include<bits/stdc++.h>
using namespace std;

//height of binary tree
// using recursion


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
int height(struct node *temp)
{
    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        int l = height(temp->left);
        int r = height(temp->right);

        if(l>r)
        {
            return l+1;
        }
        else
        {
            return r+1; 
        }
    }
}
int main()
{

    head = CreateNode(1);               
    head->left = CreateNode(2);          
    head->right = CreateNode(3);        
    head->left->left = CreateNode(4);
    head->left->left->left = CreateNode(5);
   
    cout << height(head);
    return 0;
}