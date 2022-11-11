#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<rpc/rpc.h>
#include<rpc/xdr.h>

long* add_1(int a, int b) {
	static long result; /* must be static */
	result = (a + b);
	return (&result);
}

long* sub_2(int a, int b) {
	static long result;
	result = (a - b);
	return (&result);
}

long* mul_3(int a, int b) {
	static long result;
	result = (a * b);
	return (&result);
}

float* div_4(int a, int b) {
	static float result;
	result = (a / b);
	return (&result);
}

long* square_5(int a) {
	static long result;
	result = (a * a);
	return (&result);
}
/*
float* sqroot_6(int a) {
	static float result;
	result = pow(a, 0.5);
	return (&result);
}*/
