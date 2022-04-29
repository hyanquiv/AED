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

    void setRoot(Node<T>* target) {this->root=target;}

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

public:
    T lowerBound(T key) { lowerBound(root, key); }
    bool pathSum(T key) { pathSum(root, key); }
    int countLarge(T key) { countLarge(root, key); }
    int sumLeaves() { sumLeaves(root); }
    bool isSim() {isSim(root,root);}

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

private:

    T lowerBound(Node<T> *treeNode, T key)
    {
        if (!treeNode)
            return 0;
        else if (treeNode->left == nullptr && treeNode->right == nullptr)
            return treeNode->data;
        else if (treeNode->data < key)
            return max(lowerBound(treeNode->left, key), lowerBound(treeNode->right, key));
    }  
        

    bool pathSum(Node<T> *treeNode, T key)
    {
        bool answer = false;
        T tester = key - treeNode->data;

        if (tester == 0 && treeNode->left == NULL && treeNode->right == NULL)
            return true;

        if (treeNode->left)
            answer = answer || pathSum(treeNode->left, tester);
        if (treeNode->right)
            answer = answer || pathSum(treeNode->right, tester);

        return answer;
    }

    int countLarge(Node<T> *treeNode, T key)
    {
        if (!treeNode)
            return 0;
        if (treeNode->data >= key)
            return 1;
        else
            return countLarge(treeNode->right, key) + countLarge(treeNode->left, key);
    }

    int sumLeaves(Node<T> *treeNode)
    {
        if (!treeNode)
            return 0;
        if (treeNode->left == nullptr && treeNode->right == nullptr)
            return treeNode->data;
        else
            return sumLeaves(treeNode->right) + sumLeaves(treeNode->left);
    }

    bool isSim(Node<T> *treeNode1, Node<T> *treeNode2)
    {
        if (treeNode1 == nullptr && treeNode2 == nullptr)
            return true;
        else if (treeNode1 != nullptr && treeNode2 != nullptr && treeNode1->data == treeNode2->data)
            return isSim(treeNode1->left, treeNode2->right) && isSim(treeNode1->right, treeNode2->left);
        else
            return false;
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