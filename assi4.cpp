#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create a new node
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Insert a node
Node *insertNode(Node *root, int data)
{
    if (root == nullptr)
    {
        return createNode(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Create Binary Search Tree from user input
Node *createBST()
{
    Node *root = nullptr;
    int data;
    char choice;
    do
    {
        cout << "Enter data to insert into the BST: ";
        cin >> data;
        root = insertNode(root, data);
        cout << "Do you want to insert another element? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return root;
}

// In-order Traversal
void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Pre-order Traversal
void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order Traversal
void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Search for a Node and Print Path
void searchAndPrint(Node *root, int target)
{
    if (root == nullptr)
    {
        cout << "Target not found in the BST" << endl;
        return;
    }
    cout << "Path to " << target << ": ";
    while (root != nullptr && root->data != target)
    {
        cout << root->data << " -> ";
        if (target < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (root != nullptr && root->data == target)
    {
        cout << root->data << endl;
    }
    else
    {
        cout << "Target not found in the BST" << endl;
    }
}

// Print the BST Level by Level
void printLevelByLevel(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            Node *currentNode = q.front();
            q.pop();
            cout << currentNode->data << " ";
            if (currentNode->left)
            {
                q.push(currentNode->left);
            }
            if (currentNode->right)
            {
                q.push(currentNode->right);
            }
        }
        cout << endl;
    }
}

int main()
{
    Node *root = createBST();
    int target;
    int choice;
    cout << "Printing level by level\n";
    printLevelByLevel(root);
    do
    {
        cout << " Menu \n1. Inorder Traversal\n2. Preorder Traversal\n3. Postorder Traversal\n4. Search and Print Path\n5. Exit\nEnter Your Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Inorder Traversal Of BST:\n";
            inorderTraversal(root);
            cout << endl;
            break;
        case 2:
            cout << "Preorder Traversal Of BST:\n";
            preorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Postorder Traversal Of BST:\n";
            postorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Enter Target Node To Search: ";
            cin >> target;
            searchAndPrint(root, target);
            break;
        case 5:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}
