class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long quont = 0;
        long long a = llabs(dividend);
        long long b = llabs(divisor);
        int signal = ((dividend < 0) ^ (divisor < 0) ? -1 : 1);

        while (a >= b) {
            long long aux = b;
            long long qtd = 1;
            while ((aux << 1) <= a) {
                aux <<= 1;
                qtd <<= 1;
            }

            a -= aux;
            quont += qtd;
        }

    if (quont > INT_MAX && signal == 1) return INT_MAX;
    if (quont > INT_MAX && signal == -1) return INT_MIN;
    return quont*signal;
    }
};