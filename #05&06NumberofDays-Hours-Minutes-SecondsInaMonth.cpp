/*Write a program to print Number of:
· Days
. Hours
· Minutes
· Seconds
in a certain Month.*/
#include <iostream>
#include <limits>
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
  unsigned short arr [12]={31,28,31,30,31,30,31,31,30,31,30,31};
  return((month == 2 ) ? ((IsLeapYear(year)) ? 29 : 28 )   :  (arr[month-1]));
}
unsigned short NumberOfHoursInMonth(unsigned short year,unsigned short month){
    return(NumberOfDaysInMonth(year,month)*24);
}
unsigned int NumberOfMinutesInMonth(unsigned short year,unsigned short month){
    return(NumberOfHoursInMonth(year,month)*60);
}
unsigned int NumberOfSecondsInMonth(unsigned short year,unsigned short month){
    return(NumberOfMinutesInMonth(year,month)*60);
}
void PrintDaysHoursMinSecInMonth (unsigned short year,unsigned short month){

    cout<<"Number of days    in month ["<<month<<"] is "<<NumberOfDaysInMonth(year,month)<<endl ;
    cout<<"Number of hours   in month ["<<month<<"] is "<<NumberOfHoursInMonth(year,month)<<endl ;
    cout<<"Number of minutes in month ["<<month<<"] is "<<NumberOfMinutesInMonth(year,month)<<endl ;
    cout<<"Number of seconds in month ["<<month<<"] is "<<NumberOfSecondsInMonth(year,month)<<endl ;
}
int main (){
    unsigned short year =ReadPositiveNumberInRange("Enter the year : ","Invalid input! Please enter a number of year.",1,2026);
    unsigned short month =ReadPositiveNumberInRange("Enter the number of month : ","Invalid input! Please enter a number of month.",1,12) ;
    PrintDaysHoursMinSecInMonth(year,month);
    return 0 ;
}