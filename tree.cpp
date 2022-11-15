#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* getnode(int data)
{
    node* newnode = new(node);
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insert(node* root, int data)
{
    node* newnode = getnode(data);
    if(root == NULL)
    {
        root = newnode;
        return root;
    }
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

node* findnode(node* root, int data)
{
    if(root == NULL)
        return NULL;
    else if(data == root->data)
        return root;
    else if(data <= root->data)
        return findnode(root->left, data);
    else
        return findnode(root->right, data);   
}

void Inorder(node* root)
{
    if (root==NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(node* root)
{
    if (root==NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(node* root)
{
    if (root==NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void levelorder(node* root)
{
    if(root == NULL)
        return;
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if(current->left!= NULL)
            q.push(current->left);
        if(current->right!= NULL)
            q.push(current->right);
    }

}

int height(node* root)
{
    if(root== NULL)
        return -1;
    int lh, rh;
    lh = height(root->left);
    rh = height(root->right);
    if(lh>rh)
        return lh+1;
    else
        return rh+1;

}

bool isBSTDriver(node* root, int minvalue, int maxvalue)
{
    if(root == NULL)
        return true;
    
    else if(root->data > minvalue && root->data <= maxvalue && isBSTDriver(root->left, minvalue, root->data) && isBSTDriver(root->right, root->data, maxvalue))
        return true;
    else
        return false;
}

bool isBSTUtil(node* root)
{
    return isBSTDriver(root, INT_MIN, INT_MAX);
}

// ITERATIVE
void findMin(node* root)
{
    if(root == NULL)
        return;
    while(root->left!=NULL)
        root = root->left;
    cout << "Minimum is : " << root->data << endl;
}
void findMax(node* root)
{
    if(root == NULL)
        return;
    while(root->right!=NULL)
        root = root->right;
    cout << "Maximum is : " << root->data << endl;
}

// RECURSIVE
void recmin(node* root)
{
    if(root == NULL)
        return;
    else if(root->left == NULL)
        cout << "Minimum is : " << root->data << endl;
    else
        return recmin(root->left);
}
void recmax(node* root)
{
    if(root == NULL)
        return;
    else if(root->right == NULL)
        cout << "Maximum is : " << root->data << endl;
    else
        return recmax(root->right);
}

int main()
{
    node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 14);

    findnode(root, 9)? cout<<"found" : cout<< "not found";
    cout << endl;

    Inorder(root);
    cout << endl;
    Preorder(root);
    cout << endl;
    Postorder(root);
    cout << endl;
    levelorder(root);
    cout << endl;
    
    cout << height(root) << endl;

    isBSTUtil(root)? cout << "Yes" : cout << "No";
    cout << endl;

    findMin(root);
    findMax(root);
    recmin(root);
    recmax(root);
}


