#include "m_stack.h"
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3};
    m_stack<int>* st = new m_stack<int>(arr , 3);
    cout << st->pop() << endl;
    debug_stack_s_dump(st , 2);
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->push(5);
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->push(4);
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->clear();
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->push(4);
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    cout << st->top() << endl;
    st->push(5);
    st->push(6);
    st->push(7);
    st->push(8);
    st->push(9);
    st->push(0);
    st->pop();
    debug_stack_s_dump(st , 2);
    st->push(4);
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapacity() << " " << st->getMaxSize() << endl;


    system("pause");
    return 0;
}

