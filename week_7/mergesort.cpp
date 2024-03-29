#include <iostream>
#define MAX_N 2000010
using namespace std;

int arr[MAX_N];

void merge(int const left, int const mid, int const right)
{
  auto const subArrOne = mid - left + 1;
  auto const subArrTwo = right - mid;

  auto *leftArr = new int[subArrOne];
  auto *rightArr = new int[subArrTwo];

  for (auto i = 0; i < subArrOne; i++)
    leftArr[i] = arr[left + i];
  for (auto j = 0; j < subArrTwo; j++)
    rightArr[j] = arr[mid + 1 + j];

  auto indexOfSubArrOne = 0;
  auto indexOfSubArrTwo = 0;
  int indexOfMergedArr = left;

  while (indexOfSubArrOne < subArrOne && indexOfSubArrTwo < subArrTwo)
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
    }
    indexOfMergedArr++;
  }
  // Copy the remaining elements of
  // left[], if there are any
  while (indexOfSubArrOne < subArrOne)
  {
    arr[indexOfMergedArr] = leftArr[indexOfSubArrOne];
    indexOfSubArrOne++;
    indexOfMergedArr++;
  }
  // Copy the remaining elements of
  // right[], if there are any
  while (indexOfSubArrTwo < subArrTwo)
  {
    arr[indexOfMergedArr] = rightArr[indexOfSubArrTwo];
    indexOfSubArrTwo++;
    indexOfMergedArr++;
  }
  delete[] leftArr;
  delete[] rightArr;
}

// begin is for left index and end is
// right index of the sub-arr
// of arr to be sorted */
void mergeSort(int const begin, int const end)
{
  if (begin >= end)
    return; // Returns recursively

  auto mid = begin + (end - begin) / 2;
  mergeSort(begin, mid);
  mergeSort(mid + 1, end);
  merge(begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an arr
void printArr(int size)
{
  for (auto i = 0; i < size-1; i++)
  { 
    cout << arr[i] << " ";
  }
  cout << arr[size-1] << "\n";
}

// Driver code
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n = -1;
  int a;
  cin >> n;

  while (n != 0)
  {
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      arr[i] = a;
    }
    
    int arr_size = n;

    mergeSort(0, arr_size - 1);

    printArr(arr_size);

    cin >> n;
  }

  return 0;
}