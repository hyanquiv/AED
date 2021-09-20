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
    Dnode<T> *last;
    Dnode<T> *pActual;
    int length;

public:
    DoubleLinkedList()
    {
        first = nullptr;
        last = nullptr;
        pActual = nullptr;
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
    Dnode<T> *getFirst()
    {
        return first;
    }
    Dnode<T> *getLast()
    {
        return last;
    }
    Dnode<T> *getActual()
    {
        return pActual;
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
            last = toAdd;
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
            if (toAdd->getNext() == nullptr)
                last = toAdd;
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
            while (crawler->getNext() != nullptr)
            {
                crawler = crawler->getNext();
                if (crawler->getData() == value)
                {
                    Dnode<T> *aux = first;
                    while (aux->getNext() != crawler)
                        aux = aux->getNext();
                    aux->setNext(crawler->getNext());
                    crawler->getNext()->setPrev(aux);
                    if (crawler->getNext() == nullptr)
                        last = aux;
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

    void maxIter()
    {
        Dnode<T> *crawler = first;
        T max = NULL;
        while (crawler)
        {
            if (crawler->getData() > max)
                max = crawler->getData();
            crawler = crawler->getNext();
        }
        std::cout << "Maximo Elemento: " << max << "\n";
        return;
    }

    void maxRec(Dnode<T> *follow, T max)
    {
        if (follow->getData() > max)
            max = follow->getData();
        if (follow->getNext() != nullptr)
            maxRec(follow->getNext(), max);
        else
            std::cout << "Maximo Elemento: " << max << "\n";
        return;
    }

    void printIter()
    {
        Dnode<T> *crawler = first;
        std::cout << "first <-> ";
        while (crawler)
        {
            std::cout << crawler->getData() << " <-> ";
            crawler = crawler->getNext();
        }
        std::cout << "nullptr\n";
    }

    void reverPrintIter()
    {
        Dnode<T> *crawler = last;
        std::cout << "nullptr <-> ";
        while (crawler)
        {
            std::cout << crawler->getData() << " <-> ";
            crawler = crawler->getPrev();
        }
        std::cout << "first\n";
    }

    void printRec(Dnode<T> *crawler)
    {
        if (crawler == first)
            std::cout << "first <-> ";
        if (crawler == nullptr)
        {
            std::cout << "nullptr\n";
            return;
        }
        else
        {
            std::cout << crawler->getData() << " <-> ";
            printRec(crawler->getNext());
        }
    }
    void reverPrintRec(Dnode<T> *crawler)
    {
        if (crawler == last)
            std::cout << "nullptr <-> ";
        if (crawler == nullptr)
        {
            std::cout << "first\n";
            return;
        }
        else
        {
            std::cout << crawler->getData() << " <-> ";
            reverPrintRec(crawler->getPrev());
        }
    }
    void begin()
    {
        pActual = first;
    }
    void final()
    {
        pActual = last;
    }
    void nextTo()
    {
        pActual = pActual->getNext();
    }
    void prevTo()
    {
        pActual = pActual->getPrev();
    }
    T GetData()
    {
        return pActual->getData();
    }
};
