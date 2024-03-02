#include <iostream>
#include <cmath>

bool isPointOnSegment(int xA, int yA, int xB, int yB, int xC, int yC) {
    // Vector BA
    int BAx = xA - xB;
    int BAy = yA - yB;
    
    // Vector BC
    int BCx = xC - xB;
    int BCy = yC - yB;
    
    // Tính chiều dài của vector BC
    double length_BC = std::sqrt(std::pow(BCx, 2) + std::pow(BCy, 2));
    
    // Tính phép chiếu vector BA lên vector BC
    double projection_length = (BAx * BCx + BAy * BCy) / length_BC;
    
    // Kiểm tra điểm A nằm trên đoạn thẳng BC
    return 0 <= projection_length && projection_length <= length_BC;
}

int main() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int xA, yA, xB, yB, xC, yC;
        std::cin >> xA >> yA >> xB >> yB >> xC >> yC;
        
        // Kiểm tra và in kết quả
        if (isPointOnSegment(xA, yA, xB, yB, xC, yC)) {
            std::cout << "1\n";
        } else {
            std::cout << "0\n";
        }
    }

    return 0;
}
