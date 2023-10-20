#include <bits/stdc++.h>
using namespace std;



// kiểm tra với number nhập vào ma trận ở vị trí row và colunm thì có hợp lệ hay không:
bool box_safe(int grid[9][9], int row, int colunm, int number) {
//kiểm tra trên hàng cột
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == number || grid[i][colunm] == number) {
            return false;
        }
    }

//kiểm tra trên ô 3x3
    int starrow = row - row % 3;
    int starcolunm = colunm - colunm % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + starrow][j + starcolunm] == number) {
                return false;
            }
        }
    }

    return true;
}
/*Hàm tìm và đếm kết quả khả thi, input là nguyên cái ma trận 9x9, hơi cồng kềnh
so với iuput là vị trí hàng và cột
Tuy nhiên giảm bớt được bước tìm hàng và cột tiếp theo,
thay vào đó là tìm luôn empty_box tiếp theo*/
int Find_solution(int grid[9][9]){
    int row, colunm;
    bool empty_box=false; 
    for(row=0; row<9; row++){      //Tìm đến vị trsi trống. Trong cây đệ quy: nếu là gốc, vị trí trống sẽ là đầu tiên, nếu là cành, vị trí trống sẽ là vị trí tiếp theo cần điền:
        for( colunm=0; colunm<9; colunm++){
            if(grid[row][colunm]==0){
                empty_box=true;
                break;
            }
        }
        if(empty_box) break;
    }

    //nếu không còn empty_box, tức là sudoku đã được giải xong, trả về 1 kết quả:
    if(!empty_box) return 1;

    int count=0;

    for(int v=1; v<=9; v++){
        //thử các số vào empty_box tìm được
        if(box_safe(grid, row, colunm, v)){
            grid[row][colunm]=v;
            
            //nếu hàm gọi tới lá, biến count+=1, nếu chưa phải count+=0:
            count+=Find_solution(grid);
            grid[row][colunm]=0; //Backtracking đến empty_box tiếp theo
        }
    }
    return count;
}

int main(){
//nhập vào ma trận đầu vào 9x9
int grid[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> grid[i][j];
        }
    }

    cout<<Find_solution(grid);
    return 0;
}
