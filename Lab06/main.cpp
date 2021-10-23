#include "bst.cpp"

int main()
{
    BST<int> myBST;
    myBST.insert(5);
    myBST.insert(10);
    myBST.insert(3);
    myBST.insert(6);
    myBST.insert(2);
    myBST.insert(51);
    myBST.insert(1);
    myBST.insert(13);
    myBST.insert(4);
    if(myBST.search(6))
        cout << "6 se encuentra en el ABB\n";
    myBST.inOrder();
    cout << "\n";
    myBST.postOrder();
    cout << "\n";
    myBST.preOrder();
    cout << "\n";
    myBST.print2D();
    myBST.~BST();
    cout << "\n";
    return 0;
}