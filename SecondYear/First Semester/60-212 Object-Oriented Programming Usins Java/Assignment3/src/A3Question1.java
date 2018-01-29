import java.util.Scanner;

public class A3Question1 {

    public static void main(String[] args) {

        while (true) {
            Scanner sc = new Scanner(System.in);
            System.out.println("\nPlease enter the credit card number: ");
            String cardNumber = sc.nextLine();

            //How to exit the program
            if (cardNumber.equals("-1")) {
                break;
            }
            cardNumber = cardNumber.replaceAll("\\s+", "");
            System.out.println("The validity of this card number is " + CheckValidity(cardNumber));
        }

    }

    /*
    Objective: Calculate the numerical sum of a String of 16 characters representative of numbers
    Input: This function recieves a string of numbers as input
    Output: The program returns an int value that represents the sum of all numbers in the String
     */
    private static int CalculateSum(String cardNumber) {

        //Declaring variables to hold the card sum and single chars of numbers
        int cardSum = 0;
        String holdNum = "";

        //Translating the String representation of each digit into an int and adding that to the total sum
        for (int i = 0; i < cardNumber.length(); i++) {
            holdNum = holdNum + cardNumber.charAt(i);
            cardSum = cardSum + Integer.parseInt(holdNum);
            holdNum = "";

        }
        return cardSum;
    }

    /*
    Objective: Checks the validity of a given credit card number, who's number is inputted as a String
    Input: Recieves a String of 16 numbers representative of a credit card number as input
    Output: Returns a boolean value of either true if the number is valid or false if invalid
     */
    private static boolean CheckValidity(String cardNumber){

        boolean validity = true;

        int cardSum = CalculateSum(cardNumber);
        int everyOtherNumberSum = 0;
        String holdNum = "";

        //Declaring an int array of size 8 to hold every other number in the size 16 CC number
        int[] everyOtherNumberArray = {-1,-1,-1,-1,-1,-1,-1,-1};
        int arrayTrack = 0;

        //Adding every other number to the total sum for every other number and then tracking that number in the array
        for (int i = cardNumber.length()-2; i > -1; i-=2) {
            holdNum += cardNumber.charAt(i);
            everyOtherNumberSum += Integer.parseInt(holdNum);

            everyOtherNumberArray[arrayTrack] = Integer.parseInt(holdNum);
            arrayTrack++;

            holdNum = "";
        }
        cardSum += everyOtherNumberSum;

        //Incrementing the total CC "sum" number by 1 for each "every other value" that is greater than 4
        for (int i = 0; i < 8; i++) {
            if (everyOtherNumberArray[i] > 4) {
                cardSum ++;
            }
        }

        //Checking to see if the final total sum is divisible by 10, invalid otherwise
        if (cardSum % 10 != 0) {
            validity = false;
        }

        return validity;
    }
}