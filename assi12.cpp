#include <iostream>
#include <cmath>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
class Heap
{
protected:
    int *heapArray;
    int maxSize;
    int currentSize;
    virtual void heapify(int index) = 0;

public:
    Heap(int size) : maxSize(size), currentSize(0)
    {
        heapArray = new int[maxSize];
    }
    virtual ~Heap()
    {
        delete[] heapArray;
    }
    virtual void insert(int value) = 0;
    virtual int extract() = 0;
    int peek()
    {
        if (currentSize <= 0)
        {
            cout << "Heap is empty." << endl;
            return -1;
        }
        return heapArray[0];
    }
    bool isEmpty()
    {
        return currentSize == 0;
    }
    void printHeap()
    {
        if (currentSize <= 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }
        int levels = (int)(log2(currentSize) + 1); // number of levels
        for (int l = 0; l < levels; ++l)
        {
            int numItemsLevel = (int)pow(2, l); // Maximum items
            int startIdx = (int)pow(2, l) - 1;  // Index where this level starts
            for (int i = 0; i < numItemsLevel && (startIdx + i) < currentSize; ++i)
            {
                cout << heapArray[startIdx + i] << " ";
            }
            cout << endl;
        }
    }
};
class MaxHeap : public Heap
{
protected:
    void heapify(int index) override
    {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        if (leftChild < currentSize && heapArray[leftChild] > heapArray[largest])
            largest = leftChild;
        if (rightChild < currentSize && heapArray[rightChild] > heapArray[largest])
            largest = rightChild;
        if (largest != index)
        {
            swap(heapArray[index], heapArray[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap(int size) : Heap(size) {}
    void insert(int value) override
    {
        if (currentSize == maxSize)
        {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }
        int index = currentSize;
        heapArray[index] = value;
        currentSize++;
        while (index > 0 && heapArray[index] > heapArray[(index - 1) / 2])
        {
            swap(heapArray[index], heapArray[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    int extract() override
    {
        if (currentSize <= 0)
        {
            cout << "Heap is empty." << endl;
            return -1;
        }
        int maxValue = heapArray[0];
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;
        heapify(0);
        return maxValue;
    }
};
class MinHeap : public Heap
{
protected:
    void heapify(int index) override
    {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        if (leftChild < currentSize && heapArray[leftChild] < heapArray[smallest])
            smallest = leftChild;
        if (rightChild < currentSize && heapArray[rightChild] < heapArray[smallest])
            smallest = rightChild;
        if (smallest != index)
        {
            swap(heapArray[index], heapArray[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap(int size) : Heap(size) {}
    void insert(int value) override
    {
        if (currentSize == maxSize)
        {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }
        int index = currentSize;
        heapArray[index] = value;
        currentSize++;
        while (index > 0 && heapArray[index] < heapArray[(index - 1) / 2])
        {
            swap(heapArray[index], heapArray[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    int extract() override
    {
        if (currentSize <= 0)
        {
            cout << "Heap is empty." << endl;
            return -1;
        }
        int minValue = heapArray[0];
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;
        heapify(0);
        return minValue;
    }
};
int main()
{
    int size;
    cout << "Enter the number of students: ";
    cin >> size;
    MaxHeap maxHeap(size);
    MinHeap minHeap(size);
    int choice;
    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Insert Marks" << endl;
        cout << "2. Find Maximum Marks" << endl;
        cout << "3. Find Minimum Marks" << endl;
        cout << "4. Display Max Heap" << endl;
        cout << "5. Display Min Heap" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int marks;
            cout << "Enter marks obtained: ";
            cin >> marks;
            maxHeap.insert(marks);
            minHeap.insert(marks);
            break;
        }
        case 2:
        {
            if (!maxHeap.isEmpty())
                cout << "Maximum Marks: " << maxHeap.peek() << endl;
            else
                cout << "No marks available." << endl;
            break;
        }
        case 3:
        {
            if (!minHeap.isEmpty())
                cout << "Minimum Marks: " << minHeap.peek() << endl;
            else
                cout << "No marks available." << endl;
            break;
        }
        case 4:
        {
            cout << "Max Heap:" << endl;
            maxHeap.printHeap();
            break;
        }
        case 5:
        {
            cout << "Min Heap:" << endl;
            minHeap.printHeap();
            break;
        }
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}