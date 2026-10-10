#include <stdio.h>
int main(){
    int len,wid;
    printf("Enter how length and width of rectangle\n");
    scanf("%d %d",&len,&wid);
    for(int i=0;i<wid;i++){
        
            printf("*");
            if (i!=0 && i!=(wid -1)){
                for(int k=0;k<(len-2);k++){
                    printf(" ");
                }
            }
            else{
                for(int k=0;k<(len-2);k++){
                    printf("*");
                }
            }
            printf("*\n");
    




        






    }

}