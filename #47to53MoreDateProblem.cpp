/*Write a program to read a date and make functions
as follows:
. Overload the DayOfWeekOrder to take date
structure
. IsEndOfWeek
· IsWeekEnd
. IsBusinessDay
· DaysUntilTheEndOfWeek
. DaysUntil TheEndOfMonth
. DaysUntilTheEndOfYear*/
#pragma warning(disable : 4996)
#include <iostream>
#include <limits>
#include <string>
#include <ctime>
using namespace std ;
struct stDate
{
    unsigned short year;
    unsigned short month;
    unsigned short day;
};
enum enDays {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
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
   unsigned short arr [12]={31,28,31,30,31,30,31,31,30,31,30,31};
  return((month == 2 ) ? ((IsLeapYear(year)) ? 29 : 28 )   :  (arr[month-1]));
}
unsigned short NumberOfDaysFromTheBeginningOfYear (stDate date){
    unsigned short totalDays = date.day;
    for(unsigned short i=1;i<date.month;i++){
        totalDays+=NumberOfDaysInMonth(date.year,i);
    }
    return totalDays ;
}
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
unsigned short DaysUntilEndOftheWeek(stDate date){
    return (6-(unsigned short)DayOrder(date));
}
unsigned short DaysUntilEndOftheMonth(stDate date){
    return (NumberOfDaysInMonth(date.year,date.month)-date.day);
}
unsigned short DaysUntilEndOftheYear(stDate date){

    return ((IsLeapYear(date.year)?  (366-NumberOfDaysFromTheBeginningOfYear(date)):(365-NumberOfDaysFromTheBeginningOfYear(date))));
}
stDate GetSystemDate (){
   
    time_t t = time(0); // get time now
    tm* now = localtime(&t);

    stDate nowDate ;
    nowDate.year=now->tm_year+1900;
    nowDate.month=now->tm_mon+1;
    nowDate.day=now->tm_mday;
    return nowDate ;
}
int main (){
    stDate date = GetSystemDate ();
    cout<<"Today is "+DayName(date)+" , "<<date.day<<"/"<<date.month<<"/"<<date.year<<endl;
    cout<<"It is end of week ?\n";
    (IsEndOfWeek(date))? cout<<"Yes, It is end of week\n" : cout<<"No, It is not end of week.\n" ;
    cout<<"It is Weekend Day ?\n";
    (IsWeekEndDay(date))? cout<<"Yes, It is Weekend Day.\n" : cout<<"No, It is not Weekend Day.\n" ;
    cout<<"It is Business Day ?\n";
    (IsBusinessDay(date))? cout<<"Yes, It is Business Day.\n" : cout<<"No, It is not Business Day.\n" ;

    cout <<"Days until end of week : "<<DaysUntilEndOftheWeek(date)<<" Day(s).\n";
    cout <<"Days until end of month : "<<DaysUntilEndOftheMonth(date)<<" Day(s).\n";
    cout <<"Days until end of year : "<<DaysUntilEndOftheYear(date)<<" Day(s).\n";
    return 0;
}