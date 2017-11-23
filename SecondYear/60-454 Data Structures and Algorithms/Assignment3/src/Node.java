class Node {

    public Node next;

    public String data;
    public int priority;

    public Node(String data, int priority) {
        this.data = data;
        this.priority = priority;
    }

    public Node(String data){
        this.data = data;
        this.priority = 5;

    }

    void SetNextNode(Node nextNode) {
        next = nextNode;
    }
}