//author PSS
#include<stdio.h>
int arr[3][3];int i,j;

void printarr(){
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            
            if(arr[i][j]==1){printf("X");}
            else if(arr[i][j]==0){printf("O");}
            else{printf(".");}
            if(j<2){printf("|");}
            
        }
        printf("\n");
        if(i<2){printf("------");}
        
    }
}

int inp(int t){
    int x=9;
    if(t%2==0){
        printf("X turn\n");
        x=1;
    }
    else if(t%2!=0){
        printf("O turn\n");
        x=0;
    }
    int row,col;
    printf("Enter row and col: ");
    scanf("%d %d",&row,&col);
    printf("\n");
    if(x!=arr[row][col] && arr[row][col]!=1 && arr[row][col]!=0){
          arr[row][col]=x;
          return 0;
    }
    else{
        printf("Enter another location\n");
        return 1;
    }
    

}

int win_h(){
    //horizontal check
    int x=0,o=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(arr[i][j]==1){
                x+=1;
                
                }
            else if(arr[i][j]==0){
                o+=1;
                
                }
        
        }
        if(x==3){
            printf("X won and O lost");
            return 1;
        }
        else if(o==3){
            printf("O won and X lost");
           return 1;
        }
        x=0;o=0;
    }

}

int win_v(){
    //vertical check
        int x=0,o=0;
    for(j=0;j<3;j++){
        for(i=0;i<3;i++){
            if(arr[i][j]==1){
                x+=1;
                
                }
            else if(arr[i][j]==0){
                o+=1;
                
                }
        
        }
        if(x==3){
            printf("X won and O lost");
            return 1;
        }
        else if(o==3){
            printf("O won and X lost");
           return 1;
        }
        x=0;o=0;
    }
}

int win_d(){
     int x=0,o=0;
     //diagonal check 
    for(i=0;i<3;i++){
         if(arr[i][i]==1){
                x+=1;
                
                }
            else if(arr[i][i]==0){
                o+=1;
                
                }
    }
    if(x==3){
            printf("X won and O lost");
            return 1;
        }
        else if(o==3){
            printf("O won and X lost");
           return 1;
        }
    //diagonal check 2
    x=0,o=0;
 
for(i=2;i>-1;i--){
      if((i-2)>=0){
        j=i-2;
      }
      else{
        j=-1*(i-2);
      }
         if(arr[i][j]==1){
                x+=1;
                
                }
            else if(arr[i][j]==0){
                o+=1;
                
                }
    }
    if(x==3){
            printf("X won and O lost");
            return 1;
        }
        else if(o==3){
            printf("O won and X lost");
           return 1;
        }
}

int draw(){
    int d=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(arr[i][j]!=9){
                  d+=1;
            }
        }
    }
    if(d==9){
        printf("Draw");
        return 1;
    }
}
void main(){
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            arr[i][j]=9;
        }
    }
    
    int t=0;int e=0;
    
    while (draw()!=1 && win_h()!=1 && win_v()!=1 && win_d()!=1){
         e=inp(t);
         printarr();
         if(e!=1){
            t++;
         }
    }


}