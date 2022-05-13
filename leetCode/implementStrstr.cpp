class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int offset = 0;
        string curr;
        int n = haystack.size();
        int m = needle.size();

        while (offset <= n - m)
        {

            curr = haystack.substr(offset, needle.size());
            if (curr == needle)
                return offset;
            offset++;
        }

        return -1;
    }
};