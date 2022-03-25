/*
 * In an infinite binary tree where every node has two children, the nodes are labelled in row order.
 * In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.
 * Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
 */
#include <vector>
using namespace std;

vector<int> path_helperEven(int root, int label, int start, int end)
{
    // cout << root << " " << start << " " << end << endl;
    vector<int> path;
    if (root == label)
    {
        path.push_back(root);
        return path;
    }
    else if (root > label)
    {
        return path;
    }
    else
    {
        int right = (2 * end + 1) - 2 * (root - start);
        int left = right - 1;
        path = path_helperOdd(left, label, end + 1, 2 * end + 1);
        if (!path.empty())
        {
            path.push_back(root);
            return path;
        }
        path = path_helperOdd(right, label, end + 1, 2 * end + 1);
        if (!path.empty())
        {
            path.push_back(root);
            return path;
        }
        return path;
    }
}
vector<int> path_helperOdd(int root, int label, int start, int end)
{
    // cout << root << " " << start << " " << end << endl;
    vector<int> path;
    if (root == label)
    {
        path.push_back(root);
        return path;
    }
    else if (root > label)
    {
        return path;
    }
    else
    {
        int left = (2 * end + 1) - 2 * (root - start);
        int right = left - 1;
        path = path_helperEven(left, label, end + 1, 2 * end + 1);
        if (!path.empty())
        {
            path.push_back(root);
            return path;
        }
        path = path_helperEven(right, label, end + 1, 2 * end + 1);
        if (!path.empty())
        {
            path.push_back(root);
            return path;
        }
        return path;
    }
}
vector<int> pathInZigZagTree(int label)
{
    vector<int> path = path_helperOdd(1, label, 1, 1);
    vector<int> ret;
    int size = path.size();
    for (int i = 0; i < size; ++i)
    {
        ret.push_back(path.back());
        path.pop_back();
    }
    return ret;
}
