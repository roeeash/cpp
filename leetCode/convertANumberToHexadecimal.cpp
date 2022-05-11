class Solution
{
public:
    string toHex(int num)
    {
        string res = "";

        int remain;
        char next;

        long number = (num >= 0) ? num : pow(2, 32) + num;

        if (!number)
            return "0";

        while (number != 0)
        {
            remain = number % 16;

            if (remain >= 10)
            {
                next = 'a' + (remain - 10);
                res = next + res;
            }

            else
                res = to_string(remain) + res;

            number /= 16;
        }

        return res;
    }
};