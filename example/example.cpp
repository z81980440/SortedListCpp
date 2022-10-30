#include<iostream>
#include"src/UniqueIDList.hpp"

using namespace std;

int main()
{
    UniqueIDList li;
    for(int i = 0;i<10000;i++)
    {
        cout << li.generateID() <<endl;
    }
}