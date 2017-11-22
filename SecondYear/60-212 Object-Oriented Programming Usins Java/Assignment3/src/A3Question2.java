import java.util.Scanner;

/**
 This class prints prime numbers.
 */
class PrimePrinter {

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter upper limit: ");
        int limit = in.nextInt();
        boolean running = true;

        PrimeGenerator primeGenerator = new PrimeGenerator();

        while (running) {

            int thisPrime = primeGenerator.nextPrime();

            if (thisPrime > limit) {
                running = false;
            } else {
                System.out.println(thisPrime);
            }

        }


    }

}

/**
 This class generates all prime numbers.
 */
class PrimeGenerator {

    private int current;

    public PrimeGenerator() {
        current = 1;
    }

    /**
     Calculates the next prime number. @return the next prime number
     */
    public int nextPrime() {

        int i = current;
        boolean running = true;

        i++;

        while(running) {

            if (isPrime(i)) {
                running = false;
            } else {
                i++;
            }

        }

        current = i;

        return i;

    }
    /**
     Check if n is a prime number.
     @param n to check whether it is prime or not @return true if n is prime
     */
    public static boolean isPrime(int n) {

        boolean isPrime = true;

        for (int i = 2; i < n; i++) {
            if (n % i == 0){
                isPrime = false;
                break;
            }
        }

        return isPrime;

    }

}

