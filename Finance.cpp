#include "Finance.h"

Finance::Finance(int loggedUserId)
{
    this->idOfLastIncome = incomesXml.loadIncomesFromXml(incomes,loggedUserId);
    this->idOfLastExpense = expensesXml.loadExpensesFromXml(expenses,loggedUserId);
}

Finance::~Finance()
{
    expenses.clear();
    incomes.clear();
}
void Finance::addExpense(int userLoggedId)
{
    idOfLastExpense++;
    Expense expense = giveNewExpenseData(userLoggedId);

    expenses.push_back(expense);
    expensesXml.addExpenseToXml(expense);


    cout << endl << "Dodano pomyslnie wydatek" << endl << endl;
    system("pause");
}

Expense Finance::giveNewExpenseData(int userLoggedId)
{
    Expense expense;
    string date = "", item = "", amountStr="";
    double amount = 0.0;
    char sign;
    string dateMin="2000-01-01", dateMax = getDateOfLastDayCurrentMonth();
    expense.setExpenseId(idOfLastExpense);
    expense.setUserId(userLoggedId);

    cout << endl << "Czy chcesz podac wydatek z dzisiejsza data t/n: ";
    cin>>sign;
    cin.ignore();

    if (sign == 'n')
    {
        do
        {
            cout << endl << "Podaj swoja date od  2000-01-01 do maksymalnie ostatniego dnia biezacego miesiaca w formacie rrrr-mm-dd: ";
            cin >> date;
            cin.ignore();
        }
        while( (date <= dateMin)||(date >= dateMax));
    }
    else  if (sign == 't')
        date = getTodaysDate();
    expense.setDate(date);
    cout << endl << "Podaj rodzaj wydatku: ";
    cin.sync();
    getline(cin, item);
    expense.setItem(item);
    cout << endl << "Podaj wielkosc wydatku, kwoty ulamkowe podawaj w formacie z kropka: ";
    cin>>amountStr;
    cin.ignore();
    for(int i=1; i<amountStr.size(); i++)
    {
        if (amountStr[i]==',')
            amountStr[i]='.';
    }
    amount = atof(amountStr.c_str());
    expense.setAmount(amount);
    return expense;

}
void Finance::addIncome(int userLoggedId)
{
    idOfLastIncome++;
    Income income = giveNewIncomeData(userLoggedId);
    incomes.push_back(income);
    incomesXml.addIncomeToXml(income);


    cout << endl << "Dodano pomyslnie przychod" << endl << endl;
    system("pause");
}

Income Finance::giveNewIncomeData(int userLoggedId)
{
    Income income;
    string date = "", item = "", amountStr="";
    double amount = 0.0;
    char sign;
    string dateMin="2000-01-01", dateMax = getDateOfLastDayCurrentMonth();
    income.setIncomeId(idOfLastIncome);
    income.setUserId(userLoggedId);

    cout << endl << "Czy chcesz podac przychod z dzisiejsza data t/n: ";
    cin>>sign;
    cin.ignore();

    if (sign == 'n')
    {
        do
        {
            cout << endl << "Podaj swoja date od  2000-01-01 do maksymalnie ostatniego dnia biezacego miesiaca w formacie rrrr-mm-dd: ";
            cin >> date;
            cin.ignore();
        }
        while( (date <= dateMin)||(date >= dateMax));
    }
    else  if (sign == 't')
        date = getTodaysDate();
    income.setDate(date);
    cout << endl << "Podaj rodzaj przychodu: ";
    cin.sync();
    getline(cin, item);
    income.setItem(item);
    cout << endl << "Podaj wielkosc przychodu, kwoty ulamkowe podawaj w formacie z kropka: ";
    cin>>amountStr;
    cin.ignore();
    for(int i=1; i<amountStr.size(); i++)
    {
        if (amountStr[i]==',')
            amountStr[i]='.';
    }
    amount = atof(amountStr.c_str());
    income.setAmount(amount);
    return income;

}
string Finance::getTodaysDate()//Podaje dzisiejsza date w formacie rrrr-mm-dd
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int day = st.wDay;
    int month = st.wMonth;
    int year = st.wYear;
    string  strDate = intToStringWithZero(year)+"-"+intToStringWithZero(month)+"-"+intToStringWithZero(day);
    return strDate;
}
string Finance::getDateOfFirstDayCurrentMonth()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int month = st.wMonth;
    int year = st.wYear;
    string  strDate = intToStringWithZero(year)+"-"+intToStringWithZero(month)+"-"+intToStringWithZero(1);
    return strDate;
}
string Finance::getDateOfLastDayCurrentMonth()//Podaje  date 1 dnia nastepnego miesiaca po dzisiejszej dacie rrrr-mm-dd
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int month = st.wMonth;
    int year = st.wYear;
    int day = getDaysCount(month, year);
    string  strDate = intToStringWithZero(year)+"-"+intToStringWithZero(month)+"-"+intToStringWithZero(day);
    return strDate;
}
string Finance::getDateOfFirstDayPreviousMonth()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int month = st.wMonth;
    int year = st.wYear;
    string  strDate = intToStringWithZero(year)+"-"+intToStringWithZero(month+1)+"-"+intToStringWithZero(1);
    return strDate;
}
string Finance::getDateOfLastDayPreviousMonth()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int day ;
    int month = st.wMonth;
    int year = st.wYear;
    if(month<12)
        day = getDaysCount(month, year);
    else if(month == 12)
        day = getDaysCount(1, year+1);
    string  strDate = intToStringWithZero(year)+"-"+intToStringWithZero(month+1)+"-"+intToStringWithZero(day);
    return strDate;
}
string Finance::intToStringWithZero(int intCount)
{
    string str;
    ostringstream ss;
    ss << intCount;
    if(intCount<10)
        str ="0"+ss.str();
    else
        str = ss.str();
    return str;
}
int Finance:: getDaysCount(int month, int year)//podaje liczbe dni w miesiącu w danym roku
{
    int daysCount;
    if((month==4)||(month==6)||(month==9)||(month==11))
        daysCount=30;
    else if((month==1)||(month==3)||(month==5)||(month==7)||(month==10)||(month==12))
        daysCount=31;
    else if((month==2)&&(((year%4==0)&&(year%100!=0))||((year%100==0)&&(year%400==0))))
        daysCount=29;
    else
        daysCount=28;
    return  daysCount;
}
double Finance::checkIncomeData(Income income, string minDate, string maxDate)
{
    if ((income.getDate() >=  minDate)
            &&(income.getDate() <= maxDate))
    {
        displayIncomeData(income);
        return income.getAmount();
    }
    else
        return 0;
}
double Finance::checkExpenseData(Expense expense, string minDate, string maxDate)

{
    if ((expense.getDate() >=  minDate)
            &&(expense.getDate() <= maxDate))
    {
        displayExpenseData(expense);
        return expense.getAmount();
    }
    else
        return 0;
}
void Finance::displayIncomeData(Income income)
{
    cout << "------------------------------------------------------------------------------" <<endl;

    cout << "|" <<setw(14)<< income.getDate() <<"|" <<setw(40)<<income.getItem()<<"|" << setw(20)<<income.getAmount() <<"|"<< endl;
}
void Finance::displayExpenseData(Expense expense)
{
    cout << "------------------------------------------------------------------------------" <<endl;

    cout << "|" <<setw(14)<< expense.getDate() <<"|" <<setw(40)<<expense.getItem()<<"|" << setw(20)<<expense.getAmount() <<"|"<< endl;

}
double Finance::displayAllIncomes(string minDate, string maxDate)
{
    double incomesSum = 0.0;
    cout<<endl<<"                   >>>>>>>>>>PRZYCHODY<<<<<<<<<<<<" <<endl;
    if (!incomes.empty())
    {
        cout << "------------------------------------------------------------------------------" <<endl;
        cout << "|     DATA     |                RODZAJ                  |       KWOTA        |" <<endl;

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            incomesSum = incomesSum+checkIncomeData(*itr, minDate, maxDate);
        }
    }
    cout << "------------------------------------------------------------------------------"<<endl;

    return incomesSum;
}

double Finance::displayAllExpenses(string minDate, string maxDate)
{
    double expensesSum =0.0;

    cout<<endl<<"                   >>>>>>>>>>>WYDATKI<<<<<<<<<<<<" <<endl;
    if (!expenses.empty())
    {

        cout << "------------------------------------------------------------------------------" <<endl;
        cout << "|     DATA     |                RODZAJ                  |       KWOTA        |" <<endl;

        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            expensesSum = expensesSum+checkExpenseData(*itr, minDate, maxDate);
        }
    }
    cout << "------------------------------------------------------------------------------"<<endl;
    return expensesSum;
}

void Finance::displayCurrentMonthBalance()
{
    system("cls");
    string maxDate = getDateOfLastDayCurrentMonth();
    string minDate = getDateOfFirstDayCurrentMonth();
    cout<<endl<<"                    BILANS  Z BIEZACEGO MIESIACA " <<endl;
    sortIncomesByDate(incomes);
    sortExpensesByDate(expenses);
    double incomesSum = displayAllIncomes(minDate,maxDate);
    double expensesSum = displayAllExpenses(minDate,maxDate);

    cout<<endl<<"|"<<setw(56)<<"RAZEM PRZYCHODY:  " << setw(20)<<incomesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    cout<<"|"<<setw(56)<<"RAZEM WYDATKI:  " << setw(20)<<expensesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    cout<<"|"<<setw(56)<<"SALDO:  " << setw(20)<<incomesSum-expensesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    system("pause");
}

void Finance::displayPreviousMonthBalance()
{
    system("cls");

    string minDate = getDateOfFirstDayPreviousMonth();
    string maxDate = getDateOfLastDayPreviousMonth();
    cout<<endl<<"                    BILANS Z POPRZEDNIEGO MIESIACA " <<endl;
    sortIncomesByDate(incomes);
    sortExpensesByDate(expenses);
    double incomesSum = displayAllIncomes(minDate,maxDate);
    double expensesSum = displayAllExpenses(minDate,maxDate);

    cout<<endl<<"|"<<setw(56)<<"RAZEM PRZYCHODY:  " << setw(20)<<incomesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    cout<<"|"<<setw(56)<<"RAZEM WYDATKI:  " << setw(20)<<expensesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    cout<<"|"<<setw(56)<<"SALDO:  " << setw(20)<<incomesSum-expensesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    system("pause");
}
void Finance::displayAnyPeriodBalance()
{
    string minDate,maxDate;
    cout <<"Od kiedy chcesz wyswietlic bilans? Podaj date w formacie rrrr-mm-dd: "<<endl;
    cin >> minDate;
    cout <<"Do kiedy chcesz wyswietlic bilans? Podaj date w formacie rrrr-mm-dd: "<<endl;
    cin >> maxDate;
    cout << endl << "BILANS Z OKRESU OD " << minDate << " DO " << maxDate << endl;
    sortIncomesByDate(incomes);
    sortExpensesByDate(expenses);
    double incomesSum = displayAllIncomes(minDate,maxDate);
    double expensesSum = displayAllExpenses(minDate,maxDate);

    cout<<endl<<"|"<<setw(56)<<"RAZEM PRZYCHODY:  " << setw(20)<<incomesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    cout<<"|"<<setw(56)<<"RAZEM WYDATKI:  " << setw(20)<<expensesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    cout<<"|"<<setw(56)<<"SALDO:  " << setw(20)<<incomesSum-expensesSum <<"|"<<endl;
    cout << "------------------------------------------------------------------------------"<<endl;
    system("pause");
}
void Finance::sortIncomesByDate(vector<Income> &incomes)
{
    sort(incomes.begin(), incomes.end(),[](Income& first, Income& second)
    {return (first.getDate() > second.getDate());} );
}
void Finance::sortExpensesByDate(vector<Expense> &expenses)
{
    sort(expenses.begin(), expenses.end(),[](Expense& first, Expense& second)
    {return (first.getDate() > second.getDate());} );
}
