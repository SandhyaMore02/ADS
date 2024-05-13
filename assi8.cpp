#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    string key;
    string value;
    node *left, *right;
    node(string k = "", string v = "") : key(k), value(v), left(NULL), right(NULL) {}
                                         
};
class AVL
{
private:
    node *AVLroot;
    node *insert1(node *T, string k, string v);
    node *deleteNode(node *T, string k);
    void preorder1(node *T);
    void inorder1(node *T);
    void reverseInorder1(node *T);
    node *findMin(node *T);
    node *findMax(node *T);
    int height(node *T);
    node *rotateright(node *x);
    node *rotateleft(node *x);
    node *RR(node *T);
    node *LL(node *T);
    node *LR(node *T);
    node *RL(node *T);
    int BF(node *T);
    pair<bool, int> search1(node *T, string k);

public:
    AVL() : AVLroot(NULL) {}
    void insert(string k, string v)
    {
        AVLroot = insert1(AVLroot, k, v);
    }
    void deleteKey(string k)
    {
        AVLroot = deleteNode(AVLroot, k);
    }
    void preorder()
    {
        preorder1(AVLroot);
    }
    void inorder()
    {
        inorder1(AVLroot);
    }
    void reverseInorder()
    {
        reverseInorder1(AVLroot);
    }
    void search(string k)
    {
        auto result = search1(AVLroot, k);
        if (result.first)
        {
            cout << "Key " << k << " found with " << result.second
                 << " comparisons." << endl;
        }
        else
        {
            cout << "Key " << k << " not found with " << result.second << " comparisons." << endl;
        }
    }
};
node *AVL::insert1(node *T, string k, string v)
{
    if (T == NULL)
    {
        T = new node(k, v);
    }
    else if (k > T->key)
    {
        T->right = insert1(T->right, k, v);
        if (BF(T) == -2)
            T = (k > T->right->key) ? RR(T) : RL(T);
    }
    else if (k < T->key)
    {
        T->left = insert1(T->left, k, v);
        if (BF(T) == 2)
            T = (k < T->left->key) ? LL(T) : LR(T);
    }
    return T;
}
int AVL::height(node *T)
{
    if (!T)
        return 0;
    int lh = height(T->left);
    int rh = height(T->right);
    return 1 + max(lh, rh);
}
node *AVL::rotateright(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
node *AVL::rotateleft(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
node *AVL::RR(node *T)
{
    return rotateleft(T);
}
node *AVL::LL(node *T)
{
    return rotateright(T);
}
node *AVL::LR(node *T)
{
    T->left = rotateleft(T->left);
    return rotateright(T);
}
node *AVL::RL(node *T)
{
    T->right = rotateright(T->right);
    return rotateleft(T);
}
int AVL::BF(node *T)
{
    return height(T->left) - height(T->right);
}
void AVL::preorder1(node *T)
{
    if (T != NULL)
    {
        cout << " " << T->key << ":" << T->value << "(Bf=" << BF(T) << ")";
        preorder1(T->left);
        preorder1(T->right);
    }
}
void AVL::inorder1(node *T)
{
    if (T != NULL)
    {
        inorder1(T->left);
        cout << " " << T->key << ":" << T->value << "(Bf=" << BF(T) << ")";
        inorder1(T->right);
    }
}
void AVL::reverseInorder1(node *T)
{
    if (T != NULL)
    {
        reverseInorder1(T->right);
        cout << " " << T->key << ":" << T->value << "(Bf=" << BF(T) << ")";
        reverseInorder1(T->left);
    }
}
pair<bool, int> AVL::search1(node *T, string k)
{
    int comparisons = 0;
    while (T != NULL)
    {
        comparisons++;
        if (k == T->key)
        {
            return make_pair(true, comparisons);
        }
        else if (k < T->key)
        {
            T = T->left;
        }
        else
        {
            T = T->right;
        }
    }
    return make_pair(false, comparisons);
}
node *AVL::deleteNode(node *T, string k)
{
    if (T == NULL)
    {
        return T;
    }
    else if (k < T->key)
    {
        T->left = deleteNode(T->left, k);
    }
    else if (k > T->key)
    {
        T->right = deleteNode(T->right, k);
    }
    else
    {

        if (T->left == NULL || T->right == NULL)
        {
            node *temp = T->left ? T->left : T->right;
            if (temp == NULL)
            {
                temp = T;
                T = NULL;
            }
            else
            {
                *T = *temp;
            }
            delete temp;
        }
        else
        {

            node *temp = findMin(T->right);
            T->key = temp->key;
            T->value = temp->value;
            T->right = deleteNode(T->right, temp->key);
        }
    }
    if (T == NULL)
        return T;

    T = insert1(NULL, T->key, T->value);
    return T;
}
node *AVL::findMin(node *T)
{
    node *current = T;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
int main()
{
    AVL tree;
    string key, value;
    int n, choice;
    char ch;
    do
    {
        cout << "\n\nAVL TREE";
        cout << "\n\n1.Create";
        cout << "\n\n2.Display";
        cout << "\n\n3.Insert";
        cout << "\n\n4.Delete";
        cout << "\n\n5.Search";
        cout << "\n\n6.Display Ascending";
        cout << "\n\n7.Display Descending";
        cout << "\n\n8.Exit";
        cout << "\n\nEnter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter no.of elements: ";
            cin >> n;
            cout << "\nEnter tree data (key value pairs): ";
            for (int i = 0; i < n; i++)
            {
                cin >> key >> value;
                tree.insert(key, value);
            }
            break;
        case 2:
            cout << "\nPreorder sequence:\n";
            tree.preorder();
            cout << "\nInorder sequence:\n";
            tree.inorder();
            break;
        case 3:
            cout << "\nEnter a key and value: ";
            cin >> key >> value;
            tree.insert(key, value);
            break;
        case 4:
            cout << "\nEnter a key to delete: ";
            cin >> key;
            tree.deleteKey(key);
            break;
        case 5:
            cout << "\nEnter a key to search: ";
            cin >> key;
            tree.search(key);
            break;
        case 6:
            cout << "\nInorder sequence (Ascending):\n";
            tree.inorder();
            break;
        case 7:
            cout << "\nReverse Inorder sequence (Descending):\n";
            tree.reverseInorder();
            break;
        case 8:
            return 0;
        default:
            cout << "\nInvalid choice";
        }
        cout << "\nDo you want to continue (y/n)?: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
