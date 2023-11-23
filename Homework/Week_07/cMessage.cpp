#include "cMessage.h"

cMessage::cMessage(const std::string &sNumber, const std::string &sVote, const cDate &date, const cTime &time)
    : mNumber(sNumber), mVote(sVote), mDate(date), mTime(time)
{
}

cMessage::cMessage(const cMessage &other)
    : mNumber(other.mNumber), mVote(other.mVote), mDate(other.mDate), mTime(other.mTime)
{
}

cMessage::~cMessage() = default;

void cMessage::setNumber(const std::string &sNumber)
{
    mNumber = sNumber;
}

void cMessage::setVote(const std::string &sVote)
{
    mVote = sVote;
}

void cMessage::setDate(const cDate &date)
{
    mDate = date;
}

void cMessage::setTime(const cTime &time)
{
    mTime = time;
}

std::string cMessage::getNumber() const
{
    return mNumber;
}

std::string cMessage::getVote() const
{
    return mVote;
}

cDate cMessage::getDate() const
{
    return mDate;
}

cTime cMessage::getTime() const
{
    return mTime;
}

std::string cMessage::toString() const
{
    std::stringstream ss;
    ss << mNumber << " " << mVote << " " << mDate.toString() << " " << mTime.toString();
    return ss.str();
}

bool cMessage::fInput(const std::string &sFileName)
{
    std::ifstream inFile(sFileName);
    if (!inFile.is_open())
    {
        std::cerr << "File not found " << sFileName << std::endl;
        return false;
    }

    std::string token;
    std::getline(inFile, token);
    setNumber(token);
    std::getline(inFile, token);
    setVote(token);
    inFile >> mDate;
    inFile >> mTime;

    inFile.close();
    return true;
}

bool cMessage::fOutput(const std::string &sFileName)
{
    std::ofstream outFile(sFileName);
    if (!outFile.is_open())
    {
        std::cerr << "File not found " << sFileName << std::endl;
        return false;
    }

    outFile << toString() << std::endl;

    outFile.close();
    return true;
}

std::ostream &operator<<(std::ostream &out, const cMessage &message)
{
    out << message.toString() << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, cMessage &message)
{
    std::string token;
    std::getline(in, token);
    message.setNumber(token);
    std::getline(in, token);
    message.setVote(token);
    in >> message.mDate;
    in >> message.mTime;

    return in;
}