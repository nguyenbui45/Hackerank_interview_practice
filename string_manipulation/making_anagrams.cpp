#include <bits/stdc++.h>
#include <map>
using namespace std;


class HashTableEntry{
    public:
        int key;
        int value;

        HashTableEntry(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};

class HashMapTable{
    private:
        HashTableEntry **t;
        int T_S;
    public:
        HashMapTable(int T_S) {
            this->T_S = T_S;
            t = new HashTableEntry * [this->T_S];
            for(int i=0;i<this->T_S;i++)
                t[i] = NULL;
        }
        int HashFunc(int k)
        {
            return k % this->T_S;
        }

        // create new hash code for new key,
        void Insert(int key, int value)
        {
            int h = HashFunc(key);
            while(t[h] != NULL && t[h]->key != key)
            {
                h = HashFunc(h+1);
            }  
            if(t[h] != NULL)
                t[h]->value+=1;
                //delete t[h];
            else
            {
                t[h] = new HashTableEntry(key,value);
            }
        }

        //If key is not found, create hash code for key
        //If hash code = NULL => return 1
        //If hash code exist -> return value of selected key.
        int SearchKey(int key)
        {
            int h = HashFunc(key);
            while(t[h] != NULL && t[h]->key != key)
            {
                h = HashFunc(h+1);
            }
            if (t[h] == NULL)
                return -1;
            else
                return t[h]->value;
        }

        ~HashMapTable() { 
         for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
        }

};


int makeAnagram(string a, string b)
{
    return 0;
}

int main()
{

    map<char,int> char_to_num;
    char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    for(auto i=0;i < 26;i++)
    char_to_num.insert(pair<char,int>(alphabet[i],i));

    string a,b;
    getline(cin,a);
    getline(cin,b);

    HashMapTable a_hash(a.length());
    for(int i = 0 ; i < a.length();i++)
    {
        a_hash.Insert(char_to_num[a[i]],1);
    }
    HashMapTable b_hash(b.length());
    for(int i = 0 ; i < b.length();i++)
    {
        b_hash.Insert(char_to_num[b[i]],1);

    }

    cout << a_hash.SearchKey(char_to_num['a']);


    int res = makeAnagram(a,b);
    cout << res;
    return 0 ;
}