#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    wchar_t wc = L'p';
    char *arg1 = (char *)malloc(sizeof(char));
    char *arg2 = NULL;
    int ret;

    cout << "When wctomb gets non-null argument" << endl;
    ret = wctomb(arg1, wc);

    cout << "Return Value = " << ret << endl;
    wcout << "Multibyte Character: " << arg1 << endl
          << endl;

    cout << "When wctomb gets null argument" << endl;
    ret = wctomb(arg2, wc);

    cout << "Return Value = " << ret << endl;
    wcout << "Multibyte Character: " << arg2;

    return (0);
}
