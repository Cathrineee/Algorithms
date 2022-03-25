/*
 * You are given a list of songs where the ith song has a duration of time[i] seconds.
 * Return the number of pairs of songs for which their total duration in seconds is divisible by 60. 
 * Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
 */
#include <vector>
#include <algorithm>
using namespace std;

int numPairsDivisibleBy60(vector<int> &time)
{
    vector<int> sec(60, 0);
    for (int t : time)
    {
        sec[t % 60] += 1;
    }
    int count = 0;
    for (int i = 0; i < 31; ++i)
    {
        if (i == 0 || i == 30)
        {
            if (sec[i] > 0)
            {
                if (sec[i] % 2 == 0)
                {
                    count += (sec[i] / 2) * (sec[i] - 1);
                }
                else
                {
                    count += (sec[i] - 1) / 2 * sec[i];
                }
            }
        }
        else
        {
            count += sec[i] * sec[60 - i];
        }
    }
    return count;
}
