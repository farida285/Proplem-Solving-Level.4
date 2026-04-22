/*Write a program to read a date, and
print the day name of week.*/
#include <iostream>
#include <limits>
#include <string>
using namespace std ;
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
unsigned short DayOrder(unsigned short year,unsigned short month,unsigned short day){
    unsigned short a =(14-month)/12 ;
    unsigned short y =year - a ;
    unsigned short m = month+(12*a)-2 ;
    unsigned short d =( (day+y+(y/4)-(y/100)+(y/400)+((31*m)/12)) % 7) ;
    return d ;
}
string DayName (unsigned short year,unsigned short month,unsigned short day){
    string arr [7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    return(arr[DayOrder(year,month,day)]);
}
int main (){
    unsigned short year = ReadPositiveNumberInRange("Enter the year : ","Invalid input! Please enter a number of year.",1,2026);
    unsigned short month = ReadPositiveNumberInRange("Enter the number of the month : ","Invalid input! Please enter a number of the month.",1,12); 
    unsigned short day = ReadPositiveNumberInRange("Enter the number of the day : ","Invalid input! Please enter a number of the day.",1,NumberOfDaysInMonth(year,month));
    string date =to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    cout <<"Data : "<<date <<endl;
    cout <<"Day Order : "<<DayOrder(year, month ,day)<<endl;
    cout <<"Day Name : "<<DayName(year,month,day)<<endl;


    return 0;
}