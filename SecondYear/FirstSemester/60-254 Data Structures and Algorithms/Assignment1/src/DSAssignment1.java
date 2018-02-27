//Data Structures and Algorithms
//Assignment 1
//Marcus Toldo
//Wednesday, September 20, 2017

import java.util.Scanner;

class Node {

    public Node next;
    public Node previous;

    public String poster;
    public String datePosted;
    public int numberOfLikes;
    public int numberOfComments;
    public int sizeOfPost;


    public Node(String poster, String datePosted, int numberOfLikes, int numberOfComments, int sizeOfPost) {

        this.next = next;
        this.previous = previous;

        this.poster = poster;
        this.datePosted = datePosted;
        this.numberOfLikes = numberOfLikes;
        this.numberOfComments = numberOfComments;
        this.sizeOfPost = sizeOfPost;
    }

    public void setNextNode(Node nextNode) {

        next = nextNode;

    }

    /*public Node getNext() {
        return next;

    }*/


}

class CustomLinkedList {

    Node head;
    int listLength = 0;


    //Constructor
    public CustomLinkedList() {

        head = new Node(null, null, -1, -1, -1);
        listLength = 0;
    }



    public void addElement (String poster, String datePosted, int numberOfLikes, int numberOfComments, int sizeOfPost) {

        Node temporaryNode = new Node(poster, datePosted, numberOfLikes, numberOfComments, sizeOfPost);
        Node currentNode = head;

        while (currentNode.next != null) {
            currentNode = currentNode.next;
        }

        temporaryNode.previous = currentNode;

        currentNode.setNextNode(temporaryNode);
        listLength++;
    }

}

class FacebookPost {

    public String poster;
    public String datePosted;
    public int numberOfLikes;
    public int numberOfComments;
    public int sizeOfPost;

    //Constructor
    public FacebookPost(String poster, String datePosted, int numberOfLikes, int numberOfComments, int sizeOfPost) {

        this.poster = poster;
        this.datePosted = datePosted;
        this.numberOfLikes = numberOfLikes;
    }

}

public class DSAssignment1 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        boolean running = true;
        int userChoice;


        CustomLinkedList facebookPostList = new CustomLinkedList();
        facebookPostList.addElement("Marcus Toldo", "2016/12/11", 12, 3, 87);
        facebookPostList.addElement("Dylan Docherty", "2017/03/11", 34, 14, 34);
        facebookPostList.addElement("Lemao", "2017/04/20", 30, 12, 80);
        facebookPostList.addElement("Emily Addison", "2017/04/22", 22, 7, 53);
        facebookPostList.addElement("Spencer Hyland", "2017/09/24", 14, 5, 32);
        facebookPostList.addElement("Tony Ahzhar", "2015/06/22", 55, 11, 67);

        System.out.println("Facebook Post Manager");

        while (running) {
            System.out.println("\n1. Display stored posts");
            System.out.println("2. Display a post with a particular attribute");
            System.out.println("3. Display the number of stored posts");
            System.out.println("4. Store a new post");
            System.out.println("5. Delete a particular post");
            System.out.println("6. Delete all posts");
            System.out.println("7. Sort posts based on an attribute");
            System.out.println("8. Exit");


            userChoice = sc.nextInt();

            //When user chooses to display all stored posts
            if (userChoice == 1) {
                DisplayStoredPosts(facebookPostList);

                //When user chooses to search for a particular post
            } else if (userChoice == 2) {
                boolean running2 = true;
                int userChoice2;
                int foundPostNum;

                //Opening a loop for the second level menu
                while (running2) {
                    System.out.println("\n1. Search by poster");
                    System.out.println("2. Search by number of likes");
                    System.out.println("3. Search by date posted");
                    System.out.println("4. Search by number of comments");
                    System.out.println("5. Search by size of post");
                    System.out.println("0. Back to main menu");

                    userChoice2 = sc.nextInt();

                    //When user chooses to search by name
                    if (userChoice2 == 1) {
                        foundPostNum = Search(userChoice2, facebookPostList);

                        //Fallback case for if users search did not return any results
                        if (foundPostNum == -1) {
                            System.out.println("Search query returned no results...");

                            //When the search result has been found
                        } else {
                            DisplaySinglePost(foundPostNum, facebookPostList);
                            running2 = false;
                        }

                        //When user chooses to search by number of likes
                    } else if (userChoice2 == 2) {
                        foundPostNum = Search(userChoice2, facebookPostList);

                        if (foundPostNum == -1) {
                            System.out.println("Search query returned no results...");
                        } else {
                            DisplaySinglePost(foundPostNum, facebookPostList);
                            running2 = false;
                        }

                        //When user chooses to search by date posted
                    } else if (userChoice2 == 3) {
                        foundPostNum = Search(userChoice2, facebookPostList);

                        if (foundPostNum == 01) {
                            System.out.println("Search query returned no results...");
                        } else {
                            DisplaySinglePost(foundPostNum, facebookPostList);
                            running2 = false;
                        }


                        //When user chooses to close the second loop
                    } else if (userChoice2 == 4) {

                        foundPostNum = Search(userChoice2, facebookPostList);

                        if (foundPostNum == -1) {
                            System.out.println("Search query returned no results...");
                        } else {
                            DisplaySinglePost(foundPostNum, facebookPostList);
                            running2 = false;
                        }


                    } else if (userChoice2 == 5) {

                        foundPostNum = Search(userChoice2, facebookPostList);

                        if (foundPostNum == -1) {
                            System.out.println("Search query returns no results...");
                        } else {
                            DisplaySinglePost(foundPostNum, facebookPostList);
                            running2 = false;
                        }


                    } else if (userChoice2 == 0) {
                        running2 = false;

                        //Fallback case for when the user enters an invalid input
                    } else {
                        System.out.println("Input not recognized, please try again");
                    }
                }


                //When the user chooses to display the number of stored posts
            } else if (userChoice == 3) {
                System.out.println("Number of stored  posts: " + facebookPostList.listLength);

            } else if (userChoice == 4) {
                StoreNewPost(facebookPostList);

            } else if (userChoice == 5) {
                DeleteParticularPost(facebookPostList);

            } else if (userChoice == 6) {
                AnnihilateLinkedList(facebookPostList);

            } else if (userChoice == 7) {

                Sorting(facebookPostList);


            } else if (userChoice == 8) {
                return;
            }
        }

    }

    public static void DisplayStoredPosts(CustomLinkedList facebookPostList) {

        Node currentNode = facebookPostList.head.next;

        for (int i = 1; i < facebookPostList.listLength + 1; i++) {
            System.out.println("\nPost #" + i);
            System.out.println("Poster: " + currentNode.poster);
            System.out.println("Number of likes: " + currentNode.numberOfLikes);
            System.out.println("Date posted: " + currentNode.datePosted);
            System.out.println("Number of comments: " + currentNode.numberOfComments);
            System.out.println("Size of post: " + currentNode.sizeOfPost);

            currentNode = currentNode.next;

        }
    }

    public static void DisplaySinglePost(int postToDisplay, CustomLinkedList facebookPostList) {

        Node node = facebookPostList.head;

        for (int i = 0; i < postToDisplay; i++) {
            node = node.next;
        }

        System.out.println("\nPoster: " + node.poster);
        System.out.println("Date Posted: " + node.datePosted);
        System.out.println("Number of likes: " + node.numberOfLikes);
        System.out.println("Number of comments: " + node.numberOfComments);
        System.out.println("Size of post: " + node.sizeOfPost);


    }

    public static int Search(int searchType, CustomLinkedList facebookPostList) {

        Scanner sc2 = new Scanner(System.in);

        int arrayLength = facebookPostList.listLength;

        Node currentNode = facebookPostList.head.next;

        //For when user chooses to search by poster name
        if (searchType == 1) {
            System.out.println("Please enter the name you want to search for: ");
            String wantedName = sc2.nextLine();

            for (int i = 1; i < arrayLength + 1; i++) {
                if (wantedName.equals(currentNode.poster)) {

                    return i;
                } else {
                    currentNode = currentNode.next;
                }
            }
            return -1;

            //For when user chooses to search by number of likes
        } else if (searchType == 2) {
            System.out.println("Please enter the number of likes you want to search for: ");
            int likesWanted = sc2.nextInt();

            for (int i = 1; i < arrayLength + 1; i++) {

                if (likesWanted == currentNode.numberOfLikes) {
                    return i;
                } else {
                    currentNode = currentNode.next;
                }

            }

            return -1;

            //For when user chooses to search by date posted
        } else if (searchType == 3) {

            System.out.println("Please enter the date you want to search for (YYYY/MM/DD): ");
            String dateWanted = sc2.next();


            for (int i = 1; i < arrayLength + 1; i++) {


                if (dateWanted.equals(currentNode.datePosted)) {
                    return i;
                } else {
                    currentNode = currentNode.next;
                }
            }

            return -1;
        } else if (searchType == 4) {

            System.out.println("Please enter the number of comments you want to search for: ");
            int commentsWanted = sc2.nextInt();

            for (int i = 1; i < arrayLength + 1; i++) {
                if (commentsWanted == currentNode.numberOfComments) {
                    return i;
                } else {
                    currentNode = currentNode.next;
                }
            }

            return -1;

        } else if (searchType == 5) {

            System.out.println("Please enter the post size you want to search for: ");
            int sizeWanted = sc2.nextInt();

            for (int i = 1; i < arrayLength + 1; i++) {
                if (sizeWanted == currentNode.sizeOfPost) {
                    return i;
                } else {
                    currentNode = currentNode.next;
                }
            }

            return -1;
        }


        return 0;
    }

    public static void StoreNewPost(CustomLinkedList facebookPostList) {

        Scanner sc = new Scanner(System.in);


        System.out.println("Please enter the name of the author of the post: ");
        String newName = sc.nextLine();

        System.out.println("\nPlease enter the number of likes the post recieved: ");
        int newLikes = sc.nextInt();

        System.out.println("\nPlease enter the date the post was submitted (YYYY/MM/DD): ");
        String newDate = sc.next();

        System.out.println("\nPlease enter the number of comments on the post: ");
        int newComments = sc.nextInt();

        System.out.println("\nPlease enter the size of the post: ");
        int newSize = sc.nextInt();

        facebookPostList.addElement(newName, newDate, newLikes, newComments, newSize);

        System.out.println("\nPost added!");


    }

    public static void DeleteParticularPost(CustomLinkedList facebookPostList) {

        boolean running = true;
        int userChoice;
        int postToDelete;

        Scanner sc = new Scanner(System.in);

        while (running) {

            System.out.println("\nHow would you like to find the post to delete?");
            System.out.println("1. By author");
            System.out.println("2. By likes");
            System.out.println("3. By date posted");
            System.out.println("4. By number of comments");
            System.out.println("5. By size of post");
            System.out.println("0. Return to previous menu");

            userChoice = sc.nextInt();

            if (userChoice == 1) {
                postToDelete = Search(1, facebookPostList);

                if (postToDelete == -1) {
                    System.out.println("Post not found, please try again...");
                } else {
                    DeleteSinglePost(postToDelete, facebookPostList);
                    running = false;
                }

            } else if (userChoice == 2) {
                postToDelete = Search(2, facebookPostList);

                if (postToDelete == -1) {
                    System.out.println("Post not found, please try again...");
                } else {
                    DeleteSinglePost(postToDelete, facebookPostList);
                    running = false;
                }

            } else if (userChoice == 3) {
                postToDelete = Search(3, facebookPostList);

                if (postToDelete == -1) {
                    System.out.println("Post not found, please try again...");
                } else {
                    DeleteSinglePost(postToDelete, facebookPostList);
                    running = false;
                }

            } else if (userChoice == 4) {
                postToDelete = Search(4, facebookPostList);

                if (postToDelete == -1) {
                    System.out.println("Post not found, please try again...");
                } else {
                    DeleteSinglePost(postToDelete, facebookPostList);
                    running = false;
                }

            } else if (userChoice == 5) {
                postToDelete = Search(5, facebookPostList);

                if (postToDelete == -1 ) {
                    System.out.println("Post not found, please try again...");
                } else {
                    DeleteSinglePost(postToDelete, facebookPostList);
                    running = false;
                }

            } else if (userChoice == 0) {
                return;
            } else {
                System.out.println("\nInput not recognized\n");
            }

        }
    }

    public static void DeleteSinglePost (int postToDelete, CustomLinkedList facebookPostList) {

        Node node = facebookPostList.head.next;

        for (int i = 1; i < postToDelete; i++) {
            node = node.next;
        }

        node.previous.next = node.next;

        facebookPostList.listLength--;

        System.out.println("\nPost deleted\n");
    }

    public  static void AnnihilateLinkedList (CustomLinkedList facebookPostList) {

        facebookPostList.head.next = null;

        facebookPostList.listLength = 0;

        System.out.println("\nList reset\n");

    }

    public static void Sorting (CustomLinkedList facebookPostList) {

        Scanner sc = new Scanner(System.in);

        System.out.println("0. Sort by number of liked (ascending)");
        System.out.println("1. Sort by number of comments (ascending)");
        System.out.println("2. Sort by side of post (ascending)");
        System.out.println("3. Sort by number of likes (descending)");
        System.out.println("4. Sort by number of comments (descending)");
        System.out.println("5. Sort by size of post (descending)");
        System.out.println("6. Sort by author (alphabetically)");
        System.out.println("7. Sort by date (Oldest --> Newest)");

        System.out.println("\nHow would you like to sort?");
        int sortType = sc.nextInt();

        Node node;

        if (sortType == 0) {

            for (int j = 0; j < facebookPostList.listLength; j++) {

                node = facebookPostList.head.next;

                while (node.next != null) {
                    if (node.numberOfLikes > node.next.numberOfLikes) {
                        Swap(node);

                    }

                    node = node.next;

                }
            }

            System.out.println("\nSorted!\n");

        } else if (sortType == 1) {

            for (int j = 0; j < facebookPostList.listLength; j++) {

                node = facebookPostList.head.next;

                while (node.next != null) {
                    if (node.numberOfComments > node.next.numberOfComments) {

                        Swap(node);
                    }

                    node = node.next;

                }
            }
            System.out.println("\nSorted!\n");

        } else if (sortType == 2) {

            for (int j = 0; j < facebookPostList.listLength; j++) {

                node = facebookPostList.head.next;

                while (node.next != null ) {

                    if (node.sizeOfPost > node.next.sizeOfPost) {

                        Swap(node);

                    }
                    node = node.next;

                }
            }
            System.out.println("\nSorted!\n");

        }
        else if (sortType == 3) {

            for (int j = 0; j < facebookPostList.listLength; j++) {

                node = facebookPostList.head.next;

                while (node.next != null) {
                    if (node.numberOfLikes < node.next.numberOfLikes) {

                        Swap(node);

                    }

                    node = node.next;
                }

            }

            System.out.println("\nSorted!\n");

        } else if (sortType == 4) {

            for (int j = 0; j < facebookPostList.listLength; j++) {

                node = facebookPostList.head.next;

                while (node.next != null) {
                    if (node.numberOfComments < node.next.numberOfComments) {

                        Swap(node);
                    }

                    node = node.next;

                }
            }

            System.out.println("\nSorted!\n");

        } else if (sortType == 5) {

            for (int j = 0; j < facebookPostList.listLength; j++) {

                node = facebookPostList.head.next;

                while (node.next != null ) {

                    if (node.sizeOfPost < node.next.sizeOfPost) {

                        Swap(node);

                    }
                    node = node.next;

                }

            }

            System.out.println("\nSorted!\n");

        } else if (sortType == 6) {

            for (int j = 0; j < facebookPostList.listLength; j++) {

                node = facebookPostList.head.next;

                while (node.next != null) {

                    if (node.poster.compareTo(node.next.poster) > 0) {

                        Swap(node);

                    }

                    node = node.next;

                }
            }

        } else if (sortType == 7) {

            for (int j = 0; j < facebookPostList.listLength; j++) {

                node = facebookPostList.head.next;

                while (node.next != null) {

                    if (node.datePosted.compareTo(node.next.datePosted) > 0) {


                        Swap(node);
                    }

                    node = node.next;

                }
            }
        }

    }

    public static void Swap(Node node) {

        Node temp1 = new Node("","", 0, 0, 0);
        Node temp2 = new Node("", "", 0, 0, 0);

        temp1.poster = node.poster;
        temp1.datePosted = node.datePosted;
        temp1.numberOfLikes = node.numberOfLikes;
        temp1.numberOfComments = node.numberOfComments;
        temp1.sizeOfPost = node.sizeOfPost;

        temp2.poster = node.next.poster;
        temp2.datePosted = node.next.datePosted;
        temp2.numberOfLikes = node.next.numberOfLikes;
        temp2.numberOfComments = node.next.numberOfComments;
        temp2.sizeOfPost = node.next.sizeOfPost;

        node.next.poster = temp1.poster;
        node.next.datePosted = temp1.datePosted;
        node.next.numberOfLikes = temp1.numberOfLikes;
        node.next.numberOfComments = temp1.numberOfComments;
        node.next.sizeOfPost = temp1.sizeOfPost;

        node.poster = temp2.poster;
        node.datePosted = temp2.datePosted;
        node.numberOfLikes = temp2.numberOfLikes;
        node.numberOfComments = temp2.numberOfComments;
        node.sizeOfPost = temp2.sizeOfPost;
    }

}