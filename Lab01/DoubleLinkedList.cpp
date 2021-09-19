#include <iostream>

template <typename T>
class Dnode
{
private:
    T data;
    Dnode<T> *next;
    Dnode<T> *prev;

public:
    Dnode(T data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    ~Dnode() = default;
    T getData()
    {
        return data;
    }
    void setNext(Dnode<T> *n)
    {
        next = n;
    }
    Dnode<T> *getNext()
    {
        return next;
    }
    void setPrev(Dnode<T> *p)
    {
        prev = p;
    }
    Dnode<T> *getPrev()
    {
        return prev;
    }
};

template <typename T>
class DoubleLinkedList
{
private:
    Dnode<T> *first;
    int length;

public:
    DoubleLinkedList()
    {
        first = nullptr;
        length = 0;
    }
    ~DoubleLinkedList()
    {
        Dnode<T> *crawler = first;
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
    void insert(T info)
    {
        Dnode<T> *toAdd = new Dnode<T>(info);
        if (isEmpty())
        {
            first = toAdd;
        }
        else if (info < first->getData())
        {
            toAdd->setNext(first);
            first->setPrev(toAdd);
            first = toAdd;
        }
        else
        {
            Dnode<T> *crawler = first;
            while (crawler->getNext() != nullptr && crawler->getNext()->getData() < info)
                crawler = crawler->getNext();
            toAdd->setPrev(crawler);
            toAdd->setNext(crawler->getNext());
            if (crawler->getNext())
                crawler->getNext()->setPrev(toAdd);
            crawler->setNext(toAdd);
        }
        length++;
    }
    void search(T value)
    {
        Dnode<T> *crawler = first;
        while (crawler->getNext() != nullptr)
        {
            crawler = crawler->getNext();
            if (crawler->getData() == value)
            {
                std::cout << "El elemento " << value << " ,SI fue hallado en la lista.\n";
                return;
            }
        }
        std::cout << "El elemento " << value << " ,NO fue hallado en la lista.\n";
        return;
    }

    void remove(T value)
    {
        if (first->getData() == value)
        {
            Dnode<T> *aux = first;
            first = first->getNext();
            delete aux;
            length--;
            return;
        }
        else
        {
            Dnode<T> *crawler = first;
            int index = 0;
            while (crawler->getNext() != nullptr)
            {
                crawler = crawler->getNext();
                index++;
                if (crawler->getData() == value)
                {
                    Dnode<T> *aux = first;
                    while (aux->getNext() != crawler)
                        aux = aux->getNext();
                    aux->setNext(crawler->getNext());
                    crawler->getNext()->setPrev(aux);
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

    void print()
    {
        Dnode<T> *crawler = first;
        std::cout << "head <-> ";
        while (crawler)
        {
            std::cout << crawler->getData() << " <-> ";
            crawler = crawler->getNext();
        }
        std::cout << "nullptr\n";
        std::cout << "Tamaño: " << length << "\n";
    }
};
