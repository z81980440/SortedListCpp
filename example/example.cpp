#include<iostream>
#include"src/UniqueIDList.hpp"

using namespace std;

int main1()
{
    AutoSortedList li;

    li.insert("hello");
    li.insert("world");

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;

    li.insert("debug");

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;

    li.insert("write");

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;

    li.insert("compile");

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;

    li.insert("break");

    cout << "search result: " << li.search("break") << endl;

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;






    li.insert("world");

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;

    li.insert("debug");

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;

    li.insert("write");

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;

    li.insert("compile");

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;

    li.insert("break");

    cout << "search result: " << li.search("break") << endl;

    for(uint i = 0; i<li.size(); i++)
        cout <<li.at(i)<<"->";
    cout << endl;





}


int main()
{
    UniqueIDList li;
    for(int i = 0;i<10000;i++)
    {
        cout << li.generateID() <<endl;
    }
}