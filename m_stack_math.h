//
// Created by пользователь on 08.04.2018.
//

#pragma once

#include "m_stack.h"

class m_stack_math : public m_stack<int> {
public:
    //Constructor
    explicit m_stack_math() : m_stack<int> () {}
    explicit m_stack_math(int* arr , unsigned sze) : m_stack<int> (arr , sze) {}

    //Destructor
    virtual ~m_stack_math() {}

    void add(void);
    void sub(void);
    void mul(void);
    void div(void);
    void pow(void);
};
