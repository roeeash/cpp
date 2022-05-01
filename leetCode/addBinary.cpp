class Solution
{
public:
    string addBinary(string a, string b)
    {
        int aSize = a.size();
        int bSize = b.size();
        string newString = "";
        int carry = 0;

        while (aSize < bSize)
        {
            a = "0" + a;
            aSize++;
        }
        while (aSize > bSize)
        {
            b = "0" + b;
            bSize++;
        }

        for (int i = aSize - 1; i >= 0; i--)
        {

            if (a[i] == b[i])
            {
                if (!carry)
                    newString = "0" + newString;
                else
                    newString = "1" + newString;
                carry = (int)(a[i] - '0');
            }

            else
            {
                if (carry)
                {
                    newString = "0" + newString;
                    carry = 1;
                }
                else
                    newString = "1" + newString;
            }
        }

        if (carry)
            newString = "1" + newString;

        return newString;
    }
};