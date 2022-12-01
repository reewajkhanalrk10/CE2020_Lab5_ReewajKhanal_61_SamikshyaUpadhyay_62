#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int partition(vector<int> &arr, int l, int h)
{
  int piv = arr[l];
  int i = l + 1;
  int j = h;
  while (i <= j)
  {
    while (i <= j && arr[i] <= piv)
    {
      i++;
    }
    while (i <= j && arr[j] > piv)
    {
      j--;
    }
    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[l], arr[j]);
  return j;
}

// quicksort
void quicksort(vector<int> &arr, int l, int h)
{
  if (l < h)
  {
    int piv = partition(arr, l, h);
    quicksort(arr, l, piv - 1);
    quicksort(arr, piv + 1, h);
  }
}

void printArray(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> arr;
  // for (int c = 0; c < 10; c++)
  // {
    srand(time(0)); //random number 
    for (int i = 0; i < 50; i++)
    {
      arr.push_back(rand() % 1000);
    }
    cout << "~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~" << endl;
    // cout << "Loop " << c + 1 << endl;
    printArray(arr);
    double time1 = clock();
    quicksort(arr, 0, arr.size() - 1);
    double time2 = clock();
    cout << "After sorting: ";
    printArray(arr);
    cout << "Array Length: " << arr.size() << endl;
    cout << "Time Consumed: " << (double)((time2 - time1) / (CLOCKS_PER_SEC)) * 1000 << " ms" << endl;
  // }
  return 0;
}