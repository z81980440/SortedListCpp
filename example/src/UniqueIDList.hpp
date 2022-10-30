#pragma once

#include <string>
#include <iostream>

using namespace std;

class list_item
{
public:
    string data;
    list_item *next;
};

enum HTMLUniqueIDError
{
    INDEX_DOESNT_EXIST = 0
};

typedef unsigned int uint;

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

char UniqueIDList::convertToASCII(uint value)
{
    return (char)value < 26 ? (value + 65) : (value + 97 - 26);
}

string UniqueIDList::generateID()
{
    unsigned int temp = magicM;
    magicM += increment;
    string id = "";
    while (temp)
    {
        unsigned long int reminder = temp % base;
        temp /= base;
        id += convertToASCII(reminder);
    }

    temp = magicL;
    magicL += increment;
    while (temp)
    {
        unsigned long int reminder = temp % base;
        temp /= base;
        id += convertToASCII(reminder);
    }

    return id;
}

uint AutoSortedList::binary_search(uint start, uint end, string &data)
{
    if (size() == 0)
        return 0;
    if (end < start)
        return (end < 0) ? 0 : end;
    uint half = start + (end - start) / 2;
    int compare = data.compare(at(half - 1));

    if (compare < 0)
        return binary_search(start, half - 1, data);
    if (compare > 0)
        return binary_search(half + 1, end, data);
    return half;
}

const char *AutoSortedList::at(uint index)
{
    if (!(index < size()))
    {
        error(INDEX_DOESNT_EXIST, nullptr);
        return "";
    }

    list_item *current = itemAt(index);
    return current->data.c_str();
}

uint AutoSortedList::size()
{
    return count;
}

AutoSortedList::~AutoSortedList()
{
    list_item *current, *temp;
    current = head;
    while (current->next)
    {
        temp = current;
        current = current->next;
        delete temp;
    }

    free(current);
}

void AutoSortedList::insert(const char *data)
{
    string str = data;
    insert(str);
}

void AutoSortedList::insert(string &data)
{
    list_item *item = new list_item();
    item->data = data;
    uint toAppendAfter = search(data);
    if (!toAppendAfter)
    {
        list_item *after = head;
        head = item;
        item->next = after;
        count++;
        return;
    }
    list_item *before, *after;

    before = itemAt(toAppendAfter - 1);
    if (!before)
    {
    }
    after = before->next;

    before->next = item;
    item->next = after;
    count++;
}

uint AutoSortedList::search(const char *data)
{
    string str = data;
    return search(str);
}

uint AutoSortedList::search(string &data)
{
    return binary_search(1, count, data);
}

list_item *AutoSortedList::itemAt(uint index)
{
    list_item *current = head;
    for (uint i = 0; i < index; i++)
        current = current->next;
    return current;
}

void AutoSortedList::error(HTMLUniqueIDError err, const char *log)
{
    // Do something
}
