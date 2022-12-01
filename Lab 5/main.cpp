#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void insertionsort(vector<int> &a)
{
    int values;
    int i;
    int j;
    int n = a.size();
    for (i = 1; i < n; i++)
    {
        values = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > values)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = values;
    }
}
int main()
{

    vector<int> a;
    srand(time(0));
    // for (int c = 0; c < 10; c++)
    // {
    for (int i = 0; i < 100; i++)
    {
        int rndm = rand() % 1000;
        a.push_back(rndm);
    }
    cout << "Before sorting: " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    double time1 = clock();
    insertionsort(a);
    double time2 = clock();
    cout << endl;
    cout << "After sorting: " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << (double)((time2 - time1) / (CLOCKS_PER_SEC)) * 1000 << " ms" << endl;
    // }
}