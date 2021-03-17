#include<bits/stdc++.h>
using namespace std;

//level order traversal
//level order travresal line by line
//level order in spiral from(alternate)
//reverse level order travresal



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
void levelOrder(struct node *temp)
{
    queue<struct node*>q;
    q.push(temp);

    while(q.size()!=0)
    {
        struct node *t = q.front();
        q.pop();

        cout << t->data << " ";
        if(t->left!=NULL) q.push(t->left);
        if(t->right!=NULL) q.push(t->right);
    }
}
void levelOrderLBL(struct node *temp)
{
    queue<struct node *> q;
    q.push(temp);

    while(q.size()!=0)
    {
        int t = q.size();
        for(int i=0;i<t;i++)
        {
            struct node *v = q.front();
            q.pop();
            cout << v->data << " ";
            if(v->left)q.push(v->left);
            if(v->right)q.push(v->right);

        }
        cout << "" << endl;
    }
}
void alternateLevel(struct node *temp)
{
    stack<struct node *>s1;
    stack<struct node *>s2;
    s1.push(temp);
    while (s1.size()!=0 || s2.size()!=0)// break when both stacks are empty
    {
    /* code */
        while(s1.size()!=0)
        {
            struct node *t = s1.top();
            s1.pop();
            cout << t->data << " ";

            if(t->left!=NULL)s2.push(t->left);
            if(t->right!=NULL)s2.push(t->right);
        }
        while(s2.size()!=0)
        {
            struct node *t = s2.top();
            s2.pop();
            cout << t->data << " ";

            if(t->right!=NULL)s1.push(t->right);
            if(t->left!=NULL)s1.push(t->left);
        }
    }
}

void reverseLevelOrder(struct node *temp)
{
    queue<struct node*> q;
    stack<struct node *> s;

    q.push(temp);
    while(q.size()!=0)
    {
        struct node *t = q.front();
        q.pop();
        s.push(t);

        if(t->right) q.push(t->right);
        if(t->left) q.push(t->left);

    }

    while(s.size()!=0)
    {
        cout << s.top()->data << " ";
        s.pop();
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
    head->left->right->left = CreateNode(7);
    head->left->right->right = CreateNode(8);
    reverseLevelOrder(head);
    return 0;
}