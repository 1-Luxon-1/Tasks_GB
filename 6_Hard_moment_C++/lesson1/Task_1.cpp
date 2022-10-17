#include <iostream>
#include<vector>
#include<tuple>
#include<fstream>
#include<optional>
#include<string>
#include<algorithm>
using namespace std;

/////////////////////// Person //////////////////////////////////

struct Person
{
    string name;
    string surname;
    optional<string> patronymic;
};

ostream& operator<<(ostream& out,const Person& pers)
{
    out << pers.name << "  " << pers.surname;
    if (pers.patronymic)
    {
        out << "  " << *pers.patronymic;
    }
    else
        out << "  ";
    return out;
}

bool operator<(const Person& p1, const Person& p2)
{
    return tie(p1.name, p1.surname, p1.patronymic) < tie(p2.name, p2.surname, p2.patronymic);
}

bool operator==(const Person& p1, const Person& p2)
{
    return tie(p1.name, p1.surname, p1.patronymic) == tie(p2.name, p2.surname, p2.patronymic);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////// PhoneNumber /////////////////////////////////////////////////////////
struct PhoneNumber
{
    int countryCode;
    int cityCode;
    string number;
    optional<int> extensionNumber;
};

ostream& operator<<(ostream& out, const PhoneNumber& phone)
{
    out << "+" << phone.countryCode << "(" << phone.cityCode << ")" << phone.number;
    if (phone.extensionNumber)
        cout << " " << *phone.extensionNumber;
    else
        cout << " ";
    return out;
}

bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.countryCode, p1.cityCode, p1.number,p1.extensionNumber) < tie(p2.countryCode, p2.cityCode, p2.number, p2.extensionNumber);
}

bool operator==(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.extensionNumber) == tie(p2.countryCode, p2.cityCode, p2.number, p2.extensionNumber);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////// PhoneBook //////////////////////////////////////////////////////////
class PhoneBook
{
private:
    vector<pair<Person, PhoneNumber>> phoneBook;

public:
    friend ostream& operator<<(ostream&, PhoneBook&);

    PhoneBook(ifstream& book)
    {
        if (!book)
        {
            cout << "Файл не открылся!" << endl;
        }
        else
        {
            string s;
            int count;
            int startcopy = 0;
            int endcopy;
            Person pers;
            PhoneNumber pnum;
            pair<Person, PhoneNumber>pr;

            while (!book.eof())
            {
                getline(book, s);
                count = 0;
                startcopy = 0;
                for (int i = 0; i <= s.length(); i++)
                {
                    if (s[i] == '+' && count < 3)
                    {
                        pers.patronymic = nullopt;
                        count = 3;
                    }
                    else
                    if (s[i] == ' ' && count < 3)
                    {

                        endcopy = i;                        
                        switch (count)
                        {
                        case 0: pers.name = s.substr(startcopy, endcopy - startcopy); break;
                        case 1: pers.surname = s.substr(startcopy, endcopy - startcopy); break;
                        case 2: pers.patronymic = s.substr(startcopy, endcopy - startcopy); break;
                        }
                        count++;
                        startcopy = endcopy;
                    }
                    else
                    {
                        if (count < 7 && (i == s.length() || s[i] == '(' || s[i] == ')' || s[i] == ' '))
                        {
                            endcopy = i;
                            switch (count)
                            {
                            case 3: {string stmp = s.substr(startcopy+2, endcopy - startcopy-2); pnum.countryCode = stoi(stmp); break; }
                            case 4: {string stmp = s.substr(startcopy, endcopy - startcopy); pnum.cityCode = stoi(stmp); break; }
                            case 5: pnum.number = s.substr(startcopy, endcopy - startcopy); pnum.number; break;
                            case 6: {string stmp = s.substr(startcopy, endcopy - (startcopy-1)); pnum.extensionNumber = stoi(stmp); break; }
                            }
                            if (i == s.length() && count == 5)
                            {
                                pnum.extensionNumber = nullopt;
                                count = 7;
                            }
                            count++;
                            startcopy = endcopy+1;
                        }
                    }
                }
                pr.first = pers;
                pr.second = pnum;
                phoneBook.push_back(pr);

            }
        }
    }

    void SortByName()
    {
        sort(phoneBook.begin(), phoneBook.end());
    }

    void SortByPhone()
    {
        sort(phoneBook.begin(), phoneBook.end(), [](pair<Person,PhoneNumber>&x, pair<Person,PhoneNumber>&y)->bool {return x.second < y.second; });
    }

    tuple<string, PhoneNumber> GetPhoneNumber(string searchSurname)
    {
        int num = 0;
        int i = 0;
        int pos;
        for (auto iter : phoneBook)
        {
            i++;
            if (iter.first.surname == searchSurname)
            {
                num++;
                pos = i;
            }
        }
        if (num == 1)
            return tie(" ", phoneBook[pos].second);
        else
            if (num == 0)
                return tie("not found", phoneBook[0].second);
            else
            {
                PhoneNumber pn{ 0, 0, "0", nullopt };
                return tie("found more than 1", pn);
            }       
    }


    void ChangePhoneNumber(Person p, PhoneNumber phone)
    {
        for (auto iter : phoneBook)
        {
            if (iter.first == p)
            {
                iter.second = phone;
            }
        }
    }
};

ostream& operator<<(ostream& out, PhoneBook& pb)
{
    for (auto iter : pb.phoneBook)
    {
        out << iter.first << " " << iter.second << endl;
    }
    return out;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ifstream file;
    file.open("PhoneBook.txt");
    PhoneBook book(file);
    cout << book << endl;


    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book << endl;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book << endl;




    cout << "-----GetPhoneNumber-----" << endl;
        auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;
    file.close();


return 0;
}