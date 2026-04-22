
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
unsigned short ReadPositiveNumberInRange (const string &message, const string &errorMessage, unsigned short from,unsigned short to){
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
stDate AddDaysToDate (stDate date,unsigned short addDays){
    if (addDays == 0) return date;
    unsigned short calcYear = date.year;
    unsigned short totalDaysInYear ;
    unsigned short orderDateInYear =NumberOfDaysFromTheBeginningOfYear(date.year,date.month,date.day);
    while (true)
    {
            totalDaysInYear =(IsLeapYear(calcYear))? 366 : 365 ;
            if((totalDaysInYear-orderDateInYear)<addDays){
                addDays-=(totalDaysInYear-orderDateInYear+1);
                orderDateInYear = 1;
                calcYear++;
            }else{
                orderDateInYear+=addDays ;
                return(TakeOrderDayInYearAndconvertToDate(calcYear,orderDateInYear));

            }

    }
    
}
stDate AddDaysToDate2 (stDate date,unsigned short addDays){
   if (addDays == 0) return date;
unsigned short totalDays=addDays+NumberOfDaysFromTheBeginningOfYear(date.year,date.month,date.day);
date.day=1;
date.month=1;
unsigned short daysOfMonth ;
while (true)
{
    daysOfMonth=NumberOfDaysInMonth(date.year,date.month);
    if(totalDays>daysOfMonth){
        totalDays-=daysOfMonth;
        date.month++;
        if(date.month>12){
            date.month=1;
            date.year++;
        }
    }else{
        date.day=totalDays;
        return date ;
    }
   
}

    
}
int main (){
    stDate date ;
    date.year = ReadPositiveNumberInRange("Enter the year : ","Invalid input! Please enter a number of year.",1,2026);
    date.month = ReadPositiveNumberInRange("Enter the number of the month : ","Invalid input! Please enter a number of the month.",1,12); 
    date.day = ReadPositiveNumberInRange("Enter the number of the day : ","Invalid input! Please enter a number of the day.",1,NumberOfDaysInMonth(date.year,date.month));
    unsigned short addDays =ReadPositiveNumberInRange("Enter the number of the days to add : ","Invalid input! Please enter a number of the days.",1,60000);
   stDate addingDate =AddDaysToDate2(date,addDays);
    cout<<"Date after adding ["<<addDays<<"] is "<<addingDate.day<<"/"<<addingDate.month<<"/"<<addingDate.year;
    return 0;
}