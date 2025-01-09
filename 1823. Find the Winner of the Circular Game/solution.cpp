class Solution {
public:
    int findTheWinner(int n, int k) {
        //this is the Josphus Problem 
        int winnerPos = 0; //Base recursion for case n = 1
        for(int i = 2; i <= n; i++){
            //for n>1, the formula will be
            //J(n,k) = (J(n-1, k) + k) % i
            //  the solution is the same as previous problem, with
            //  shifting the index by k and prevent the overflow by i
            winnerPos = (winnerPos + k) % i;
        }
        return winnerPos + 1;
    }
};