#include "User.h"

using namespace std;

User::User()
{
    id = 0;
    name = "";
    surname = "";
    login = "";
    password = "";
}
User::~User() {;}
int User::getId()
{
    return id;
}
string User::getLogin()
{
    return login;
}
string User::getName()
{
    return name;
}
string User::getSurname()
{
    return surname;
}
string User::getPassword()
{
    return password;
}
void User::setId(int id)
{
    this->id = id;
}
void User::setLogin(string login)
{
    this->login = login;
}
void User::setName(string name)
{
    this->name = name;
}void User::setSurname(string surname)
{
    this->surname = surname;
}
void User::setPassword(string password)
{
    this->password = password;
}