#include <iostream>
#include "Users.h"
#include "Finance.h"

#include "Markup.h"



using namespace std;

char chooseOptionFromMainMenu();
char chooseOptionFromLoggedUserMenu();

int main()
{
    Users users ;
    char choice;
    while(1)
    {
        if(users.getLoggedUserId() == 0)
        {
            choice = chooseOptionFromMainMenu();
            switch (choice)
            {
            case '1':
                users.userRegistration();
                break;
            case '2':
                users.userLogging();
                break;
            case '8':
                users.endOff();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else if (users.getLoggedUserId()>0)
        {
            Finance finance(users.getLoggedUserId());
            //finance.displayAllIncomes();
           // finance.displayAllExpenses();
            choice = chooseOptionFromLoggedUserMenu();
            switch (choice)
            {
            case '1':
                finance.addIncome(users.getLoggedUserId());
                //finance.displayAllIncomes();
                break;
            case '2':
                finance.addExpense(users.getLoggedUserId());
                //finance.displayAllExpenses();
                break;
            case '3':
                //  bilans z biezacego miesiaca
                finance.displayCurrentMonthBalance();
                break;
            case '4':
                //bilans z dowolnego moiesiaca
                finance.displayPreviousMonthBalance();
                break;
            case '5':
                // blilans z dowolnego okresu
                finance.displayAnyPeriodBalance();
                break;

            case '6':
                users.changePassword();
                break;
            case '7':
                users.logout();
                break;
            }
        }
    }
    return 0;
}
char chooseOptionFromMainMenu()
{
    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "8. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
    cin.ignore();

    return choice;
}
char chooseOptionFromLoggedUserMenu()
{
    char choice;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z dowolnego okresu" << endl;

    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
    cin.ignore();
    return choice;
}
