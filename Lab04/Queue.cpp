#include <iostream>

template <typename T>
class Qnode
{
private:
    T data;
    Qnode<T> *next;

public:
    Qnode(T data)
    {
        this->data = data;
        next = nullptr;
    }
    ~Qnode() = default;
    T getData()
    {
        return data;
    }
    void setNext(Qnode<T> *n)
    {
        next = n;
    }
    Qnode<T> *getNext()
    {
        return next;
    }
};

template <typename T>
class Queue
{
private:
    Qnode<T> *first;
    Qnode<T> *last;
    int length;

public:
    Queue()
    {
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    ~Queue()
    {
        Qnode<T> *crawler = first;
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
    void enqueue(T info)
    {
        Qnode<T> *toAdd = new Qnode<T>(info);
        if (first != nullptr)
        {
            last->setNext(toAdd);
            last = toAdd;
            length++;
        }
        else
        {
            first = toAdd;
            last = toAdd;
        }
    }
    Qnode<T> * dequeue()
    {
        if (!isEmpty())
        {
            Qnode<T> *output = first;
            if (length == 1)
            {
                first = nullptr;
                last = nullptr;
                return output;
            }
            else
            {
                first = first->getNext();
                return output;
            }
        }
        else
            return nullptr;
    }
    void print()
    {
        Qnode<T> *crawler = first;
        std::cout << "first -> ";
        while (crawler)
        {
            std::cout << crawler->getData() << " -> ";
            crawler = crawler->getNext();
        }
        std::cout << "nullptr\n";
    }
};