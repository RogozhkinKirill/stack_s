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
m_stack_math::sub(void) {
    int a = pop();
    int b = pop();
    push(b - a);
}

void
m_stack_math::mul(void) {
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

void
m_stack_math::inc(void) {
    int a = pop();
    push(++a);
}

void
m_stack_math::dec(void) {
    int a = pop();
    push(--a);
}

void
m_stack_math::m_or(void) {
    int a = pop();
    int b = pop();

    push(a | b);
}

void
m_stack_math::m_nor(void) {
    int a = pop();
    int b = pop();

    push(!(a | b));
}

void
m_stack_math::m_xor(void) {
    int a = pop();
    int b = pop();

    push(a ^ b);
}

void
m_stack_math::m_and(void) {
    int a = pop();
    int b = pop();

    push(a & b);
}

void
m_stack_math::m_nand(void) {
    int a = pop();
    int b = pop();

    push(~(a & b));
}

void
m_stack_math::m_not(void) {
    push(~pop());
}

void
m_stack_math::m_shl(void) {
    push(pop() << pop());
}

void
m_stack_math::m_shr(void) {
    push(pop() >> pop());
}