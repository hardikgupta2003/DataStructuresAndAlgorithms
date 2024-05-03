#include <iostream>
using namespace std;

class Heap
{

public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap overflow ~ " << endl;
            return;
        }
        size++;
        int index = size;
        arr[size] = val;

        while (index > 1)
        {
            int parentIndex = index / 2;

            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index=parentIndex;
            }
            else{
                break;
            }
        }
    }
};

int main()
{
    Heap h(10);
    h.insert(5);
    h.insert(11);
    h.insert(8);
    h.insert(25);
    h.insert(67);
    h.printHeap();


    return 0;
}