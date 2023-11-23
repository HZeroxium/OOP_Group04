#pragma once

#include "cMessage.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>

using std::map;
using std::string;
using std::vector;

class cListMessage
{
private:
    vector<cMessage> m_vMessage;
    unsigned int m_uiAmount;

public:
    cListMessage();
    ~cListMessage();

public:
    bool fInput(const string &sFileName = "input.txt");
    bool fOutput(const string &sFileName = "output.txt");
};