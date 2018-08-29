#ifndef INCOMESXML_H
#define INCOMESXML_H

#include <iostream>
#include <sstream>
#include "Income.h"

#include "Markup.h"
#include <vector>

using namespace std;

class IncomesXml
{
private:
    string nameIncomeXml;
public:
    IncomesXml();
    virtual ~IncomesXml();
    int loadIncomesFromXml(vector<Income> &incomes, int userLoggedId);
    void addIncomeToXml(Income income);

private:
    string intToString(int intCount);
    string doubleToString(double doubleCount);

};

#endif // INCOMESXML_H
