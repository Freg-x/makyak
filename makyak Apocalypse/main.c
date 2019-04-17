#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// board information
#define BOARD_SIZE 12
#define EMPTY 0
#define BLACK 1
#define WHITE 2

// bool
typedef int BOOL;
#define TRUE 1
#define FALSE 0

// option
typedef int OPTION;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_RIGHT 7

#define MAX_BYTE 10000

#define START "START"
#define PLACE "PLACE"
#define TURN  "TURN"
#define END   "END"

struct Command
{
    int x;
    int y;
    OPTION option;
};

char buffer[MAX_BYTE] = {0};
char board[BOARD_SIZE][BOARD_SIZE] = {0};
int me_flag;
int other_flag;

const int DIR[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

void debug(const char *str) {
    printf("DEBUG %s\n", str);
    fflush(stdout);
}

void printBoard() {
    char visual_board[BOARD_SIZE][BOARD_SIZE] = {0};
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                visual_board[i][j] = '.';
            } else if (board[i][j] == BLACK) {
                visual_board[i][j] = 'O';
            } else if (board[i][j] == WHITE) {
                visual_board[i][j] = 'X';
            }
        }
        printf("%s\n", visual_board[i]);
    }
}

BOOL isInBound(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

/*
 * YOUR CODE BEGIN
 * ÄãµÄ´úÂë¿ªÊ¼
 */

/*
 * You can define your own struct and variable here
 * Äã¿ÉÒÔÔÚÕâÀï¶¨ÒåÄã×Ô¼ºµÄ½á¹¹ÌåºÍ±äÁ¿
 */

struct Board{
    char my_board[BOARD_SIZE][BOARD_SIZE];
};   //define this to return an array




struct Command NextStep={0,0,0};


int BlackValue[BOARD_SIZE][BOARD_SIZE]={
    {-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8},
    {-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8},
    {-8,-8,-8,-8,-1,-1,-1,-1,-1,-1,-1,-1},
    {-8,-8,-8,-8,-1,3,3,3,3,-5,-1,3},
    {-8,-8,-8,-8,-1,3,3,3,8,3,3,3},
    {-8,-8,-8,-8,-1,3,8,8,8,8,3,3},
    {-8,-8,-8,-8,-1,3,8,10,10,8,3,3},
    {-8,-8,-8,-8,-1,3,8,10,10,8,3,3},
    {-8,-8,-8,-8,-1,3,8,8,8,8,3,3},
    {-8,-8,-8,-8,-1,3,3,-3,-5,3,3,3},
    {-8,-8,-8,-8,-1,-1,-1,-1,-1,-1,-1,-1},
    {-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8}
};






void message(){
    int message1; /*带哥，这儿没源码，要看加QQ:1093893470交流哦*/
}









int MYMatrix(const char board[BOARD_SIZE][BOARD_SIZE],int flag,int x,int y){
    int count=0;int otherflag=3-flag;
    
    if(isInBound(x,y-2))
    {
        if(board[x][y-1]==otherflag&&board[x][y-1]==0){
            if(isInBound(x-1,y-1)&&board[x-1][y-1]==flag)count+=5;
            if(isInBound(x-1,y-2)&&board[x-1][y-2]==flag)count+=5;
            if(isInBound(x-1,y-3)&&board[x-1][y-3]==flag)count+=5;
            if(isInBound(x,y-3)&&board[x][y-3]==flag)count+=5;
            if(isInBound(x+1,y-3)&&board[x+1][y-3]==flag)count+=5;
            if(isInBound(x+1,y-2)&&board[x+1][y-2]==flag)count+=5;
            if(isInBound(x+1,y-1)&&board[x+1][y-1]==flag)count+=5;
            
        }
        else{
            if(board[x][y-1]==0)
            {
                if(isInBound(x-1,y-1)&&board[x-1][y-1]==otherflag&&isInBound(x+1,y-1)&&board[x+1][y-1]==otherflag)count+=10;
                if(isInBound(x-1,y-2)&&board[x-1][y-2]==otherflag&&isInBound(x-1,y-2)&&board[x-1][y-2]==otherflag)count+=10;
                if(isInBound(x-1,y)&&board[x-1][y]==otherflag&&isInBound(x+1,y-2)&&board[x+1][y-2]==otherflag)count+=10;
            }
            
            
            
        }
        
        
    }
    
    if(isInBound(x-2,y-2)){
        if(board[x-1][y-1]==otherflag&&board[x-2][y-2]==0){
            
            
            if(isInBound(x-2,y-1)&&board[x-2][y-1]==flag)count+=5;
            if(isInBound(x-3,y-1)&&board[x-3][y-1]==flag)count+=5;
            if(isInBound(x-3,y-2)&&board[x-3][y-2]==flag)count+=5;
            if(isInBound(x-3,y-3)&&board[x-3][y-3]==flag)count+=5;
            if(isInBound(x-2,y-3)&&board[x-2][y-3]==flag)count+=5;
            if(isInBound(x-1,y-3)&&board[x-1][y-3]==flag)count+=5;
            if(isInBound(x-1,y-2)&&board[x-1][y-2]==flag)count+=5;}
        
        else if(board[x-1][y-1]==0){
            if(isInBound(x-2,y-1)&&board[x-2][y-1]==otherflag&&isInBound(x,y-1)&&board[x][y-1]==otherflag)count+=10;
            if(isInBound(x-2,y)&&board[x-2][y]==otherflag&&isInBound(x,y-2)&&board[x][y-2]==otherflag)count+=10;
            if(isInBound(x-1,y-2)&&board[x-1][y-2]==otherflag&&isInBound(x-1,y)&&board[x-1][y]==otherflag)count+=10;
            
        }
        
        
        
        
    }
    
    if(isInBound(x-2,y)){
        if(board[x-1][y]==otherflag&&board[x-2][y]==0){
            
            
            if(isInBound(x-1,y+1)&&board[x-1][y+1]==flag)count+=5;
            if(isInBound(x-2,y+1)&&board[x-2][y+1]==flag)count+=5;
            if(isInBound(x-3,y+1)&&board[x-3][y+1]==flag)count+=5;
            if(isInBound(x-3,y)&&board[x-3][y]==flag)count+=5;
            if(isInBound(x-3,y-1)&&board[x-3][y-1]==flag)count+=5;
            if(isInBound(x-2,y-1)&&board[x-2][y-1]==flag)count+=5;
            if(isInBound(x-1,y-1)&&board[x-1][y-1]==flag)count+=5;}
        
        else if(board[x-1][y]==0){
            if(isInBound(x-1,y-1)&&board[x-1][y-1]==otherflag&&isInBound(x-1,y+1)&&board[x-1][y+1]==otherflag)count+=10;
            if(isInBound(x-2,y-1)&&board[x-2][y-1]==otherflag&&isInBound(x,y+1)&&board[x][y+1]==otherflag)count+=10;
            if(isInBound(x-2,y+1)&&board[x-2][y+1]==otherflag&&isInBound(x,y-1)&&board[x][y-1]==otherflag)count+=10;
            
            
            
        }
        
    }
    
    if(isInBound(x-2,y+2)){
        if(board[x-1][y+1]==otherflag&&board[x-2][y+2]==0){
            if(isInBound(x-2,y+1)&&board[x-2][y+1]==flag)count+=5;
            if(isInBound(x-3,y+1)&&board[x-3][y+1]==flag)count+=5;
            if(isInBound(x-3,y+2)&&board[x-3][y+2]==flag)count+=5;
            if(isInBound(x-3,y+3)&&board[x-3][y+3]==flag)count+=5;
            if(isInBound(x-2,y+3)&&board[x-2][y+3]==flag)count+=5;
            if(isInBound(x-1,y+3)&&board[x-1][y+3]==flag)count+=5;
            if(isInBound(x-1,y+2)&&board[x-1][y+2]==flag)count+=5;}
        else if(board[x-1][y+1]==0){
            if(isInBound(x-1,y)&&board[x-1][y]==otherflag&&isInBound(x-1,y+2)&&board[x-1][y+2]==otherflag)count+=10;
            if(isInBound(x-2,y)&&board[x-2][y]==otherflag&&isInBound(x,y+2)&&board[x][y+2]==otherflag)count+=10;
            if(isInBound(x-2,y+1)&&board[x-2][y+1]==otherflag&&isInBound(x,y+1)&&board[x][y+1]==otherflag)count+=10;
            
            
        }
        
        
        
    }
    
    if(isInBound(x,y+2)){
        
        if(board[x][y+1]==otherflag&&board[x][y+2]==0){
            if(isInBound(x+1,y+1)&&board[x+1][y+1]==flag)count+=5;
            if(isInBound(x+1,y+2)&&board[x+1][y+2]==flag)count+=5;
            if(isInBound(x+1,y+3)&&board[x+1][y+3]==flag)count+=5;
            if(isInBound(x,y+3)&&board[x][y+3]==flag)count+=5;
            if(isInBound(x-1,y+3)&&board[x-1][y+3]==flag)count+=5;
            if(isInBound(x-1,y+2)&&board[x-1][y+2]==flag)count+=5;
            if(isInBound(x-1,y+1)&&board[x-1][y+1]==flag)count+=5;}
        
        else if(board[x][y+1]==0){
            if(isInBound(x-1,y+1)&&board[x-1][y+1]==otherflag&&isInBound(x+1,y+1)&&board[x+1][y+1]==otherflag)count+=10;
            if(isInBound(x-1,y)&&board[x-1][y]==otherflag&&isInBound(x+1,y+2)&&board[x+1][y+2]==otherflag)count+=10;
            if(isInBound(x-1,y+2)&&board[x-1][y+2]==otherflag&&isInBound(x+1,y)&&board[x+1][y]==otherflag)count+=10;
            
            
        }
        
    }
    
    if(isInBound(x+2,y+2)){
        if(board[x+1][y+1]==otherflag&&board[x+2][y+2]==0){
            if(isInBound(x+2,y+1)&&board[x+2][y+1]==flag)count+=5;
            if(isInBound(x+1,y+2)&&board[x+1][y+2]==flag)count+=5;
            if(isInBound(x+1,y+3)&&board[x+1][y+3]==flag)count+=5;
            if(isInBound(x+2,y+3)&&board[x+2][y+3]==flag)count+=5;
            if(isInBound(x+3,y+3)&&board[x+3][y+3]==flag)count+=5;
            if(isInBound(x+3,y+2)&&board[x+3][y+2]==flag)count+=5;
            if(isInBound(x+3,y+1)&&board[x+3][y+1]==flag)count+=5;}
        else if(board[x+1][y+1]==0){
            if(isInBound(x,y+1)&&board[x][y+1]==otherflag&&isInBound(x+2,y+1)&&board[x+2][y+1]==otherflag)count+=10;
            if(isInBound(x,y+2)&&board[x][y+2]==otherflag&&isInBound(x+2,y)&&board[x+2][y]==otherflag)count+=10;
            if(isInBound(x+1,y)&&board[x+1][y]==otherflag&&isInBound(x+1,y+2)&&board[x+1][y+2]==otherflag)count+=10;
            
            
        }
    }
    
    if(isInBound(x+2,y)){
        if(board[x+1][y]==otherflag&&board[x+2][y]==0){
            if(isInBound(x+1,y+1)&&board[x+1][y+1]==flag)count+=5;
            if(isInBound(x+2,y+1)&&board[x+2][y+1]==flag)count+=5;
            if(isInBound(x+3,y+1)&&board[x+3][y+1]==flag)count+=5;
            if(isInBound(x+3,y)&&board[x+3][y]==flag)count+=5;
            if(isInBound(x+3,y-1)&&board[x+3][y-1]==flag)count+=5;
            if(isInBound(x+2,y-1)&&board[x+2][y-1]==flag)count+=5;
            if(isInBound(x+1,y-1)&&board[x+1][y-1]==flag)count+=5;}
        
        else if(board[x+1][y]==0){
            if(isInBound(x,y+1)&&board[x][y+1]==otherflag&&isInBound(x+2,y-1)&&board[x+2][y-1]==otherflag)count+=10;
            if(isInBound(x+1,y-1)&&board[x+1][y-1]==otherflag&&isInBound(x+1,y+1)&&board[x+1][y+1]==otherflag)count+=10;
            if(isInBound(x,y-1)&&board[x][y-1]==otherflag&&isInBound(x+2,y+1)&&board[x+2][y+1]==otherflag)count+=10;
            
        }
    }
    
    if(isInBound(x+2,y-2)){
        if(board[x+1][y-1]==otherflag&&board[x+2][y-2]==0){
            if(isInBound(x+1,y-2)&&board[x+1][y-2]==flag)count+=5;
            if(isInBound(x+1,y-3)&&board[x+1][y-3]==flag)count+=5;
            if(isInBound(x+2,y-3)&&board[x+2][y-3]==flag)count+=5;
            if(isInBound(x+3,y-3)&&board[x+3][y-3]==flag)count+=5;
            if(isInBound(x+3,y-2)&&board[x+3][y-2]==flag)count+=5;
            if(isInBound(x+3,y-1)&&board[x+3][y-1]==flag)count+=5;
            if(isInBound(x+2,y-1)&&board[x+2][y-1]==flag)count+=5;}
        
        else if(board[x+1][y-1]==0){
            if(isInBound(x,y-1)&&board[x][y-1]==otherflag&&isInBound(x+2,y-1)&&board[x+2][y-1]==otherflag)count+=10;
            if(isInBound(x+1,y-2)&&board[x+1][y-2]==otherflag&&isInBound(x+1,y)&&board[x+1][y]==otherflag)count+=10;
            if(isInBound(x,y-2)&&board[x][y-2]==otherflag&&isInBound(x+2,y)&&board[x+2][y]==otherflag)count+=10;
            
            
        }
        
        
        
    }
    
    return count;
    
}



int Position(const char board[BOARD_SIZE][BOARD_SIZE],int flag,int x,int y){
    int count=0;
    if(flag==1)count=count+BlackValue[x][y];
    else count=count+BlackValue[11-x][11-y];
    return count;
}










int evaluate(const char board[BOARD_SIZE][BOARD_SIZE],int flag){
    int count=0,i,j;
    
    for(i=1;i<BOARD_SIZE-1;i++)
        for(j=1;j<BOARD_SIZE-1;j++)
        {if(board[i][j]==flag){
            count+=3000;  //how many do i have
            count=count+MYMatrix(board,flag,i,j)+Position(board,flag,i,j);
            
            
        }
            
        }
    
    return count;
}

int evaluate_6(const char board[BOARD_SIZE][BOARD_SIZE],int flag){
    int count=0,i,j;
    
    for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {if(board[i][j]==flag){
            count+=3000;  //how many do i have
            
            
            
        }
            
        }
    
    return count;
}





struct Board renew(int x,int y,int dir,const char board[BOARD_SIZE][BOARD_SIZE]){
    struct Board newboard;  //used for return
    
    int i,j,k;
    
    int flag=board[x][y];
    int otherflag=3-flag;
    
    int new_x=x+DIR[dir][0];
    int new_y=y+DIR[dir][1];
    
    for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)newboard.my_board[i][j]=board[i][j];
            newboard.my_board[x][y]=0;
            newboard.my_board[new_x][new_y]=flag;
            
            //yak
            
            if(isInBound(new_x-1, new_y-1)&&isInBound(new_x+1,new_y+1)&&newboard.my_board[new_x-1][new_y-1]==otherflag&&newboard.my_board[new_x+1][new_y+1]==otherflag)
            {newboard.my_board[new_x-1][new_y-1]=newboard.my_board[new_x+1][new_y+1]=flag;}
    
    if(isInBound(new_x+1, new_y-1)&&isInBound(new_x-1,new_y+1)&&newboard.my_board[new_x+1][new_y-1]==otherflag&&newboard.my_board[new_x-1][new_y+1]==otherflag)
    {newboard.my_board[new_x+1][new_y-1]=newboard.my_board[new_x-1][new_y+1]=flag;}
    
    if(isInBound(new_x-1, new_y)&&isInBound(new_x+1,new_y)&&newboard.my_board[new_x-1][new_y]==otherflag&&newboard.my_board[new_x+1][new_y]==otherflag)
    {newboard.my_board[new_x-1][new_y]=newboard.my_board[new_x+1][new_y]=flag;}
    
    if(isInBound(new_x, new_y-1)&&isInBound(new_x,new_y+1)&&newboard.my_board[new_x][new_y-1]==otherflag&&newboard.my_board[new_x][new_y+1]==otherflag)
    {newboard.my_board[new_x][new_y-1]=newboard.my_board[new_x][new_y+1]=flag;}
    
    //mak
    
    for(k=0;k<8;k++){if(isInBound(new_x+2*DIR[k][0], new_y+2*DIR[k][1])&&newboard.my_board[new_x+DIR[k][0]][new_y+DIR[k][1]]==otherflag&&newboard.my_board[new_x+2*DIR[k][0]][new_y+2*DIR[k][1]]==flag)
        newboard.my_board[new_x+DIR[k][0]][new_y+DIR[k][1]]=flag;
    }
    
    return newboard;
    
}








int alpha_beta(const char board[BOARD_SIZE][BOARD_SIZE],int h,int player,int alpha,int beta,int start){
    if(h==5||clock()-start>1975)return evaluate(board,player);
    
    
    int i,j,k,ans;
    
    
    if(h==1){for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j]==player){
                for(k=0;k<8;k++)
                    if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0)
                    {ans=alpha_beta(renew(i,j,k,board).my_board,h+1,player,alpha,beta,start);
                        if(ans>alpha){alpha=ans;NextStep.x=i;NextStep.y=j;NextStep.option=k;}
                        if(alpha>=beta)return alpha;
                    }
            }
            
        }
        return alpha;
    }
    
    
    
    
    
    if(h%2==1){for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j]==player){
                for(k=0;k<8;k++)
                    if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0)
                    {ans=alpha_beta(renew(i,j,k,board).my_board,h+1,player,alpha,beta,start);
                        if(ans>alpha)alpha=ans;
                        if(alpha>=beta)return alpha;
                    }
            }
            
        }
        return alpha;
    }
    
    else{for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {if(board[i][j]==3-player){
            for(k=0;k<8;k++)if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0){
                ans=alpha_beta(renew(i,j,k,board).my_board,h+1,player,alpha,beta,start);
                if(ans<beta)beta=ans;
                if(alpha>=beta)return beta;
            }
            
            
        }
            
            
        }
        return beta;
        
    }
    
    
    
}





int alpha_beta_less(const char board[BOARD_SIZE][BOARD_SIZE],int h,int player,int alpha,int beta,int depth){
    if(h==depth)return evaluate(board,player);
    
    
    int i,j,k,ans;
    
    
    if(h==1){for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j]==player){
                for(k=0;k<8;k++)
                    if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0)
                    {ans=alpha_beta_less(renew(i,j,k,board).my_board,h+1,player,alpha,beta,depth);
                        if(ans>alpha){alpha=ans;NextStep.x=i;NextStep.y=j;NextStep.option=k;}
                        if(alpha>=beta)return alpha;
                    }
            }
            
        }
        return alpha;
    }
    
    
    
    
    
    if(h%2==1){for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j]==player){
                for(k=0;k<8;k++)
                    if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0)
                    {ans=alpha_beta_less(renew(i,j,k,board).my_board,h+1,player,alpha,beta,depth);
                        if(ans>alpha)alpha=ans;
                        if(alpha>=beta)return alpha;
                    }
            }
            
        }
        return alpha;
    }
    
    else{for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {if(board[i][j]==3-player){
            for(k=0;k<8;k++)if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0){
                ans=alpha_beta_less(renew(i,j,k,board).my_board,h+1,player,alpha,beta,depth);
                if(ans<beta)beta=ans;
                if(alpha>=beta)return beta;
            }
            
            
        }
            
            
        }
        return beta;
        
    }
    
    
    
}


int alpha_beta_6(const char board[BOARD_SIZE][BOARD_SIZE],int h,int player,int alpha,int beta,int start){
    if(h==6||clock()-start>1975)return evaluate_6(board,player);
    
    
    int i,j,k,ans;
    
    
    if(h==1){for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j]==player){
                for(k=0;k<8;k++)
                    if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0)
                    {ans=alpha_beta_6(renew(i,j,k,board).my_board,h+1,player,alpha,beta,start);
                        if(ans>alpha){alpha=ans;NextStep.x=i;NextStep.y=j;NextStep.option=k;}
                        if(alpha>=beta)return alpha;
                    }
            }
            
        }
        return alpha;
    }
    
    
    
    
    
    if(h%2==1){for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j]==player){
                for(k=0;k<8;k++)
                    if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0)
                    {ans=alpha_beta_6(renew(i,j,k,board).my_board,h+1,player,alpha,beta,start);
                        if(ans>alpha)alpha=ans;
                        if(alpha>=beta)return alpha;
                    }
            }
            
        }
        return alpha;
    }
    
    else{for(i=0;i<BOARD_SIZE;i++)
        for(j=0;j<BOARD_SIZE;j++)
        {if(board[i][j]==3-player){
            for(k=0;k<8;k++)if(isInBound(i+DIR[k][0], j+DIR[k][1])&&board[i+DIR[k][0]][j+DIR[k][1]]==0){
                ans=alpha_beta_6(renew(i,j,k,board).my_board,h+1,player,alpha,beta,start);
                if(ans<beta)beta=ans;
                if(alpha>=beta)return beta;
            }
            
            
        }
            
            
        }
        return beta;
        
    }
    
    
    
}





/*
 * ÂÖµ½ÄãÂä×Ó¡£
 * ÆåÅÌÉÏ0±íÊ¾¿Õ°×£¬1±íÊ¾ºÚÆå£¬2±íÊ¾°×Æì
 * me±íÊ¾ÄãËù´ú±íµÄÆå×Ó(1»ò2)
 * ÄãÐèÒª·µ»ØÒ»¸ö½á¹¹ÌåPosition£¬ÔÚxÊôÐÔºÍyÊôÐÔÌîÉÏÄãÏëÒªÂä×ÓµÄÎ»ÖÃ¡£
 */
struct Command aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me,int tcount) {
    clock_t start=clock();
    if(tcount==59&&me==1){alpha_beta_less(board,1,me,0,60000,3);return NextStep;}
    if(tcount==58&&me==2){alpha_beta_less(board,1,me,0,60000,4);return NextStep;}
    if(tcount==59&&me==2){alpha_beta_less(board,1,me,0,60000,2);return NextStep;}
    if(tcount==57&&me==2){alpha_beta_6(board,1,me,0,60000,start);return NextStep;}
    alpha_beta(board,1,me,0,60000,start);
    
    return NextStep;
}








BOOL place(int x, int y, OPTION option, int cur_flag) {
    // ç§»åŠ¨ä¹‹å‰çš„ä½ç½®æ²¡æœ‰æˆ‘æ–¹æ£‹å­
    if (board[x][y] != cur_flag) {
        return FALSE;
    }
    
    int new_x = x + DIR[option][0];
    int new_y = y + DIR[option][1];
    // ç§»åŠ¨ä¹‹åŽçš„ä½ç½®è¶…å‡ºè¾¹ç•Œ, æˆ–è€…ä¸æ˜¯ç©ºåœ°
    if (!isInBound(new_x, new_y) || board[new_x][new_y] != EMPTY) {
        return FALSE;
    }
    
    board[x][y] = EMPTY;
    board[new_x][new_y] = cur_flag;
    
    int cur_other_flag = 3 - cur_flag;
    
    // æŒ‘
    int intervention_dir[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    for (int i = 0; i < 4; i++) {
        int x1 = new_x + intervention_dir[i][0];
        int y1 = new_y + intervention_dir[i][1];
        int x2 = new_x - intervention_dir[i][0];
        int y2 = new_y - intervention_dir[i][1];
        if (isInBound(x1, y1) && isInBound(x2, y2) && board[x1][y1] == cur_other_flag && board[x2][y2] == cur_other_flag) {
            board[x1][y1] = cur_flag;
            board[x2][y2] = cur_flag;
        }
    }
    
    // å¤¹
    int custodian_dir[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    for (int i = 0; i < 8; i++) {
        int x1 = new_x + custodian_dir[i][0];
        int y1 = new_y + custodian_dir[i][1];
        int x2 = new_x + custodian_dir[i][0] * 2;
        int y2 = new_y + custodian_dir[i][1] * 2;
        if (isInBound(x1, y1) && isInBound(x2, y2) && board[x2][y2] == cur_flag && board[x1][y1] == cur_other_flag) {
            board[x1][y1] = cur_flag;
        }
    }
    
    return TRUE;
}


//........
//........
//..XXXX..
//XXXX....
//....OOOO
//..OOOO..
//........
//........
void start(int flag) {
    memset(board, 0, sizeof(board));
    
    for (int i = 0; i < 3; i++) {
        board[2][2 + i] = WHITE;
        board[6][6 + i] = WHITE;
        board[5][3 + i] = BLACK;
        board[9][7 + i] = BLACK;
    }
    
    for (int i = 0; i < 2; i++) {
        board[8 + i][2] = WHITE;
        board[2 + i][9] = BLACK;
    }
    
    
}

void turn(int tcount) {
    // AI
    struct Command command = aiTurn((const char (*)[BOARD_SIZE])board, me_flag,tcount);
    place(command.x, command.y, command.option, me_flag);
    printf("%d %d %d\n", command.x, command.y, command.option);
    fflush(stdout);
}

void end(int x) {
    
}

void loop() {int tcount=0;
    //  freopen("../input", "r", stdin);
    while (TRUE)
    {
        memset(buffer, 0, sizeof(buffer));
        gets(buffer);
        
        if (strstr(buffer, START))
        {
            char tmp[MAX_BYTE] = {0};
            sscanf(buffer, "%s %d", tmp, &me_flag);
            other_flag = 3 - me_flag;
            start(me_flag);
            printf("OK\n");
            fflush(stdout);
        }
        else if (strstr(buffer, PLACE))
        {
            char tmp[MAX_BYTE] = {0};
            int x, y;
            OPTION option;
            sscanf(buffer, "%s %d %d %d", tmp, &x, &y, &option);
            place(x, y, option, other_flag);
        }
        else if (strstr(buffer, TURN))
        {
            turn(tcount);
            tcount++;
        }
        else if (strstr(buffer, END))
        {
            char tmp[MAX_BYTE] = {0};
            int x;
            sscanf(buffer, "%s %d", tmp, &x);
            end(x);
        }
        //    printBoard();
    }
}


int main(int argc, char *argv[]) {
    loop();
    return 0;
}

