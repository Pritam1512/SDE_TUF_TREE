#include<bits/stdc++.h>
using namespace std;

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
void topView(struct node *root)
{
    queue<pair<struct node * , int>> q;
    q.push({root,0});

    map<int,int> mp;// first value is hd and second value is node value

    while(q.size()!= 0 )
    {
        pair<struct node *,int> p = q.front();
        q.pop();

        struct node *temp = p.first;
        int hd = p.second;

       
           mp[hd] = temp->data;
        
        if(temp->left)q.push({temp->left,hd-1});
        if(temp->right)q.push({temp->right,hd+1});

    }

    for(auto x : mp)
    {
        cout << x.second << " ";
    }

}
int main()
{

    head = CreateNode(1);               
    head->left = CreateNode(2);          
    head->right = CreateNode(3);        
    head->left->left = CreateNode(4);
    head->left->right = CreateNode(5);
    head->right->left = CreateNode(6);
    
    topView(head);
    
    return 0;
}