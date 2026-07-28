class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int ld = fib(n - 1);
        int Sld = fib(n - 2);

        return ld + Sld;
    }
};