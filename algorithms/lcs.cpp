#include <iostream>
#include <bits/stdc++.h>
#include <string>
// elephants are similar if the lcs of their names is
//  over a quarter the length of the sum of its names length
//  example: Yossi and Yosu are similar since |Yos| = 3 >= (1/4)*(5+4) = 2.25
//  this program determines if two Elephants are similar

using namespace std;
class Elephant
{

public:
    Elephant()
    {
    }
    ~Elephant()
    {
    }
    Elephant(string _name, int _weight)
    {
        this->name = _name;
        this->weight = _weight;
    }
    string getName()
    {
        return this->name;
    }

    int lcs(Elephant &other)
    {
        string str1 = this->name;
        string str2 = other.Elephant::name;
        int n = str1.length();
        int m = str2.length();
        // The dynamic programming table
        int tab[n + 1][m + 1];
        memset(tab, 0, sizeof(tab));
        // init first row and column to be 0
        for (int j = 0; j < m + 1; j++)
        {
            tab[0][j] = 0;
        }
        for (int i = 0; i < n + 1; i++)
        {
            tab[i][0] = 0;
        }
        // main loop
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    tab[i][j] = tab[i - 1][j - 1] + 1;
                else
                    tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            }
        }
        return tab[n][m];
    }
    // determines if two elephants are similar
    bool isSimilar(Elephant &other)
    {
        int lcs = this->lcs(other);
        return bool(lcs >= (1 / 4) * (this->name.length() + other.Elephant::name.length()));
    }

private:
    string name;
    int weight;
};

int main()
{
    Elephant e1("Yossi", 100);
    Elephant e2("Yosu", 200);
    cout << std::boolalpha << (e1.isSimilar(e2)) << endl;
    return 0;
}