#include "DoubleLinkedList.cpp"

template <typename T>
void printDataDLL (DoubleLinkedList<T> DLL)
{
    DLL.begin();
    std::cout << "first <-> ";
    while( DLL.getActual())
    {
        std::cout << DLL.GetData() <<" <-> ";
        DLL.nextTo();
    }
    std::cout<<"nullptr\n";
}

template <typename T>
void reverPrintDataDLL(DoubleLinkedList<T> DLL)
{
    DLL.final();
    std::cout << "nullptr <-> ";
    while (DLL.getActual())
    {
        std::cout << DLL.GetData() << " <-> ";
        DLL.prevTo();
    }
    std::cout << "first\n";
}

int main()
{
    DoubleLinkedList< int> DLL1;
    DLL1.insert(20);
    DLL1.printIter();
    DLL1.insert(8);
    DLL1.printIter();
    DLL1.insert(21);
    DLL1.printIter();
    DLL1.insert(31);
    DLL1.printIter();
    DLL1.insert(12);
    DLL1.printIter();
    DLL1.insert(50);
    DLL1.printIter();
    DLL1.search(20);
    DLL1.remove(21);
    DLL1.printIter();
    DLL1.maxIter();
    DLL1.maxRec(DLL1.getFirst() ,0);
    DLL1.reverPrintIter();
    DLL1.printRec(DLL1.getFirst());
    DLL1.reverPrintRec(DLL1.getLast());
    printDataDLL(DLL1);
    reverPrintDataDLL(DLL1);
    DLL1.~DoubleLinkedList();
}