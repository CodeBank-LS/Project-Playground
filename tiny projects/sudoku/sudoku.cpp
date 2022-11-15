//A sudoku game that take input to generate board
//check the value fill in grid
//and solve the game by itself
#include <iostream>
#include<stdio.h>
using namespace std;
int P[9][9];
bool flag = false;
// 处理输入 
void input(){
    char t;
    cout << "enter board，use 0 as empty\n";
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            cin >> t;
            P[i][j] = t - '0';
        }
    }
}
//output
void output(){
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            if(P[i][j]){
                cout << P[i][j];    
            }else{
                cout << " ";
            }
            if(j%3 == 2) cout << "  ";
        }
        if(i%3 == 2) cout << endl;
        cout << endl;
    }
}

//fill in value in row n and column m and check the grid
bool checkGrid(int m, int n, int val){
    //row check
    for(int i = 0; i < 9; i ++){
        if(P[n/9][i] == val){
            cout<<"same value in the row"<<endl;
            return false;
        }
    }
    //column check
    for(int i = 0; i < 9; i ++){
        if(P[n/9][i] == val){
            cout<<"same value in the row"<<endl;
            return false;
        }
    }
    //grid check
    int x = n / 9 / 3 * 3;
    int y = n % 9 / 3 * 3;
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(P[x+i][y+j] == val){
                cout<<"same value in the square"<<endl;
                return false;
            }
        }
    }
}

//check every grid, row check, column check and square check
bool SolveCheck(int n, int num){
    // row check
    for(int i = 0; i < 9; i ++){
        if(P[n/9][i] == num){
//            cout<<"same value in the row"<<endl;
            return false;
        }
    } 
    //column check
    for(int i = 0; i < 9; i ++){
        if(P[n/9][i] == num){
//            cout<<"same value in the row"<<endl;
            return false;
        }
    }
    // 3*3square check
    int x = n / 9 / 3 * 3;
    int y = n % 9 / 3 * 3;
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(P[x+i][y+j] == num){
//                cout<<"same value in the square"<<endl;
                return false;
            }
        }
    } 
    return true;
}
// [n/9][n%9]
void dfs(int n){
    // solved
    if(n > 80){
        flag = true;
        return;
    }
    int x = n/9, y = n%9;
    // a value already in grid, pass
    if(P[x][y]){
        dfs(n+1);
        return;
    }
    // iteration
    for(int i = 1; i <= 9; i ++){
        // check
        if(SolveCheck(n, i)){
            // all checks pass, fill in value
            P[x][y] = i;
            dfs(n+1);
            // check if game finished, if yes, exit
            if(flag){
                return;
            }
            // if not, reset board
            P[x][y] = 0;
        }
    }
}
int main(){
    input();
    cout << endl << endl;
    output();
    cout<<endl;
    int n, m, val;
    cout<<"enter row number, column number and value, seperated with space (e.g, 2 3 5 means fill 5 in row 2 and column 3:"<<endl;
    cin>>n>>m>>val;
    if((n>=0&&n<=9)&&(m>=0&&m<=9)&&(val>=1&&val<=9)){ 


        }
    }



    //dfs(0);
    output();
    return 0;
} 
