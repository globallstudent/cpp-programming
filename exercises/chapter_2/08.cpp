#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

    string pop1 = "Location", pop2 = "Portcity", pop3 = "Hightown",
         pop4 = "Population", pop5 = "324354";

    cout << setfill('.') << setw(8) << pop1 << setw(12) << pop4 << endl
         << setw(8) << pop2 << setw(12) << pop5 << endl
         << setw(8) << pop3 << endl;
    return 0;

}
