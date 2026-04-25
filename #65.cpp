//Write a program to read Date and write a function to format that date.
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cctype>
using namespace std ;
struct stDate
{
    unsigned short year;
    unsigned short month;
    unsigned short day;
};
vector<string> SplitWordsInStringVector(string text , string separator =" "){
   int position ;
   string word ;
   vector<string> words ;
    while((position = text.find(separator))!=string::npos){
      word =text.substr(0,position);
      text.erase(0,position+separator.size());
      if(word!=""){
        words.push_back(word);
      }
    }
     if(text!=""){
        words.push_back(text);
      }
    return words ;

}
string  TrimLeft (const string &s1){
 unsigned int size =s1.length();
    for(unsigned int i =0 ;i<size;i++){
        if(s1[i] != ' '){
            return (s1.substr(i,size-i));
        }
    }
    return "";   
}
string  TrimRight (const string &s1){
 unsigned int size =s1.length();
    for(unsigned int i =size-1 ;i>=0;i--){
        if(s1[i] != ' '){
            return (s1.substr(0,i+1));
        }
    }
    return "";   
    
}
string  Trim (const string &s1){

    return (TrimLeft(TrimRight(s1)));   
}
bool IsLeapYear (unsigned short year){
if(year%400==0){
    return 1;
}else if(year%100!=0 && year%4==0){
  return 1;
}
return 0 ;

}
unsigned short NumberOfDaysInMonth(unsigned short year,unsigned short month){
    if(month<1||month>12){
        return 0 ;
    }
  short arr [12]={31,28,31,30,31,30,31,31,30,31,30,31};
  return((month == 2 ) ? ((IsLeapYear(year)) ? 29 : 28 )   :  (arr[month-1]));
}
bool ValideDate (stDate date){
   return(   (date.month>=1&&date.month<=12)  &&    (date.day>=1&&date.day<=NumberOfDaysInMonth(date.year,date.month)) );
}
unsigned short NumberOfSeparotor (string date , string separator){
   int position ;
   unsigned short count = 0 ;
    while((position = date .find(separator))!=string::npos){
      count ++ ;
      date .erase(0,position+separator.size());
    }
    return count ;
}
bool DateStringNumbersOnly( string date,string separator){
   int position ;
    while((position = date .find(separator))!=string::npos){
      date .erase(position,separator.size());
    }
    for(unsigned short i = 0;i<date.size();i++){
       if(!isdigit(date[i])){
        return false ;
       }
    }
    return true ;
}
string ReadStringDate (){

    string date ;
    bool repeat ;
   do{

     cout<<"Please Enter Date In this Format (dd/mm/yyyy) : ";
     getline(cin>>ws,date) ;
     date=Trim(date);
        vector<string> parts = SplitWordsInStringVector(date, "/");
     repeat = NumberOfSeparotor (date,"/")!=2 ? true: ( DateStringNumbersOnly(date,"/"))? (date.length()>=8&&date.length()<=10)? (parts.size() != 3)? true:false :true :true  ;
   }while(repeat);
   return date ;

}
stDate ConvertStringDateToStDate(const string &date){
    stDate stdate ;
    unsigned short number ;
    vector<string> Vdate =SplitWordsInStringVector(date,"/");
    stdate.day=(unsigned short)stoi(Vdate.at(0));
    stdate.month=(unsigned short)stoi(Vdate.at(1));
    stdate.year=(unsigned short)stoi(Vdate.at(2));
    return stdate;
}
string DateToString(const stDate &date){
    return(to_string(date.day)+"/"+to_string(date.month)+"/"+to_string(date.year));
}
string ReplaceWordInString (string s1,string origWord,string newWord,char extraCharSeparator=' ', string extraStringSeparator=""){
   
     size_t  position =0;
      size_t  extrasepLength = extraStringSeparator.size();

    while ((position=s1.find(origWord,position))!=string::npos)
    { 
        bool leftOK=(position==0||(s1[position-1]==' '||s1[position-1]==extraCharSeparator)||(extrasepLength > 0 && position >= extrasepLength &&s1.substr((position-extrasepLength),extrasepLength)==extraStringSeparator));
        size_t  afterWord =position+origWord.size();
        bool rightOk= ( afterWord==s1.size() || (s1[afterWord]==' '|| s1[afterWord]==extraCharSeparator|| (extrasepLength > 0 && s1.substr(afterWord,extrasepLength)==extraStringSeparator))) ;
        if(leftOK&&rightOk){
        s1= s1.replace(position,origWord.size(),newWord);
        position +=newWord.size();
        }else{
            position+=origWord.size();
        }
    
    }
    return s1;

}
string FormatDate(const stDate &date ,string formatDate="dd/mm/yyyy",char CharString='/',string extraStringseparator=""){
    formatDate=ReplaceWordInString(formatDate,"dd",to_string(date.day),CharString,extraStringseparator);
    formatDate=ReplaceWordInString(formatDate,"mm",to_string(date.month),CharString,extraStringseparator);
    formatDate=ReplaceWordInString(formatDate,"yyyy",to_string(date.year),CharString,extraStringseparator);
    return formatDate ;

}
       
int main (){
    string stringDate ;
    stDate date ;
    bool repeat = false ;
 do {
    stringDate =ReadStringDate();
    date =ConvertStringDateToStDate (stringDate);
    if(! ValideDate (date)){
        cout<<"Invalid Date !!!!!\n";
        repeat =true ;
    }else{
        repeat=false ;
    }
 }while(repeat);

 cout<<FormatDate(date)<<endl ;
 cout<<FormatDate(date,"yyyy/dd/mm")<<endl ;
 cout<<FormatDate(date,"mm/dd/yyyy")<<endl ;
 cout<<FormatDate(date,"mm-dd-yyyy",'-')<<endl ;
  cout<<FormatDate(date,"mm dd yyyy")<<endl ;
 cout<<FormatDate(date,"dd-mm-yyyy",'-')<<endl ;
 cout<<FormatDate(date,"Day:dd, Month:mm, Year:yyyy",':',",")<<endl ;

    return 0;
}