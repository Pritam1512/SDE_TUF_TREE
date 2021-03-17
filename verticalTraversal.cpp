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
void getVerticalOrder(struct node *temp , int hd,map<int ,vector<int>> &mp)
{
    if(temp==NULL)
        return;
    else
    {
        mp[hd].push_back(temp->data);
        getVerticalOrder(temp->left,hd-1,mp);
        getVerticalOrder(temp->right,hd+1,mp);
    }
}
void verticalOrder(struct node *root)
{
    map<int ,vector<int>> mp;
    int hd = 0;
    getVerticalOrder(root,0,mp);
    vector<int> res;
    map< int,vector<int> > :: iterator it;
    for (it=mp.begin(); it!=mp.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
           res.push_back(it->second[i]);
        
    }

    for(auto x : res)
    {
        cout << x << " ";
    }
}

int main()
{

    head = CreateNode(1);               
    head->left = CreateNode(2);          
    head->right = CreateNode(3);        
    head->left->left = CreateNode(4);
    head->left->right = CreateNode(5);
    head->right->right = CreateNode(6);
    
    ///leftView(head);
    verticalOrder(head);
    
    return 0;
}