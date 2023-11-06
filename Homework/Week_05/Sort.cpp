#include <iostream>
#include <string>

using std::cout;
using std::ostream;
using std::string;

// Singleton class SortAlgorithm
template <typename T>
class SortAlgorithm
{
    typedef bool (*Compare)(const T &, const T &);

private:
    SortAlgorithm() = default;
    SortAlgorithm(const SortAlgorithm &) = delete;
    SortAlgorithm &operator=(const SortAlgorithm &) = delete;
    void (*curAlg)(T *, int, Compare);

public:
    static SortAlgorithm &GetInstance(void (*alg)(T *, int, Compare))
    {
        static SortAlgorithm instance;
        instance.curAlg = alg;
        return instance;
    }

    static void BubbleSort(T *arr, int len, Compare cmp)
    {
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = len - 1; j > i; j--)
            {
                if (cmp(arr[j], arr[j - 1]))
                {
                    T tmp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = tmp;
                }
            }
        }
    }

    static void SelectionSort(T *arr, int len, Compare cmp)
    {
        for (int i = 0; i < len - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < len; j++)
            {
                if (cmp(arr[j], arr[min]))
                {
                    min = j;
                }
            }
            if (min != i)
            {
                T tmp = arr[i];
                arr[i] = arr[min];
                arr[min] = tmp;
            }
        }
    }

    static void InsertionSort(T *arr, int len, Compare cmp)
    {
        for (int i = 1; i < len; i++)
        {
            T tmp = arr[i];
            int j = i;
            while (j > 0 && cmp(tmp, arr[j - 1]))
            {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = tmp;
        }
    }

    void Sort(T *arr, int len, Compare cmp)
    {
        if (curAlg == nullptr)
        {
            curAlg = BubbleSort;
        }
        curAlg(arr, len, cmp);
    }
};

struct Fraction
{
    int numerator;
    int denominator;
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {}
};

ostream &operator<<(ostream &os, const Fraction &f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

bool operator<(const Fraction &a, const Fraction &b)
{
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

bool operator>(const Fraction &a, const Fraction &b)
{
    return a.numerator * b.denominator > b.numerator * a.denominator;
}

template <typename T>
bool Ascending(const T &a, const T &b)
{
    return a < b;
}

template <typename T>
bool Descending(const T &a, const T &b)
{
    return a > b;
}

template <typename T>
void PrintArray(T *arr, int len)
{
    if (arr == nullptr || len <= 0)
    {
        return;
    }
    cout << "[";
    for (int i = 0; i < len - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[len - 1] << "]" << std::endl;
}

int main()
{
    int intArr[] = {1, 3, 2, 5, 4};
    constexpr int intLen = std::size(intArr);
    cout << "Int array:\n";
    SortAlgorithm<int>::GetInstance(SortAlgorithm<int>::InsertionSort).Sort(intArr, intLen, Ascending);
    PrintArray(intArr, intLen);
    SortAlgorithm<int>::GetInstance(SortAlgorithm<int>::SelectionSort).Sort(intArr, intLen, Descending);
    PrintArray(intArr, intLen);

    Fraction fracArr[] = {Fraction(1, 2), Fraction(1, 3), Fraction(2, 3), Fraction(3, 4), Fraction(2, 5)};
    constexpr int fracLen = std::size(fracArr);
    cout << "Fraction array:\n";
    SortAlgorithm<Fraction>::GetInstance(SortAlgorithm<Fraction>::InsertionSort).Sort(fracArr, fracLen, Ascending);
    PrintArray(fracArr, fracLen);
    SortAlgorithm<Fraction>::GetInstance(SortAlgorithm<Fraction>::SelectionSort).Sort(fracArr, fracLen, Descending);
    PrintArray(fracArr, fracLen);

    float floatArr[] = {1.2, 1.3, 2.3, 3.4, 2.5};
    constexpr int floatLen = std::size(floatArr);
    cout << "Float array:\n";
    SortAlgorithm<float>::GetInstance(SortAlgorithm<float>::InsertionSort).Sort(floatArr, floatLen, Ascending);
    PrintArray(floatArr, floatLen);
    SortAlgorithm<float>::GetInstance(SortAlgorithm<float>::SelectionSort).Sort(floatArr, floatLen, Descending);
    PrintArray(floatArr, floatLen);

    string strArr[] = {"abc", "def", "ghi", "jkl", "mno"};
    constexpr int strLen = std::size(strArr);
    cout << "String array:\n";
    SortAlgorithm<string>::GetInstance(SortAlgorithm<string>::InsertionSort).Sort(strArr, strLen, Ascending);
    PrintArray(strArr, strLen);
    SortAlgorithm<string>::GetInstance(SortAlgorithm<string>::SelectionSort).Sort(strArr, strLen, Descending);
    PrintArray(strArr, strLen);
    return 0;
}
