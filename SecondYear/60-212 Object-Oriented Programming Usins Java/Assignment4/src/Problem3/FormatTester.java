package Problem3;

public class FormatTester {

    public static void main(String[] args) {

        DefaultFormatter defaultFormatter = new DefaultFormatter();
        DecimalSeperatorFormatter decimalSeperatorFormatter = new DecimalSeperatorFormatter();
        AccountingFormatter accountingFormatter = new AccountingFormatter();
        BaseFormatter baseFormatter = new BaseFormatter();

        String formattedNum1 = defaultFormatter.format(500000);
        System.out.println("Input is 500000: " + formattedNum1);

        System.out.println();

        String formattedNum2 = decimalSeperatorFormatter.format(749387653);
        System.out.println("Input is 749387653: " + formattedNum2);

        System.out.println();


        String formattedNum3 = accountingFormatter.format(-500);
        String formattedNum4 = accountingFormatter.format(100);
        System.out.println("Input is -500: " + formattedNum3 + "\n" + "Input is 100: " + formattedNum4);

        System.out.println();

        String formattedNum5 = baseFormatter.format(2, 749387653);
        String formattedNum6 = baseFormatter.format(8, 749387653);
        String formattedNum7 = baseFormatter.format(16, 749387653);
        System.out.println("The number 749387653 converted to...");
        System.out.println("Base 2: " + formattedNum5);
        System.out.println("Base 8: " + formattedNum6);
        System.out.println("Base 16: " + formattedNum7);
    }

}
