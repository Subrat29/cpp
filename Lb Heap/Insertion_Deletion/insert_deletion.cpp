#include<iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        //step1: insert at end
        size = size + 1;
        int index = size;
        arr[index] = val;

        //step2: take it to its correct posn
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()  //deletion me root node delete ho jayegi
    {
        if (size == 0)
        {
            cout << "Nothing to delete";
            return;
        }

        // step1: put last node in root node
        arr[1] = arr[size];

        // step2: remove last node
        size--;

        // step3: correct posn of root node
        int index = 1;
        while (index < size)
        {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            if (leftChild < size && arr[index] < arr[leftChild])      //left or right child should less than size
            {
                swap(arr[index], arr[leftChild]);
                index = leftChild;
            }
            else if (rightChild < size && arr[index] < arr[rightChild])
            {
                swap(arr[index], arr[rightChild]);
                index = rightChild;  
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Heap h;
    h.insert(55);
    h.insert(50);
    h.insert(52);
    h.insert(54);
    h.insert(53);

    h.print();

    cout << endl;

    h.deletion();
    h.print();

    return 0;
}