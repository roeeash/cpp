#include <iostream>
#include <map>

using namespace std;

int main()
{

    map<int, string> mp;
    int n;
    cin >> n;
    // perform n queries
    int q, key;
    string value;
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        switch (q)
        {
        // if it's 1 - insert
        case 1:
            cin >> key >> value;
            mp.insert({key, value});
            break;
        // if it's 2 - erase
        case 2:
            cin >> key;
            mp.erase(key);
            break;
        // if it's 3 - find
        case 3:
            cin >> key;
            auto it = mp.find(key);
            if (it != mp.end())
            {
                cout << mp[key] << endl;
            }
            break;
        }
    }

    return 0;
}