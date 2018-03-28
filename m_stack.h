#ifndef STACK_S_STACK_S_H
#define STACK_S_STACK_S_H


#include <cstdlib>
#include <afxres.h>
#include <cstring>
#include <iostream>

#define debug_stack_s_dump(var) var->dump(1 , __FILE__ , __PRETTY_FUNCTION__ , #var , __LINE__);


using namespace std;

template <class array_t>
class m_stack
{
public:

//Creators
    explicit m_stack(void);

    explicit m_stack(array_t* arr , unsigned int sze);
//Destoyer
    ~m_stack();

//Functions
    //Verifier
    bool ok();

    bool dump(int stream , string file , string function , string variable , size_t line);
//Getting information about struct m_stack

    /**
     * get _capacity of stack_s
     * @return _capasity
     */
    size_t getCapasity(void);

    /**
     *Get size of array in struct stack_s
     * @return _max_size
     */
    size_t getMaxSize(void);

    /**Increase size of _data
     *
     *  New _max_size is [_max_size * 1.7]
     *  @return TRUE if copying finished correctly
     *          FALSE if copying finished incorrectly
     */
    bool increaseSize(void);




    /**Increase size of _data
     *
     * @param newSize new size of _data
     * @return TRUE  if realloc is successful
     *         FALSE if realloc is unsuccessful
     */
    bool increaseSize(unsigned int newSize);

    /**
     *
     * @tparam array_t
     * @param element is new element to the _data
     *                which will be added to the end of the stack
     * @return TRUE  if element was added
     *         FALSE if element was not added
     */
    bool push (array_t);

    /**
     *
     * @tparam array_t
     * @return top element if it is possible
     *         0           if it is not possible
     */
    array_t pop (void);

   /**
    *
    * @tparam array_t
    * @return TRUE if clearing finished correctly
    *         FALSE if cleaning finished incorrectly
    */
    bool    clear(void);

    array_t top(void);
    bool isEmpty(void);

    bool isFully(void);
protected:

    /**
     *Get pointer on _data
     * @return pointer on _data
     */
    array_t* getData(void);
private:
    void*    _first_canary;
    array_t* _data;
    size_t   _max_size;
    size_t   _capacity;

    /**
     *
     * @return _first_canary
     */
    void* getFirstCanary(void);

    /**
     *
     * @return _last_canary
     */
    void* getLastCanary (void);

    void* _last_canary;
};






//Creators
template <class array_t>
m_stack<array_t>::m_stack(void) :
        _first_canary(0),
        _data(new array_t[1]),
        _max_size(1),
        _capacity(0),
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
        _data(arr),
        _max_size(sze),
        _capacity(sze),
        _last_canary(0) {}

//Destroyer
template <class array_t>
m_stack<array_t>::~m_stack(void) {
    if(_data!= 0)
        delete  _data;
}



///Checking stack_s functions
/**
 * Checking stack_s on correctly
 *@return TRUE if state of stack_s is correct
 *        FALSE if state of stack_s is not correct
 */
template <class array_t>
bool
m_stack<array_t>::ok(void) {
    if(_data) {
        if(_capacity <= _max_size
                     &&
           _first_canary == 0
                     &&
           _last_canary == 0)
            return TRUE;
    }

    return FALSE;
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
bool
m_stack<array_t>::dump(int stream , string file , string function , string variable , size_t line) {
    size_t warnings = 0;
    size_t errors =   0;

    cout                                                                                       << endl;
    cout                                                                                       << endl;
    cout << "================================================================================" << endl;
    cout << "                                 M_STACK DUMP                                   " << endl;
    cout                                                                                       << endl;
    cout << "File: " << file                                                                   << endl;
    cout << "Function: " << function                                                           << endl;
    cout << "Line: " << line                                                                   << endl;
    cout << "Variable: " << variable                                                           << endl;
    cout << "Address of variable: " << this                                                    << endl;
    cout                                                                                       << endl;
    if(_first_canary != 0) ++warnings;
    cout << "_first_canary: " << _first_canary                                                 << endl;
    cout                                                                                       << endl;
    cout << "_max_size: " << _max_size                                                         << endl;
    if(_capacity > _max_size) { ++errors;
    cout << "ERROR: _capacity: " << _capacity << "  ERROR"                                     << endl; }
    else if(_capacity == _max_size) { ++warnings;
    cout << "WARNING: _capacity: " << _capacity << "  WARNING"                                 << endl; }
    else
    cout << "_capacity: " << _capacity                                                         << endl;
    cout << "_data: " << _data                                                                 << endl;
    if(_data != 0)
    for(int i=0; i<_capacity; ++i) {
    cout << "_data[" << i << "]: " << _data[i]                                                 << endl; }
    else ++warnings;
    for(int i=_capacity; i<_max_size; ++i)
    cout << "\t_data[" << i << "]: " << _data[i]                                               << endl;
    cout                                                                                       << endl;
    if(_last_canary != 0) ++warnings;
    cout << "_last_canary: " << _last_canary                                                   << endl;
    cout                                                                                       << endl;
    cout                                                                                       << endl;
    cout << "WARNINGS: " << warnings                                                           << endl;
    cout << "ERRORS: " << errors                                                               << endl;
    cout << "                               END M_STACK DUMP                                 " << endl;
    cout << "================================================================================" << endl;
    cout                                                                                       << endl;
    cout                                                                                       << endl;
}


///Getting information about struct stack_s
/**
 *
 *@return _capacity
 */
template <class array_t>
size_t
m_stack<array_t>::getCapasity(void) {
    return _capacity;
}

/**
 *
 * @return size of array in struct stack_s
 */
template <class array_t>
size_t
m_stack<array_t>::getMaxSize(void) {
    return _max_size;
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
m_stack<array_t>::getLastCanary (void) {
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
bool
m_stack<array_t>::push(array_t element) {
    if(isFully() != TRUE) {
        _data[_capacity++] = element;
    }
    else {
        bool res = increaseSize();
        if(res == TRUE) {
            _data[_capacity++] = element;
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
    if(_capacity != 0) {
        return _data[--_capacity];
    }

    return 0;
}

template <class array_t>
array_t
m_stack<array_t>::top(void) {
    if(isEmpty() != TRUE)
        return _data[_capacity - 1];
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
    void* res;
    unsigned int newSize = (unsigned int)((double)_max_size * 2);
    array_t* newArray = new array_t[newSize];

    if(newArray != 0) {
        res = memcpy(newArray, _data, sizeof(array_t) * newSize);

        if(res != 0) {
            delete _data;
            _data = newArray;
            _max_size = newSize;

            return TRUE;
        }
    }

    return FALSE;
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
    array_t* newArray = new array_t[newSize];

    if(newArray != 0) {
        if(newSize > _max_size) {
            newSize = _max_size;
            res = memcpy(newArray, _data, sizeof(array_t) * newSize);
        }
        else
            res = memcpy(newArray, _data, sizeof(array_t) * newSize);

        if(res != 0) {
            delete _data;
            _data = newArray;
            _max_size = newSize;

            return TRUE;
        }
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
            _capacity = 0;
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
    if(_capacity == 0)
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
m_stack<array_t>::isFully(void) {
     if(_capacity == _max_size)
        return TRUE;
    else
        return FALSE;

}

#endif //STACK_S_STACK_S_H
