/*Write a program to read date1, date2 and
check if Date l is Less than Date2*/
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
bool CheckDate1LessThanDate1(stDate date1,stDate date2){

    return (date1.year<date2.year)? 1:(date1.year>date2.year)? 0 : (date1.month<date2.month)? 1 : (date1.month>date2.month)? 0 : (date1.day<date2.day)? 1 : 0 ;
}
bool CheckDate1LessThanDate2(stDate date1,stDate date2){
    if(date1.year<date2.year){
        return 1;
    }else if(date1.year>date2.year){
        return 0;
    }else {
       return  (NumberOfDaysFromTheBeginningOfYear(date2.year,date2.month,date2.day)>NumberOfDaysFromTheBeginningOfYear(date1.year,date1.month,date1.day))?  1 : 0 ;
    }
}
bool CheckDate1LessThanDate3(stDate date1, stDate date2) {
    if (date1.year < date2.year)  return true;
    if (date1.year > date2.year)  return false;
    if (date1.month < date2.month) return true;
    if (date1.month > date2.month) return false;
    return date1.day < date2.day;
}
int main (){
    cout<<"Enter Date 1 :\n";
    stDate date1 =ReadFullDate();
    cout<<"Enter Date 2 :\n";
    stDate date2 =ReadFullDate();
    if (CheckDate1LessThanDate2(date1,date2)){
        cout <<"Yes, Date 1 is less than date 2 .\n";
    }else{
         cout <<"No, Date 1 is not less than date 2 .\n";
    }
      return 0;
}