/*
 * Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.
 * Implement the TimeMap class:
 *     TimeMap() Initializes the object of the data structure.
 *     void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
 *     String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
 *      If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 */

#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

typedef pair<string, vector<pair<int, string> > > time_key_pair;

class TimeMap
{
private:
    vector<time_key_pair> key;

public:
    TimeMap() {}

    int search_key(string key)
    {
        int begin = 0;
        int end = this->key.size() - 1;
        while (begin <= end)
        {
            int mid = begin + (end - begin) / 2;
            // cout << mid << " " << this->key[mid].first << " " << key << endl;
            if (this->key[mid].first == key)
            {
                // cout << "find at " << mid << endl;
                return mid;
            }
            else if (this->key[mid].first < key)
            {
                begin = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return begin;
    }

    void set(string key, string value, int timestamp)
    {
        if (this->key.empty())
        {
            vector<pair<int, string> > new_pair;
            new_pair.push_back(make_pair(timestamp, value));
            this->key.push_back(make_pair(key, new_pair));
        }
        else
        {
            int pos = this->search_key(key);
            if (pos < this->key.size() && this->key[pos].first == key)
            {
                auto new_pair = this->key[pos].second;
                new_pair.push_back(make_pair(timestamp, value));
                this->key[pos] = make_pair(key, new_pair);
            }
            else
            {
                vector<pair<int, string> > new_pair;
                new_pair.push_back(make_pair(timestamp, value));
                if (pos == this->key.size())
                {
                    this->key.push_back(make_pair(key, new_pair));
                }
                else
                {
                    this->key.insert(this->key.begin() + pos, make_pair(key, new_pair));
                }
            }
            // cout << "insert " << key << " at " << pos << endl;
            // cout << this->key.front().first << " " << this->key.back().first << endl;
        }
    }

    string get(string key, int timestamp)
    {
        if (this->key.empty())
            return "";
        // cout << "find " << key << endl;
        int pos = this->search_key(key);
        // cout << "find " << key << " at " << pos << endl;
        if (pos < this->key.size() && this->key[pos].first == key)
        {
            auto record = this->key[pos].second;
            int end = record.size() - 1;
            int begin = 0;
            while (begin <= end)
            {
                int mid = begin + (end - begin) / 2;
                if (record[mid].first == timestamp)
                    return record[mid].second;
                else if (record[mid].first < timestamp)
                {
                    begin = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            if (end < 0)
                return "";
            else
                return record[end].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
