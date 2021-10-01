#include <iostream>

template <typename T>
class Snode
{
private:
    T data;
    Snode<T> *next;

public:
    Snode(T data)
    {
        this->data = data;
        next = nullptr;
    }
    ~Snode() = default;
    T getData()
    {
        return data;
    }
    void setNext(Snode<T> *n)
    {
        next = n;
    }
    Snode<T> *getNext()
    {
        return next;
    }
};

template <typename T>
class Stack
{
private:
    Snode<T> *first;
    Snode<T> *last;
    int length;

public:
    Stack()
    {
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    ~Stack()
    {
        Snode<T> *crawler = first;
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
    void push(T info)
    {
        Snode<T> *toAdd = new Snode<T>(info);
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
    Snode<T> *pop()
    {
        if (!isEmpty())
        {
            Snode<T> *output = last;
            if (length == 1)
            {
                first = nullptr;
                last = nullptr;
                return output;
            }
            else
            {
                Snode<T> *crawler = first;
                while (crawler->getNext() != last)
                    crawler = crawler->getNext();
                last = crawler;
                last->setNext(nullptr);
                return output;
            }
        }
        else
            return nullptr;
    }
    void print()
    {
        Snode<T> *crawler = first;
        std::cout << "first -> ";
        while (crawler)
        {
            std::cout << crawler->getData() << " -> ";
            crawler = crawler->getNext();
        }
        std::cout << "nullptr\n";
    }
};
