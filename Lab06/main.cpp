#include "bst.cpp"

int main()
{
    BST<int> myBST;
    myBST.insert(11);
    myBST.insert(12);
    myBST.insert(10);
    myBST.insert(9);
    myBST.insert(8);
    myBST.insert(17);
    myBST.insert(5);
    myBST.insert(1);
    myBST.insert(4);
    /*cout<<"La suma de las hojas es: "<<myBST.sumLeaves()<<"\n";
    if(myBST.search(6))
        cout << "6 se encuentra en el ABB\n";
    myBST.inOrder();
    cout << "\n";
    myBST.postOrder();
    cout << "\n";
    myBST.preOrder();
    cout << "\n";*/
    cout<<myBST.lowerBound(5)<<"\n";
    myBST.print2D();
    myBST.~BST();
    cout << "\n";
    /*Node<int> *root = new Node<int>(5);
    root->left = new Node<int>(3);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(8);
    root->left->right = new Node<int>(9);
    root->right->left = new Node<int>(9);
    root->right->right = new Node<int>(8);
    BST<int> bt;
    bt.setRoot(root);
    if(bt.isSim())
        cout<<"el arbol es simetrico.\n";
    bt.print2D();*/
    return 0;
}