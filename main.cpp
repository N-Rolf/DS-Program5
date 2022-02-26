#include <iostream>
#include <ctime>

using namespace std;

void insertionSort(int* , int);
void mergeSort(int *, int const, int);
void merge(int *array, int const left, int const mid, int const right);
void quickSort(int *, int, int);
int partition(int *list, int low, int high);
void swap(int* a, int* b);
void print(int *list, int n, bool t);

int main()
{
    clock_t time1, time2;
    double time_diff;
    int sum = 0;
    int SIZE = 0;
    //prompt user for size
    cout << "Enter a number of integers to fill array with: " << endl;
    cin >> SIZE;
    cout << "now testing sort algorithms with " << SIZE << " elements...\n" << endl;

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

    //insertion sort
    print(arrayA, SIZE, 0);
    time1 = clock();
    insertionSort(arrayA, SIZE);
    time2 = clock();
    print(arrayA, SIZE, 1);
    time_diff = (static_cast <double> (time2) - static_cast <double> (time1) ) / CLOCKS_PER_SEC;
    cout << "Insertion Sort Elapsed Time: " << time_diff  << " seconds" << endl;

    //merge sort
    print(arrayB, SIZE, 0);
    time1 = clock();
    mergeSort(arrayB, 0, SIZE - 1);
    time2 = clock();
    print(arrayB, SIZE, 1);
    time_diff = (static_cast <double> (time2) - static_cast <double> (time1) ) / CLOCKS_PER_SEC;
    cout << "Merge Sort Elapsed Time: " << time_diff  << " seconds" << endl;

    //quick sort
    print(arrayA, SIZE, 0);
    time1 = clock();
    quickSort(arrayC, 0, SIZE - 1);
    time2 = clock();
    print(arrayA, SIZE, 1);
    time_diff = (static_cast <double> (time2) - static_cast <double> (time1) ) / CLOCKS_PER_SEC;
    cout << "Quick Sort Elapsed Time: " << time_diff  << " seconds" << endl;

    return 0;
}

void insertionSort(int *list, int n)
{
    int key, i, j;
    
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

void quickSort(int *list, int low, int high)
{
    if(low < high)
    {
        int index = partition(list, low, high);

        quickSort(list, low, index-1);
        quickSort(list, index+1, high);
    }
}

int partition(int *list, int low, int high)
{
    int pivot = list[high];
    int i = (low-1);

    for(int j=low; j <= high-1; j++)
    {
        if(list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i+1], &list[high]);
    return (i+1);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int *list, int n, bool t)
{
    if(n < 101)
    {
        if(t==0)
            cout << "PRE-SORT..." << endl;
        else
            cout << "POST-SORT..." << endl;

        for(int i=0; i<n; i++)
        {
            cout << list[i] << endl;
        }
    }
}