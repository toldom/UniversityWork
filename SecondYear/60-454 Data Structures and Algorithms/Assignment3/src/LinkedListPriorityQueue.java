
public class LinkedListPriorityQueue {

    Node front = new Node(null, -1);
    Node rear = new Node(null, -1);
    int size = 0;


    //***
    public void enqueue(String data, int priority) {

        Node node = new Node(data, priority);


        if(front.next == null){
            front.next = node;
            rear.next  = node;
        } else {
            Node currentNode = front.next;
            Node previousNode = front;

            while(currentNode != null){

                if(currentNode.priority > node.priority){

                    node.next = currentNode;
                    previousNode.next = node;
                    break;
                } else {
                    previousNode= currentNode;
                    currentNode = currentNode.next;
                }
            }

            if(previousNode.next == null){
                previousNode.next = node;
                rear.next = node;
            }
        }

        size++;
    }

    public void enqueue(String data) {

        enqueue(data, 5);
    }

    //***
    public void dequeue() {

        if (front.next == null) {
            return;
        }

        front.next = front.next.next;
        size--;
    }

    public String peek() {


        String firstElement = front.next.data;

        return firstElement;
    }

    //***
    public boolean IsRegular() {

        if (front.next.priority == rear.next.priority) {
            return true;
        } else {
            return false;
        }

    }

    public int size() {

        return size;

    }

    public boolean isEmpty() {
        if (front.next == null) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isFull() {
        return false;
    }

    public void display() {

        Node currentNode = front.next;


        for (int i = 0; i < size; i ++) {

            System.out.println(currentNode.data);
            currentNode = currentNode.next;

        }

    }



}
