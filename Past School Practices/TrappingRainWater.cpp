#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void vectorElimination(vector<int> &rainPlatform)
{
    if (rainPlatform.size() < 3)
    {
        return;
    }

    bool popHappen = false;
    if (rainPlatform[0] <= rainPlatform[1])
    {
        popHappen = true;
        rainPlatform.erase(rainPlatform.begin());
    }

    if (rainPlatform[rainPlatform.size() - 1] <= rainPlatform[rainPlatform.size() - 2])
    {
        popHappen = true;
        rainPlatform.pop_back();
    }

    if (popHappen)
    {
        return vectorElimination(rainPlatform);
    }
}

int addingRain(vector<int>& rainPlatform, int lowestNumber)
{
    int adding = 0;
    for (auto iterator = rainPlatform.begin(); iterator != rainPlatform.end(); iterator++)
    {
        if (*iterator == lowestNumber)
        {
            (*iterator)++;
            adding++;
        }
    }
    return adding;
}

int main()
{
    vector<int> container;
    int val;
    int lowestNumber = INT_MAX;
    while (cin >> val)
    {
        lowestNumber = min(val, lowestNumber);
        container.push_back(val);
    }

    int result = 0;
    vectorElimination(container);
    while (container.size() >= 3)
    {
        result += addingRain(container, lowestNumber);
        lowestNumber++;
        vectorElimination(container);
    }
    cout << "Result: " << result << endl;
    return 0;
}