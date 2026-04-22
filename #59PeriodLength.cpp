//Write a program to read a Period and calculate period length in days?
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

struct stPeriod {
    stDate startDate ;
    stDate endDate ;
} ;
enum enCompareResult {Before=-1,Equal,After};   

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

bool CheckDate1EqualThanDate2(stDate date1,stDate date2){

    return ((date1.year==date2.year)? ((date1.month==date2.month)? ((date1.day==date2.day)? true:false ):false) :false);
}
bool CheckDate1LessThanDate2(stDate date1, stDate date2) {
    if (date1.year < date2.year)  return true;
    if (date1.year > date2.year)  return false;
    if (date1.month < date2.month) return true;
    if (date1.month > date2.month) return false;
    return date1.day < date2.day;
}
bool CheckDate1AfterDate2 (stDate date1, stDate date2){
    return(!CheckDate1EqualThanDate2(date1,date2)&&!CheckDate1LessThanDate2(date1,date2)) ;
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
void SwapDates (stDate &date1, stDate &date2){
    stDate temp ;
    temp.year = date1.year;
    temp.month= date1.month;
    temp.day  =date1 .day ;
    date1.year  =date2.year ;
    date1.month =date2.month;
    date1.day   =date2.day;
    date2.year  =temp.year ;
    date2.month =temp.month;
    date2.day   =temp.day;

}
int  GetDifferenceInDays (stDate date1, stDate date2,bool includeEndDay=false){
    int  days=0;
    short swapFlag =1 ;
    if(CheckDate1LessThanDate2(date2,date1)){
       SwapDates(date1,date2) ;
       swapFlag=-1 ;
    }
    if(CheckDate1LessThanDate2(date1,date2)) {
        while (CheckDate1LessThanDate2(date1,date2))
        {
            date1=IncreaseDateByOneDay(date1);
            days++;
        }
             return ((includeEndDay)? ++days*swapFlag  : days*swapFlag ) ;
    }
    return (days) ;
  
}
stPeriod ReadPeriod (){
    stPeriod per ;
    cout<<"Enter Start Date :\n";
    per.startDate = ReadFullDate() ;
    cout<<"Enter End Date :\n";
    per.endDate = ReadFullDate();
    if( CheckDate1AfterDate2 (per.startDate, per.endDate )){
        SwapDates(per.startDate, per.endDate );
    }
    return per ;
}
enCompareResult CompareDate1WithDate2 (stDate date1, stDate date2){
    return (CheckDate1LessThanDate2(date1,date2)? enCompareResult::Before : (CheckDate1EqualThanDate2(date1,date2))? enCompareResult::Equal : enCompareResult::After);
}
bool CheckPeriodsOverlap(stPeriod period1,stPeriod period2){
    return(!((CompareDate1WithDate2(period1.endDate,period2.startDate)==enCompareResult::Before)||
             (CompareDate1WithDate2(period1.startDate,period2.endDate)==enCompareResult::After) )  );
}
int PreiodLength(stPeriod period ,bool IncludeEndDay =false){
       return GetDifferenceInDays(period.startDate,period.endDate,IncludeEndDay);
  
}
int main (){
    cout<<"Enter Period 1 :\n";
    stPeriod period1=ReadPeriod();
    cout <<"Period length include end day = "<<PreiodLength(period1,true)<<endl ;
    cout<<"Period length exclude end day = "<<PreiodLength(period1)<<endl ;
    return 0;
}