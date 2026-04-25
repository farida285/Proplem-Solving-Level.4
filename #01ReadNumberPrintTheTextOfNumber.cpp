//Write a program to read a number and print the text of that number.
#include <iostream>
#include <limits>
using namespace std ;
string  Return1_19NumberString (unsigned short number ){
    string arr [20]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
    "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    return (arr[number]);
}
string  Return20_90NumberString (unsigned short number ){
    string arr [10]={"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    return (arr[number]);
}
string ReturnTextNumber (long long  number ){

if(number==0){
    return "Zero";
}

    if(number>=1&&number<=19){
        return (Return1_19NumberString (number));
    }

    if(number>=20&&number<=99){

        if((number%10)==0){
            return( Return20_90NumberString (number/10));
        }else{
            return( Return20_90NumberString (number/10))+" "+ReturnTextNumber (number%10 );
        }  
    }

    if(number>=100&&number<=999){

        if((number%100)==0){    
            if((number/100)==1){
                return("One Hundred");
            } else{
                 return(ReturnTextNumber (number/100)+" Hundreds"); 
            }      
        }else{
           if((number/100)==1){
                return("One Hundred "+ReturnTextNumber((number%100)));
            } else{
                return(ReturnTextNumber (number/100)+" Hundreds "+ReturnTextNumber((number%100)));
            }

        } 
    }

     if(number>=1000&&number<=999999){

        if((number%1000)==0){    
            if((number/1000)==1){
                return("One Thousand");
            } else{
                 return(ReturnTextNumber (number/1000)+" Thousands"); 
            }      
        }else{
           if((number/1000)==1){
                return("One Thousand "+ReturnTextNumber((number%1000)));
            } else{
                return(ReturnTextNumber (number/1000)+" Thousands "+ReturnTextNumber((number%1000)));
            }

        } 
    }

   if(number>=1000000&&number<=999999999){
        if((number%1000000)==0){    
            if((number/1000000)==1){
                return("One Million");
            } else{
                 return(ReturnTextNumber (number/1000000)+" Millions"); 
            }      
        }else{
           if((number/1000000)==1){
                return("One Million "+ReturnTextNumber((number%1000000)));
            } else{
                return(ReturnTextNumber (number/1000000)+" Millions "+ReturnTextNumber((number%1000000)));
            }

        } 

    }
    if(number>=1000000000&&number<=999999999999){
        if((number%1000000000)==0){    
            if((number/1000000000)==1){
                return("One Billion");
            } else{
                 return(ReturnTextNumber (number/1000000000)+" Billions"); 
            }      
        }else{
           if((number/1000000000)==1){
                return("One Billion "+ReturnTextNumber((number%1000000000)));
            } else{
                return(ReturnTextNumber (number/1000000000)+" Billions "+ReturnTextNumber((number%1000000000)));
            }

        } 
    }
     if(number>=1000000000000&&number<=999999999999999){
        if((number%1000000000000)==0){    
            if((number/1000000000000)==1){
                return("One Trillion");
            } else{
                 return(ReturnTextNumber (number/1000000000000)+" Trillions"); 
            }      
        }else{
           if((number/1000000000000)==1){
                return("One Trillion "+ReturnTextNumber((number%1000000000000)));
            } else{
                return(ReturnTextNumber (number/1000000000000)+" Trillions "+ReturnTextNumber((number%1000000000000)));
            }

        } 
    }
    return "";
}
long long ReadlongNumber (const string& message){
      cout<<message ;
    long long number;
do{
    if(!(cin>>number)){
        cin.clear() ;
        cin.ignore(numeric_limits<streamsize>::max(),'\n') ;
        cout<<"Invalid input , Please enter integer number:\n"; 

    }else if(number<0){
        cout<<"Please enter positive number:\n";
    }else{
        return  number ;

    }
}while(true);
 
}
int main (){
 cout<<ReturnTextNumber(ReadlongNumber("Enter number : "));
    return 0;
}