class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int indexInS = 0;

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == s[indexInS])
                indexInS++;
        }
        return (indexInS == s.size());
    }
};