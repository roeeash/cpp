class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int count = 0;
        int lastBitStart, lastBitGoal;

        while (start > 0 && goal > 0)
        {

            lastBitStart = start & 1;
            lastBitGoal = goal & 1;

            if (lastBitStart != lastBitGoal)
                count++;

            start >>= 1;
            goal >>= 1;
        }

        while (start > 0)
        {
            lastBitStart = start & 1;
            if (lastBitStart)
                count++;
            start >>= 1;
        }

        while (goal > 0)
        {
            lastBitGoal = goal & 1;
            if (lastBitGoal)
                count++;
            goal >>= 1;
        }

        return count;
    }
};
