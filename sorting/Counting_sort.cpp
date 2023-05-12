#include <bits/stdc++.h>


int max_value(std::vector<int> array)
{
    int max = array[0];
    for(auto i : array)
    {
        if (max < i)
        {
            max = i;
        }
    }
    return max;
}

int min_value(std::vector<int> array)
{
    int min = array[0];
    for(auto i : array)
    {
        if (min > i)
        {
            min = i;
        }
    }
    return min;
}

void countingSort(std::vector<int> array, int d)
{
    std::vector<int> output(array.size(),0);
    // To optimize count array, we also find the min value to 
    // reduce uneccesary values prior min value.
    int min = min_value(array);
    int max = max_value(array);
    int count_arr_size = max - min + 1;
    std::vector<int> count(count_arr_size,0);

    //Store the frequent of each value in input array into count array
    for(int i = 0; i < array.size();i++)
        count[array[i] - min] ++;
    // Cumulative values on count array
    for(int i =1; i <count_arr_size; i++)
        count[i]+= count[i-1];
    //Place the elemne t in sorted order
    for(int i=0; i < output.size();i++)
    {
        output[count[array[i] - min]-1]= array[i];
        count[array[i]-min]--;
    }


}