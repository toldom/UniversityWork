public class Question2 {

    public static void main(String[] args) {

        Microwave microwave = new Microwave();

        microwave.incrementButton();
        microwave.incrementButton();
        microwave.powerButton();
        microwave.startButton();

        microwave.resetButton();
        microwave.incrementButton();
        microwave.startButton();

    }

}

class Microwave {

    //Time in seconds
    int time = 0;
    int powerLevel = 1;

    void incrementButton() { time += 30; }

    void powerButton() {

        if (powerLevel == 1) {
            powerLevel = 2;
        } else if (powerLevel == 2) {
            powerLevel = 1;
        }

    }

    void resetButton() {
        time = 0;
        powerLevel = 1;
    }

    void startButton() {

        System.out.println("Cooking for " + time + " at power level " + powerLevel);

    }

}