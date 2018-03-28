#include "m_stack.h"
#include <iostream>




using namespace std;


int main()
{
    int arr[] = {1,2,3};
    m_stack<int>* st = new m_stack<int>(arr , 3);
    cout << st->pop() << endl;
    debug_stack_s_dump(st);
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->push(5);
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->push(4);
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->clear();
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->push(4);
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    cout << st->top() << endl;
    debug_stack_s_dump(st);
    st->push(4);
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;
    st->pop();
    cout << st->getCapasity() << " " << st->getMaxSize() << endl;


    system("pause");
    return 0;
}

