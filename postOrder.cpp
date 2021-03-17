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
void postOrder(struct node *temp)
{
    if(temp!=NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data << " ";
    }
    return;
}

void postOrderIterative(struct node *temp)
{
    stack<struct node *> s;

    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
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
    cout << "postorder using recursion :\n";
    postOrder(head);
    cout << "" << endl;
    cout << "postorder using stack :\n";
    postOrderIterative(head);
    

    return 0;
}