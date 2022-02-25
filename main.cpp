#include <iostream>
#include <ctime>

using namespace std;

void insertionSort(int* , int);
void mergeSort(int *, int const, int);
void merge(int *array, int const left, int const mid, int const right);
void quickSort(int *, int);

int count = 0;

int main()
{
    int testArray[5] = {3, 5, 1, 2, 4};

    //prompt user for size
    int SIZE = 15;

    //create & copy array
    int i = 0;
    int * arrayA = new int[SIZE];
    int * arrayB = new int[SIZE];
    int * arrayC = new int[SIZE];

    for(i=0; i<(SIZE); i++)
    {
        arrayA[i] = rand();
    }

    for(i=0; i<(SIZE); i++)
    {
        arrayB[i] = arrayA[i];
        arrayC[i] = arrayA[i];
    }
    int n = SIZE;
    //print array if less than 100 elems
    if(n < 101)
    {
        cout << "BEFORE: " << endl;
        for(i=0; i<SIZE; i++)
        {
            cout << arrayB[i] << endl;
        }
    }

    //insertionSort(arrayA, SIZE);
    //mergeSort(arrayB, 0, SIZE - 1);
    quickSort(arrayC, SIZE);

    //print sorted array if less than 100 elems
    if(n < 101)
    {
        cout << "\nAFTER: " << endl;
        for(i=0; i<SIZE; i++)
        {
            cout << arrayB[i] << endl;
        }
    }

    return 0;
}

void insertionSort(int *list, int n)
{
    clock_t time1, time2;
    double time_diff;
    int sum = 0;
    int key, i, j;
    //print array if less than 100 elems
    if(n < 101)
    {
        cout << "BEFORE: " << endl;
        for(i=0; i<n; i++)
        {
            cout << list[i] << endl;
        }
    }
    
    //insert sort
    time1 = clock();
    for(i=1; i<n; i++)
    {
        key = list[i];
        j = i-1;

        while(j >= 0 && list[j] > key)
        {
            list[j+1] = list[j];
            j = j-1;
        }
        list[j+1] = key;
    }
    time2 = clock();

    //cout << "Time 1: " << time1 << endl;
    //cout << "Time 2: " << time2 << endl;

    time_diff = (static_cast <double> (time2) - static_cast <double> (time1) ) / CLOCKS_PER_SEC;
    cout << "Insertion Sort Elapsed Time: " << time_diff  << " seconds" << endl;;

    //print sorted array if less than 100 elems
    if(n < 101)
    {
        cout << "\nAFTER: " << endl;
        for(i=0; i<n; i++)
        {
            cout << list[i] << endl;
        }
    }
}

void mergeSort(int *list, const int begin, const int end)
{
    //cout << "begin: " << begin << " end: " << end << endl;
    if(begin != end)
    { 
        int mid = begin + (end - begin) / 2;
        //cout << "mid: " << mid << endl;
        mergeSort(list, begin, mid);
        mergeSort(list, mid+1, end);
        merge(list, begin, mid, end);
    }
}

void merge(int *array, const int left, const int mid, const int right)
{
    //cout << "MERGE RUN " << count << "............." << endl;
    //count++;
    //cout << "left: " << left << " mid:" << mid << " right: " << right << endl;

    int const subArrayA = mid - left +1;
    int const subArrayB = right - mid;

    //cout << "subArrayA: " << subArrayA << " subArrayB: " << subArrayB << endl;

    //create temp arrays
    int *leftArray = new int[subArrayA];
    int *rightArray = new int[subArrayB];

    //copy to temp arrays
    for(int i=0; i<subArrayA; i++)
        leftArray[i] = array[left + i];

    for(int j=0; j<subArrayB; j++)
        rightArray[j] = array[mid + 1 + j];
    
    //debug - print left & right array contents
    // cout << "\nleft array contents: " << endl;
    // for(int i=0; i<subArrayA; i++)
    //     cout << leftArray[i] << ", ";
    // cout << "\nright array contents: " << endl;
    // for(int i=0; i<subArrayB; i++)
    //     cout << rightArray[i] << ", ";
    // cout << "\n\n";

    //init indexes
    int indexSubArrayA = 0;
    int indexSubArrayB = 0;
    int indexMergedArray = left;

    //merge temp arrays back into array[left...right]
    while(indexSubArrayA < subArrayA && indexSubArrayB < subArrayB)
    {
        if(leftArray[indexSubArrayA] <= rightArray[indexSubArrayB])
        {
            array[indexMergedArray] = leftArray[indexSubArrayA];
            indexSubArrayA++;
        }
        else
        {
            array[indexMergedArray] = rightArray[indexSubArrayB];
            indexSubArrayB++;
        }
        indexMergedArray++;
    }

    //copy any remaining elements of left
    while(indexSubArrayA < subArrayA)
    {
        array[indexMergedArray] = leftArray[indexSubArrayA];
        indexSubArrayA++;
        indexMergedArray++;
    }
    //copy any remaining elements of right
    while(indexSubArrayB < subArrayB)
    {
        array[indexMergedArray] = rightArray[indexSubArrayB];
        indexSubArrayB++;
        indexMergedArray++;
    }
    
}

void quickSort(int *list, int n)
{
    clock_t time1, time2;
    double time_diff;
    int sum = 0;
    int i;
    //print array if less than 100 elems
    if(n < 101)
    {
        cout << "BEFORE: " << endl;
        for(i=0; i<n; i++)
        {
            cout << list[i] << endl;
        }
    }
    
    //quick sort
    time1 = clock();
    for(i=1; i<n; i++)
    {
       
    }
    time2 = clock();

    //cout << "Time 1: " << time1 << endl;
    //cout << "Time 2: " << time2 << endl;

    time_diff = (static_cast <double> (time2) - static_cast <double> (time1) ) / CLOCKS_PER_SEC;
    cout << "Insertion Sort Elapsed Time: " << time_diff  << " seconds" << endl;;

    //print sorted array if less than 100 elems
    if(n < 101)
    {
        cout << "\nAFTER: " << endl;
        for(i=0; i<n; i++)
        {
            cout << list[i] << endl;
        }
    }
}
