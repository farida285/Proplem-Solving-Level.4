#include <iostream>
#include <limits>
using namespace std ;
bool IsLeapYear (unsigned short year){

  return (year%400==0||(year%100!=0 && year%4==0));

}
unsigned short ReadYearInRange (const string &message ,unsigned  short from ,unsigned  short to ){
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
int main (){
    if(IsLeapYear(ReadYearInRange("Enter the year : ",1,2026))){
        cout << "Is Leap Year.\n";
    }else{
         cout << "Is Not Leap Year.\n";
    }
    return 0 ;
}