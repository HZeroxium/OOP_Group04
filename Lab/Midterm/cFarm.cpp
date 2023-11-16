#include "cFarm.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// CONSTRUCTORS - DESTRUCTORS //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cFarm::cFarm(unsigned int uLength, unsigned int uWidth)
{
    m_uLength = uLength;
    m_uWidth = uWidth;

    m_pFarm = new int *[m_uLength];
    for (unsigned int i = 0; i < m_uLength; i++)
    {
        m_pFarm[i] = new int[m_uWidth];
        for (unsigned int j = 0; j < m_uWidth; j++)
        {
            m_pFarm[i][j] = 0;
        }
    }
}

cFarm::cFarm(const cFarm &farm)
{
    m_uLength = farm.m_uLength;
    m_uWidth = farm.m_uWidth;

    m_pFarm = new int *[m_uLength];
    for (unsigned int i = 0; i < m_uLength; i++)
    {
        m_pFarm[i] = new int[m_uWidth];
        for (unsigned int j = 0; j < m_uWidth; j++)
        {
            m_pFarm[i][j] = farm.m_pFarm[i][j];
        }
    }
}

cFarm::~cFarm()
{
    for (unsigned int i = 0; i < m_uLength; i++)
    {
        delete[] m_pFarm[i];
    }
    delete[] m_pFarm;
    m_pFarm = nullptr;
    m_uLength = m_uWidth = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// GETTERS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int **cFarm::getFarm() const
{
    return m_pFarm;
}

unsigned int cFarm::getLength() const
{
    return m_uLength;
}

unsigned int cFarm::getWidth() const
{
    return m_uWidth;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// SETTERS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cFarm::setFarm(int **pFarm)
{
    m_pFarm = pFarm;
}

void cFarm::setLength(unsigned int uLength)
{
    m_uLength = uLength;
}

void cFarm::setWidth(unsigned int uWidth)
{
    m_uWidth = uWidth;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// METHODS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool cFarm::isAvailable(unsigned int uX, unsigned int uY) const
{
    return m_pFarm[uX][uY] == 0;
}

unsigned int cFarm::getCropType(unsigned int uX, unsigned int uY) const
{
    return m_pFarm[uX][uY];
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// OPERATORS ///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cFarm &cFarm::operator=(const cFarm &farm)
{
    if (this == &farm)
    {
        return *this;
    }
    m_uLength = farm.m_uLength;
    m_uWidth = farm.m_uWidth;

    m_pFarm = new int *[m_uLength];
    for (unsigned int i = 0; i < m_uLength; i++)
    {
        m_pFarm[i] = new int[m_uWidth];
        for (unsigned int j = 0; j < m_uWidth; j++)
        {
            m_pFarm[i][j] = farm.m_pFarm[i][j];
        }
    }
    return *this;
}

ostream &operator<<(ostream &out, const cFarm &farm)
{
    out << farm.m_uLength << " " << farm.m_uWidth << endl;
    for (unsigned int i = 0; i < farm.m_uLength; i++)
    {
        for (unsigned int j = 0; j < farm.m_uWidth; j++)
        {
            out << farm.m_pFarm[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, cFarm &farm)
{
    cout << "Enter farm information:\n";
    cout << "Enter length of farm: ";
    in >> farm.m_uLength;
    cout << "Enter width of farm: ";
    in >> farm.m_uWidth;
    if (farm.m_uLength < 0 || farm.m_uWidth < 0)
    {
        cout << "Invalid length or width!" << endl;
        in >> farm;
    }
    farm.m_pFarm = new int *[farm.m_uLength];
    for (unsigned int i = 0; i < farm.m_uLength; i++)
    {
        farm.m_pFarm[i] = new int[farm.m_uWidth];
        for (unsigned int j = 0; j < farm.m_uWidth; j++)
        {
            in >> farm.m_pFarm[i][j];
        }
    }
    return in;
}