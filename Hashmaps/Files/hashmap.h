#include <string>
using namespace std;
template <class T>
class node
{
public:
    string key;
    T value;
    node<T> *next;
    node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~node()
    {
        delete next;
    }
};

template <class T>
class hashmap
{
private:
    node<T> **bucketArray;
    int bucketSize;
    int size;
    int getIndex(string);
    void rehash();

public:
    hashmap();
    ~hashmap();
    void insert(string, T);
    T search(string);
    T erase(string);
    int count();
    double loadFactor();
};

template <class T>
hashmap<T>::hashmap()
{
    bucketArray = new node<T> *[2];
    bucketSize = 2;
    size = 0;
    for (int i = 0; i < 2; i++)
    {
        bucketArray[i] = NULL;
    }
}

template <class T>
hashmap<T>::~hashmap()
{
    for (int i = 0; i < bucketSize; i++)
        delete bucketArray[i];
    delete[] bucketArray;
}

template <class T>
int hashmap<T>::getIndex(string key)
{
    int count = 0;
    int p = 1;
    for (int i = key.size() - 1; i >= 0; i--)
    {
        count += p * key[i];
        p *= 17;
        count %= bucketSize;
        p %= bucketSize;
    }
    return count % bucketSize;
}

template <class T>
void hashmap<T>::insert(string key, T value)
{
    int index = getIndex(key);
    node<T> *head = bucketArray[index];
    while (head != NULL)
    {
        if (head->key == key)
        {
            head->value = value;
            return;
        }
        head = head->next;
    }
    node<T> *temp = new node<T>(key, value);
    temp->next = bucketArray[index];
    bucketArray[index] = temp;
    size++;
    float loadFactor = (float(size)) / bucketSize;
    if (loadFactor > 0.7) // load-factor is kept greater than 0.7 for better optimization.
    {
        rehash();
    }
}

template <class T>
double hashmap<T>::loadFactor()
{
    return (double(size))/bucketSize;
}

template <class T>
T hashmap<T>::search(string key)
{
    int index = getIndex(key);
    node<T> *head = bucketArray[index];
    while (head != NULL)
    {
        if (head->key == key)
        {
            return head->value;
        }
        head = head->next;
    }
    return 0;
}

template <class T>
T hashmap<T>::erase(string key)
{
    int index = getIndex(key);
    node<T> *head = bucketArray[index];
    node<T> *previous = NULL;
    T value = 0;
    while (head != NULL)
    {
        if (head->key == key)
        {
            value = head->value;
            if (previous == NULL)
            {
                bucketArray[index] = head->next;
            }
            else
            {
                previous->next = head->next;
            }
            size--;
            head->next = NULL;
            delete head;
            break;
        }
        previous = head;
        head = head->next;
    }
    return value;
}

template <class T>
int hashmap<T>::count()
{
    return size;
}

template <class T>
void hashmap<T>::rehash()
{
    node<T> **temp = bucketArray;
    bucketArray = new node<T> *[2 * bucketSize];
    int oldBucketSize = bucketSize;
    bucketSize *= 2;
    size = 0;
    for (int i = 0; i < bucketSize; i++)
    {
        bucketArray[i] = NULL;
    }
    for (int i = 0; i < oldBucketSize; i++)
    {
        node<T> *head = temp[i];
        while (head != NULL)
        {
            string key = head->key;
            T value = head->value;
            insert(key, value);
            head = head->next;
        }
    }
    for (int i = 0; i < oldBucketSize; i++)
    {
        delete temp[i];
    }
    delete[] temp;
}