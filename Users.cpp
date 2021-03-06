#include "Users.h"

using namespace std;

Users::Users()
{
    this->loggedUserId = 0;
    usersXml.loadUsersFromXml(users);
}
Users::~Users()
{
    users.clear();
}
int Users::getLoggedUserId()
{
    return loggedUserId;
}
void Users::userRegistration()
{
    User user = giveNewUserData();

    users.push_back(user);
    usersXml.addUserToXml(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
void Users::userLogging()
{
    string login = "", password = "";
    int tryCount = 3;
    bool isUser = false;
    cout<<"Podaj login: ";
    cin>>login;
    cin.ignore();
    vector<User>::iterator itr =users.begin();

    while( itr != users.end())
    {
        if(itr->User::getLogin() == login)
        {
            while(tryCount>0)
            {
                cout<<"Podaj haslo. Pozostalo prob: "<< tryCount <<" : ";
                cin>>password;
                cin.ignore();
                if(itr->User::getPassword() == password)
                {
                    this->loggedUserId = itr->User::getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    isUser = true;
                    break;
                }
                tryCount--;
            }
            if(tryCount == 0)
            {
                cout<<  endl << "Podales 3 razy bledne haslo. "<< endl << endl;
                this->loggedUserId = 0;
                isUser = true;
                break;
            }
        }
        itr++;
    }
    if(!isUser)
        cout<<endl<<"Nie ma uzytkownika z takim loginem." << endl << endl;
    system("pause");
}
void Users::changePassword()
{
    if( loggedUserId >0)
    {
        string newPassword ="";
        bool changedPassword = false;
        newPassword = inputPassword();
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            if ( itr->User::getId() == loggedUserId)
            {
                itr->User::setPassword(newPassword);
                changedPassword = true;
                break;
            }
        }

        if (changedPassword)
        {   usersXml.changePasswordInXml(loggedUserId,newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
        }
        else
        {
            cout << "Haslo nie zostalo zmienione." << endl << endl;
        }
    }
    else
    {
        cout << "Niepoprawny numer id. Aby zmienic haslo musisz sie zalogowac." << endl << endl;
    }
   system("pause");
}

void Users::logout()
{
    this->loggedUserId = 0;
}
void Users::endOff()
{
    exit(0);
}
string Users::changeFirstLetterToupperOtherTolower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
User Users::giveNewUserData()
{
    User user;
    string login = "", password = "", name="", surname="";

    user.setId(getNewUserId());
    cout << endl << "Podaj imie: ";
    cin >> name;
    name = changeFirstLetterToupperOtherTolower(name);
    cin.ignore();
    user.setName(name);
    cout << endl << "Podaj nazwisko: ";
    cin >> surname;
    surname = changeFirstLetterToupperOtherTolower(surname);
    cin.ignore();
    user.setSurname(surname);
    do
    {
        cout << endl << "Podaj login: ";
        cin >> login;
        cin.ignore();
        user.setLogin(login);
    }

    while (isLogin(user.getLogin()) == true);

    password = inputPassword();
    user.setPassword(password);

    return user;

}
int Users::getNewUserId()
{
    if (users.empty() == true)
    {
        return 1;
    }
    else
    {
        return users.back().getId() + 1;
    }
}
bool Users::isLogin(string login)
{
    vector <User>::iterator itr = users.begin();

    while (itr != users.end())
    {
        if (itr->User::getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
        {
            itr++;
        }
    }

    return false;

}
string Users::inputPassword()
{
    string password ="";

    do
    {
        cout << "Podaj haslo (minimum 3 znaki): ";
        cin >> password;
        cin.ignore();
    }
    while (password.length() < 3);

    return password;
}

