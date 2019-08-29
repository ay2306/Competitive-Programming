#include<stdio.h>
#include<math.h>
int main()
{
    int x1,y1,x2,y2,x3,y3,n,t;
    long long int bit,nibble,byte;

    scanf("%d",&t);
    while(t>0){
        
        bit =0;
        nibble=0;
        byte=0;
        x1=0;
        y1=2;
        x2=2;
        y2=10;
        x3=10;
        y3=26;
        
        scanf("%d",&n);
        
        for(int i=0;i<=n;i++){
            
           
            
            if(n>x1 && n<=y1){ //comparing n with initial x1=0 and y1=2
                bit = pow(2,i);
                nibble = 0;
                byte = 0;
                break;
            }
            
             if(n>x2 && n<=y2){  //comparing n with initial x2=2 and y2=10
                bit = 0;
                nibble = pow(2,i);
                byte = 0;
                break;
            }
            
             if(n>x3 && n<=y3){ //comparing n with initial x3=10 and y3=26
                bit = 0;
                nibble = 0;
                byte = pow(2,i);
                break;
            }
            
        x1+=26; //increasing x1 to next interval in which bit exists
        y1+=26; //increasing y1 to next interval in which bit exists
        x2+=26; //increasing x2 to next interval in which nibble exists
        y2+=26; //increasing y2 to next interval in which nibble exists
        x3+=26; //increasing x3 to next interval in which byte exists
        y3+=26; //increasing y3 to next interval in which byte exists
}
        
        printf("%lld ",bit);
        printf("%lld ",nibble);
        printf("%lld\n",byte);
        t--;
    }


    return 0;
}
