#include <stdio.h>

void avg_sum(double a[], int n, double *avg, double *sum);

int main(void)
{
	int n = 5;
	double a[n], avg, sum;
	a[0] = 2.21;
	a[1] = 1.34;
	a[2] = 7.56;
	a[3] = 9.01;
	a[4] = 5.82;
	avg_sum(a, n, &avg, &sum);
	printf("sum is %lf\navg is %lf\n", sum, avg);
}

void avg_sum(double a[], int n, double *avg, double *sum)
{
	int i;
	*sum = 0.0;
	for (i = 0; i < n; i++)
		*sum += a[i];
	*avg = *sum / n;
}

/*
void avg_sum(double a[], int n, double *avg, double *sum)
{
	int i;
	sum = 0.0;
	for (i = 0; i < n; i++)
		sum += a[i];
	avg = sum / n
}
*/
