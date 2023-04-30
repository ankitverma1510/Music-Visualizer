/*
 * math_fun.h
 *
 *  Created on: 01-May-2022
 *      Author: ankit
 */

#include <complex.h>
complex float W[10]={1.0 + 0.00000000000000024493*I,-1.0 + 0.0000000000000012246*I, 0.000000000000000061232 + 1.0000*I, 0.70711 + 0.70711*I, 0.92388 + 0.38268*I, 0.98079 + 0.19509*I, 0.99518 + 0.098017*I, 0.99880 + 0.049068*I, 0.99970 + 0.024541*I, 0.99992 + 0.012272*I, 0.99998 + 0.0061359*I};


float sqrt(int number);
complex float power( complex float a, int n);


float sqrt(int number)
{
    float temp, sqrt;

        // store the half of the given number e.g from 256 => 128
        sqrt = number / 2;
        temp = 0;

        // Iterate until sqrt is different of temp, that is updated on the loop
        while(sqrt != temp)
        {
            // initially 0, is updated with the initial value of 128
            // (on second iteration = 65)
            // and so on
            temp = sqrt;

            // Then, replace values (256 / 128 + 128 ) / 2 = 65
            // (on second iteration 34.46923076923077)
            // and so on
            sqrt = ( number/temp + temp) / 2;
        }
        return(sqrt);
}

void fft(volatile complex float *v, int n, volatile complex float *tmp)
{

    if (n >1)
    {
        int k,m;
        complex float z, *vo, *ve;
        ve=tmp;
        vo=tmp+n/2;

        for (k=0;k<n/2;k++)
        {
            ve[k] = v[2*k];
            vo[k] = v[2*k+1];
        }
        fft(ve, n/2, v);
        fft(vo, n/2, v);
        for (m=0;m<n/2;m++)
        {
            z = power(W[Log2n(n)],m)*vo[m];
            v[m] = ve[m] + z;
            v[m +n/2] = ve[m] -z;
        }
    }
    return;

}

int Log2n(int n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}



complex float power( complex float a, int n)
{
    complex float temp=1;
    if(n<=0)
        return temp;
    else
    {
        temp=a*power(a, (n-1));
    }
        return temp;
}



