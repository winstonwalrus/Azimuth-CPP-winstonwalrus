#include "pch.h"
#include "Random.h"

namespace AzimuthLINQTests
{
    list<int> Random::IntList(int _count, bool _allEven, int _maxValue)
    {
        return TemplateList<int, bool, int>(_count, [](bool _allEven, int _maxValue) -> int
            {
                if (_allEven)
                {
                    return (rand() % (_maxValue + 1)) * 2;
                }
                else
                {
                    return rand() % _maxValue;
                }
            }, _allEven, _maxValue);
    }

    vector<int> Random::IntVector(int _count, bool _allEven, int _maxValue)
    {
        return TemplateVector<int, bool, int>(_count, [](bool _allEven, int _maxValue) -> int
            {
                if (_allEven)
                {
                    return (rand() % (_maxValue + 1)) * 2;
                }
                else
                {
                    return rand() % _maxValue;
                }
            }, _allEven, _maxValue);
    }
}
