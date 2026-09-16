class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0)
            return 1;

        double half = myPow(x, n / 2);
        double result = half * half;

        if (n % 2 == 0)
            return result;

        if (n > 0)
            return x * result;

        return result / x;
    }
};