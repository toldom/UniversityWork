public class Question4 {

    public static void main(String[] args) {

        CalculateChange(1475, 2000);

    }

    public static void CalculateChange(int amountOwed, int amountPaid) {

        int changeDue = amountPaid - amountOwed;
        int staticChangeDue = changeDue;

        int looniesDue = 0;
        int quartersDue = 0;
        int dimesDue = 0;
        int nicklesDue = 0;
        int penniesDue = 0;

        if (changeDue >= 100) {

            looniesDue = changeDue / 100;
            changeDue -= looniesDue*100;

        }

        if (changeDue >= 25) {

            quartersDue = changeDue/25;
            changeDue -= quartersDue*25;

        }

        if (changeDue >= 10) {

            dimesDue = changeDue/10;
            changeDue -= dimesDue*10;

        }

        if (changeDue >= 5) {

            nicklesDue = changeDue/5;
            changeDue -= nicklesDue*5;

        }

        if (changeDue >= 1) {

            penniesDue = changeDue;

        }

        System.out.println("The total change due was " + staticChangeDue + " pennies");
        System.out.println("You receive " + looniesDue + " loonies");
        System.out.println("You receive " + quartersDue + " quarters");
        System.out.println("You receive " + dimesDue + " dimes");
        System.out.println("You receive " + nicklesDue + " nickles");
        System.out.println("You receive " + penniesDue + " pennies");

    }

}
