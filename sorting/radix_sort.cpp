#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int getMax(vector<long int> arr, int n)
{
    int max = arr[0];
    for(int i = 1; i < n;i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}


void countingSort(vector<long int> &arr, int size, int place, long int max)
{
    vector<long int> output(size);
    vector<long int> count(max,0);

    // Cal count of elements
    for(int i = 0; i < size;i++)
    {
        count[(arr[i]/place) % 10]++;
    }
    // Cumulative count
    for(int i = 1;i < max; i++ )
    {
        count[i] +=count[i-1];
    }

    // Place the elements in sorted order
    for(int i = size-1;i>=0;i--)
    {
        output[count[(arr[i] / place)%10]-1] = arr[i];
        count[(arr[i] / place) % 10] --;
    }

    for(int i = 0; i <size;i++)
    {
        arr[i] = output[i];
    }

}

int radixSort(vector<long int> &arr,int size,int k)
{
    int max = getMax(arr,size);

    //counting sort to sort element based on place value
    for(int place = 1; max/place > 0; place*=10)
    {
        countingSort(arr,size,place,max);
    }

    for(int i = 0;i < size;i++)
    {
        cout << arr[i] <<endl;
    }

    int count_item = 0;
    for(int i = 0;i < arr.size();i++)
    {
        if(k < 0)
        {
            count_item -=1;
            break;
        }
        else if( k ==0)
        {
            break;
        }

        k -=arr[i];
        count_item+=1;
    }
    return count_item;

}

int main()
{
    int n,k;
    long int temp = 0;
    cin>>n;
    cin>>k;
    vector<long int> array;

    for (int i=0; i < n;i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
    int byte = 0;
    for(int i = 0; i < array.size();i++)
    {
        byte += sizeof(array[i]);
    }

    cout << radixSort(array,byte/ sizeof(array[0]),k);
    return 0;
}
