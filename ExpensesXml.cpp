#include "ExpensesXml.h"

ExpensesXml::ExpensesXml()
{
     nameExpenseXml = "expenses.xml";
}

ExpensesXml::~ExpensesXml()
{
    ;
}

string ExpensesXml::intToString(int intCount)
{
    ostringstream ss;
    ss << intCount;
    string str = ss.str();

    return str;
}
string ExpensesXml::doubleToString(double doubleCount)
{
    ostringstream ss;
    ss << doubleCount;
    string str = ss.str();

    return str;
}
void ExpensesXml::addExpenseToXml(Expense expense)
{
    CMarkup xmlFile;
    if (xmlFile.Load(nameExpenseXml))
    {
        xmlFile.FindElem();
        xmlFile.IntoElem ();
        while(xmlFile.FindElem ("EXPENSE"))
        {
            xmlFile.IntoElem();
            xmlFile.OutOfElem();
        }
        xmlFile.OutOfElem();
    }
    else
    {
        xmlFile.AddElem("EXPENSES");
    }
    xmlFile.IntoElem();
    xmlFile.AddElem ("EXPENSE");
    xmlFile.IntoElem ();
    xmlFile.AddElem ("EXPENSEID",intToString(expense.getExpenseId()));
    xmlFile.AddElem ("USERID",intToString(expense.getUserId()));
    xmlFile.AddElem ("DATE", expense.getDate());
    xmlFile.AddElem ("ITEM", expense.getItem());
    xmlFile.AddElem ("AMOUNT", doubleToString(expense.getAmount()));

    xmlFile.OutOfElem();

    xmlFile.Save(nameExpenseXml);
}

int ExpensesXml::loadExpensesFromXml(vector<Expense> &expenses, int userLoggedId)
{
    CMarkup xmlFile;
    Expense expense;
    int expenseId,userId;
    string date, item;
    double amount;
    int idOfLastExpense = 0;


    if (xmlFile.Load(nameExpenseXml))
    {
        xmlFile.FindElem();
        xmlFile.IntoElem();

        while ( xmlFile.FindElem("EXPENSE") )
        {
            xmlFile.IntoElem();
            xmlFile.FindElem( "EXPENSEID" );
            expenseId = atoi( MCD_2PCSZ(xmlFile.GetData()) );

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

                expense.setExpenseId(expenseId);
                expense.setUserId(userId);
                expense.setDate(date);
                expense.setItem(item);
                expense.setAmount(amount);

                expenses.push_back(expense);
            }
            idOfLastExpense++;

        }

    }
    return idOfLastExpense;
}
