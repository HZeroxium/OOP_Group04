#include "cRectangle.h"
#include "cSquare.h"

int main()
{
    cRectangle **rectangles = new cRectangle *[2];

    rectangles[0] = new cRectangle();
    rectangles[1] = new cSquare();

    for (int i = 0; i < 2; ++i)
    {
        cout << "Enter the following information of the rectangle " << i + 1 << ":" << endl;
        cin >> *rectangles[i];
        cout << "----------------------------------------" << endl;
    }

    for (int i = 0; i < 2; ++i)
    {
        cout << *rectangles[i];
        cout << "----------------------------------------" << endl;
    }
}