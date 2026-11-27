#include <iostream>
#include <string>

using namespace std;

typedef __float128 f128;

// Q 접미사 없이 35자리 PI 계산: 16*atan(1/5) - 4*atan(1/239) (마친의 공식)
f128 calc_pi() {
    auto atan_inv = [](int n) -> f128 {
        f128 x = (f128)1 / n;
        f128 x2 = x * x;
        f128 term = x, sum = x;
        for (int i = 1; i <= 35; i++) {
            term = -term * x2;
            sum += term / (2 * i + 1);
        }
        return sum;
    };
    return (f128)16 * atan_inv(5) - (f128)4 * atan_inv(239);
}

const f128 PI = calc_pi();
const f128 TWO_PI = (f128)2 * PI;

// [0, 2*PI) 범위로 각도 축소
f128 reduce_angle(f128 x) {
    long long k = (long long)(x / TWO_PI);
    x -= (f128)k * TWO_PI;
    if (x < 0) x += TWO_PI;
    return x;
}

f128 sin128(f128 x) {
    x = reduce_angle(x);
    f128 term = x, sum = x, x2 = x * x;
    for (int i = 1; i <= 35; i++) {
        term = -term * x2 / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

f128 cos128(f128 x) {
    x = reduce_angle(x);
    f128 term = 1, sum = 1, x2 = x * x;
    for (int i = 1; i <= 35; i++) {
        term = -term * x2 / ((2 * i - 1) * (2 * i));
        sum += term;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long double a_in, b_in, c_in;
    cin >> a_in >> b_in >> c_in;

    f128 A = a_in, B = b_in, C = c_in;
    f128 x = C / A;

    for (int i = 0; i < 100; i++) {
        f128 fx = A * x + B * sin128(x) - C;
        f128 dfx = A + B * cos128(x);
        if (dfx == 0) x += (f128)1 / 10000000000LL;
        else x = x - fx / dfx;
    }

    // 소수점 6자리 반올림 출력 (0.0000005 = 5 / 10^7)
    x += (f128)5 / 10000000;
    long long int_part = (long long)x;
    long long frac_part = (long long)((x - int_part) * 1000000);

    string frac_str = to_string(frac_part);
    while (frac_str.length() < 6) frac_str = "0" + frac_str;

    cout << int_part << "." << frac_str << '\n';
    return 0;
}