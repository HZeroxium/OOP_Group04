#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Array
{
private:
    vector<int> arr;

public:
    Array(const vector<int> &arr)
    {
        this->arr = arr;
    }
    vector<int> &getArr()
    {
        return arr;
    }
    void print() const
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Array a(v);
    a.print();
    vector<int> v2 = a.getArr();
    v2[0] = 100;
    a.print();
}