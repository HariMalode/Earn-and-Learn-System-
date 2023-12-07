#include <iostream>
#include <string>
using namespace std;

int HR = 45;
int date = 1;
class workDetails;

// Student Data Class
class student
{

public:
    string name, faculty; // Variable for name
    long int elNo;        // Variable for Eligibility No
    void getData();
    void displayData();
};

// Getting Student Data
void student ::getData()
{
    cout << "Enter Student Name : ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Eligibility No : ";
    cin >> elNo;
    cout << "Enter Faculty To Assign:";
    cin.ignore();
    getline(cin, faculty);
}

// Display Student Data
void student ::displayData()
{
    cout << "\n Name : " << name;
    cout << " |\t Eligibility No : " << elNo << endl;
}

// Work Details Class
class workDetails : public student
{

    int payment = 0;
    int totalhours = 0;
    int sr;

public:
    int hours;
    int amount;
    string work[30];
    void calAmt();
    void displayAmt();
    void displayList(int a);
};

void workDetails ::calAmt()
{
    do
    {
        cout << " Date: " << date << "/12/22 " << endl;

        cout << "Enter Total Work Hours : ";
        cin >> hours;
        if (hours <= 3 && hours >= 1)
        {
            amount = hours * HR;
            totalhours = totalhours + hours;
            payment = payment + amount;

            cout << "Enter Work Details:";
            cin.ignore();
            getline(cin, work[date]);
        }
        else
        {
            cout << "Hours Should Between 1-3,Put it Again!!" << endl;
        }
    } while (hours >= 4 || hours <= 0);
    date++;
}

void workDetails ::displayAmt()
{

    cout << "\t Total Work Hours : " << totalhours << endl;
    cout << "\t Total Amount : " << payment << endl;
}

void workDetails ::displayList(int a)
{
    sr = a;
    cout << "" << sr + 1 << "    " << name << "\t\t\ " << elNo << "\t\t" << faculty << " \t" << totalhours << " \t" << payment << " ";
    // sr++;
    cout << endl;
}

int main()
{
    long int en;
    char menu;
    workDetails s[100];
    int ch1;
    int count = 0;
    int flag = 0;
    do
    {
        cout << "\n1. Add Student" << endl;
        cout << "2. Add Work Details " << endl;
        cout << "3. Final List " << endl;
        cout << "4. Individual List" << endl
             << endl;

        cout << "Enter Your Choice : ";
        cin >> ch1;
        int i;
        string pass;
        switch (ch1)
        {
        case 1:
            cout << "Enter Admin Password : ";
            cin >> pass;
            if (pass == "ioit")
            {
                s[count].getData();
                count++;
                cout << "Student Added Successfully !!!" << endl;
            }
            else
            {
                cout << "Wrong Password !!!" << endl;
            }
            break;

        case 2:
            cout << "\n Enter Admin Password:";
            cin >> pass;
            if (pass == "ioit")
            {
                cout << "Enter Eligibility No : ";
                cin >> en;
                for (int i = 0; i < count; i++)
                {
                    if (en == s[i].elNo)
                    {
                        s[i].displayData();
                        s[i].calAmt();
                        s[i].displayAmt();
                        flag = 1;

                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "No student Found with Eligibility No " << en << endl;
                }
                flag = 0;
            }
            else
            {
                cout << "Wrong Password !!!" << endl;
            }
            break;

        case 3:
            if (count == 0)
            {
                cout << "\t No Student Found !!!";
            }
            else
            {
                cout << "\n \t \t \t  -::STUDENT DATABASE::-" << endl;
                cout << "______________________________________________________________________________" << endl;
                cout << "Sr  Student Name\tELigibility No\tFaculty  \tTotal Hours\tPayment" << endl;
                cout << "______________________________________________________________________________" << endl;

                for (int i = 0; i < count; i++)
                {
                    s[i].displayList(i);
                }
                cout << "______________________________________________________________________________" << endl;
            }
            break;
        case 4:
            cout << "Enter Eligibility No For Individual Details : ";
            cin >> en;
            for (int i = 0; i < count; i++)
            {
                if (en == s[i].elNo)
                {
                    s[i].displayData();
                    cout << "\n Date \t\t Work Details \t Work Hours \t Payment" << endl;
                    for ( int j = 1; j < date; date++)
                    {
                        cout << " " << date << "/12/22 \t" << s[i].work[date] << " \t " << s[i].hours << " \t " << s[i].amount << "  " << endl;
                        flag = 1;
                    }
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "No student Found with Eligibility No " << en << endl;
            }
            flag = 0;
        }
        cout << "\n Back to MAIN Menu (Press y/n): ";
        cin >> menu;
    } while (menu == 'y');

    return 0;
}