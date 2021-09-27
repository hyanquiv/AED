#include <iostream>

template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
    ~Node() = default;
    T getData()
    {
        return data;
    }
    void setNext(Node<T> *n)
    {
        next = n;
    }
    Node<T> *getNext()
    {
        return next;
    }
};

template <typename T>
class SingleLinkedList
{
private:
    Node<T> *first;
    Node<T> *last;
    int length;

public:
    SingleLinkedList()
    {
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    ~SingleLinkedList()
    {
        Node<T> *crawler = first;
        while (first)
        {
            crawler = first->getNext();
            delete first;
            first = crawler;
        }
        length = 0;
    }
    bool isEmpty()
    {
        if (first == nullptr && length == 0)
            return true;
        return false;
    }
    bool isSorted()
    {
        Node<T> *crawler = first;
        Node<T> *crawlerPrev = nullptr;
        while (crawler)
        {
            crawlerPrev = crawler;
            crawler = crawler->getNext();
            if (crawler->getData() < crawlerPrev->getData())
                return false;
        }
        return true;
    }
    void insertK(T info, int index)
    {
        Node<T> *toAdd = new Node<T>(info);
        if (first == nullptr)
        {
            if (index != 0)
                return;
            else
            {
                first = toAdd;
                last = toAdd;
                length++;
                return;
            }
        }
        else if (first != nullptr && index == 0)
        {
            toAdd->setNext(first);
            first = toAdd;
            length++;
            return;
        }
        else
        {
            Node<T> *crawler = first;
            Node<T> *crawlerPrev = nullptr;
            int indexActual = 0;
            while (indexActual < index)
            {
                crawlerPrev = crawler;
                crawler = crawler->getNext();
                if (crawler == nullptr)
                    break;
                indexActual++;
            }
            toAdd->setNext(crawler);
            crawlerPrev->setNext(toAdd);
            length++;
            if (toAdd->getNext() == nullptr)
                last = toAdd;
            return;
        }
        std::cout << "Posición Inválida!!!\n";
    }

    void insertTail (T info)
    {
        Node<T> *toAdd = new Node<T>(info);
        if(first == nullptr)
        {
            first = toAdd;
            last = toAdd;
        }
        else
        {
            last->setNext(toAdd);
            last = toAdd;
        }
        length++;
        return;
    }

    void sortedInsert(T info)
    {
        Node<T> *toAdd = new Node<T>(info);
        if (isEmpty())
        {
            first = toAdd;
            last = toAdd;
        }
        else if (info < first->getData())
        {
            toAdd->setNext(first);
            first = toAdd;
        }
        else
        {
            Node<T> *crawler = first;
            while (crawler->getNext() != nullptr && crawler->getNext()->getData() < info)
                crawler = crawler->getNext();
            toAdd->setNext(crawler->getNext());
            crawler->setNext(toAdd);
            if (toAdd->getNext() == nullptr)
                last = toAdd;
        }
        length++;
        return;
    }

    bool search(T value)
    {
        Node<T> *crawler = first;
        while (crawler)
        {
            crawler = crawler->getNext();
            if (crawler->getData() == value)
                return true;
        }
        return false;
    }

    void remove(T value)
    {
        if (first->getData() == value)
        {
            Node<T> *aux = first;
            first = first->getNext();
            delete aux;
            length--;
            return;
        }
        else
        {
            Node<T> *crawler = first;
            int index = 0;
            while (crawler->getNext() != nullptr)
            {
                crawler = crawler->getNext();
                index++;
                if (crawler->getData() == value)
                {
                    Node<T> *aux = first;
                    while (aux->getNext() != crawler)
                        aux = aux->getNext();
                    aux->setNext(crawler->getNext());
                    delete crawler;
                    length--;
                    std::cout << "El elemento " << value << " ,fue eliminado.\n";
                    return;
                }
            }
        }
        std::cout << "El elemento " << value << " ,NO existe en la lista.\n";
        return;
    }

    T min()
    {
        T min = first->getData();
        Node<T> *crawler = first;
        while (crawler != nullptr)
        {
            if (crawler->getData() < min)
                min = crawler->getData();
            crawler = crawler->getNext();
        }
        return min;
    }

    void reverse ()
    {
        Node<T> *current = first;
        Node<T> *prev = nullptr, *next = nullptr;

        while (current != nullptr)
        {
            next = current->getNext();

            current->setNext(prev);

            prev = current;
            current = next;
        }
        first = prev;
        return;
    }
    void print()
    {
        Node<T> *crawler = first;
        std::cout << "head -> ";
        while (crawler)
        {
            std::cout << crawler->getData() << " -> ";
            crawler = crawler->getNext();
        }
        std::cout << "nullptr\n";
        std::cout << "Tamaño: " << length << "\n";
        return;
    }
};
