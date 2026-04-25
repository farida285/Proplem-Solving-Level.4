/*Write a program to read a date and make a functions
to increase date as follows:
· IncreaseDateByXDays
. IncreaseDateByOneWeek
· IncreaseDateByXWeeks
· IncreaseDateByOneMonth
· IncreaseDateByXMonths
. IncreaseDateByOneyear
. IncreaseDateByXyears
· IncreaseDateByXYearsFaster
· IncreaseDateByOneDecade
· IncreaseDateByXDecades
· IncreaseDateByXDecadesFaster
. IncreaseDateByOneCentury
· IncreaseDateByOneMillennium */
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
stDate IncreaseDateByXDaysForMediumNumbers(stDate date,unsigned short addDays){
    if(addDays==0){
        return date ;
    }
   unsigned short totalDays = NumberOfDaysFromTheBeginningOfYear(date.year,date.month,date.day)+addDays;
   unsigned short daysOfMonth;
   date.month = 1;
   date.day=1 ;
   while(true){
     daysOfMonth =NumberOfDaysInMonth(date.year,date.month) ;
    if(totalDays >daysOfMonth){
        totalDays-=daysOfMonth;
        date.month++;
        date.day=1;
        if(date.month>12){
            date.month=1;
            date.year++;
        }
    }else{
        date.day=totalDays ;
        return date ;
    }
   }
}
stDate IncreaseDateByXDaysFasterForHugeNumbers (stDate date,unsigned int addDays){
    if (addDays == 0) return date;
    unsigned short totalDaysInYear ;
    unsigned short orderDateInYear =NumberOfDaysFromTheBeginningOfYear(date.year,date.month,date.day);
    while (true)
    {
            totalDaysInYear =(IsLeapYear(date.year))? 366 : 365 ;
            if((totalDaysInYear-orderDateInYear)<addDays){
                addDays-=(totalDaysInYear-orderDateInYear+1);
                orderDateInYear = 1;
                date.year++;
            }else{
                orderDateInYear+=addDays ;
                return(TakeOrderDayInYearAndconvertToDate(date.year,orderDateInYear));

            }

    }
    
}
stDate IncreaseDateByXDaysForSmallNumbers( stDate Date,unsigned short Days)
{
for (short i = 1; i <= Days; i++)
{
Date = IncreaseDateByOneDay(Date);
}
return Date;
}
stDate IncreaseDateByOneWeek(stDate date){
    return IncreaseDateByXDaysForSmallNumbers (date,7);
}
stDate IncreaseDateByXWeeks(stDate date , unsigned short numberOfWeeks){
    return IncreaseDateByXDaysForMediumNumbers (date,7*numberOfWeeks);
}
stDate IncreaseDateByOneMonth(stDate date){
  if(IsLastMonthInYear(date.month)){
    date.month=1;
    date.year++;
  }else{
     date.month++;
  }
  //last check day in date should not exceed max days in the current month
// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
// be 28/2/2022
 if(NumberOfDaysInMonth(date.year,date.month)<date.day){
        date.day=NumberOfDaysInMonth(date.year,date.month);
    }
  return date ;

}
stDate IncreaseDateByXMonths(stDate date,unsigned short numberOfMonths){
   for(unsigned short  i =0 ; i<numberOfMonths;i++ ){
       if(IsLastMonthInYear(date.month)){
       date.month=1;
       date.year++;
      }else{
       date.month++;
     }
    }
     if(NumberOfDaysInMonth(date.year,date.month)<date.day){
        date.day=NumberOfDaysInMonth(date.year,date.month);
        }
  return date ;

}
stDate FixLeapDayIfNeededInYearsFunctions(stDate date){
    if(date.month == 2 && date.day == 29 && !IsLeapYear(date.year))
        date.day = 28;
    return date;
}
stDate IncreaseDateByOneYear(stDate date){

    date.year++;
  return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate IncreaseDateByXYears(stDate date,unsigned short numberOfYears){
  bool wasLeapDay = (date.month == 2 && date.day == 29&&IsLeapYear(date.year));
   for(unsigned short  i =0 ; i<numberOfYears;i++ ){
    date=IncreaseDateByOneYear(date);
    }
    if(wasLeapDay && IsLeapYear(date.year)){
      date.day = 29;
     }

  return date ;

}
stDate IncreaseDateByXYearsFaster(stDate date,unsigned short numberOfYears){ 
    date.year+=numberOfYears ;
      return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate IncreaseDateByOneDecade(stDate date){ 
    date.year+=10 ;
   return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate IncreaseDateByXDecades(stDate date,unsigned short numberOfDecade){ 
 bool wasLeapDay = (date.month == 2 && date.day == 29&&IsLeapYear(date.year));
    for(unsigned short  i =0 ; i<numberOfDecade;i++ ){
       date=IncreaseDateByOneDecade(date);
    }
   if(wasLeapDay && IsLeapYear(date.year)){
        date.day = 29;
      }
    return date ;
}
stDate IncreaseDateByXDecadesFaster(stDate date,unsigned short numberOfDecade){ 
    date.year+=(numberOfDecade*10);
  return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate IncreaseDateByOneCentury(stDate date){ 
    date.year+=(100);
  return FixLeapDayIfNeededInYearsFunctions(date);

}
stDate IncreaseDateByOneMillennium(stDate date){ 
    date.year+=(1000);
  return FixLeapDayIfNeededInYearsFunctions(date);

}
int main()
{
stDate Date1 = ReadFullDate();
cout << "\nDate After: \n";
Date1 = IncreaseDateByOneDay(Date1);
cout << "\n01-Adding one day is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByXDaysForSmallNumbers(Date1,10);
cout << "\n02-Adding 10 days is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByOneWeek(Date1);
cout << "\n03-Adding one week is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByXWeeks( Date1,10);
cout << "\n04-Adding 10 weeks is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByOneMonth(Date1);
cout << "\n05-Adding one month is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByXMonths( Date1,5);
cout << "\n06-Adding 5 months is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByOneYear(Date1);
cout << "\n07-Adding one year is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByXYears( Date1,10);
cout << "\n08-Adding 10 Years is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByXYearsFaster(Date1,10);
cout << "\n09-Adding 10 Years (faster) is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByOneDecade(Date1);
cout << "\n10-Adding one Decade is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByXDecades(Date1,10);
cout << "\n11-Adding 10 Decades is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByXDecadesFaster( Date1,10);
cout << "\n12-Adding 10 Decade (faster) is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByOneCentury(Date1);
cout << "\n13-Adding One Century is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;
Date1 = IncreaseDateByOneMillennium(Date1);
cout << "\n14-Adding One Millennium is: "
<< Date1.day << "/" << Date1.month << "/" << Date1.year;

return 0;
}