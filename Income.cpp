#include "Income.h"

using namespace std;

Income::Income()
{
    incomeId = 0;
    userId = 0;
    string date = "";
    string name = "";
    string item = "";
    double amount = 0.0;
}
Income::~Income() {;}

int Income::getIncomeId()
{
    return incomeId;
}
int Income::getUserId()
{
    return userId;
}
string Income::getDate()
{
    return date;
}
string Income::getItem()
{
    return item;
}
double Income::getAmount()
{
    return amount;
}

void  Income::setIncomeId(int incomeId)
{
    this->incomeId = incomeId;
}
void  Income::setUserId(int userId)
{
    this->userId = userId;
}
void  Income::setDate(string date)
{
    this->date = date;
}
void  Income::setItem(string item)
{
    this->item = item;
}
void  Income::setAmount(double amount)
{
    this->amount = amount;
}
