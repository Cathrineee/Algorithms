/* There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
 * You have to form a team of 3 soldiers amongst them under the following rules:
 *      Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
 *      A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
 * Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
 */

#include <vector>
using namespace std;

int numTeams(vector<int> &rating)
{
    int n = rating.size();
    vector<int> pair_increase(n, 0);
    vector<int> pair_decrease(n, 0);
    int increase = 0;
    int decrease = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        if (i == n - 2)
        {
            if (rating[i + 1] > rating[i])
                pair_increase[i] += 1;
            else
                pair_decrease[i] += 1;
        }
        else
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (rating[j] > rating[i])
                {
                    increase += pair_increase[j];
                    pair_increase[i] += 1;
                }
                else
                {
                    decrease += pair_decrease[j];
                    pair_decrease[i] += 1;
                }
            }
        }
    }
    return (increase + decrease);
}
