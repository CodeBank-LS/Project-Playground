//A sudoku game that take input to generate board
//check the value fill in grid
//and solve the game by itself
//test case
//530070000
//600195000
//098000060
//800060003
//400803001
//700020006
//060000280
//000419005
//000080079

#include <iostream>
using namespace std;
int P[9][9];
bool flag = false;
// Input handling
void input(){
    char t;
    cout << "enter board，use 0 as empty\n";
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            cin >> t;
            P[i][j] = t - '0';//convert char to int
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
bool checkGrid(int row, int column, int number){
    for(int i = 0; i < 9; i ++){
        if(P[row][i] == number){
            cout<<"row check fail"<<endl;
            return false;}
        if(P[i][column] == number){
            cout<<"column check failed" << endl;
            return false;}
    }
    int x = row/3*3;
    int y = column/3*3;
    for(int i = x; i < x+3; i ++){
        for(int j = y; j < y+3; j ++){
            if(P[i][j] == number){
                cout<<"grid check failed" << endl;
                return false;}
        }
    }
    return true;
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
    cout<<"You want to solve the game by yourself? (y/n)"<<endl;
    char t;
    cin >> t;
    if(t == 'y'||t == 'Y'){
        cout<<"enter the number you want to fill in"<<endl;
        int row,col,num;
        cin >> row>>col>>num;
        while(checkGrid(row,col,num)!=true){
            P[row][col] = num;
            output();
            cout<<"enter the number you want to fill in"<<endl;
            cin >> row>>col>>num;
        }



    }
    if(t == 'n'||t == 'N'){
        cout<<"Do you want system solve it for you? (y/n)"<<endl;
        char z;
        cin >> z;
        if(z == 'y'||z == 'Y'){
            dfs(0);
            output();
        }else{
            cout<<"Bye"<<endl;
        }
    }
    return 0;
    }





