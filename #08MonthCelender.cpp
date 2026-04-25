// Write a program to print Month Calendar.
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
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
string MonthName (unsigned short month){
    string months[12] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"};
    return(months[month-1]);
}
void PrintMonthCelender (unsigned short year,unsigned short month){
    unsigned short count = 0;
    unsigned short numberOfDays = NumberOfDaysInMonth(year,month); 
    cout<<"___________________________________________________"<<MonthName(month)<<"___________________________________________________\n\n";
    cout<<setw(12)<<"Sunday\t"<<setw(12)<<"Monday\t"<<setw(12)<<"Tuesday\t"<<setw(12)<<"Wednesday\t"<<setw(12)<<"Thursday\t"<<setw(12)<<"Friday\t"<<setw(12)<<"Saturday\n";
    unsigned short i ;
    for( i = 0;i<DayOrder(year,month,1);i++){
        cout<<"\t\t";
    };
    for(unsigned short j =1;j<=numberOfDays;j++){
            cout<<setw(8)<<j;
            i++ ;
            if(i==7){
                i =0 ;
                cout<<endl ;
            }else{
                cout<<"\t" ;
            }
        }
  cout<<"\n____________________________________________________________________________________________________________\n";
}
int main (){
    unsigned short year = ReadPositiveNumberInRange("Enter the year : ","Invalid input! Please enter a number of year.",1,2026);
    unsigned short month = ReadPositiveNumberInRange("Enter the number of the month : ","Invalid input! Please enter a number of the month.",1,12); 
    PrintMonthCelender(year,month);
    system("pause");
    return 0;
}