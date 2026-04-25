/*Write a program to read a Date1, Date2
and make a function to calculate the
difference in days.
Note: Date 1 should be less than Date2*/
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
unsigned short NumberOfDaysFromTheBeginningOfYear (unsigned short year,unsigned short month,unsigned short dayN){
    unsigned short totalDays = dayN;
    for(unsigned short i=1;i<month;i++){
        totalDays+=NumberOfDaysInMonth(year,i);
    }
    return totalDays ;
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
stDate IncreaseDateByOne (stDate date){
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
bool CheckDate1LessThanDate3(stDate date1, stDate date2) {
    if (date1.year < date2.year)  return true;
    if (date1.year > date2.year)  return false;
    if (date1.month < date2.month) return true;
    if (date1.month > date2.month) return false;
    return date1.day < date2.day;
}

int GetDifferenceInDays1 (stDate date1, stDate date2,bool includeEndDay=false){

    int  days=0;
    if(CheckDate1LessThanDate3(date1,date2)){
        while (date2.year>date1.year)
        {
            unsigned short noOfDaysInYear = (IsLeapYear(date1.year))? 366 : 365 ;
            days +=(noOfDaysInYear - NumberOfDaysFromTheBeginningOfYear(date1.year,date1.month,date1.day)+1);
            date1.year ++ ;
            date1.month=1 ;
            date1.day=1 ;
        }
        days +=  NumberOfDaysFromTheBeginningOfYear(date2.year,date2.month,date2.day)
         -NumberOfDaysFromTheBeginningOfYear(date1.year,date1.month,date1.day);
            
    }else{
        return (-11111);
    }
 return ((includeEndDay)? ++days:days) ;
}
int   GetDifferenceInDays2 (stDate date1, stDate date2,bool includeEndDay=false){
    if(!CheckDate1LessThanDate3(date1,date2)){
        return (-11111);
    }
  int  days=0;
        while (CheckDate1LessThanDate3(date1,date2))
        {
            date1=IncreaseDateByOne(date1);
            days++;
        }
  
 return ((includeEndDay)? ++days:days) ;
}
int main (){
    cout<<"Enter Date 1 :\n";
    stDate date1 =ReadFullDate();
    cout<<"Enter Date 2 :\n";
    stDate date2 =ReadFullDate();
    cout<<"Diffrence is "<<GetDifferenceInDays1(date1,date2,1) <<" Day(s) \n";
    cout<<"Diffrence is "<<GetDifferenceInDays2(date1,date2,1) <<" Day(s) \n";

     return 0;
}