package Problem1;

import Problem1.ComboLock;

public class ComboLockTester {

    public static void main(String[] args) {

        ComboLock lock1 = new ComboLock(20, 1, 21);
        ComboLock lock2 = new ComboLock(30, 31, 5);
        ComboLock lock3 = new ComboLock(1, 2, 3);

        lock1.turnRight(20);
        lock1.turnLeft(19);
        lock1.turnRight(20);

        lock1.open();

        System.out.println();

        lock2.open();
        lock2.turnRight(30);
        lock2.turnLeft(61);
        lock2.turnRight(14);
        lock2.open();

        System.out.println();

        lock3.turnRight(1);
        lock3.turnLeft(43);
        lock3.turnRight(1);
        lock3.open();


    }
}
