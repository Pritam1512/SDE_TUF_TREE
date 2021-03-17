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
void leftView(struct node *temp)
{
    queue<struct node *> q;
    q.push(temp);


    while(q.size()!=0)
    {
        int t = q.size();
        for(int i=0;i<t;i++)
        {
            struct node *t = q.front();
            q.pop();
            if(i==0)
            {
                cout << t->data << " ";

            }
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
    }
}

int main()
{

    head = CreateNode(1);               
    head->left = CreateNode(3);          
    head->right = CreateNode(2);        
    head->right->left = CreateNode(5);
    head->right->right = CreateNode(4);
    
    leftView(head);
    
    return 0;
}