#include "array.h"

//*********************************************************************************************************************
//************************************ CONSTRUCTORS AND DESTRUCTOR ****************************************************
//*********************************************************************************************************************

template <typename T>
Array<T>::Array()
{
    elements = vector<T>();
}

template <typename T>
Array<T>::Array(const vector<T> &elements)
{
    this->elements = elements;
}

template <typename T>
Array<T>::Array(const Array &array)
{
    elements = array.elements;
}

template <typename T>
Array<T>::Array(Array &&array)
{
    elements = array.elements;
    array.elements.clear();
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &array)
{
    elements = array.elements;
    return *this;
}

template <typename T>
Array<T> &Array<T>::operator=(Array &&array)
{
    elements = array.elements;
    array.elements.clear();
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    elements.clear();
}

//*********************************************************************************************************************
//*********************************************** GETTERS AND SETTERS **************************************************
//*********************************************************************************************************************

template <typename T>
const vector<T> &Array<T>::getElements() const
{
    return elements;
}

template <typename T>
void Array<T>::setElements(const vector<T> &elements)
{
    this->elements = elements;
}

template <typename T>
int Array<T>::size() const
{
    return elements.size();
}

//*********************************************************************************************************************
//***************************************************** OPERATORS ******************************************************
//*********************************************************************************************************************

template <typename T>
T &Array<T>::operator[](int index)
{
    return elements[index];
}

template <typename T>
const T &Array<T>::operator[](int index) const
{
    return elements[index];
}

//*********************************************************************************************************************
//****************************************************** METHODS *******************************************************
//*********************************************************************************************************************

template <typename T>
void Array<T>::print() const
{
    cout << "[";
    for (int i = 0; i < elements.size(); i++)
    {
        cout << elements[i];
        if (i < elements.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

//*********************************************************************************************************************
//******************************************************* FRIENDS *******************************************************
//*********************************************************************************************************************

template <typename T>
ostream &operator<<(ostream &out, const Array<T> &array)
{
    out << "[";
    for (int i = 0; i < array.elements.size(); i++)
    {
        out << array.elements[i];
        if (i < array.elements.size() - 1)
        {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

template <typename T>
istream &operator>>(istream &in, Array<T> &array)
{
    int size;
    cout << "Enter the size of the array: ";
    in >> size;
    array.elements.clear();
    for (int i = 0; i < size; i++)
    {
        T element;
        cout << "Enter element " << i + 1 << ": ";
        in >> element;
        array.elements.push_back(element);
    }
    return in;
}

#include "fraction.h"

template class Array<int>;
template class Array<Fraction>;
template ostream &operator<<(ostream &out, const Array<int> &array);
template istream &operator>>(istream &in, Array<int> &array);
template ostream &operator<<(ostream &out, const Array<Fraction> &array);
template istream &operator>>(istream &in, Array<Fraction> &array);
