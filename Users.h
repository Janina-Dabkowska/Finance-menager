#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "User.h"
#include "UsersXml.h"


using namespace std;
class Users
{
private:
    vector<User> users;
    int loggedUserId;
    UsersXml usersXml;
public:
    Users();
    virtual ~Users();
    int getLoggedUserId();
    void userLogging();
    void userRegistration();
    void changePassword();
    void logout();
    void endOff();

private:
    User giveNewUserData();
    string changeFirstLetterToupperOtherTolower(string text);
    int getNewUserId();
    bool isLogin(string login);
    string inputPassword();
};
#endif
