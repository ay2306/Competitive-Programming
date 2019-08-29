#include<stdio.h>


int main(){
    struct data{
        char info;
        int show;
    };
    struct data a[26];
    int i;
    char inp,tmp[10000],c;
    int b[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int bd[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int t;
    scanf("%d",&t);
    while(t--){
        for(i = 65; i <= 90; ++i){
        a[i-65].info = (char)i;
        a[i-65].show = 0;
        }

        for(i = 0 ; i <10; i++){
           b[i]=-1;
           bd[i]=-1;
        }
        scanf("%c",&inp);
        do{
            switch(inp){
                case '0': if(b[0]==0)bd[0]=0;b[0]=0;break;
                case '1': if(b[1]==1)bd[1]=1;b[1]=1;break;
                case '2': if(b[2]==2)bd[2]=2;b[2]=2;break;
                case '3': if(b[3]==3)bd[3]=3;b[3]=3;break;
                case '4': if(b[4]==4)bd[4]=4;b[4]=4;break;
                case '5': if(b[5]==5)bd[5]=5;b[5]=5;break;
                case '6': if(b[6]==6)bd[6]=6;b[6]=6;break;
                case '7': if(b[7]==7)bd[7]=7;b[7]=7;break;
                case '8': if(b[8]==8)bd[8]=8;b[8]=8;break;
                case '9': if(b[9]==9)bd[9]=9;b[9]=9;break;

            }
        scanf("%c",&inp);
            //printf("%d",(int)inp);
        }while((int)inp!=10);
        //scanf("%s",&tmp);
        /*for(i = 0; tmp[i]!='\0'; ++i){
            switch(tmp[i]){
                case '0': if(b[0]==0)bd[0]=0;b[0]=0;break;
                case '1': if(b[1]==1)bd[1]=1;b[1]=1;break;
                case '2': if(b[2]==2)bd[2]=2;b[2]=2;break;
                case '3': if(b[3]==3)bd[3]=3;b[3]=3;break;
                case '4': if(b[4]==4)bd[4]=4;b[4]=4;break;
                case '5': if(b[5]==5)bd[5]=5;b[5]=5;break;
                case '6': if(b[6]==6)bd[6]=6;b[6]=6;break;
                case '7': if(b[7]==7)bd[7]=7;b[7]=7;break;
                case '8': if(b[8]==8)bd[8]=8;b[8]=8;break;
                case '9': if(b[9]==9)bd[9]=9;b[9]=9;break;
            }
        }*/
        /*/for(i = 0 ; i <10; i++){
        //    printf("%d\t",b[i]);
        //}*/
        //printf("\n");
        if(b[0]==0){
            if(b[7]==7)a[5].show=1;
            if(b[8]==8)a[15].show=1;
            if(b[9]==9)a[25].show=1;
        }
        if(b[1]==1){
            if(b[7]==7)a[6].show=1;
            if(b[8]==8)a[16].show=1;
        }
        if(b[2]==2){
            if(b[7]==7)a[7].show=1;
            if(b[8]==8)a[17].show=1;
        }
        if(b[3]==3){
            if(b[7]==7)a[8].show=1;
            if(b[8]==8)a[18].show=1;
        }
        if(b[4]==4){
            if(b[7]==7)a[9].show=1;
            if(b[8]==8)a[19].show=1;
        }
        if(b[5]==5){
            if(b[6]==6)a[0].show=1;
            if(b[7]==7)a[10].show=1;
            if(b[8]==8)a[20].show=1;
        }
        //printf("\n%d  %d\n",b[5],b[6]);
        if(b[6]==6){
            if(bd[6]==6)a[1].show=1;
            if(b[7]==7)a[11].show=1;
            if(b[8]==8)a[21].show=1;
        }
        if(b[7]==7){
            if(b[6]==6)a[2].show=1;
            if(bd[7]==7)a[12].show=1;
            if(b[8]==8)a[22].show=1;
        }
        if(b[8]==8){
            if(b[6]==6)a[3].show=1;
            if(b[7]==7)a[13].show=1;
            if(bd[8]==8)a[23].show=1;
        }
        if(b[9]==9){
            if(b[6]==6)a[4].show=1;
            if(b[7]==7)a[14].show=1;
            if(b[8]==8)a[24].show=1;
        }
        for(i = 0; i < 26; ++i){
            if(a[i].show==1){
                c=a[i].info;
                printf("%c",c);
            }
        }
        c=a[13].info;
        printf("\n");
    }
return 0;
}
