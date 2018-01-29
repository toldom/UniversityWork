public class QueueTester {

    public static void main(String[] args) {

        LinkedListPriorityQueue myQueue = new LinkedListPriorityQueue();

        myQueue.enqueue("Dylan");


        myQueue.display();
        System.out.println();


        myQueue.enqueue("Spenny", 4);

        myQueue.display();
        System.out.println();

        myQueue.enqueue("Emily", 4);

        myQueue.display();
        System.out.println();

        myQueue.enqueue("Marcus", 1);

        myQueue.display();
        System.out.println();

        myQueue.enqueue("Austin", 2);

        myQueue.display();
        System.out.println();

        myQueue.dequeue();

        myQueue.display();
        System.out.println();

        String peeking = myQueue.peek();
        System.out.println(peeking);
        System.out.println();

        System.out.println(myQueue.IsRegular());
        System.out.println();

        int size = myQueue.size;
        System.out.println(size);
        System.out.println();

        System.out.println(myQueue.isEmpty());
        System.out.println();

        System.out.println(myQueue.isFull());
        System.out.println();

    }

}