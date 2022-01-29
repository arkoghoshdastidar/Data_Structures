#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class STACK
{
    stack<int> main_stack;
    stack<int> auxillary_stack;
    int size_of_main_stack;

    public:
    STACK()
    {
        size_of_main_stack = 0;
    }
    void push_element(int element)
    {
        if(size_of_main_stack == 0)
        {
            main_stack.push(element);
            auxillary_stack.push(element);
            size_of_main_stack++;
            return;
        }
        main_stack.push(element);
        size_of_main_stack++;
        if(auxillary_stack.top() >= element)
        {
            auxillary_stack.push(element);
        }
    }
    void pop_element()
    {
        if(main_stack.size() == 0)
        {
            return;
        }
        if(auxillary_stack.top() == main_stack.top())
        {
            auxillary_stack.pop();
        }
        main_stack.pop();
    }
    int min()
    {
        if(main_stack.size() == 0)
        {
            return -1;
        }
        return auxillary_stack.top();
    }
};

bool monk_prediction(vector<int> const * const voldemort_army, int N, int min)
{
    if(min == -1)
    {
        return false;
    }

    for(int i=1; i<N; i++)
    {
        int temp_size = voldemort_army[i].size();

        if(temp_size == 0)
        {
            return false;
        }

        if(voldemort_army[i][temp_size-1] < min)
        {
            return false;
        }

        int low = 0;
        int high = temp_size-1;
        int mid = (high+low)/2;

        while(low < high)
        {
            if(voldemort_army[i][mid] <= min)
                low = mid+1;
            else
                high = mid-1;
            mid = (low+high)/2;
        }

        for(int j=low; j<temp_size; j++)
        {
            if(voldemort_army[i][j] > min)
            {
                min = voldemort_army[i][j];
                break;
            }
        }
    }
    return true;
}

int main(void)
{
    // creating voldemort army.
    int N;
    cin >> N;
    vector<int> *voldemort_army = new vector<int>[N];
    STACK legendaries;
    for(int i=0; i<N; i++)
    {
        int x;
        cin >> x;
        for(int j=0; j<x; j++)
        {
            int y;
            cin >> y;
            voldemort_army[i].push_back(y);
            if(i == 0)
            {
                legendaries.push_element(y);
            }
        }
    }
    // voldemort army creation finished and running query starts form here onwards.
    int t;
    cin >> t;
    while(t--)
    {
        int v;
        cin >> v;
        if(v == 0)
        {
            int k;
            cin >> k;
            voldemort_army[k-1].pop_back();
            if(k == 1)
                legendaries.pop_element();
        }
        else if(v == 1)
        {
            int k, h;
            cin >> k >> h;
            voldemort_army[k-1].push_back(h);
            if(k == 1)
                legendaries.push_element(h);
        }
        else if(v == 2)
        {
            bool result = monk_prediction(voldemort_army, N, legendaries.min());
            if(result)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}