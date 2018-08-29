#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
using namespace std;
class Expense
{
private:
    int expenseId;
    int userId;
    string date;
    string name;
    string item;
    double amount;

public:
    Expense();
    virtual ~Expense();

    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();

    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(string date);
    void setItem(string item);
    void setAmount(double amount);

};

#endif // EXPENSE_H
