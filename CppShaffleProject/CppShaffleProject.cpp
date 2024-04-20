#include <iostream>

void Swap(int& a, int& b)
{
    int temp{ a };
    a = b;
    b = temp;
}


void ArrayPrint(int* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void Heapify(int* array, int size, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    int largest = index;
    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != index)
    {
        Swap(array[index], array[largest]);
        if (largest < size / 2 - 1)
            Heapify(array, size, largest);
    }
}

void ArraySortHeap(int* array, int size)
{
    for (int i{ size / 2 - 1 }; i >= 0; i--)
        Heapify(array, size, i);

    for (int i{ size - 1 }; i >= 0; i--)
    {
        Swap(array[0], array[i]);
        Heapify(array, i, 0);
    }


}

int main()
{
    srand(time(nullptr));

    int size{ 20 };
    int* array = new int[size];
    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
    ArrayPrint(array, size);

    ArraySortHeap(array, size);

    ArrayPrint(array, size);

    /*int size{ 10 };
    int* array = new int[size];
    for (int i{}; i < size; i++)
        array[i] = i + 1;

    ArrayPrint(array, size);

    for (int i{}; i < size; i++)
    {
        int index1 = rand() % size;
        int index2 = rand() % size;
        Swap(array[index1], array[index2]);
    }

    ArrayPrint(array, size);*/


}
