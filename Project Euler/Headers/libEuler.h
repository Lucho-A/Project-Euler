/*
 * 	libEuler.h
 *
 *  Created on: 24/04/2018
 *
 */

#ifndef LIBEULER_H_
#define LIBEULER_H_
//includes
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    #include <string.h>
//defines
    #define FALSE 0
    #define TRUE 1
	#define PI 3.14159265358979323846264338327950288419716939937510
//typedef
	typedef int bool;
	typedef long double ld;
    typedef long unsigned int lu;
    typedef long long unsigned int llu;
//pause.c
    void pause(int sec);
//vector.c
    typedef struct Node Node;
    typedef struct Vector Vector;
    void vInit(Vector **v);
    void vFirst(Vector *v);
    Node * vNext(Vector *v);
    void vGoTo(Vector *v, int pos);
    llu vGetValue(Vector *v);
    llu vGetSize(Vector *v);
    Vector * vGetAux(Vector *v);
    void vSetAux(Vector *v, Vector * value);
    void vAdd(Vector *v, int value, int pos);
    void vUpdate(Vector *v, int value, int pos);
    void vDelete(Vector *v, int pos);
    void vShow(Vector *v);
//palindrome.c
    bool is_palindrome(char *c);
//prime.c
    bool is_prime(llu number);
    llu generate_vector_of_primes(lu **v, llu n);
    bool is_circular_prime(lu n);
//factorization.c
    llu maxFactor(llu num);
//commonFunctions.c
    llu fibonacci_by_Lucas(llu n);
    llu fibonacci_qDigits(llu n);
    llu gcd(llu a, llu b);
    llu triangle_number(llu pos);
    //llu numbers_of_divisors(llu n);
    llu sum_of_divisors(llu n);
    llu sum_of_proper_divisors(llu n);
//aritmeticOperations.c
    void sum_big_numbers(char *num1, char *num2, char *result);
    void factorial(int num, char *result);
    ld factoriall(int n);
//combiatoric.c
    //void lexi_permutate(char *s, llu n);
    long double combinatory(llu m, llu n);
    bool is_permutation_of(lu n1, lu n2);
//numberConversion.c
    void dec_to_binary(char *n, char *numBinary);
#endif /* LIBEULER_H_ */
