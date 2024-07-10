/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int lucas(int n) {
    if(n==0)
        return 2;
    if(n==1)
        return 1;
    return lucas(n-1) + lucas(n-2);
}