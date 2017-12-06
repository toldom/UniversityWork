package Problem3;

public class AccountingFormatter implements NumberFormatter {

    @Override
    public String format(int n) {

        String value;

        if (n < 0) {
            n *= -1;

            value = "(" + String.valueOf(n) + ")";
        } else {
            value = String.valueOf(n);
        }

        return value;

    }
}
