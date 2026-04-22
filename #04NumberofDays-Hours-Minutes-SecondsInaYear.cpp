/*Write a program to print Number of:
· Days
. Hours
· Minutes
· Seconds
in a certain Year.*/
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
unsigned short ReadYearInRange (const string &message , unsigned  short from ,unsigned   short to ){
    int number ;

    do{
        cout<<message;
        if (!(cin >> number))  
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number of year.\n";
        }else if(number<from||number>to){
            cout<<"Unavailable number!!\n" ;
            cout<<"Enter year in range from "<<from<<" to "<<to<<".\n";
        }else{
             return (unsigned short)number ;
        }
    }while(true);
   
}
unsigned short NumberOfDaysInYear(unsigned short year){
    return((IsLeapYear(year))? 366:365);
}
unsigned short NumberOfHoursInYear(unsigned short year){
    return(NumberOfDaysInYear(year)*24);
}
unsigned int NumberOfMinutesInYear(unsigned short year){
    return(NumberOfHoursInYear(year)*60);
}
unsigned int NumberOfSecondsInYear(unsigned short year){
    return(NumberOfMinutesInYear(year)*60);
}
void PrintDaysHoursMinSecInYear (unsigned short year){

    cout<<"Number of days    in year ["<<year<<"] is "<<NumberOfDaysInYear(year)<<endl ;
    cout<<"Number of hours   in year ["<<year<<"] is "<<NumberOfHoursInYear(year)<<endl ;
    cout<<"Number of minutes in year ["<<year<<"] is "<<NumberOfMinutesInYear(year)<<endl ;
    cout<<"Number of seconds in year ["<<year<<"] is "<<NumberOfSecondsInYear(year)<<endl ;
}
int main (){
    PrintDaysHoursMinSecInYear(ReadYearInRange("Enter the Year :",1,2026));
    return 0 ;
}