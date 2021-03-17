#include<bits/stdc++.h>
using namespace std;

//Inorder traversal using both recursion and stack

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
void Inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        Inorder(temp->left);
        cout << temp->data << " ";
        Inorder(temp->right);
    }
}

void InorderIterative(struct node *temp)
{
    stack<struct node *> s;

    while(temp!= NULL || s.size() != 0)
    {
        while(temp !=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();

        cout << temp->data << " ";
        temp = temp->right;
    }
}
int main()
{

    head = CreateNode(1);
    head->left = CreateNode(2);
    head->right = CreateNode(3);
    head->left->left = CreateNode(4);
    head->left->right = CreateNode(5);
    cout << "Inorder using recursion :\n";
    Inorder(head);
    cout << "" << endl;
    cout << "Inorder using stack :\n";
    InorderIterative(head);
    

    return 0;
}