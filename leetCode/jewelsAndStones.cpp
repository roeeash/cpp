class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int count = 0;

        for (int i = 0; i < stones.size(); i++)
        {
            auto it = find(jewels.begin(), jewels.end(), stones[i]);
            if (it != jewels.end())
                count++;
        }

        return count;
    }
};