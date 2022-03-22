#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    wchar_t wc = L'x';
    char *pmb1 = (char *)malloc(sizeof(char));
    char *pmb2 = NULL;
    int ret_val;

    cout << "When pmb is not null" << endl;
    ret_val = wctomb(pmb1, wc);

    cout << "Return Value = " << ret_val << endl;
    wcout << "Multibyte Character: " << pmb1 << endl
          << endl;

    cout << "When pmb is null" << endl;
    ret_val = wctomb(pmb2, wc);

    cout << "Return Value = " << ret_val << endl;
    wcout << "Multibyte Character: " << pmb2;

    return (0);
}