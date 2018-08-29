#include "IncomesXml.h"

IncomesXml::IncomesXml()
{
    nameIncomeXml = "incomes.xml";
}
IncomesXml::~IncomesXml()
{
    ;
}
string IncomesXml::intToString(int intCount)
{
    ostringstream ss;
    ss << intCount;
    string str = ss.str();

    return str;
}
string IncomesXml::doubleToString(double doubleCount)
{
    ostringstream ss;
    ss << doubleCount;
    string str = ss.str();

    return str;
}
void IncomesXml::addIncomeToXml(Income income)
{
    CMarkup xmlFile;
    if (xmlFile.Load(nameIncomeXml))
    {
        xmlFile.FindElem();
        xmlFile.IntoElem ();
        while(xmlFile.FindElem ("INCOME"))
        {
            xmlFile.IntoElem();
            xmlFile.OutOfElem();
        }
        xmlFile.OutOfElem();
    }
    else
    {
        xmlFile.AddElem("INCOMES");
    }
    xmlFile.IntoElem();
    xmlFile.AddElem ("INCOME");
    xmlFile.IntoElem ();
    xmlFile.AddElem ("INCOMEID",intToString(income.getIncomeId()));
    xmlFile.AddElem ("USERID",intToString(income.getUserId()));
    xmlFile.AddElem ("DATE", income.getDate());
    xmlFile.AddElem ("ITEM", income.getItem());
    xmlFile.AddElem ("AMOUNT", doubleToString(income.getAmount()));

    xmlFile.OutOfElem();

    xmlFile.Save(nameIncomeXml);
}

int IncomesXml::loadIncomesFromXml(vector<Income> &incomes, int userLoggedId)
{
    CMarkup xmlFile;
    Income income;
    int incomeId,userId;
    string date, item;
    double amount;
    int idOfLastIncome = 0;


    if (xmlFile.Load(nameIncomeXml))
    {
        xmlFile.FindElem();
        xmlFile.IntoElem();

        while ( xmlFile.FindElem("INCOME") )
        {
            xmlFile.IntoElem();
            xmlFile.FindElem( "INCOMEID" );
            incomeId = atoi( MCD_2PCSZ(xmlFile.GetData()) );

            xmlFile.FindElem( "USERID" );
            userId = atoi( MCD_2PCSZ(xmlFile.GetData()) );
            xmlFile.FindElem("DATE");
            date = xmlFile.GetData();
            xmlFile.FindElem("ITEM");
            item = xmlFile.GetData();
            xmlFile.FindElem("AMOUNT");
            amount = atof( MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.OutOfElem();
            if(userLoggedId == userId)
            {

                income.setIncomeId(incomeId);
                income.setUserId(userId);
                income.setDate(date);
                income.setItem(item);
                income.setAmount(amount);

                incomes.push_back(income);
            }
            idOfLastIncome++;

        }

    }
    return idOfLastIncome;
}
