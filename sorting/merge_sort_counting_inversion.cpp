#include <bits/stdc++.h>
using namespace std;


long merge(vector<int> &array, int const left, int const mid, int const right)
{
    long count = 0;
    auto const subArray1 = mid - left + 1;
    auto const subArray2 = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArray1],
        *rightArray = new int[subArray2];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArray1; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArray2; j++)
        rightArray[j] = array[mid + 1 + j];

    auto SubArray1_index = 0, // Initial index of first sub-array
        SubArray2_index = 0; // Initial index of second sub-array
    int mergedArray_index = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (SubArray1_index < subArray1 && SubArray2_index < subArray2) {
        if (leftArray[SubArray1_index] <= rightArray[SubArray2_index]) {
            array[mergedArray_index] = leftArray[SubArray1_index];
            SubArray1_index++;
        }
        else
        {
            array[mergedArray_index] = rightArray[SubArray2_index];
            SubArray2_index++;
            count += subArray1 - SubArray1_index ;
        }
        mergedArray_index++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (SubArray1_index < subArray1) {
        array[mergedArray_index] = leftArray[SubArray1_index];
        SubArray1_index++;
        mergedArray_index++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (SubArray2_index < subArray2) {
        array[mergedArray_index] = rightArray[SubArray2_index];
        SubArray2_index++;
        mergedArray_index++;
    }
    return count;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
long mergeSort(vector<int> &array, int const begin, int const end)
{
    long count = 0;
    if(begin < end)
    {
        auto mid =  (end + begin) / 2;
        count += mergeSort(array, begin, mid);
        count += mergeSort(array, mid + 1, end);
        count += merge(array, begin, mid, end);
    }
    return count;
}  

void printArray(vector<int> A, int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        cout << mergeSort(arr,0,n-1)<<endl;
    }
        return 0;
}