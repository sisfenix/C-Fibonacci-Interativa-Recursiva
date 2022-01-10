/*
; fibonacci.c - Desempenho vs Implementação da Interatividade e Recursividade
;
; hw: Intel
; os: Windows
; compiler name: TDM-GCC 4.9.2 64-bit Release
; options: -static-libgcc -std=gnu99
;
; by Alan Lopes
*/

#include <stdio.h>
#include <time.h>

typedef unsigned long int fibo_t;

fibo_t fibonacci_interativa(int n);
fibo_t fibonacci_recursiva(int n);

int main(int argc, char **argv){
	int N;
	printf("Numero de Fibonacci = ");
	scanf("%d", &N);
	
	double time_FNi, time_FNr  = 0;
	clock_t clk1, clk2;
	
	clk1 = clock();
	fibo_t FNi = fibonacci_interativa(N);
	clk2 = clock();
	time_FNi = (clk2 - clk1) / (double) CLOCKS_PER_SEC;
	
	clk1 = clock();
	fibo_t FNr = fibonacci_recursiva(N);
	clk2 = clock();
	time_FNr = (clk2 - clk1) / (double) CLOCKS_PER_SEC;
	
	printf("Valor FNi =  %lu (%.6lf seg.)\n", FNi, time_FNi);
	printf("Valor FNr =  %lu (%.6lf seg.)\n", FNr, time_FNr);
	
	return 0;
} // end main

fibo_t fibonacci_interativa(int n){	
	fibo_t a = 0;
	fibo_t b = 1;
	fibo_t c;
	
	if (n == 1) return a; // caso base
	if (n == 2) return b; // caso base
	
	while(n-2 > 0){
		c = a + b;
		a = b;
		b = c;
		n = n - 1;
	} // end while
	
	return c;
} // end fibonacci_interativa

fibo_t fibonacci_recursiva(int n){
	if (n == 1) return 0; // caso base
	if (n == 2) return 1; // caso base
	return fibonacci_recursiva(n-1) + fibonacci_recursiva(n-2);
} // end fibonacci_recursiva
