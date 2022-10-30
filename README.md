# SortedListCpp


**Classes:**

|name|function|
|----|-----------|
|list_item|Wrapper for string|
|AutoSortedList| A list auto sorts on inserting item in it|
|UniqueIDList| List to generate unique string id|



# Class Definations

**list_item**

```
class list_item
{
public:
    string data;
    list_item *next;
};

```


**AutoSortedList**

```
class AutoSortedList
{
private:
    list_item *head;
    uint count = 0;
    uint binary_search(uint start, uint end, string &data);
    list_item *itemAt(uint index);

public:
    ~AutoSortedList();

    void insert(const char *data);
    void insert(string &data);

    uint search(const char *data);
    uint search(string &data);

    const char *at(uint index);

    void deleteData(const char *data);
    void deleteData(string &data);

    uint size();

    void error(HTMLUniqueIDError err, const char *log);
};

```

**UniqueIDList**

```
class UniqueIDList
{
private:
    AutoSortedList list;
    uint idLength = 16;
    char convertToASCII(uint value);
    unsigned int magicM = 4294967;
    unsigned int magicL = 1293967;
    unsigned int increment = 3193961;
    uint base = 52;

public:
    string generateID();
};

```


# Basic Usage

file: ```example/example.cpp```

prints 100000 generated string.

```
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

```

