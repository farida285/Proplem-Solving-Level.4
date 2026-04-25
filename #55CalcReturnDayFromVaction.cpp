/*Write a program to read Vacation Start
DateFrom and VacationDays, then make a
function to calculate the vacation return
Date.
Note: Weekends are excluded.*/
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

stDate IncreaseDateByOneDay (stDate date){
    if(IsLastDayInmonth(date.year,date.month,date.day))
    { 
        if(IsLastMonthInYear(date.month)){ 
            date.year++ ;
            date.month=1;
            date.day=1;
          }else{
             date.month++;
             date.day=1;
          }
    }else{
        date.day++;
    }
    return date ;
}
enum enDays {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
enDays DayOrder(stDate date ){
    unsigned short a =(14-date.month)/12 ;
    unsigned short y =date.year - a ;
    unsigned short m = date.month+(12*a)-2 ;
    unsigned short d =( (date.day+y+(y/4)-(y/100)+(y/400)+((31*m)/12)) % 7) ;
    return (enDays)d ;
}
string DayName (stDate date ){
    string arr [7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    return(arr[(int)DayOrder(date)]);
}
bool IsEndOfWeek (stDate date){
    return(DayOrder(date)==enDays::Saturday);
}
bool IsWeekEndDay (stDate date){
    enDays day =DayOrder(date) ;
    return(day==enDays::Friday||day==enDays::Saturday);
}
bool IsBusinessDay (stDate date){
    return(!IsWeekEndDay(date) );
}
bool CheckDate1LessThanDate2(stDate date1, stDate date2) {
    if (date1.year < date2.year)  return true;
    if (date1.year > date2.year)  return false;
    if (date1.month < date2.month) return true;
    if (date1.month > date2.month) return false;
    return date1.day < date2.day;
}
bool CheckDate1EqualThanDate2(stDate date1,stDate date2){

    return (date1.year==date2.year&&date1.month==date2.month&&date1.day==date2.day);
}

stDate CalcReturnDayFromVaction (stDate startDate,unsigned short actualvacationDays){
 
    while (actualvacationDays>0)
  {
    if(IsBusinessDay(startDate)){
        actualvacationDays--;
    }
    startDate=IncreaseDateByOneDay(startDate);
  }
  return startDate ;
}
int main()
{
cout<<"Vaction Starts :\n";
stDate date1 = ReadFullDate();
unsigned short actualvacationDays =ReadPositiveNumberInRange("Please enter vacation days : ","Invalid input!!\nPlease enter number of vacation days : ",1,3000);
stDate date2 =CalcReturnDayFromVaction(date1,actualvacationDays) ;
cout<<"Return Date : "<<DayName(date2)+" , "<<date2.day<<"/"<<date2.month<<"/"<<date2.year<<endl;

return 0;
}