#include <iostream>
using namespace std;
#define SPACE 5

template <typename T>
struct Node
{
    Node<T>(T value) : data(value), left(nullptr), right(nullptr) {}
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
class BST
{
public:
    BST() { root = nullptr; }
    ~BST() { deleteBST(); }

    void insert(int data) { insert(root, data); }

    int getHeight() { return getHeight(root); }

    Node<T> *getMaxNode()
    {
        if (!root)
        {
            cout << "el ABB esta vacio!" << endl;
            return nullptr;
        }
        Node<T> *treeNode = root;
        while (treeNode->right)
            treeNode = treeNode->right;
        return treeNode;
    }
    Node<T> *getMinNode()
    {
        if (!root)
        {
            cout << "el ABB esta vacio!" << endl;
            return nullptr;
        }
        Node<T> *treeNode = root;
        while (treeNode->left)
            treeNode = treeNode->left;
        return treeNode;
    }

    void deleteBST() { deleteBST(root); }
    bool search(T key) { search(root, key); }

    void inOrder() { inOrder(root); }
    void preOrder() { preOrder(root); }
    void postOrder() { postOrder(root); }
    void print2D() { print2D(root, 10); }

private:
    Node<T> *root;

    void insert(Node<T> *treeNode, int data)
    {
        if (!treeNode)
        {
            treeNode = new Node<T>(data);
            root = treeNode;
        }
        else
        {
            if (data < treeNode->data)
            {
                if (!treeNode->left)
                {
                    Node<T> *treeTemp = new Node<T>(data);
                    treeNode->left = treeTemp;
                }
                else
                    insert(treeNode->left, data);
            }
            else
            {
                if (!treeNode->right)
                {
                    Node<T> *treeTemp = new Node<T>(data);
                    treeNode->right = treeTemp;
                }
                else
                    insert(treeNode->right, data);
            }
        }
    }

    int getHeight(Node<T> *treeNode)
    {
        if (!treeNode)
            return 0;
        return 1 + max(getHeight(treeNode->left), getHeight(treeNode->right));
    }

    bool search(Node<T> *treeNode, T key, bool answer = false)
    {
        if (!treeNode)
            return answer;
        if (treeNode->data == key)
            answer = true;

        if (treeNode->data < key)
            return search(treeNode->right, key, answer);

        return search(treeNode->left, key, answer);
    }

    void deleteBST(Node<T> *treeNode)
    {
        if (!treeNode)
            return;

        Node<T> *curTreeNode = treeNode;
        Node<T> *leftTreeNode = treeNode->left;
        Node<T> *rightTreeNode = treeNode->right;
        delete curTreeNode;
        deleteBST(leftTreeNode);
        deleteBST(rightTreeNode);
    }

    void inOrder(Node<T> *treeNode)
    {
        if (!treeNode)
            return;
        inOrder(treeNode->left);
        cout << treeNode->data << " ";
        inOrder(treeNode->right);
    }

    void preOrder(Node<T> *treeNode)
    {
        if (!treeNode)
            return;
        cout << treeNode->data << " ";
        preOrder(treeNode->left);
        preOrder(treeNode->right);
    }

    void postOrder(Node<T> *treeNode)
    {
        if (!treeNode)
            return;
        postOrder(treeNode->left);
        postOrder(treeNode->right);
        cout << treeNode->data << " ";
    }

    void print2D(Node<T> *treeNode, int space)
    {
        if (!treeNode)
            return;
        space += SPACE;
        print2D(treeNode->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
            cout << " ";
        cout << treeNode->data << "\n";
        print2D(treeNode->left, space);
    }
};