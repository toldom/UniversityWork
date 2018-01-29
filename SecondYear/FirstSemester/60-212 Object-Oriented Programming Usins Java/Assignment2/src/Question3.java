public class Question3 {

    public static void main(String[] args) {


        BankAccount myAccount = new BankAccount(5000);

        myAccount.withdraw(1000);
        myAccount.deposit(35);
        myAccount.deposit(20);
        myAccount.withdraw(38);
        myAccount.deposit(262);
        myAccount.withdraw(40);
        myAccount.withdraw(75);
        myAccount.deposit(3);

        myAccount.EndOfMonthCalculations();

    }

}

/**
 A bank account has a balance that can be changed by
 deposits and withdrawals.
 */
class BankAccount
{
    private double balance;
    private double fee = 0.75;
    private int freeTransactions = 5;
    private int postFreeTransactions = 0;


    /**
     Constructs a bank account with a zero balance.
     */
    public BankAccount()
    {
        balance = 0;
    }

    /**
     Constructs a bank account with a given balance.
     @param initialBalance the initial balance
     */
    public BankAccount(double initialBalance)
    {

        balance = initialBalance;
    }

    /**
     Deposits money into the bank account.
     @param amount the amount to deposit
     */
    public void deposit(double amount)
    {

        if (freeTransactions > 0) {
            balance += amount;
            freeTransactions--;
        } else {
            balance += amount;
            postFreeTransactions++;
        }
    }

    /**
     Withdraws money from the bank account.
     @param amount the amount to withdraw
     */
    public void withdraw(double amount)
    {

        if (freeTransactions > 0) {
            balance -= amount;
            freeTransactions--;
        } else {
            balance -= amount;
            postFreeTransactions++;
        }
    }

    /**
     Gets the current balance of the bank account.
     @return the current balance
     */
    public double getBalance()
    {
        return balance;
    }

    /*
    Sets the fee variable to something new, specified by the user
     */
    public void setFee(double newFee) {

        fee = newFee;

    }

    /*
    Calculates the total fee to deduct from the account at the end of the month
    Also resets transaction counter variables
     */
    public void EndOfMonthCalculations() {

        double totalFees =fee * postFreeTransactions;
        balance -= totalFees;

        System.out.println("You ended this month with a balance of: " + balance);
        System.out.println("You paid $" + totalFees + " in transfer fees");

        postFreeTransactions = 0;
        freeTransactions = 5;
    }
}
