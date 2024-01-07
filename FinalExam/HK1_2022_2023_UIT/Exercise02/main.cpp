#include <iostream>

using namespace std;

class IntArr
{
private:
    int count;
    int *values;

public:
    IntArr(int count = 0, int value = 0)
    {
        this->count = count;
        if (count == 0)

            values = nullptr;

        else
        {
            values = new int[count];
            for (int i = 0; i < count; i++)
            {
                values[i] = value;
            }
        }
    }

    IntArr concat(const IntArr &other)
    {
        int newSize = other.count + count;
        IntArr result(newSize);
        for (int i = 0; i < count; i++)
        {
            result.values[i] = values[i];
        }
        for (int i = count; i < newSize; i++)
        {
            result.values[i] = other.values[i - count];
        }
        return result;
    }

    void push(int value)
    {
        int newSize = count + 1;
        int *newValues = new int[newSize];
        for (int i = 0; i < count; i++)
        {
            newValues[i] = values[i];
        }
        newValues[count] = value;
        delete values;
        values = newValues;
        count = newSize;
    }

    friend ostream &operator<<(ostream &out, const IntArr &arr)
    {
        out << "[";
        for (int i = 0; i < arr.count - 1; i++)
        {
            out << arr.values[i] << ", ";
        }
        if (arr.count >= 1)
            out << arr.values[arr.count - 1];
        else
            out << "Empty array";
        out << "]" << endl;
        return out;
    }

    friend istream &operator>>(istream &in, IntArr &arr)
    {
        cout << "Enter size of array: ";
        in >> arr.count;
        arr.values = new int[arr.count];
        cout << "Enter elements: ";
        for (int i = 0; i < arr.count; i++)
        {
            cin >> arr.values[i];
        }
        return in;
    }
};

int main()
{
    IntArr l1;
    cout << l1;
    IntArr l2(3, 2);
    cout << l2;
    IntArr l3(2);
    cout << l3;
    IntArr l4 = l2.concat(l3);
    cout << l4;
    l2.push(3);
    cout << l2;
    cin >> l2;
    cout << l2;
}