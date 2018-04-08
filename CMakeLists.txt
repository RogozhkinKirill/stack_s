cmake_minimum_required(VERSION 3.9)
project(stack_s)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack_s
        main.cpp

        m_stack.cpp
        m_stack.h

        errors_warning.h

        m_stack_math.cpp
        m_stack_math.h errors_warning.cpp
        )

add_definitions()