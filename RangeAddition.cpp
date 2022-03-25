/*
 * You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].
 * You have an array arr of length length with all zeros, and you have some operation to apply on arr. 
 * In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.
 * 
 * Return arr after applying all the updates.
 */
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int> > &updates)
{
    vector<int> arr(length, 0);
    for (auto upd : updates)
    {
        arr[upd[0]] += upd[2];
        if (upd[1] < length - 1)
            arr[upd[1] + 1] -= upd[2];
    }
    for (int i = 1; i < length; ++i)
    {
        arr[i] += arr[i - 1];
    }
    return arr;
}
