//class CustomLinkedList {
//
//    public Node head;
//    public int listLength;
//
//    public CustomLinkedList() {
//
//        head = new Node(null, -1);
//
//        this.listLength = 0;
//
//    }
//
//    public void AddNewNode(String data, int priority) {
//
//        Node newNode = new Node(data, priority);
//        Node currentNode = head;
//
//        while(currentNode.next != null) {
//            currentNode = currentNode.next;
//        }
//
//
//        currentNode.SetNextNode(newNode);
//        listLength++;
//
//    }
//
//    public void SortByPriority() {
//
//        Node currentNode = head.next;
//        int counter = 0;
//
//        while (true) {
//
//            if (listLength == 0) {
//                break;
//            }
//
//            if (currentNode.next == null) {
//
//                if (counter == listLength) {
//                    break;
//                } else {
//                    currentNode = head.next;
//                    counter ++;
//                }
//
//            }
//
//            if (currentNode.priority > currentNode.next.priority) {
//
//                currentNode.next = currentNode.next.next;
//                currentNode.previous.next = currentNode.next.previous;
//
//                currentNode.next.previous.next = currentNode;
//                currentNode.next.previous = currentNode;
//
//                currentNode.previous.next.previous = currentNode.previous;
//                currentNode.previous = currentNode.previous.next;
//            } else {
//                currentNode = currentNode.next;
//            }
//        }
//    }
//
//    public void RemoveFirstItem() {
//
//        Node firstNode = head.next;
//
//        head.next = head.next.next;
//        head.next.previous = head;
//
//    }
//
//    public int CheckPriority(int num) {
//
//        Node currentNode = head.next;
//
//        for (int i = 0; i < num; i++) {
//            currentNode = currentNode.next;
//        }
//
//        return currentNode.priority;
//
//    }
//
//}
