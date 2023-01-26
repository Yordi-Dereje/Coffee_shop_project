#include <iostream>
#include "header.h"
#include "menu.cpp"
#include "order.cpp"
#include "calculate.cpp"
#include "wrap-up.cpp"

using namespace std;


int main()
{
    int x;
    system ("color 70");
    populateMenu();

    do
    {
        frontMenu();
        cin >> x;

        system("cls");

        switch(x)
        {
        case 1:
            newOrder();
            break;
        case 2:
            collectOrder();
            break;
        case 3:
            trackingOrder();
            break;
        case 9:
            alterMenu();
            break;
        case 0:
            cout << "Goodbye..." << endl;
            break;
        default:
            cout << "Invalid choice..." << endl;
            break;
        }

        system("pause");
        system("cls");

    }while (x != 0);

    return 0;
}
