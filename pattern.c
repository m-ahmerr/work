//prints:
//    *
//   ***
//  *****
// *******


#include <stdio.h>
int main(){
    int n,space,count =1;
    printf("Enter how many lines of pattern you want\n");
    scanf("%d",&n);
    space = n;
    for (int i =0 ;i<n;i++){
        space--;
        
        for(int z=0;z<space;z++){
            printf(" ");
        }
        for(int w=1;w<=count;w++){
            printf("*");
        }
        count+=2;
        
        printf("\n"); 





    }


    
}
