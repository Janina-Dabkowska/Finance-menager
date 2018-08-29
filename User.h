#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;
class User
{

private:
    int id;
    string login;
    string name;
    string surname;
    string password;

public:
    User();
    virtual ~User();
    int getId();
    string getLogin();
    string getPassword();
    string getSurname();
    string getName();

    void setId(int id);
    void setLogin(string login);
    void setName(string name);
    void setSurname(string surname);
    void setPassword(string password);
};

#endif
