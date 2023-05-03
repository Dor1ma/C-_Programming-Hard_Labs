#ifndef LAB_7_CIRCULARBUFFER_H
#define LAB_7_CIRCULARBUFFER_H

#include <iostream>
using namespace std;

template <class T>
class Circular_Buffer
{
private:
    T *data = nullptr;
    size_t size;
    size_t capacity;
    size_t start;
    size_t finish;
public:

    class Iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    private:
        T* pData = nullptr;
    public:
        Iterator (T* temp)
        {
            pData = temp;
        }

        T& operator ++ (int)
        {
            return *pData++;
        }

        T& operator --( int)
        {
            return *pData--;
        }

        bool operator == (const Iterator& other)
        {
            return this -> pData == other.pData;
        }

        bool operator != (const Iterator& other)
        {
            return this -> pData != other.pData;
        }

        T& operator* ()
        {
            return *pData;
        }
    };

    explicit Circular_Buffer(size_t newCapacity)
    {
        capacity = newCapacity;
        data = new T [newCapacity];
        size = 0;
        start = 0;
        finish = 0;
    }

    Circular_Buffer(const Circular_Buffer &buffer)
    {
        capacity = buffer.capacity;
        data = new T [capacity];
        size = buffer.size;
        start = buffer.start;
        finish = 0;

        for (size_t i = 0; i < size; i++)
        {
            *data[i] = buffer.data[i];
        }

    }

    T &operator[](size_t index) const
    {
        return data[index % capacity];
    }

    void push_front(T x)
    {
        if (size == capacity)
        {
            start = 0;
            for (int i = size - 1; i >= 0; i--)
            {
                data[i + 1] = data[i];
            }
        }
        data[start] = x;
        start++;
        size++;
    }

    void showStart()
    {
        cout << start << endl;
    }

    void showFinish()
    {
        cout << finish << endl;
    }

    void push_back(const T x)
    {
        if (size == 0)
        {
            finish = capacity - 1;
        }

        if (size == capacity)
        {
            for (int i = 0; i <= capacity - 1; i++)
            {
                data[i] = data[i + 1];
            }

            finish = size - 1;
        }

        data[finish] = x;
        size++;
        finish--;
    }

    void pop_front()
    {
        if (size > 0)
        {
            start = size - 1;
            data[start] = 0;
            size--;
            start--;
        }
        else
        {
            throw logic_error("Error: the buffer is empty");
        }
    }

    void pop_back()
    {
        finish++;
        data[finish] = 0;
    }

    void changeCapacity(size_t newCapacity)
    {
        T *temp = new T [newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }

        delete [] data;
        data = temp;
        capacity = newCapacity;
        start = size;
        finish = 0;
    }

    Iterator begin() const
    {
        return data;
    }

    Iterator end() const
    {
        return data + capacity - 1;
    }

    T first() const
    {
        return data[start];
    }

    T last() const
    {
        return data[(size + start - 1) % capacity];
    }

    ~Circular_Buffer()
    {
        delete [] data;
    }
};


#endif //LAB_7_CIRCULARBUFFER_H
