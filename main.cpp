#include "m_stack.h"
#include "m_stack_math.h"
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3};
    m_stack_math* st = new m_stack_math(arr , 3);
    cout << st->pop() << endl;
    st->push(5);
    st->push(4);
    st->clear();
    st->push(4);
    st->push(5);
    st->push(6);
    st->push(1);
    st->push(3);
    st->m_shl();
    debug_stack_s_dump(st , 2);
    st->pow();
    debug_stack_s_dump(st , 2);
    st->push(0);
    st->pop();



    system("pause");
    return 0;
}

