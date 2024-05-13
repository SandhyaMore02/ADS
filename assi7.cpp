#include <iostream>
#include <string>
#include <queue>
using namespace std;

class TreeNode
{
public:
    char val;
    TreeNode *left, *right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    int preIndex = 0;

    TreeNode *buildTreeHelper(const string &preorder, const string &inorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return nullptr;
        char curr = preorder[preIndex++];
        TreeNode *node = new TreeNode(curr);
        if (inStart == inEnd)
            return node;
        int inIndex = 0;
        for (int i = inStart; i <= inEnd; ++i)
        {
            if (inorder[i] == curr)
            {
                inIndex = i;
                break;
            }
        }
        node->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1);
        node->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd);
        return node;
    }

public:
    TreeNode *buildTree(const string &preorder, const string &inorder)
    {
        preIndex = 0;
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }

    void postOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << ' ';
    }

    void displayLevelByLevel(TreeNode *root)
    {
        if (!root)
            return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *currentNode = q.front();
                q.pop();
                cout << currentNode->val << " ";
                if (currentNode->left)
                    q.push(currentNode->left);
                if (currentNode->right)
                    q.push(currentNode->right);
            }
            cout << endl;
        }
    }
};

int main()
{
    string preStr, inStr;
    cout << "Enter preorder sequence: ";
    cin >> preStr;
    cout << "Enter inorder sequence: ";
    cin >> inStr;

    BinaryTree bt;
    TreeNode *root = bt.buildTree(preStr, inStr);

    cout << "Postorder Traversal: ";
    bt.postOrder(root);
    cout << "\n\nLevel-by-Level Traversal:\n";
    bt.displayLevelByLevel(root);

    return 0;
}
