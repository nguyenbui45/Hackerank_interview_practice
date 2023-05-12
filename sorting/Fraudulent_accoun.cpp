#include <bits/stdc++.h>
using namespace std;
/*
input: d-> trailing day
       expenditure[] ->  client's daily expenditure prior n days (n is the length of array)

output: no of notification's mess.
    If the money of condidered day i >= median{i-d, i-1}*2 , add notification's count

*/


/*
Counting sort:
Step 1: Slide through input array, count the value frequecy and add to count array
->input index: 0 1 2 3 4 5 6 7 8
->input value: 2 3 5 4 3 7 1 2 1

->count index: 0 1 2 3 4 5 6 7
->count value: 0 2 2 2 1 1 0 1  

Step 2: Do cumulative values on count array
->count index: 0 1 2 3 4 5 6 7
->count value: 0 2 4 6 7 8 8 9

Step 3: Place every element of input array to sorted order
->input index: 0 1 2 3 4 5 6 7 8
->input value: 2 3 5 4 3 7 1 2 1

->count index: 0 1 2 3 4 5 6 7
->count value: 0 2 4 6 7 8 8 9

->output index: 0 1 2 3 4 5 6 7 8
->output value: 1 1 2 2 3 3 4 5 7

explain in detail:
1. access value input[0] -> index of count array
2. access value count[input[0]] -> index of output array
3. put value of input[0] to output[count[input[0]]]
4. count[input[0]] -=1


*/


int median(vector<int> &count, int d)
{
    vector<int> cumulative_count (count);

    for(int i=1; i < cumulative_count.size();i++)
    {
        cumulative_count[i] += cumulative_count[i-1];
    }

    int a = 0;
    int b = 0;
    int median;
    int first,second;
    bool get_f= false;
    bool get_s = false;

    if(d%2 == 0)
    {
        first = d/2;
        second = first + 1;

        for(int i = 0; i < cumulative_count.size();i++)
        {
            if(first <= cumulative_count[i])
            {
                a = i;
                get_f = true;
            }

            if(second <= cumulative_count[i])
            {
                b = i;
                get_s = true;
            }

            if(get_f == true && get_s == true)
                break;
        }
    }
    else
    {
        first = d/2 + 1;
        for(int i = 0;i < cumulative_count.size();i++)
        {
            if(first <= cumulative_count[i])
            {
                a = 2*i;
                break;
            }
        }
    }
    median = a + b;
    return median;

}




int countingSort(std::vector<int> array, int d)
{
    // To optimize count array, we also find the min value to 
    // reduce uneccesary values prior min value.
    int noti = 0;
    // distiguish odd or even d
    int max = 0;
    for(auto i : array)
    {
        if (max < i)
        {
            max = i;
        }
    }

 // add d first elenment to input

    int count_arr_size = max+ 1; // max element in count array is 201
    std::vector<int> count(count_arr_size,0);

    //Store the frequent of each value in input array into count array
    for(int i = 0; i < d;i++)
        count[array[i]] ++;



    for(int i = d; i < array.size();i++)
    {
      int medi = median(count,d);
      if(array[i] >= medi)
        noti +=1;

      count[array[i]]++;
      count[array[i-d]]++;
    }
    return noti;
}


int main()
{
    int n,d;
    std::vector<int> expenditure;

    std::cin >> n >> d;
    
    for(int i = 0; i < n;i++)
    {
        int temp;
        std::cin >> temp;
        expenditure.push_back(temp);
    }
    std::cout <<countingSort(expenditure,d);
    return 0;
}
