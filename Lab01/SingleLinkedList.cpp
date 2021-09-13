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
    int length;

public:
    SingleLinkedList()
    {
        first = nullptr;
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
    void insert(T info)
    {
        Node<T> *toAdd = new Node<T>(info);
        if (isEmpty())
        {
            first = toAdd;
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
        }
        length++;
    }
    void search(T value)
    {
        Node<T> *crawler = first;
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
                    while(aux->getNext()!=crawler)
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
    }
};
