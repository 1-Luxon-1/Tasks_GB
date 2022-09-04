#include <iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    ///////////////////////////////////////////////////
    /////////////////// Task 1 ////////////////////////
    ///////////////////////////////////////////////////
    stringstream MS;
    int num;
    bool flag;
    string str;
    do
    {
        cin >> str;
        flag = true;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9')
            {
                flag = false;
                cerr << "Error! Repeat enter to number" << endl;
                break;
            }
        }
    } while (flag != true);
    MS << str;
    MS >> num;
    cout << "num = " << num;

    ///////////////////////////////////////////////////
    /////////////////// Task 2 ////////////////////////
    ///////////////////////////////////////////////////
    
    ostream& endll(ostream& out)
    {

        return (out << "\n\n" << flush);
    }

    return 0;
}