public interface MyQueue <T> {

    void enqueue (T item, int priority, MyQueue queue);

    void dequeue (MyQueue queue);

    void peek (MyQueue queue);

    void IsRegular (MyQueue queue);

    void size (MyQueue queue);

    void isEmpty (MyQueue queue);

    void isFull (MyQueue queue);

    void display(MyQueue queue);

}
