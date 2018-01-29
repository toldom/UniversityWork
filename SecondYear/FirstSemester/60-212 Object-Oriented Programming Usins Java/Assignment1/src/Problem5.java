//Object Oriented Programming Using Java
//Assignment 1 - Problem 5
//Marcus Toldo
//Thursday, September 28, 2017

import java.lang.Math;

import static java.lang.Math.PI;

public class Problem5 {

    public static void main(String[] args) {

        //Part 1
        System.out.println("Question 1: ");

        int s0 = 5, v0 = 10, g = 7, t = 4;
        int gt2 = (g*t) * (g*t);

        double S = s0 + v0 + (gt2/2);

        System.out.println("The answer is: " + S);


        //Part 2
        System.out.println("Question 2: ");

        int a = 10, p = 2, m1 = 20, m2 = 22;

        double G = 4 * (PI*PI) * ((a*a*a)/((p*p) * (m1 + m2)));

        System.out.println("The answer is: " + G);

    }
}
