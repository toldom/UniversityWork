package Problem3;

import java.util.Scanner;

public class DecimalSeperatorFormatter implements NumberFormatter {

    @Override
    public String format(int n) {

        String unformattedNumber = String.valueOf(n);
        String formattedNumber = "";

        unformattedNumber = unformattedNumber.replaceAll("", " ");
        String reversedNumber = new StringBuilder(unformattedNumber).reverse().toString();

        Scanner sc = new Scanner(reversedNumber);

        int counter = 0;

        while (sc.hasNextInt()) {
            //formattedNumber += sc.nextInt();

            formattedNumber += sc.nextInt();

            counter++;

            if (counter == 3) {
                formattedNumber += ",";
                counter = 0;
            }
        }

        sc.close();

        if (formattedNumber.endsWith(",")) {
            formattedNumber = formattedNumber.substring(0, formattedNumber.length()-1);
        }

        return new StringBuilder(formattedNumber).reverse().toString();

    }
}
