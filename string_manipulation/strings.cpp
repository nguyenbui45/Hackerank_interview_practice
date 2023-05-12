#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b;
    cin >> a;
    cin >> b;
    int len_a = a.length();
    int len_b = b.length();
    cout << len_a <<" " <<len_b <<endl;
    cout<< a <<b <<endl;
    cout<< b[0]; for(int i=1;i < len_a;i++){cout<<a[i];}  
    cout<< " ";
    cout<< a[0]; for(int i=1;i < len_b;i++){cout<<b[i];}
    return 0;

}
