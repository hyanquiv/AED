#include <iostream>

template <typename T>
class Cnode
{
private:
    T data;
    Cnode<T> *next;
    Cnode<T> *prev;

public:
    Cnode(T data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    ~Cnode() = default;
    T getData()
    {
        return data;
    }
    void setNext(Cnode<T> *n)
    {
        next = n;
    }
    Cnode<T> *getNext()
    {
        return next;
    }
    void setPrev(Cnode<T> *p)
    {
        prev = p;
    }
    Cnode<T> *getPrev()
    {
        return prev;
    }
};

template <typename T>
class CircularLinkedList
{
private:
    Cnode<T> *first;
    Cnode<T> *last;
    int length;

public:
    CircularLinkedList()
    {
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    ~CircularLinkedList()
    {
        Cnode<T> *crawler = first;
        while (first)
        {
            crawler = first->getNext();
            delete first;
            first = crawler;
        }
        length = 0;
    }
    Cnode<T> *getFirst()
    {
        return first;
    }
    Cnode<T> *getLast()
    {
        return last;
    }
    bool isEmpty()
    {
        if (first == nullptr && length == 0)
            return true;
        return false;
    }
    void insert(T info)
    {
        Cnode<T> *toAdd = new Cnode<T>(info);
        if (isEmpty())
        {
            first = toAdd;
            last = toAdd;
        }
        else if (info < first->getData())
        {
            toAdd->setNext(first);
            first->setPrev(toAdd);
            first = toAdd;
            first->setPrev(last);
            last->setNext(first);
        }
        else
        {
            Cnode<T> *crawler = first;
            while (crawler->getNext() != first && crawler->getNext()->getData() < info)
                crawler = crawler->getNext();
            toAdd->setPrev(crawler);
            toAdd->setNext(crawler->getNext());
            if (crawler->getNext())
                crawler->getNext()->setPrev(toAdd);
            crawler->setNext(toAdd);
            if (toAdd->getNext() == first)
                last = toAdd;
            first->setPrev(last);
            last->setNext(first);
        }
        length++;
    }
    void search(T value)
    {
        Cnode<T> *crawler = first;
        while (crawler->getNext() != first)
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
            Cnode<T> *aux = first;
            first = first->getNext();
            delete aux;
            first->setPrev(last);
            last->setNext(first);
            length--;
            return;
        }
        else
        {
            Cnode<T> *crawler = first;
            while (crawler->getNext() != first)
            {
                crawler = crawler->getNext();
                if (crawler->getData() == value)
                {
                    Cnode<T> *aux = first;
                    while (aux->getNext() != crawler)
                        aux = aux->getNext();
                    aux->setNext(crawler->getNext());
                    crawler->getNext()->setPrev(aux);
                    if (crawler->getNext() == first)
                        last = aux;
                    delete crawler;
                    first->setPrev(last);
                    last->setNext(first);
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
        bool loop = true;
        Cnode<T> *crawler = first;
        std::cout << "first <-> ";
        while (crawler != first || loop)
        {
            std::cout << crawler->getData() << " <-> ";
            crawler = crawler->getNext();
            if (crawler->getNext() == first)
                loop = false;
        }
        std::cout << "last\n";
    }

    void reverPrint()
    {
        bool loop = true;
        Cnode<T> *crawler = last;
        std::cout << "last <-> ";
        while (crawler != last || loop)
        {
            std::cout << crawler->getData() << " <-> ";
            crawler = crawler->getPrev();
            if (crawler->getPrev() == last)
                loop = false;
        }
        std::cout << "first\n";
    }
};