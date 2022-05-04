class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {

        int lastBit;
        int afterRemoval;
        int count = 0;
        uint32_t bits = 0;

        while (n != 0)
        {
            lastBit = n & 1;
            afterRemoval = n << 1;
            bits |= lastBit << (31 - count);
            count++;
            n /= 2;
        }

        return bits;
    }
};