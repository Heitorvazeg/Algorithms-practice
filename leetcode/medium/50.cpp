class Solution {
    // Naive Solution:
    // Concept: We multiply the x value n times to get the result. The problem
    // is that, like this, we will have to do 2^31 operations, which means
    // almost 10^9.
    // O(n);

    // Optimized 1:
    // What if we dont need to do n iterations?
    // Concept: We will divide n for log n times in a recursive way.
    // x^n = (x^n/2)^n for even, and x^n = (x^n/2)^n * x for odd.
    // With this, we can just reutilize calculations:
    // 2x2x2x2x2 = (2x2)*(2x2)*2
    // O(log n)

public:
    double modPowWithoutMod(double x, int n) {
        if (n == 0) return 1;
        if (x == 0) return 0;

        double ans = modPowWithoutMod(x, n/2);

        ans = (ans * ans);

        if (n%2) ans = (ans * x);

        return ans;
    }

    double myPow(double x, int n) {
        double N = n;

        if (N < 0) {
            x = 1.0/x;
            N = -N;
        }

        return modPowWithoutMod(x, n);   
    }
};