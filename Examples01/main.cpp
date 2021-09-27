
#include "SingleLinkedList.cpp"

template <typename T>
T min(SingleLinkedList<T> L)
{
    return L.min();
}

template <typename T>
bool isSorted(SingleLinkedList<T> L)
{
    return L.isSorted();
}

template <typename T>
void checksort(SingleLinkedList<T> L)
{
    if (L.isSorted())
    {
        std::cout << "La lista esta ordenada.\n";
        return;
    }
    else
    {
        std::cout << "La lista NO esta ordenada.\n";
        return;
    }
}
template <typename T>
void checkElement(SingleLinkedList<T> L, T data)
{
    if (L.search(data))
    {
        std::cout << "El elemento " << data << " ,SI fue hallado en la lista.\n";
        return;
    }
    else
    {
        std::cout << "El elemento " << data << " ,NO fue hallado en la lista.\n";
        return;
    }
}
template <typename T>
void reverse(SingleLinkedList<T> L)
{
    L.reverse();
}

int main()
{
    SingleLinkedList<int> SLL1;
    SLL1.sortedInsert(5);
    SLL1.sortedInsert(20);
    SLL1.sortedInsert(8);
    SLL1.sortedInsert(12);
    SLL1.sortedInsert(1);
    SLL1.insertK(18, 8);
    SLL1.insertTail(100);
    SLL1.print();
    SLL1.reverse();
    SLL1.print();
    //std::cout << "Minino: " << min(SLL1) << "\n";
    //checksort(SLL1);
    checkElement(SLL1, 20);
    SLL1.~SingleLinkedList();
    return 0;
}