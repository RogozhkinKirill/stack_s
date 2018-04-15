#ifndef STACK_S_STACK_S_H
#define STACK_S_STACK_S_H


#include <cstdlib>
#include <afxres.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <new>

#include "errors_warning.h"

#define debug_stack_s_dump(var , stream) if(stream == 1) \
                                     var->dumpToConsole(__FILE__ , __PRETTY_FUNCTION__ , #var , __LINE__); \
                                         else \
                                             var->dumpToFile(__FILE__ , __PRETTY_FUNCTION__ , #var , __LINE__);


//using namespace std;

template <class array_t>
class m_stack
{
public:
//Constructor
    explicit m_stack(void);
    explicit m_stack(array_t* arr , unsigned int sze);
//Destructor
    virtual ~m_stack();

//Functions
    WnE ok();
    WnE dumpToConsole(std::string file , std::string function , std::string variable , size_t line);
    WnE dumpToFile   (std::string file , std::string function , std::string variable , size_t line);

    size_t getCapacity(void);
    size_t getMaxSize(void);
    bool increaseSize(void);
    bool increaseSize(unsigned int newSize);

    bool clear(void);

    WnE    push (array_t);
    array_t pop (void);
    array_t top (void);

    bool isEmpty(void);
    bool isFull(void);

protected:
    array_t* getData(void);


private:

    void*    _first_canary;
    array_t* _data;
    size_t   _capacity;
    size_t   _max_size;

    void* getFirstCanary(void);
    void* getLastCanary (void);

    void* _last_canary;
};


//Constructor
template <class array_t>
m_stack<array_t>::m_stack(void) :
        _first_canary(0),
        _data(new array_t[1]),
        _capacity(1),
        _max_size(0),
        _last_canary(0) {}

/**
 *
 * @tparam array template typename
 * @param arr    pointer on array
 *               which you want to place into stack_s
 * @param sze    size of transmitted array
 */
template <class array_t>
m_stack<array_t>::m_stack(array_t *arr, unsigned int sze) :
        _first_canary(0),
        _data(new array_t(sze)),
        _capacity(sze),
        _max_size(sze),
        _last_canary(0) {
    for(int i=0; i<sze; ++i) {
        _data[i] = arr[i];
    }
}

//Destructor
template <class array_t>
m_stack<array_t>::~m_stack(void) {
    if(_data!= 0)
        delete[]  _data;
        _data = nullptr;
}



///Checking stack_s functions
/**
 * Checking stack_s on correctly
 *@return TRUE if state of stack_s is correct
 *        FALSE if state of stack_s is not correct
 */
template <class array_t>
WnE
m_stack<array_t>::ok(void) {
    WnE result = 0;

    if(this)
        if(_data) {
            if(_max_size > _capacity)
                add_WnE(result , __OVERFLOW__);
            if(_first_canary != 0 || _last_canary != 0)
                add_WnE(result , __CHANGED_PRIVATE_ZONE__);
            if(_capacity == 0)
                add_WnE(result , __INVALID_VALUE__);
        }
        else
            add_WnE(result , __NULL_POINTER__);

    return result;
}

/**
 *
 * @tparam array_t
 * @param stream
 *                  1 - print dump to console
 *                  2 - print dump to file
 * @return TRUE if state of stack_s is correct
 *         FALSE if state of stack_s is not correct
 */
template <class array_t>
WnE
m_stack<array_t>::dumpToConsole(std::string file , std::string function , std::string variable , size_t line) {
    WnE result = 0;

    size_t warnings = 0;
    size_t errors =   0;

    std::cout                                                                                       << std::endl;
    std::cout                                                                                       << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "                                 M_STACK DUMP                                   " << std::endl;
    std::cout                                                                                       << std::endl;
    std::cout << "File: " << file                                                                   << std::endl;
    std::cout << "Function: " << function                                                           << std::endl;
    std::cout << "Line: " << line                                                                   << std::endl;
    std::cout << "Variable: " << variable                                                           << std::endl;
    std::cout << "Address of variable: " << this                                                    << std::endl;
    std::cout                                                                                       << std::endl;

    if(_first_canary != 0) { ++warnings; add_WnE(result , __CHANGED_PRIVATE_ZONE__);
    std::cout << "WARNING: _first_canary: " << _first_canary << "WARNONG"                           << std::endl; }
    else
    std::cout << "_first_canary: " << _first_canary                                                 << std::endl;

    std::cout                                                                                       << std::endl;
    std::cout << "_capacity: " << _capacity                                                         << std::endl;

    if(_max_size > _capacity) { ++errors; add_WnE(result , __OVERFLOW__);
    std::cout << "ERROR: _max_size: " << _max_size << "  ERROR"                                     << std::endl; }
    else if(_max_size == _capacity) { ++warnings; add_WnE(result , __FILLED__);
    std::cout << "WARNING: _max_size: " << _max_size << "  WARNING"                                 << std::endl; }
    else
    std::cout << "_max_size: " << _max_size                                                         << std::endl;

    std::cout << "_data: " << _data                                                                 << std::endl;
    if(_data != 0)
    for(int i=0; i<_max_size; ++i) {
    std::cout << "_data[" << i << "]: " << _data[i]                                                 << std::endl; }
    else ++warnings;
    for(int i=_max_size; i<_capacity; ++i)
    std::cout << "\t_data[" << i << "]: " << _data[i]                                               << std::endl;

    std::cout                                                                                       << std::endl;
    if(_last_canary != 0) { ++warnings; add_WnE(result , __CHANGED_PRIVATE_ZONE__);
    std::cout << "WARNING: _last_canary: " << _last_canary << "WARNING"                             << std::endl; }
    else
    std::cout << "_last_canary: " << _last_canary                                                   << std::endl;

    std::cout                                                                                       << std::endl;
    std::cout                                                                                       << std::endl;
    std::cout << "WARNINGS: " << warnings                                                           << std::endl;
    std::cout << "ERRORS: " << errors                                                               << std::endl;
    std::cout << "                               END M_STACK DUMP                                 " << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout                                                                                       << std::endl;
    std::cout                                                                                       << std::endl;

    return result;
}

/**
 *
 * @tparam array_t
 * @param stream
 *                  1 - print dump to console
 *                  2 - print dump to file
 * @return TRUE if state of stack_s is correct
 *         FALSE if state of stack_s is not correct
 */
template <class array_t>
WnE
m_stack<array_t>::dumpToFile(std::string file, std::string function, std::string variable, size_t line) {
    std::ofstream fout(dump_file , std::ios_base::app);
    WnE result = 0;


    if(fout) {
        size_t warnings = 0;
        size_t errors =   0;

        fout                                                                                       << std::endl;
        fout                                                                                       << std::endl;
        fout << "================================================================================" << std::endl;
        fout << "                                 M_STACK DUMP                                   " << std::endl;
        fout                                                                                       << std::endl;
        fout << "File: " << file                                                                   << std::endl;
        fout << "Function: " << function                                                           << std::endl;
        fout << "Line: " << line                                                                   << std::endl;
        fout << "Variable: " << variable                                                           << std::endl;
        fout << "Address of variable: " << this                                                    << std::endl;
        fout                                                                                       << std::endl;

        if(_first_canary != 0) { ++warnings; add_WnE(result , __CHANGED_PRIVATE_ZONE__);
        fout << "WARNING: _first_canary: " << _first_canary << "WARNONG"                           << std::endl; }
        else
        fout << "_first_canary: " << _first_canary                                                 << std::endl;

        fout                                                                                       << std::endl;
        fout << "_capacity: " << _capacity                                                         << std::endl;

        if(_max_size > _capacity) { ++errors; add_WnE(result , __INVALID_VALUE__);
        fout << "ERROR: _max_size: " << _max_size << "  ERROR"                                     << std::endl; }
        else if(_max_size == _capacity) { ++warnings; add_WnE(result , __FILLED__);
        fout << "WARNING: _max_size: " << _max_size << "  WARNING"                                 << std::endl; }
        else
        fout << "_max_size: " << _max_size                                                         << std::endl;

        fout << "_data: " << _data                                                                 << std::endl;
        if(_data != 0)
            for(int i=0; i<_max_size; ++i) {
        fout << "_data[" << i << "]: " << _data[i]                                                 << std::endl; }
        else ++warnings;

        for(int i=_max_size; i<_capacity; ++i)
        fout << "\t_data[" << i << "]: " << _data[i]                                               << std::endl;

        fout                                                                                       << std::endl;
        if(_last_canary != 0) { ++warnings; add_WnE(result , __CHANGED_PRIVATE_ZONE__);
        fout << "WARNING: _last_canary: " << _last_canary << "WARNING"                             << std::endl; }
        else
        fout << "_last_canary: " << _last_canary                                                   << std::endl;

        fout                                                                                       << std::endl;
        fout                                                                                       << std::endl;
        fout << "WARNINGS: " << warnings                                                           << std::endl;
        fout << "ERRORS: " << errors                                                               << std::endl;
        fout << "                               END M_STACK DUMP                                 " << std::endl;
        fout << "================================================================================" << std::endl;
        fout                                                                                       << std::endl;
        fout                                                                                       << std::endl;



        fout.close();
    }

    return result;
}

///Getting information about struct stack_s
/**
 *
 *@return _capacity
 */
template <class array_t>
size_t
m_stack<array_t>::getMaxSize(void) {
    return _max_size;
}

/**
 *
 * @return size of array in struct stack_s
 */
template <class array_t>
size_t
m_stack<array_t>::getCapacity(void) {
    return _capacity;
}

/**
 *
 *@return pointer on _data
 */
template <class array_t>
array_t*
m_stack<array_t>::getData(void) {
    return _data;
}

/**
 *
 *@return _first_canary*
 */
template <class array_t>
void*
m_stack<array_t>::getFirstCanary(void) {
    return _first_canary;
}

/**
 *
 *@return last_canary
 */
template <class array_t>
void*
m_stack<array_t>::getLastCanary(void) {
    return _last_canary;
}



///Stack functions to work
/**
 *
 * @tparam array_t
 * @param element is new element to the _data
 *                which will be added to the end of the stack
 * @return TRUE  if element was added
 *         FALSE if element was not added
 */
template <class array_t>
WnE
m_stack<array_t>::push(array_t element) {
    if(isFull() != TRUE) {
        _data[_max_size++] = element;
    }
    else {
        bool res = increaseSize();
        if(res == TRUE) {
            _data[_max_size++] = element;
            return TRUE;
        }
    }

    return FALSE;
}

/**
 *
 * @tparam array_t
 * @return top element if it is possible
 *         0           if it is not possible
 */
template <class array_t>
array_t
m_stack<array_t>::pop(void)
{
    if(_max_size != 0) {
        return _data[--_max_size];
    }

    return 0;
}

template <class array_t>
array_t
m_stack<array_t>::top(void) {
    if(isEmpty() != TRUE)
        return _data[_max_size - 1];
    return 0;
}

/**Increase size of _data
 *
 *  New _max_size is [_max_size * 1.7]
 *  @return TRUE if copying finished correctly
 *          FALSE if copying finished incorrectly
 */
template <class array_t>
bool
m_stack<array_t>::increaseSize(void) {
    void *res;
    unsigned int newSize = (unsigned int) ((double) _capacity * 2);

    array_t *newArray;
    try {
        newArray = new array_t[newSize];
    } catch (const std::bad_alloc &e) {
        return FALSE;
    }

    res = memcpy(newArray, _data, sizeof(array_t) * newSize);

    if (res != 0) {
        delete _data;
        _data = newArray;
        _capacity = newSize;
    }

    return TRUE;
}

/**
 *
 * @tparam array_t
 * @param  newSize new _max_size
 * @return TRUE if copying finished correctly
 *         FALSE if copying finished incorrectly
 */
template <class array_t>
bool
m_stack<array_t>::increaseSize(unsigned int newSize) {
    void* res;
    array_t* newArray;

    try {
        newArray = new array_t[newSize];
    } catch(std::bad_alloc& e) {
        return FALSE;
    }


    if(newSize > _capacity) {
        newSize = _capacity;
        res = memcpy(newArray, _data, sizeof(array_t) * newSize);
    }
    else
        res = memcpy(newArray, _data, sizeof(array_t) * newSize);

    if(res != 0) {
        delete _data;
        _data = newArray;
        _capacity = newSize;

        return TRUE;
    }

    return FALSE;
}

/**
 *
 * @tparam array_t
 * @return TRUE if clearing finished correctly
 *         FALSE if cleaning finished incorrectly
 */
template  <class array_t>
bool
m_stack<array_t>::clear(void) {
    if(_data) {
        if(increaseSize(1)) {
            _max_size = 0;
            return TRUE;
        }
    }

    return FALSE;
}

/**
 *
 * @tparam array_t
 * @return TRUE if _capacity == 0
 *         FALSE if _capacity != 0
 */
template <class array_t>
bool
m_stack<array_t>::isEmpty(void) {
    if(_max_size == 0)
        return TRUE;
    return FALSE;
}

/**
 *
 * @tparam array_t
 * @return TRUE if _capacity == _max_size
 *         FALSE if _capacity != _max_size
 */
template <class array_t>
bool
m_stack<array_t>::isFull(void) {
     if(_max_size == _capacity)
        return TRUE;
    else
        return FALSE;

}

#endif //STACK_S_STACK_S_H
