//https://github.com/kvk1920/MyDeque

//
// Created by kvk on 11/28/17.
//


#ifndef DEQUE_H
#define DEQUE_H

#include <algorithm>
#include <iterator>
#include <memory.h>

namespace Utility {

    const size_t minSize = 10;

    template <typename T>
    struct Deque
    {
        size_t _begin, _size, _realSize;
        T *_data;

        void _reAlloc(size_t newSize)
        {
            T *newData = new T[newSize];
            for (size_t i(0); i < _size; ++i)
                newData[i] = _data[(_begin + i) % _realSize];
            _begin = 0;
            delete [] _data;
            _data = newData;
            _realSize = newSize;
        }

        void _check()
        {
            if (_size + 1 == _realSize)
                _reAlloc(_realSize * 2);
            else if (_size * 4 < _realSize and _realSize > minSize)
                _reAlloc(std::max(minSize, _realSize / 2));
        }

        Deque() : _begin(0), _size(0), _realSize(minSize), _data(new T[_realSize]) {}
        Deque(const Deque &other) : _begin(other._begin), _size(other._size), _realSize(other._realSize), _data(new T[_realSize]) { std::copy(other._data, other._data + _realSize, _data; }

        Deque &operator=(const Deque &other)
        {
            delete [] _data;
            _begin = other._begin;
            _size = other._size;
            _realSize = other._realSize;
            _data = new T[_realSize];
            std::copy(other._data, other._data + _realSize, _data);
	    return *this;
        }

        ~Deque() { delete [] _data; }

        bool empty() const { return _size == 0; }
        size_t size() const { return _size; }

        T &operator[](size_t i) { return _data[(_begin + i) % _realSize]; }
        const T &operator[](size_t i) const { return _data[(_begin + i) % _realSize]; }

        T &front() { return this->operator[](0); }
        const T &front() const { return this->operator[](0); }
        T &back() { return this->operator[](_size - 1); }
        const T &back() const { return this->operator[](_size - 1); }

        void push_front(const T &x) { ++_size; _begin = (_begin + _realSize - 1) % _realSize; _data[_begin] = x; _check(); }
        void push_back(const T &x) { _data[(_begin + _size++) % _realSize] = x; _check(); }

        void pop_front() { _begin = (_begin + 1) % _realSize; --_size; _check(); }
        void pop_back() { --_size; _check(); }
    };

    template <typename T, typename ptr_type>
    class Iterator : public std::iterator <std::random_access_iterator_tag, T, int> {
    protected:
        int _pos;
        ptr_type _ptr;
    public:

        Iterator &operator++() { ++_pos; return *this; }
        Iterator operator++(int) { Iterator res(*this); ++_pos; return res; }

        Iterator &operator--() { --_pos; return *this; }
        Iterator operator--(int) { Iterator res(*this); --_pos; return res; }

        Iterator &operator+=(int n) { _pos += n; return *this; }
        Iterator &operator-=(int n) { return *this += -n; }

        int operator-(const Iterator &other) const { return _pos - other._pos; }

        Iterator(ptr_type ptr, int pos) : _pos(pos), _ptr(ptr) {}
        Iterator &operator=(const Iterator <T, ptr_type> &other) { _ptr = other._ptr; _pos = other._pos; return *this; }
        Iterator(const Iterator &other) : _pos(other._pos), _ptr(other._ptr) {}
        //ConstIter(const Iter &other) : Iterator(other._pos), _ptr(other._ptr) {}

        T &operator*() const { return (*_ptr)[_pos]; }
        T &operator[](int n) const { return (*_ptr)[n + _pos]; }

        T *operator->() { return &(*_ptr)[_pos]; }

        bool operator==(const Iterator &other) const { return _ptr == other._ptr and _pos == other._pos; }
        bool operator!=(const Iterator &other) const { return !(*this == other); }

        Iterator operator+(int a) const { Iterator res(*this); return res += a; }
        Iterator operator-(int a) const { Iterator res(*this); return res -= a; }

        bool operator<(const Iterator &other) { return other - *this > 0; }
        bool operator>(const Iterator &other) { return other < *this; }
        bool operator>=(const Iterator &other) { return !(*this < other); }
        bool operator<=(const Iterator &other) { return !(*this > other); }
    };

    /*template <typename T>
    class Iter : public Iterator <T>
    {
    private:
        Deque <T> *_ptr;
    public:
        Iter(Deque <T> *ptr, int pos) : Iterator <T>(pos), _ptr(ptr) {}
        Iter &operator=(const Iter <T> &other) { _ptr = other._ptr; Iterator <T>::_pos = other._pos; return *this; }
        Iter(const Iter &other) : Iterator <T>(other._pos), _ptr(other._ptr) {}
        //ConstIter(const Iter &other) : Iterator(other._pos), _ptr(other._ptr) {}

        T &operator*() const { return (*_ptr)[Iterator <T>::_pos]; }
        T &operator[](int n) const { return (*_ptr)[n + Iterator <T>::_pos]; }

        bool operator==(const Iter &other) const { return _ptr == other._ptr and Iterator <T>::_pos == other._pos; }
        bool operator!=(const Iter &other) const { return !(*this == other); }

    };*/

    /*template <typename T>
    class ConstIter : public Iterator <T>
    {
    private:
        const Deque <T> *_ptr;
    public:
        ConstIter(const Deque <T> *ptr, int pos) : Iterator <T>(pos), _ptr(ptr) {}
        ConstIter &operator=(const ConstIter &other) { _ptr = other._ptr; Iterator <T>::_pos = other._pos; return *this; }
        ConstIter(const ConstIter &other) : Iterator <T>(other._pos), _ptr(other._ptr) {}
        ConstIter(const Iter <T> &other) : Iterator <T>(other._pos), _ptr(other._ptr) {}

        const T &operator*() const { return _ptr[Iterator <T>::_pos]; }
        const T &operator[](int n) const { return _ptr[n + Iterator <T>::_pos]; }

        bool operator==(const ConstIter <T> &other) const { return _ptr == other._ptr and Iterator <T>::_pos == other._pos; }
        bool operator!=(const ConstIter <T> &other) const { return !(*this == other); }
    };*/

}

/*
template <typename T, typename ptr_type>
Utility::Iterator <T, ptr_type> operator+(const Utility::Iterator <T, ptr_type> &a, int b)
{
	Utility::Iterator <T, ptr_type> res(a);
	res += b;
	return res;
}*/

template <typename T, typename ptr_type>
Utility::Iterator <T, ptr_type> operator+(int a, const Utility::Iterator <T, ptr_type> &b) { return b + a; }

/*template <typename T, typename ptr_type>
Utility::Iterator <T, ptr_type> operator-(const Utility::Iterator <T, ptr_type> &a, int b) { return a + (-b); }
*//*
template <typename T, typename ptr_type>
bool operator>(const Utility::Iterator <T, ptr_type> &a, const Utility::Iterator <T, ptr_type> &b)
{
	return a - b > 0;
}

template <typename T, typename ptr_type>
bool operator<(const Utility::Iterator <T, ptr_type> &a, const Utility::Iterator <T, ptr_type> &b)
{
	return b > a;
}

template <typename T, typename ptr_type>
bool operator<=(const Utility::Iterator <T, ptr_type> &a, const Utility::Iterator <T, ptr_type> &b) { return !(a > b); }

template <typename T, typename ptr_type>
bool operator>=(const Utility::Iterator <T, ptr_type> &a, const Utility::Iterator <T, ptr_type> &b) { return !(a < b); }
*/
template <typename T>
class Deque {
private:
    Utility::Deque <T> _base;
public:
    Deque() : _base() {}
    Deque(const Deque <T> &other) : _base(other._base) {}
    Deque &operator=(const Deque <T> &other) { _base = other._base; return *this; }

    typedef Utility::Iterator <T, Utility::Deque <T> *> iterator;
    typedef Utility::Iterator <const T, const Utility::Deque <T> *> const_iterator;
    typedef std::reverse_iterator <iterator> reverse_iterator;
    typedef std::reverse_iterator <const_iterator> const_reverse_iterator;

    void push_back(const T &x) { _base.push_back(x); }
    void pop_back() { _base.pop_back(); }
    void push_front(const T &x) { _base.push_front(x); }
    void pop_front() { _base.pop_front(); }

    T &operator[](size_t i) { return _base[i]; }
    const T &operator[](size_t i) const { return _base[i]; }
    T &back() { return _base.back(); }
    const T &back() const { return _base.back(); }
    T &front() { return _base.front(); }
    const T &front() const { return _base.front(); }

    bool empty() const { return _base.empty(); }
    size_t size() const { return _base.size(); }

    iterator begin() { return iterator(&_base, 0); }
    const_iterator cbegin() const { return const_iterator(&_base, 0); }
    const_iterator begin() const { return cbegin(); }

    iterator end() { return iterator(&_base, size()); }
    const_iterator cend() const { return const_iterator(&_base, size()); }
    const_iterator end() const { return cend(); }

    reverse_iterator rbegin() { return reverse_iterator(iterator(&_base, size()/* - 1*/)); }
    const_reverse_iterator crbegin() const { return const_reverse_iterator(const_iterator(&_base, size()/* - 1*/)); }
    const_reverse_iterator rbegin() const { return crbegin(); }

    reverse_iterator rend() { return reverse_iterator(iterator(&_base, 0/*-1*/)); }
    const_reverse_iterator crend() const { return const_reverse_iterator(const_iterator(&_base, /*-1*/0)); }
    const_reverse_iterator rend() const { return crend(); }
};

#endif // DEQUE_H
