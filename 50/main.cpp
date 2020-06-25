//
// Created by Yujia Li  on 2020/6/25.
//

class Solution {
    double qpow(double base, long long exponent) {
        double ret = 1;
        while(exponent) {
            if (exponent & 1) {
                ret *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        return ret;
    }
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n > 0) {
            return qpow(x, n);
        }
        return 1 / qpow(x, -1ll * n);
    }
};