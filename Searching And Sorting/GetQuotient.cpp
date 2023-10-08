#include<iostream>
using namespace std;

 
   int getQuotient(int dividend,int divisor){
        int s=0;
        int e=dividend;
        int mid=s+(e-s)/2;
        int ans=-1;

        while(s<=e){
            if(mid*divisor==dividend){
                return mid;
            }
            else if(mid*divisor<dividend){
                //store ans
                ans=mid;
                s=mid+1;
            }
            else{
                //move left
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
    return ans;
        
    }

    
    int divide(int dividend, int divisor) {
        // int ans=getQuotient(dividend,divisor);
        int ans=getQuotient(abs(dividend),abs(divisor));
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0) ){
            ans=0-ans;
        }
        return ans;
    }

    int  main(){
        int dividend=7;
        int divisor=-3;
        int ans=divide(dividend,divisor);
        cout<<ans;


        return 0;

    }