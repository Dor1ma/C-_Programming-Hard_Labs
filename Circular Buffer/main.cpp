#include <iostream>
#include <cassert>
#include "CircularBuffer.h"
using namespace std;

void test_push_front()
{
    Circular_Buffer<int> buffer(3);

    cout << "First test" << endl;

    buffer.push_front(1);
    buffer.push_front(2);
    buffer.push_front(3);

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;

    assert(buffer[0] == 1);
    assert(buffer[1] == 2);
    assert(buffer[2] == 3);

    buffer.push_front(4);

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;

    assert(buffer[0] == 4);
    assert(buffer[1] == 1);
    assert(buffer[2] == 2);
}

void test_push_back()
{
    Circular_Buffer<int> buffer(3);

    cout << "Second test" << endl;

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;

    assert(buffer[0] == 3);
    assert(buffer[1] == 2);
    assert(buffer[2] == 1);

    buffer.push_back(4);

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;

    assert(buffer[0] == 2);
    assert(buffer[1] == 1);
    assert(buffer[2] == 4);
}

void test_pop_front()
{
    Circular_Buffer<int> buffer(3);

    cout << "Third test" << endl;

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;

    buffer.pop_front();

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;


    assert(buffer[0] == 3);
    assert(buffer[1] == 2);
    assert(buffer[2] == 0);
}

void test_pop_back()
{
    Circular_Buffer<int> buffer(3);

    cout << "Fourth test" << endl;

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;

    buffer.pop_back();

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;

    assert(buffer[0] == 0);
    assert(buffer[1] == 2);
    assert(buffer[2] == 1);
}

void test_iterators()
{
    Circular_Buffer<int> buffer(3);

    cout << "Fifth test" << endl;

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    int a = buffer.first();
    int b = buffer.last();

    cout << a << " " << b << endl;

    assert(a == buffer[0]);
    assert(b == buffer[2]);

    for (auto it = buffer.begin(); it != buffer.end(); it++)
    {
        cout << *it << " ";
    }

    auto temp = buffer.end();
    cout << *temp << endl;
}

void test_capacity()
{
    cout << "Sixth test" << endl;

    Circular_Buffer<int> buffer(3);

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;

    buffer.changeCapacity(5);

    buffer.push_front(4);
    buffer.push_front(5);

    assert(buffer[0] == 3);
    assert(buffer[1] == 2);
    assert(buffer[2] == 1);
    assert(buffer[3] == 4);
    assert(buffer[4] == 5);

    cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << " " << buffer[3] << " " << buffer[4] << endl;
}

int main()
{
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_iterators();
    test_capacity();

    cout << "All tests passed!" << endl;
    return 0;
}