//Object Oriented Programming Using Java
//Assignment 1 - Problem 1
//Marcus Toldo
//Thursday, September 21, 2017

/*
This program takes an initial bank account balance, displays it to the user, and then
compounds annual interest before returning what the new bank account balance (with interest)
would be after each year, for the first three years.
 */

public class Problem1 {


    public static void main(String[] args) {

        //Declaring the initial bank balance and setting the intrest percentage
        double bankBalance = 1000;
        double percentageValue = 1.05;

        //Printing the initial bank balance
        System.out.println("Initial bank balance: " + bankBalance);

        //Redefining the bank balance as itself, after compounding interest once (one year)
        bankBalance = bankBalance * percentageValue;

        //Reprinting balance
        System.out.println("Balance after one year: " + bankBalance);

        //Redefining the bank balance as itself, after compounding interest twice (two years)
        bankBalance = bankBalance * percentageValue;

        //Reprinting balance
        System.out.println("Balance after two years: " + bankBalance);

        //Redefining the bank balance as itself, after compounding interest thrice (three years)
        bankBalance = bankBalance * percentageValue;

        //Reprinting balance
        System.out.println("Balance after three years: " + bankBalance);

    }

}