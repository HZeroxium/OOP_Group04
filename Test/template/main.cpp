#include "utils.h"

using int_array = Array<int>;

int main()
{
    int_array a({1, 2, 3, 4, 5});
    int_array b({6, 7, 8, 9, 10});
    a.print();
    b.print();
    my_swap(a, b);
    a.print();
    b.print();
}