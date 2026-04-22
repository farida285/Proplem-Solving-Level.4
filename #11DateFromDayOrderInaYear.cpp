/*Write a program to print total days
from the beginning of year, then
Take the total days and convert them
back to date.*/
#include <iostream>
#include <limits>
#include <string>
using namespace std ;
struct stDate
{
    unsigned short year;
    unsigned short month;
    unsigned short day;
};

bool IsLeapYear (unsigned short year){
if(year%400==0){
    return 1;
}else if(year%100!=0 && year%4==0){
  return 1;
}
return 0 ;

}
unsigned short ReadPositiveNumberInRange (const string &message, const string &errorMessage,unsigned  short from,unsigned  short to){
    int number ;
    do{
        cout<<message;
        if (!(cin >> number))  
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMessage <<"\n";
        }else if(number<from||number>to){
            cout<<"Unavailable number!!\n" ;
            cout<<"Enter number in range from "<<from<<" to "<<to<<".\n";
        }else{
            return (unsigned short)number ;
        }
    }while(true);
}
unsigned short NumberOfDaysInMonth(unsigned short year,unsigned short month){
    if(month<1||month>12){
        return 0 ;
    }
  short arr [12]={31,28,31,30,31,30,31,31,30,31,30,31};
  return((month == 2 ) ? ((IsLeapYear(year)) ? 29 : 28 )   :  (arr[month-1]));
}

unsigned short NumberOfDaysFromTheBeginningOfYear (unsigned short year,unsigned short month,unsigned short dayN){
    unsigned short totalDays = dayN;
    for(unsigned short i=1;i<month;i++){
        totalDays+=NumberOfDaysInMonth(year,i);
    }
    return totalDays ;
}
stDate TakeOrderDayInYearAndconvertToDate(unsigned short year, unsigned short dateOrderInYear) {
    stDate date;
    
    unsigned short remainingDays = dateOrderInYear;

    for (unsigned short month = 1; month <= 12; month++) {
        unsigned short daysInMonth = NumberOfDaysInMonth(year, month);

        if (remainingDays > daysInMonth) {
            remainingDays -= daysInMonth;
        } else {
            date.year = year;
            date.month = month;
            date.day = remainingDays;
            break;
        }
    }

    return date;
}
int main (){
    unsigned short year = ReadPositiveNumberInRange("Enter the year : ","Invalid input! Please enter a number of year.",1,2026);
    unsigned short month = ReadPositiveNumberInRange("Enter the number of the month : ","Invalid input! Please enter a number of the month.",1,12); 
    unsigned short day = ReadPositiveNumberInRange("Enter the number of the day : ","Invalid input! Please enter a number of the day.",1,NumberOfDaysInMonth(year,month));
    
    unsigned short dayOrderInYear =NumberOfDaysFromTheBeginningOfYear(year,month,day);
    stDate date =TakeOrderDayInYearAndconvertToDate(year,dayOrderInYear);
    cout<<"Number of days from the beginning of year is "<<dayOrderInYear<<endl;
    cout<<"Date for ["<<dayOrderInYear<<"] is "<<date.day<<"/"<<date.month<<"/"<<date.year;
    return 0;
}