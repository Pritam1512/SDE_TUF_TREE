#include<bits/stdc++.h>
using namespace std;

//preorder traversal using both recursion and stack
// concept is same as inorder traversal


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
void preOrder(struct node *temp)
{
    if(temp != NULL)
    {
        cout << temp->data << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void preorderIterative(struct node *temp)
{
    stack<struct node *> s;

    while(temp != NULL || s.size() != 0)
    {
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

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
    cout << "preorder using recursion :\n";
    preOrder(head);
    cout << "" << endl;
    cout << "Preorder using stack :\n";
    preorderIterative(head);
    

    return 0;
}