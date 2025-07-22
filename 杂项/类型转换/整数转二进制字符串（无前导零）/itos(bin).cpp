#include <bits/stdc++.h>
using namespace std;
string getBinary(int n)
{

    int index = 0;
    const int size = 32;
    string binary = bitset<size>(n).to_string();
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == '1')
        {
            index = i;
            break;
        }
    }
    string res = binary.substr(index);
    return res;
}