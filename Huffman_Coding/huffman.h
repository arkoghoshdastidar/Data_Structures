#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    char data;
    int frequency;
    node *left;
    node *right;
    node(int frequency, char data = '1')
    {
        this->frequency = frequency;
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class min_priority_queue
{
private:
    node **data_array;
    int next_index;
    int capacity;

public:
    min_priority_queue()
    {
        capacity = 5;
        data_array = new node *[capacity];
        next_index = 0;
        for (int i = 0; i < capacity; i++)
        {
            data_array[i] = NULL;
        }
    }
    void insert(node *element)
    {
        if (next_index == capacity)
        {
            node **newData = new node *[2 * capacity];
            capacity *= 2;
            for (int i = 0; i < capacity; i++)
            {
                if (i < next_index)
                {
                    newData[i] = data_array[i];
                }
                else
                {
                    newData[i] = NULL;
                }
            }
            delete data_array;
            data_array = newData;
        }
        data_array[next_index++] = element;
        upHeapify();
    }

private:
    void upHeapify()
    {
        int child_index = next_index - 1;
        int parent_index = 0;
        while (child_index > 0)
        {
            parent_index = (child_index - 1) / 2;
            if (data_array[parent_index]->frequency >= data_array[child_index]->frequency)
            {
                node *temp = data_array[parent_index];
                data_array[parent_index] = data_array[child_index];
                data_array[child_index] = temp;
            }
            else
            {
                break;
            }
            child_index = parent_index;
        }
    }

public:
    node *top()
    {
        if (next_index == 0)
        {
            return NULL;
        }
        return data_array[0];
    }

    void pop()
    {
        if (next_index == 0)
        {
            return;
        }
        node *temp = data_array[0];
        data_array[0] = data_array[next_index - 1];
        data_array[next_index - 1] = temp;
        next_index--;
        downHeapify();
    }

    int size()
    {
        return next_index;
    }

    bool empty()
    {
        return next_index == 0;
    }

private:
    void downHeapify()
    {
        int parent_index = 0;
        int left_child_index = 0;
        int right_child_index = 0;
        int child_index = 0;
        while (parent_index < next_index)
        {
            left_child_index = 2 * parent_index + 1;
            right_child_index = 2 * parent_index + 2;
            if (right_child_index < next_index)
            {
                if (data_array[right_child_index]->frequency < data_array[left_child_index]->frequency)
                {
                    child_index = right_child_index;
                }
                else
                {
                    child_index = left_child_index;
                }
            }
            else if (right_child_index >= next_index && left_child_index < next_index)
            {
                child_index = left_child_index;
            }
            else if (left_child_index >= next_index)
            {
                break;
            }
            if (data_array[parent_index]->frequency <= data_array[child_index]->frequency)
            {
                break;
            }
            node *temp = data_array[parent_index];
            data_array[parent_index] = data_array[child_index];
            data_array[child_index] = temp;
            parent_index = child_index;
        }
    }
};

void print(node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " " << root->frequency << endl;
    print(root->left);
    print(root->right);
}

pair<bool, string> get_code(node* root, char input)
{
    if(root->right == NULL && root->left == NULL)
    {
        pair<bool, string> ans;
        ans.first = false;
        ans.second = "";
        if(input == root->data)
        {
            ans.first = true;
        }
        return ans;
    }
    pair<bool, string> smallAns;
    smallAns = get_code(root->left, input);
    if(smallAns.first == true)
    {
        smallAns.first = true;
        smallAns.second = '0'+smallAns.second;
        return smallAns;
    }
    smallAns = get_code(root->right, input);
    if(smallAns.first)
    {
        smallAns.first = true;
        smallAns.second = '1' + smallAns.second;
        return smallAns;
    }
    return smallAns;
}

string encode(unordered_map<char, string> CHAR_TO_CODE, string input)
{
    string output = "";
    for(int i=0; i<input.size(); i++)
    {
        output += CHAR_TO_CODE[input.at(i)];
    }
    return output;
}

string decode(unordered_map<string, char> CODE_TO_CHAR, string input)
{
    string search;
    string output;
    for(int i=0; i<input.size(); i++)
    {
        search = search + input.at(i);
        if(CODE_TO_CHAR.count(search) > 0)
        {
            output = output + CODE_TO_CHAR[search];
            search = "";
        }
    }
    return output;
}