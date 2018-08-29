#ifndef USERSXML_H
#define USERSXML_H

#include <iostream>
#include <sstream>
#include "User.h"
#include "Markup.h"
#include <vector>

using namespace std;

class UsersXml
{
private:
    string nameUserXml;
public:
    UsersXml();
    virtual ~UsersXml();
    void loadUsersFromXml(vector<User> &users);
    void addUserToXml(User user);
    void changePasswordInXml(int loggedUserId,string newPassword);
private:
    string intToString(int intCount);
};

#endif // USERSXML_H
