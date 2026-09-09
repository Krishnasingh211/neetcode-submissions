class Solution {
public:
    double f(double x,long long n){
        if(n==0) return 1;
        double half=f(x,n/2);
        double res=half*half;
        if(n%2==1){
            return res*x;
        }
        return res;
    }

    double myPow(double x, int n) {

        long long N=n;
        if(n<0){
            N=-N;
            x=1/x;;
        }
        return f(x,N);
        
    }
};
