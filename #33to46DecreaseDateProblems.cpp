/*Write a program to read a date and make a functions
to Decrease date as follows:
· DecreaseDateByXDays
. DecreaseDateByOneWeek
· DecreaseDateByXWeeks
· DecreaseDateByOneMonth
· DecreaseDateByXMonths
. DecreaseDateByOneyear
. DecreaseDateByXyears
· DecreaseDateByXYearsFaster
· DecreaseDateByOneDecade
· DecreaseDateByXDecades
· DecreaseDateByXDecadesFaster
. DecreaseDateByOneCentury
· DecreaseDateByOneMillennium */
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
bool IsFirstMonthInYear (unsigned short month){
    return(month==1);
}
bool IsFirstDayInmonth (unsigned short day){
   return(day==1);
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
stDate DecreaseDateByOneDay (stDate date){
  if(IsFirstDayInmonth(date.day)){
    if(IsFirstMonthInYear(date.month)){
        date.year--;
        date.month=12;
        date.day=31;
    }else{
        date.month--;
        date.day=NumberOfDaysInMonth(date.year,date.month);
    }
  }else{
    date.day--;
  }
  return date ;
}
stDate DecreaseDateByXDaysForMediumNumbers(stDate date,unsigned short subDays){
    if(subDays==0){
        return date ;
    }

    while (subDays >= date.day){
       unsigned short remainingDaysInCurrentMonth = date.day;
       subDays -= remainingDaysInCurrentMonth ;
       date.month--;
       if (date.month == 0)
       {
        date.month = 12;
        date.year--;
       }    
      date.day = NumberOfDaysInMonth(date.year, date.month);
    }

    date.day-=subDays;
    return date ;  

}
stDate DecreaseDateByXDaysFasterForHugeNumbers (stDate date,unsigned int subDays){
    if (subDays == 0) return date;
    unsigned short dayOfYear = NumberOfDaysFromTheBeginningOfYear(date.year,date.month,date.day);

    while(dayOfYear<=subDays){
        subDays-=dayOfYear ;
        date.year--;
        dayOfYear =(IsLeapYear(date.year)? 366 : 365);
    } 
    dayOfYear-=subDays ;
    return (TakeOrderDayInYearAndconvertToDate(date.year,dayOfYear));
}
stDate DecreaseDateByXDaysForSmallNumbers( stDate Date,unsigned short Days)
{
for (short i = 0; i < Days; i++)
{
   Date = DecreaseDateByOneDay(Date);
}
return Date;
}
stDate DecreaseDateByOneWeek(stDate date){
    return DecreaseDateByXDaysForSmallNumbers (date,7);
}
stDate DecreaseDateByXWeeks(stDate date , unsigned short numberOfWeeks){
    return DecreaseDateByXDaysForMediumNumbers (date,7*numberOfWeeks);
}
stDate DecreaseDateByOneMonth(stDate date){
  if(IsFirstDayInmonth(date.month)){
    date.month=12;
    date.year-- ;

  }else{
    date.month--;
  }
  if(date.day>NumberOfDaysInMonth(date.year,date.month)){
    date.day=NumberOfDaysInMonth(date.year,date.month);
  }
  return date ;
}
stDate DecreaseDateByXMonths(stDate date,unsigned short numberOfMonths){
  for(unsigned short i =0 ;i<numberOfMonths;i++){
      if(IsFirstDayInmonth(date.month)){
    date.month=12;
    date.year-- ;

    }else{
    date.month--;
    }
  }
  if(date.day>NumberOfDaysInMonth(date.year,date.month)){
    date.day=NumberOfDaysInMonth(date.year,date.month);
  }
  return date ;
}
stDate FixLeapDayIfNeededInYearsFunctions(stDate date){
    if(date.month == 2 && date.day == 29 && !IsLeapYear(date.year))
        date.day = 28;
    return date;
}
stDate DecreaseDateByOneYear(stDate date){

  date.year--;
  return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate DecreaseDateByXYears(stDate date,unsigned short numberOfYears){
  bool wasLeapDay = (date.month == 2 && date.day == 29&&IsLeapYear(date.year));
   for(unsigned short  i =0 ; i<numberOfYears;i++ ){
    date=DecreaseDateByOneYear(date);
    }
    if(wasLeapDay && IsLeapYear(date.year)){
      date.day = 29;
     }

  return date ;

}
stDate DecreaseDateByXYearsFaster(stDate date,unsigned short numberOfYears){ 
    date.year-=numberOfYears ;
    return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate DecreaseDateByOneDecade(stDate date){ 
    date.year-=10 ;
   return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate DecreaseDateByXDecades(stDate date,unsigned short numberOfDecade){ 
 bool wasLeapDay = (date.month == 2 && date.day == 29&&IsLeapYear(date.year));
    for(unsigned short  i =0 ; i<numberOfDecade;i++ ){
       date=DecreaseDateByOneDecade(date);
    }
   if(wasLeapDay && IsLeapYear(date.year)){
        date.day = 29;
      }
    return date ;
}
stDate DecreaseDateByXDecadesFaster(stDate date,unsigned short numberOfDecade){ 
    date.year-=(numberOfDecade*10);
  return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate DecreaseDateByOneCentury(stDate date){ 
    date.year-=(100);
  return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate DecreaseDateByOneMillennium(stDate date){ 
    date.year-=(1000);
  return FixLeapDayIfNeededInYearsFunctions(date);

}
int main()
{
stDate Date1 = ReadFullDate();
cout << "\nDate After: \n";
Date1 = DecreaseDateByOneDay(Date1);
cout << "\n01-Substracting one day is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByXDaysForSmallNumbers(Date1,10);
cout << "\n02-Substracting 10 days is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByOneWeek(Date1);
cout << "\n03-Substracting one week is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByXWeeks( Date1,10);
cout << "\n04-Substracting 10 weeks is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByOneMonth(Date1);
cout << "\n05-Substracting one month is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByXMonths( Date1,5);
cout << "\n06-Substracting 5 months is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByOneYear(Date1);
cout << "\n07-Substracting one year is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByXYears( Date1,10);
cout << "\n08-Substracting 10 Years is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByXYearsFaster(Date1,10);
cout << "\n09-Substracting 10 Years (faster) is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByOneDecade(Date1);
cout << "\n10-Substracting one Decade is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByXDecades(Date1,10);
cout << "\n11-Substracting 10 Decades is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByXDecadesFaster( Date1,10);
cout << "\n12-Substracting 10 Decade (faster) is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByOneCentury(Date1);
cout << "\n13-Substracting One Century is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = DecreaseDateByOneMillennium(Date1);
cout << "\n14-Substracting One Millennium is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;

return 0;
}