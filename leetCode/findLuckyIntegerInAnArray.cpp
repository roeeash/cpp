class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        map<int, int> freq;
        int curr;

        for (int i = 0; i < arr.size(); i++)
        {

            curr = arr[i];

            if (freq.find(curr) != freq.end())
                freq[curr]++;
            else
                freq[curr] = 1;
        }

        for (auto it = freq.rbegin(); it != freq.rend(); it++)
        {
            if (it->first == it->second)
                return it->first;
        }

        return -1;
    }
};