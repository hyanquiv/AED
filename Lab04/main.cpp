#include "Stack.cpp"
#include "Queue.cpp"

int main ()
{
    Stack<int> S1;
    Queue<int> Q1;

    S1.push(1);
    S1.push(3);
    S1.push(8);
    S1.push(9);
    S1.push(2);
    S1.print();
    std::cout<<"Se extrajo: "<<S1.pop()->getData()<<"\n";
    S1.print();

    Q1.enqueue(1);
    Q1.enqueue(3);
    Q1.enqueue(8);
    Q1.enqueue(9);
    Q1.enqueue(2);
    Q1.print();
    std::cout << "Se extrajo: " << Q1.dequeue()->getData() << "\n";
    Q1.print();

    return 0;
}