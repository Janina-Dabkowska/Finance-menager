#include "Expense.h"
using namespace std;

Expense::Expense()
{
    expenseId = 0;
    userId = 0;
    string date = "";
    string name = "";
    string item = "";
    double amount = 0.0;
}
Expense::~Expense()
{
    ;
}

int Expense::getExpenseId()
{
    return expenseId;
}
int Expense::getUserId()
{
    return userId;
}
string Expense::getDate()
{
    return date;
}
string Expense::getItem()
{
    return item;
}
double Expense::getAmount()
{
    return amount;
}
void  Expense::setExpenseId(int expenseId)
{
    this->expenseId = expenseId;
}
void  Expense::setUserId(int userId)
{
    this->userId = userId;
}
void  Expense::setDate(string date)
{
    this->date = date;
}
void  Expense::setItem(string item)
{
    this->item = item;
}
void  Expense::setAmount(double amount)
{
    this->amount = amount;
}


