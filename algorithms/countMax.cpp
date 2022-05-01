#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // the number of test cases
    int t;
    cin >> t;
    int i, j, k;
    for (i = 0; i < t; i++)
    {
        // n rows, m columns
        int n, m;
        cin >> n >> m;
        int maxRow = 0;
        int maxColumn = 0;

        int countRow = 0;
        int countColumn = 0;

        char allchars[n][m];
        memset(allchars, ' ', sizeof(allchars));

        // read into input
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < m; k++)
            {
                cin >> allchars[j][k];
            }
        }

        // max in rows
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < m; k++)
            {
                if (allchars[j][k] == '#')
                {
                    countRow++;
                }
                else if (allchars[j][k] == '.')
                {
                    countRow = 0;
                }
                if (countRow > maxRow)
                {
                    maxRow = countRow;
                }
            }
        }

        // max from columns - go over colmns first and change rows

        for (k = 0; k < m; k++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> allchars[j][k];

                if (allchars[j][k] == '#')
                {
                    countColumn++;
                }
                else if (allchars[j][k] == '.')
                {
                    countColumn = 0;
                }
                if (countColumn > maxColumn)
                {
                    maxColumn = countColumn;
                }
            }
        }

        cout << ((maxRow > maxColumn) ? maxRow : maxColumn) << endl;
    }
    return 0;
}