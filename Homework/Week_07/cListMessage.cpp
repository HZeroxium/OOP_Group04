#include "cListMessage.h"

cListMessage::cListMessage() : m_uiAmount(0)
{
}

cListMessage::~cListMessage() = default;

bool cListMessage::fInput(const string &sFileName)
{
    std::ifstream inFile(sFileName);
    if (!inFile.is_open())
    {
        std::cout << "Cannot open file " << sFileName << std::endl;
        return false;
    }

    inFile >> m_uiAmount;
    std::string dummy = "";
    std::getline(inFile, dummy);

    for (unsigned int i = 0; i < m_uiAmount; ++i)
    {
        cMessage message;
        inFile >> message;
        m_vMessage.push_back(message);
    }

    inFile.close();
    return true;
}

// Write highly voted messages to output file
bool cListMessage::fOutput(const string &sFileName)
{
    std::ofstream outFile(sFileName);
    if (!outFile.is_open())
    {
        std::cout << "Cannot open file " << sFileName << std::endl;
        return false;
    }

    map<string, unsigned int> vote;
    for (const auto &message : m_vMessage)
    {
        vote[message.getVote()]++;
    }

    int max = 0;
    std::string maxCode = "";
    for (const auto &[code, amount] : vote)
    {
        if (amount > max)
        {
            max = amount;
            maxCode = code;
        }
    }

    outFile << maxCode;

    outFile.close();
    return true;
}