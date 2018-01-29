//Object Oriented Programming Using Java
//Assignment 1 - Problem 3
//Marcus Toldo
//Thursday, September 28, 2017

/*
This program calculates and returns the sum and product of the first five
negative integers respectively
 */

public class Problem3 {

    public static void main(String[] args) {

        //Declaring variables for the sum and product to be stored in
        int sum = 0;
        int product = 1;

        //Loop to calculate the sum and product
        for (int i = -1; i > -6; i--) {

            sum += i;
            product *= i;
        }

        //Displaying results to the user
        System.out.println("The sum of the first 5 negative integers is " + sum + "\nThe product of the first 5 negative integers is " + product);

    }

}
