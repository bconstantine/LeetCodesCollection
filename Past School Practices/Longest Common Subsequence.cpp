
#include <iostream>
#include <string>
#include <vector>
using namespace std;


pair <int, string> returnLongestSubsequence(string a, string b, int bindex, int aindex, string result)
{
    int returnValue = 0;
    if (bindex == -1 || aindex == -1)
    {
        return pair<int, string>(0, result);
    }

    if (a[aindex] == b[bindex])
    {
        //store the psis
        result.push_back(a[aindex]);
        return returnLongestSubsequence(a, b, bindex - 1, aindex - 1, result);
    }
    else
    {
        //aindex and b index is not the same
        pair<int, string> firstRes = returnLongestSubsequence(a, b, bindex-1, aindex, result);
        pair<int, string> secondRes = returnLongestSubsequence(a, b, bindex, aindex-1, result);
        string stringRes;
        int intRes;
        if (firstRes > secondRes)
        {
            stringRes = firstRes.second;
            intRes = firstRes.first;
        }
        else
        {
            stringRes = secondRes.second;
            intRes = secondRes.first;
        }

        return pair<int, string>(intRes, stringRes);

    }
}
int main()
{
    string a, b;
    cout << "Please enter your first string: " << endl;
    cin >> a;
    cout << "Please enter your second string: " << endl;
    cin >> b;
    pair <int, string> result = returnLongestSubsequence(a, b, a.length() - 1, b.length() - 1, "");
    cout << "Longest length: " << result.first << endl;
    cout << "String representattion : ";
    for (auto iterator = result.second.rbegin(); iterator != result.second.rend(); iterator++)
    {
        cout << *iterator;
    }
    cout << "Finished!\n";
}

