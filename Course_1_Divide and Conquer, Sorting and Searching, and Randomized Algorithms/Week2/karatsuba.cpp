
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long int ll;
 ll karatsuba(ll x, ll y)
{
    ll B,A,D,C,AC,AD,BD;
    int x_l = log10(x)+1, y_l = log10(y)+1;
	int N = (int)(max(x_l, y_l));
	if (N < 10)
		return x * y;
        N = (N/2) + (N%2);
    ll mul = pow(10, N);
	 B = x/mul; A = x - (B * mul);
	D = y / mul; C = y - (D * N);
    AC = karatsuba(A,C); AD = karatsuba(A + B, C + D);
    BD = karatsuba(B, D);
    return AC + ((AD - AC - BD) * mul) + (BD * (long long)(pow(10, 2 * N)));
}
int main()
{
cout<<karatsuba(123456,45);
return 0;
}
