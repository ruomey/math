#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define S21_PI 3.14159265358979323846264338327950288
#define S21_NAN 0.0 / 0.0
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);

int main(){
	double x = 0.1;
	printf("x = 0.1\n");
	printf("acos %Lf\n", s21_acos(x));
	printf("atan %Lf\n", s21_atan(x));
	printf("asin %Lf\n", s21_asin(x));
}
long double s21_acos(double x) {
    long double res = S21_NAN;
    if (fabs(x) < 1) {
        res = S21_PI / 2 - s21_asin(x);
    } else if (x == 1) {
        res = 0.0;
    } else if (x == -1) {
        res = S21_PI;
    }
    return res;
}

long double s21_asin(double x) {
    long double res = S21_NAN;
    if (fabs(x) < 1) {
        res = s21_atan(x / sqrt(1 - pow(x, 2)));
    } else if (x == -1.0) {
        res = -S21_PI / 2;
    } else if (x == 1.0) {
        res = S21_PI / 2;
    }
    return res;
}

long double s21_atan(double x) {
    long double res = 0;
    if (x == 1) {
        res = 0.785398;
    } else if (x == -1) {
        res = -0.785398;
    } else {
        if (fabs(x) <= 1) {
            for (int i = 0; i < 10000; i++) {
                res += (((pow(-1, i)*pow(x, (1 + 2*i))) / (1 + 2*i)));
            }
        } else if (fabs(x) > 1) {
            long double temp = 0;
            for (int i = 0; i < 10000; i++) {
                temp += ((pow(-1, i) * pow(x, (-1 - (2 * i)))) / (1 + (2 * i)));
            }
            res = ((S21_PI*fabs(x)) / (2*x)) - temp;
        }
    }
    return res;
}
