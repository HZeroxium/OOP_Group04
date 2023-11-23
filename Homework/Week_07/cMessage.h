#ifndef C_MESSAGE_H
#define C_MESSAGE_H

#include <string>
#include <fstream>
#include "cDate.h"
#include "cTime.h"

class cMessage
{
private: // Properties
    std::string mNumber;
    std::string mVote;
    cDate mDate;
    cTime mTime;

public: /// Constructors & Destructor
    cMessage(const std::string &sNumber = "", const std::string &sVote = "", const cDate &date = cDate(), const cTime &time = cTime());
    cMessage(const cMessage &other);
    ~cMessage();

public: // Getters
    std::string getNumber() const;
    std::string getVote() const;
    cDate getDate() const;
    cTime getTime() const;

public: // Setters
    void setNumber(const std::string &sNumber);
    void setVote(const std::string &sVote);
    void setDate(const cDate &date);
    void setTime(const cTime &time);

public: // Conversions
    std::string toString() const;

public: // Input & Output
    bool fInput(const std::string &sFileName = "input.txt");
    bool fOutput(const std::string &sFileName = "output.txt");

    friend std::ostream &operator<<(std::ostream &out, const cMessage &message);
    friend std::istream &operator>>(std::istream &in, cMessage &message);
};

#endif // C_MESSAGE_H