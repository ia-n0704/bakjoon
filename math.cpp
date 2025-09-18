#include <iostream>
#include <cmath>

bool isSquare(int n) {
    int sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}

int main() {
    int count = 0;
    for (int X2 = 10; ; X2++) {
        // X2의 1의 자릿수가 0이 아닌지 확인
        if (X2 % 10 == 0) continue;

        // X2의 가장 높은 자릿수가 8인지 확인
        if (X2 / 10 % 10 != 8) continue;

        // X2의 가장 높은 자릿수를 제거한 수가 제곱수인지 확인
        int removedDigit = X2 % 100;
        if (!isSquare(removedDigit)) continue;

        // log_10(2)가 조건을 만족하는지 확인
        double log2 = log10(2);
        if (0.301 < log2 && log2 < 0.302) {
            count++;
            if (count == 6) {
                std::cout << "6번째로 작은 X는 " << X2 << "입니다." << std::endl;
                break;
            }
        }
    }
    return 0;
}
