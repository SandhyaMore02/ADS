#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    string key;
    string value;
    Node *left;
    Node *right;
};
class Dictionary
{
private:
    Node *root;
    Node *insertUtil(Node *node, string key, string value)
    {
        if (node == nullptr)
        {
            Node *newNode = new Node;
            newNode->key = key;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }
        if (key < node->key)
        {
            node->left = insertUtil(node->left, key, value);
        }
        else if (key > node->key)
        {
            node->right = insertUtil(node->right, key, value);
        }
        else
        {
            // Key already exists, update the value
            node->value = value;
        }
        return node;
    }
    Node *searchUtil(Node *node, string key, int &comparisons)
    {
        comparisons++;
        if (node == nullptr || node->key == key)
        {
            return node;
        }
        if (key < node->key)
        {
            return searchUtil(node->left, key, comparisons);
        }
        else
        {
            return searchUtil(node->right, key, comparisons);
        }
    }
    void inorderUtil(Node *node)
    {
        if (node == nullptr)
            return;
        inorderUtil(node->left);
        cout << node->key << ": " << node->value << endl;
        inorderUtil(node->right);
    }
    void reverseInorderUtil(Node *node)
    {
        if (node == nullptr)
            return;
        reverseInorderUtil(node->right);
        cout << node->key << ": " << node->value << endl;
        reverseInorderUtil(node->left);
    }

public:
    Dictionary()
    {
        root = nullptr;
    }
    void insert(string key, string value)
    {
        root = insertUtil(root, key, value);
    }
    string find(string key, int &comparisons)
    {
        Node *found = searchUtil(root, key, comparisons);
        if (found != nullptr)
        {
            return found->value;
        }
        else
        {
            return "Key not found";
        }
    }
    void displayAscending()
    {
        cout << "Dictionary contents in ascending order:" << endl;
        inorderUtil(root);
    }
    void displayDescending()
    {
        cout << "Dictionary contents in descending order:" << endl;
        reverseInorderUtil(root);
    }
};
int main()
{
    Dictionary dictionary;
    int choice;
    do
    {
        cout << "\nDictionary Operations:" << endl;
        cout << "1. Insert (key, value) pair" << endl;
        cout << "2. Find value by key" << endl;
        cout << "3. Display contents in ascending order" << endl;
        cout << "4. Display contents in descending order" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string key, value;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            dictionary.insert(key, value);
            break;
        }
        case 2:
        {
            string key;
            cout << "Enter key to find: ";
            cin >> key;
            int comparisons = 0;
            string result = dictionary.find(key, comparisons);
            cout << "Result: " << result << endl;
            cout << "Number of comparisons made: " << comparisons << endl;
            break;
        }
        case 3:
            dictionary.displayAscending();
            break;
        case 4:
            dictionary.displayDescending();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}