// #include<iostream>

// using namespace std;

// int main() {

//     int i = 1;
//     for(; ;){
        
//         if(i<5){
//         cout<<"hi"<<endl;
//         }
//         if( i==4)
//             break;
//         i++;
//     }
    
//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

int divide(int dividend, int divisor)
{
    int s = 0, e = dividend;
    int ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;
        // check if mid is the answer, treat mid as Quotient
        // Quotient * Divisor + Reminder = Dividend,
        // Predicate: Quotient * Divisor <= Dividend
        if (mid * divisor <= dividend)
        {
            ans = mid;
            // go right for more precise answer
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

double myPrecisionDivide(int dividend, int divisor)
{
    double quotient = divide(dividend, divisor);
    int precision = 5;
    double step = 0.1;
    for (int i = 0; i < precision; ++i)
    {
        double j = quotient;

        cout << "Value of i " << i << endl;
        cout << "Value of j " << j << " " << endl;
        while (j * divisor <= dividend)
        {
            cout << "inside while value of j " << j << endl;
            quotient = j;
            j += step;
            cout << "inside while value of after doing j+steps " << j << endl;
        }
        step /= 10;
        cout << "After loop ending value of quotent  " << quotient << endl ;
    }
    return quotient;
}

int main()
{
    int dividend = 29;
    int divisor = 7;
    cout << myPrecisionDivide(dividend, divisor) << endl;
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int n)
{
    int s = 0, e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;

        // predicate fn
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1; // go right
        }
        else
            e = mid - 1; // go left
    }
    return ans;
}

double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);
    int precision = 10;
    double step = 0.1;
    for (int i = 0; i < precision; ++i)
    {
        double j = sqrt;
        while (j * j <= n)
        {
            sqrt = j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}

int main()
{
    int n = 63;
    // cout << mySqrt(n) << endl;
    cout << myPrecisionSqrt(n) << endl;
    return 0;
}
