#pragma once

#include <string>
#include <vector>
#include <iostream>
class cLyrics
{
private:
    std::vector<std::string> m_vLyrics; ///< Lyrics of the song

public:
    cLyrics(const std::vector<std::string> &vLyrics = std::vector<std::string>());
    ~cLyrics() = default;

    void setLyrics(const std::vector<std::string> &vLyrics);

    const std::vector<std::string> &getLyrics() const;

    std::string toString() const;

    friend std::ostream &operator<<(std::ostream &out, const cLyrics &lyrics);
    friend std::istream &operator>>(std::istream &in, cLyrics &lyrics);
};

/*
cLyrics
- std::vector<std::string> m_vLyrics
+ cLyrics(const std::vector<std::string>& vLyrics = std::vector<std::string>())
+ ~cLyrics() = default
+ void setLyrics(const std::vector<std::string>& vLyrics)
+ const std::vector<std::string>& getLyrics() const
+ std::string toString() const
+ friend std::ostream& operator<<(std::ostream& out, const cLyrics& lyrics)
+ friend std::istream& operator>>(std::istream& in, cLyrics& lyrics)
*/
