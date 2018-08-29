#include "UsersXml.h"

UsersXml::UsersXml()
{
    nameUserXml="users.xml";
}
UsersXml::~UsersXml()
{
    ;
}
string UsersXml::intToString(int intCount)
{
    ostringstream ss;
    ss << intCount;
    string str = ss.str();

    return str;
}
void UsersXml::addUserToXml(User user)
{
    CMarkup xmlFile;
    if (xmlFile.Load(nameUserXml))
    {
        xmlFile.FindElem();
        xmlFile.IntoElem ();
        while(xmlFile.FindElem ("USER"))
        {
            xmlFile.IntoElem();
            xmlFile.OutOfElem();
        }
        xmlFile.OutOfElem();
    }
    else
    {
        xmlFile.AddElem("USERS");
    }
    xmlFile.IntoElem();
    xmlFile.AddElem ("USER");
    xmlFile.IntoElem ();
    xmlFile.AddElem ("USERID",intToString(user.getId()));
    xmlFile.AddElem ("LOGIN", user.getLogin());
    xmlFile.AddElem ("PASSWORD", user.getPassword());
    xmlFile.AddElem ("NAME", user.getName());
    xmlFile.AddElem ("SURNAME", user.getSurname());
    xmlFile.OutOfElem();

    xmlFile.Save(nameUserXml);
}
void UsersXml::changePasswordInXml(int loggedUserId,string newPassword)
{
    CMarkup xmlFile;
    int userId;
    if (xmlFile.Load(nameUserXml))
    {
        xmlFile.FindElem();
        xmlFile.IntoElem();
        while ( xmlFile.FindElem("USER") )
        {
            xmlFile.IntoElem();
            xmlFile.FindElem( "USERID" );
            userId = atoi( MCD_2PCSZ(xmlFile.GetData()) );
            if(userId == loggedUserId)
            {
                xmlFile.FindElem("PASSWORD");
                xmlFile.SetData(newPassword);
                xmlFile.Save(nameUserXml);
                break;
            }
            xmlFile.OutOfElem();

        }
    }
}
void UsersXml::loadUsersFromXml(vector<User> &users)
{
    CMarkup xmlFile;
    User user;
    int userId;
    string login, password, name, surname;

    if (xmlFile.Load(nameUserXml))
    {
        xmlFile.FindElem();
        xmlFile.IntoElem();

        while ( xmlFile.FindElem("USER") )
        {
            xmlFile.IntoElem();
            xmlFile.FindElem( "USERID" );
            userId = atoi( MCD_2PCSZ(xmlFile.GetData()) );
            xmlFile.FindElem("LOGIN");
            login = xmlFile.GetData();
            xmlFile.FindElem("PASSWORD");
            password = xmlFile.GetData();
            xmlFile.FindElem("NAME");
            name = xmlFile.GetData();
            xmlFile.FindElem("SURNAME");
            surname = xmlFile.GetData();
            xmlFile.OutOfElem();
            user.setId(userId);
            user.setLogin(login);
            user.setName(name);
            user.setSurname(surname);
            user.setPassword(password);
            users.push_back(user);
        }
    }
}
