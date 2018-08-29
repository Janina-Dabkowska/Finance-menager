#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;
class Income
{

private:
    int incomeId;
    int userId;
    string date;
    string name;
    string item;
    double amount;

public:
    Income();
    virtual ~Income();

    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(string date);
    void setItem(string item);
    void setAmount(double amount);

};

#endif
