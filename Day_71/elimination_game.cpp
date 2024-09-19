class Solution {
public:
    int lastRemaining(int n) {
        int first = 1;
        int step = 1;
        bool leftToRight = true;
        int remaining = n;

        while (remaining > 1) {
            if (leftToRight || remaining % 2 == 1) {
                first += step;
            }
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }
        
        return first;
    }
};