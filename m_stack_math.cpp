//
// Created by пользователь on 08.04.2018.
//

#include "m_stack_math.h"


/***
 * Sum 2 numbers
 *
 */
void
m_stack_math::add(void) {
    int a = pop();
    int b = pop();
    push(b + a);
}

void
m_stack_math::sub() {
    int a = pop();
    int b = pop();
    push(b - a);
}

void
m_stack_math::mul() {
    int a = pop();
    int b = pop();
    push(b * a);
}

void m_stack_math::div(void) {
    int a = pop();
    int b = pop();
    push(a / b);
}

void m_stack_math::pow(void) {
    int power = pop();
    int base =  pop();
    for(int i=0; i<power; ++i) {
        base *= base;
    }

    push(base);
}

