////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Safearray class methods definition
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// This file contains templates of the method of the class Safearray.
/// This file is not going to be used w/o its main counterpart, safearray.h.
/// Since the file is used only through safearray.h, which has its own "include 
/// watcher", we add no addition "watcher" here.
///
////////////////////////////////////////////////////////////////////////////////

// #ifndef    // No need to have a watcher here!


// we have to indicate that methods of the class Safearray are also inside the namespace xi
namespace xi {


    template <typename T>
    SafeArray<T>::SafeArray(size_t cap)
    {

        this->_storage = new T[cap];
        this->_capacity = cap;
    }

    template <typename T>
    SafeArray<T>::SafeArray(const SafeArray &arr)
    {
        //TODO: delete
        std::cout << "Вызван конструктор копирования";

        this->_storage = new T[arr.getCapacity()];
        this->_capacity = arr.getCapacity();

        for (int i = 0; i < arr.getCapacity(); i++)
        {
            this->_storage[i] = arr[i];
        }
    }

    template<typename T>
    SafeArray<T>::~SafeArray()
    {
        //TODO: delete
        std::cout << "Вызван десруктор";

        delete [] this->_storage;
        this->_storage = nullptr;
        this->_capacity = 0;
    }

    template<typename T>
    T &SafeArray<T>::operator[](size_t k)
    {
        checkBounds(k);
        return *this->_storage[k];
    }

    template<typename T>
    const T &SafeArray<T>::operator[](size_t k) const
    {
       checkBounds(k);
        return &this->_storage;
    }

    template<typename T>
    size_t SafeArray<T>::getCapacity() const
    {
        return this->_capacity;
    }

    template<typename T>
    void SafeArray<T>::checkBounds(size_t index) const
    {
        if (index >= this->_capacity)
            throw std::out_of_range("Out of range exception.");
    }


} // namespace xi
