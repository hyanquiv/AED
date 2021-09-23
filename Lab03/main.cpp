#include "CircularLinkedList.cpp"

template <typename T>
void concatCLL(CircularLinkedList<T> CLL_target, CircularLinkedList<T> CLL_source)
{
    CLL_target.getFirst()->setPrev(CLL_source.getLast());
    CLL_target.getLast()->setNext(CLL_source.getFirst());
    CLL_source.getFirst()->setPrev(CLL_target.getLast());
    CLL_source.getLast()->setNext(CLL_target.getFirst());
}

int main()
{
    CircularLinkedList<int> CLL1, CLL2;

    CLL1.insert(20);
    CLL1.insert(10);
    CLL1.insert(11);
    CLL1.insert(11);
    CLL1.print();
    CLL1.search(20);
    CLL1.remove(31);
    CLL1.reverPrint();
   
    CLL2.insert(8);
    CLL2.insert(99);
    CLL2.insert(24);
    CLL2.insert(15);
    CLL2.print();

    concatCLL(CLL1,CLL2);
    CLL1.print();

    CLL1.~CircularLinkedList();
    CLL2.~CircularLinkedList();
    return 0;
}