#include <iostream>
#include <ctime>
using namespace std;

int main ()
{

    clock_t time1, time2;
    double time_diff;
    int sum = 0;

    time1 = clock();

    for (int i=0; i < 10000000; i++)
        sum++;

    time2 = clock();

    cout << "Time 1: " << time1 << endl;
    cout << "Time 2: " << time2 << endl;

    time_diff = (static_cast <double> (time2) - static_cast <double> (time1) ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time: " << time_diff  << endl;;

    return 0;

}
