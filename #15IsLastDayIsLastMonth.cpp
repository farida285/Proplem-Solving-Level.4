/*Write a program to read a date and check:
. if it is last Day in Month
. If it is last Month In Year */
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
unsigned short ReadPositiveNumberInRange (const string &message, const string &errorMessage,unsigned  short from, unsigned  short to){
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

stDate ReadFullDate (){
    stDate date ;
    date.year = ReadPositiveNumberInRange("Enter the year : ","Invalid input! Please enter a number of year.",1,2026);
    date.month = ReadPositiveNumberInRange("Enter the number of the month : ","Invalid input! Please enter a number of the month.",1,12); 
    date.day = ReadPositiveNumberInRange("Enter the number of the day : ","Invalid input! Please enter a number of the day.",1,NumberOfDaysInMonth(date.year,date.month));
    return date ;
}
bool IsLastMonthInYear (unsigned short month){
    return(month==12);
}
bool IsLastDayInmonth (unsigned short year,unsigned short month,unsigned short day){
   return(day==NumberOfDaysInMonth(year,month));
}
int main (){
    cout<<"Enter Date :\n";
    stDate date =ReadFullDate();
    (IsLastMonthInYear(date.month)) ? cout<<"Yes, it is last Month In Year.\n" : cout<<"No, it is not last Month In Year.\n";
    (IsLastDayInmonth(date.year,date.month,date.day))? cout<<"Yes, It is last Day in Month.\n" : cout<<"No, It is not last Day in Month.\n";
     return 0;
}