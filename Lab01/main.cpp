#include "SingleLinkedList.cpp"
#include "DoubleLinkedList.cpp"

int main()
{
    //prueba lista simplemente enlazada
    /*SingleLinkedList<int> SLL1;
    SLL1.insert(10);
    SLL1.print();
    SLL1.insert(20);
    SLL1.print();
    SLL1.insert(15);
    SLL1.print();
    SLL1.insert(13);
    SLL1.print();
    SLL1.insert(12);
    SLL1.print();
    SLL1.search(20);
    SLL1.remove(10);
    SLL1.print();*/
    //prueba lista doblemente enlazada
    DoubleLinkedList<int> DLL1;
    DLL1.insert(20);
    DLL1.print();
    DLL1.insert(8);
    DLL1.print();
    DLL1.insert(15);
    DLL1.print();
    DLL1.insert(13);
    DLL1.print();
    DLL1.insert(12);
    DLL1.print();
    DLL1.search(20);
    DLL1.remove(13);
    DLL1.print();
}