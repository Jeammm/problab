#include <iostream>
#define MAX_N 2000010
using namespace std;

int arr[MAX_N];
long long inv_count;

void merge(int const left, int const mid, int const right)
{
  auto const subArrOneSize = mid - left + 1;
  auto const subArrTwoSize = right - mid;

  auto *leftArr = new int[subArrOneSize];
  auto *rightArr = new int[subArrTwoSize];

  for (auto i = 0; i < subArrOneSize; i++)
    leftArr[i] = arr[left + i];
  for (auto j = 0; j < subArrTwoSize; j++)
    rightArr[j] = arr[mid + 1 + j];

  auto indexOfSubArrOne = 0;
  auto indexOfSubArrTwo = 0;
  int indexOfMergedArr = left;

  while (indexOfSubArrOne < subArrOneSize && indexOfSubArrTwo < subArrTwoSize)
  {
    if (leftArr[indexOfSubArrOne] <= rightArr[indexOfSubArrTwo])
    {
      arr[indexOfMergedArr] = leftArr[indexOfSubArrOne];
      indexOfSubArrOne++;
    }
    else
    {
      arr[indexOfMergedArr] = rightArr[indexOfSubArrTwo];
      indexOfSubArrTwo++;
      inv_count += subArrOneSize - indexOfSubArrOne;
    }
    indexOfMergedArr++;
  }

  while (indexOfSubArrOne < subArrOneSize)
  {
    arr[indexOfMergedArr] = leftArr[indexOfSubArrOne];
    indexOfSubArrOne++;
    indexOfMergedArr++;
  }

  while (indexOfSubArrTwo < subArrTwoSize)
  {
    arr[indexOfMergedArr] = rightArr[indexOfSubArrTwo];
    indexOfSubArrTwo++;
    indexOfMergedArr++;
  }
  delete[] leftArr;
  delete[] rightArr;
}


void mergeSort(int const begin, int const end)
{
  if (begin >= end)
    return;

  auto mid = begin + (end - begin) / 2;
  mergeSort(begin, mid);
  mergeSort(mid + 1, end);
  merge(begin, mid, end);
}

void printArr(int size)
{
  for (auto i = 0; i < size; i++)
  { 
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main()
{
  int n = -1;
  int a;
  cin >> n;


  for (int i = 0; i < n; i++)
  {
    cin >> a;
    arr[i] = a;
  }
  
  int arr_size = n;

  mergeSort(0, arr_size - 1);

  cout << inv_count;

  return 0;
}