#ifndef EXPENSESXML_H
#define EXPENSESXML_H

#include <iostream>
#include <sstream>
#include "Expense.h"

#include "Markup.h"
#include <vector>

using namespace std;

class ExpensesXml
{
private:
    string nameExpenseXml;
public:
    ExpensesXml();
    virtual ~ExpensesXml();
    int loadExpensesFromXml(vector<Expense> &expenses, int userLoggedId);
    void addExpenseToXml(Expense expense);

private:
    string intToString(int intCount);
    string doubleToString(double doubleCount);

};


#endif // EXPENSESXML_H
