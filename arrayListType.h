#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>& operator=(const arrayListType<elemType>&);
      // Overloads the assignment operator
    bool isEmpty() const;
      // Determines whether the list is empty
    bool isFull() const;
      // Determines whether the list is full
    int listSize() const;
      // Returns the number of elements in the list
    int maxListSize() const;
      // Returns the maximum capacity of the list
    void print() const;
      // Outputs the elements of the list
    bool isItemAtEqual(int location, const elemType& item) const;
      // Checks if list[location] == item
    void insertAt(int location, const elemType& insertItem);
      // Inserts an item at the specified location
    void insertEnd(const elemType& insertItem);
      // Inserts an item at the end of the list
    void removeAt(int location);
      // Removes the item at the specified location
    void retrieveAt(int location, elemType& retItem) const;
      // Retrieves the item at the specified location
    void replaceAt(int location, const elemType& repItem);
      // Replaces the item at the specified location
    void clearList();
      // Removes all elements from the list
    int seqSearch(const elemType& item) const;
      // Searches the list for an item
    void insert(const elemType& insertItem);
      // Inserts an item if not already present
    void remove(const elemType& removeItem);
      // Removes an item from the list

    // Lab02 tasks: students implement these
    void removeAll(const elemType& removeItem);
    elemType min() const;
    elemType max() const;

    // Constructors and destructor
    arrayListType(int size = 100);
    arrayListType(const arrayListType<elemType>& otherList);
    ~arrayListType();

protected:
    elemType *list;  // array to hold the list elements
    int length;      // current number of elements
    int maxSize;     // maximum capacity of the list
};

// -----------------------------------------------------------------------
// Provided implementations: students should NOT modify
// -----------------------------------------------------------------------

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating an array of size 100." << endl;
        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];
    assert(list != NULL);
    for (int j = 0; j < length; j++)
        list[j] = otherList.list[j];
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList)
{
    if (this != &otherList)
    {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new elemType[maxSize];
        assert(list != NULL);
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{ return (length == 0); }

template <class elemType>
bool arrayListType<elemType>::isFull() const
{ return (length == maxSize); }

template <class elemType>
int arrayListType<elemType>::listSize() const
{ return length; }

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{ return maxSize; }

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{ return (location >= 0 && location < length && list[location] == item); }

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
    if (location < 0 || location > length)
        cerr << "Insert location out of range." << endl;
    else if (length >= maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        for (int i = length; i > location; i--)
            list[i] = list[i - 1];
        list[location] = insertItem;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (length >= maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
        list[length++] = insertItem;
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "Retrieve location out of range." << endl;
    else
        retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cerr << "Replace location out of range." << endl;
    else
        list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList()
{ length = 0; }

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
    for (int i = 0; i < length; i++)
        if (list[i] == item)
            return i;
    return -1;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else if (seqSearch(insertItem) == -1)
        list[length++] = insertItem;
    else
        cerr << "No duplicates allowed." << endl;
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc = seqSearch(removeItem);
    if (loc != -1)
        removeAt(loc);
    else
        cout << "Item not found; nothing removed." << endl;
}

// -----------------------------------------------------------------------
// Lab02 stubs — implement these methods
// -----------------------------------------------------------------------

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    // TODO: student implements removeAt using swap-with-last or shift
}

template <class elemType>
void arrayListType<elemType>::removeAll(const elemType& removeItem)
{
    // TODO: student implements removeAll
}

template <class elemType>
elemType arrayListType<elemType>::min() const
{
    // TODO: student implements min
}

template <class elemType>
elemType arrayListType<elemType>::max() const
{
    // TODO: student implements max
}

#endif // H_arrayListType
