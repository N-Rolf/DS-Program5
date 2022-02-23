#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    //prompt user for size
    int SIZE = 99;

    //create & copy array
    int i = 0;
    int * arrayA = new int[SIZE];
    int * arrayB = new int[SIZE];
    int * arrayC = new int[SIZE];

    for(i=0; i<(SIZE-1); i++)
    {
        arrayA[i] = rand();
    }

    for(i=0; i<(SIZE-1); i++)
    {
        arrayB[i] = arrayA[i];
        arrayC[i] = arrayA[i];
    }

    //insert sort

    //merge sort

    //quick sort

    return 0;
}