#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int x11, x12, y11, y12;
    int x21, x22, y21, y22;
    int distx, disty;
    cin >> x11 >> y11 >> x12 >> y12;
    cin >> x21 >> y21 >> x22 >> y22;

    if (x11 > x12)
        swap(x11, x12);
    if (y11 > y12)
        swap(y11, y12);
    if (x21 > x22)
        swap(x21, x22);
    if (y21 > y22)
        swap(y21, y22);

    if (x22 < x11) distx = x11 - x22;
    else
    if (x12 < x21) distx = x21 - x12;
    else
        distx = 0;

    if (y22 < y11) disty = y11 - y22;
    else
    if (y12 < y21) disty = y21 - y12;
    else
        disty = 0;

    cout << distx + disty << endl;

    //cout << x11 << " " << y11 << " " << x12 << " " << y12 << endl;
    //cout << x21 << " " << y21 << " " << x22 << " " << y22 << endl;
    return 0;
}