
//Object Oriented Programming Using Java
//Assignment 1 - Problem 2
//Marcus Toldo
//Thursday, September 28, 2017

/*
Psudocode

int initialValue;
System.out.println("What number would you like to fine the square root of?: ");
initialValue = sc.nextInt();

double guess, temp, avg, diff = -1;
guess = initialValue/2;

while (diff != 0) {

    temp = initialValue/guess;
            avg = (guess+temp)/2;
            diff = guess - avg;
            guess = avg;

        }

        System.out.println("The square root is " + guess);

 */

import java.util.Scanner;

public class Problem2 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int initialValue;
        System.out.println("What number would you like to fine the square root of?: ");
        initialValue = sc.nextInt();

        double guess, temp, avg, diff = -1;
        guess = initialValue/2;

        while (diff != 0) {

            temp = initialValue/guess;
            avg = (guess+temp)/2;
            diff = guess - avg;
            guess = avg;

        }

        System.out.println("The square root is " + guess);

    }
}

