#include "Azimuth/Utils.h"

#include <sstream>

using std::stringstream;

bool Utils::Any(string _string, bool(*_predicate)(char))
{
    bool flag = false;

    for (size_t i = 0; i < _string.length(); i++)
    {
        // If flag is true OR the predicate returns true
        // set flag to true
        flag |= _predicate(_string[i]);
    }

    return flag;
}

bool Utils::All(string _string, bool(*_predicate)(char))
{
    bool flag = true;

    for (size_t i = 0; i < _string.length(); i++)
    {
        // If flag is true AND the predicate returns true
        // set flag to true
        flag &= _predicate(_string[i]);
    }

    return flag;
}

vector<string> Utils::Split(string _string, char _delim, int& _count)
{
    _count = 1;

    for (size_t i = 0; i < _string.length(); i++)
    {
        if (_string[i] == _delim)
            _count++;
    }

    vector<string> split;

    int index = 0;

    for (size_t i = 0; i < _count; i++)
    {
        string val = "";

        for (;; index++)
        {
            if (index >= _string.length())
                break;

            if (_string[index] == _delim)
                break;

            val += _string[index];
        }

        split.push_back(val);
        index++;

        if (index >= _string.length())
            break;
    }

    return split;
}

bool Utils::TryParse(string _string, bool& _val)
{
    if (_string == "true" || _string == "false")
    {
        _val = _string == "true";
        return true;
    }

    return false;

    //stringstream stream = stringstream(_string);
    //bool val;

    //// Attempt to parse the string by pushing the stream
    //// into the variable
    //// This returns false if it fails (isn't a valid parse)
    //// This returns true if it succeeds (it successfully set the bool
    //// variable)
    //if (!(stream >> val))
    //    return false;

    //_val = val;
    //return true;
}

bool Utils::TryParse(string _string, int& _val)
{
    stringstream stream = stringstream(_string);
    int val;

    // Attempt to parse the string by pushing the stream
    // into the variable
    // This returns false if it fails (isn't a valid parse)
    // This returns true if it succeeds (it successfully set the bool
    // variable)
    if (!(stream >> val))
        return false;

    _val = val;
    return true;
}
