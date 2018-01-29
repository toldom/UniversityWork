package Problem1;

public class ComboLock {

    private int number1;
    private int number2;
    private int number3;
    private int currentPos = 0;

    private boolean firstNumberHit = false;
    private boolean secondNumberHit = false;
    private boolean thirdNumberHit = false;

    public ComboLock(int number1, int number2, int number3) throws IllegalArgumentException {

        if (!(number1 < 40 && number1 >= 0) || !(number2 < 40 && number2 >= 0) || !(number3 < 40 && number3 >= 0)) {
            throw new IllegalArgumentException("Invalid numbers, object not created");

        }
        this.number1 = number1;
        this.number2 = number2;
        this.number3 = number3;
    }

    public void reset() {
        currentPos = 0;

        firstNumberHit = false;
        secondNumberHit = false;
        thirdNumberHit = false;
    }

    public void turnLeft(int ticks) {

        currentPos -= ticks;

        if (currentPos < 0) {
            currentPos *= -1;
        }

        if (currentPos > 40) {
            currentPos -= 40;
        }

        System.out.println("The lock was turned left " + ticks);

        if (currentPos == number2 && firstNumberHit) {

            secondNumberHit = true;

        } else {
            firstNumberHit = false;
            secondNumberHit = false;
        }
    }

    public void turnRight(int ticks){

        currentPos += ticks;

        if (currentPos < 0) {
            currentPos *= -1;
        }

        if (currentPos > 40) {
            currentPos -= 40;
        }

        System.out.println("The lock was turned right " + ticks);

        if (currentPos == number1) {
            firstNumberHit = true;
        } else if (currentPos == number3 && firstNumberHit && secondNumberHit) {
            thirdNumberHit = true;
        } else {
            firstNumberHit = false;
            secondNumberHit = false;
            thirdNumberHit = false;
        }
    }

    public boolean open() {

        if (firstNumberHit && secondNumberHit && thirdNumberHit) {
            System.out.println("The lock opened!");
            this.reset();
            return true;
        } else {
            System.out.println("The lock did not open! D:");
            return false;
        }
    }


}
