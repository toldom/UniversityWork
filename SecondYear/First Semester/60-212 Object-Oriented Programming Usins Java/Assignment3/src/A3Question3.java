import java.util.Scanner;

public class A3Question3 {

    public static void main(String[] args) {

        //Generating the game board
        char[][] board = GenerateBaseBoard();

        int gameWonStatus;

        //Displaying a one time coordinate reference for the players
        System.out.println();
        System.out.println("Coordinates reference");

        System.out.println("       |       |       ");
        System.out.println(" (1,1) | (2,1) | (3,1) ");
        System.out.println("       |       |       ");
        System.out.println("-------|-------|-------");
        System.out.println("       |       |       ");
        System.out.println(" (1,2) | (2,2) | (3,2) ");
        System.out.println("       |       |       ");
        System.out.println("-------|-------|-------");
        System.out.println("       |       |       ");
        System.out.println(" (1,3) | (2,3) | (3,3) ");
        System.out.println("       |       |       ");


        System.out.println();
        System.out.println();

        //Starting the game
        System.out.println("WELCOME TO TIC-TAC-TOE");
        while(true) {

            //PlayerOnes turn
            PrintBoard(board);
            PlayerMove(board, 1);

            gameWonStatus = CheckWinCondition(board, 1);

            if (gameWonStatus != -1) {
                break;
            }

            //PlayerTwos turn
            PrintBoard(board);
            PlayerMove(board, 2);

            gameWonStatus = CheckWinCondition(board, 2);

            if (gameWonStatus != -1) {
                break;
            }

        }

        PrintBoard(board);

        //Conditions for what happens when someone wins the game
        if (gameWonStatus == 1) {
            System.out.println("Player One has won the game!");
        } else if (gameWonStatus == 2) {
            System.out.println("Player Two has won the game!");
        } else if (gameWonStatus == 3) {
            System.out.println("The game finished with a draw!");
        }

    }

    /*
    Objective: Generates the basic tic-tac-toe board with no player markers in any of the spaces
    Input: Recieves no input
    Output: Returns a (11 x 23) char array with the board data in it
     */
    private static char[][] GenerateBaseBoard() {

        //Declares a [11][23] char array that will serve as the game board
        char[][] board = new char[11][23];

        //Bunch of for-loops that populate the empty array with ' ', '-' and '|' characters to make the board structure
        //Lines 0-2
        for (int h = 0; h < 3; h++) {
            for (int i = 0; i < 7; i++) {
                board[h][i] = ' ';
            }
            board[h][7] = '|';

            for (int i = 8; i < 15; i++) {
                board[h][i] = ' ';
            }
            board[h][15] = '|';

            for (int i = 16; i < 23; i++) {
                board[h][i] = ' ';
            }
        }

        //Line 3
        for (int i = 0; i < 7; i++) {
            board[3][i] = '-';
        }
        board[3][7] = '|';

        for (int i = 8; i < 15; i++) {
            board[3][i] = '-';
        }
        board[3][15] = '|';

        for (int i = 16; i < 23; i++) {
            board[3][i] = '-';
        }
        board[3][22] = '-';

        //Lines 4-6
        for (int h = 4; h < 7; h++) {
            for (int i = 0; i < 7; i++) {
                board[h][i] = ' ';
            }
            board[h][7] = '|';

            for (int i = 8; i < 15; i++) {
                board[h][i] = ' ';
            }
            board[h][15] = '|';

            for (int i = 16; i < 23; i++) {
                board[h][i] = ' ';
            }
        }

        //Line 7
        for (int i = 0; i < 7; i++) {
            board[7][i] = '-';
        }
        board[7][7] = '|';

        for (int i = 8; i < 15; i++) {
            board[7][i] = '-';
        }
        board[7][15] = '|';

        for (int i = 16; i < 23; i++) {
            board[7][i] = '-';
        }
        board[7][22] = '-';

        //Lines 8-10
        for (int h = 8; h < 11; h++) {
            for (int i = 0; i < 7; i++) {
                board[h][i] = ' ';
            }
            board[h][7] = '|';

            for (int i = 8; i < 15; i++) {
                board[h][i] = ' ';
            }
            board[h][15] = '|';

            for (int i = 16; i < 23; i++) {
                board[h][i] = ' ';
            }
        }

        return board;

    }

    /*
    Objective: Prints out the current state of the game board to the terminal
    Input: Recieves the (11 x 23) game board char array as input parameter
    Output: Method returns void but prints the board while running
     */
    private static void PrintBoard(char[][] board) {

        //Loops to print every element of the board array in proper order
        System.out.println();
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 23; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }

        System.out.println();

    }

    /*
    Objective: Function handles the player move sequence. Allows the coordinates to be entered and properly positioned on the game board
    Input: Receives the char array that is the game board as an input parameter (so it can be edited), and an int that represents which player is taking their turn
    Output: Returns no output; only edits the board within the function
     */
    private static void PlayerMove(char[][] board, int playerToMove) {

        //Initializing a scanner and two 1d int arrays for the players desired coordinates, and another for the actual coordinates on the game board
        Scanner sc = new Scanner(System.in);
        int[] coordinates = new int[2];
        int[] truCoordinates;

        //Running booleans
        boolean running = true, running0 = true;

        //Telling the player it is their turn
        System.out.println();
        System.out.println("Player One, it is your turn!");

        //Opening the main running loops
        while (running0) {
            while (running) {

                //Getting the players desired x coordinate, takes into account that coordinates must be in range
                if (playerToMove == 1) {
                    System.out.print("Please enter the x coordinate for where you would like to place your X: ");
                } else if (playerToMove == 2) {
                    System.out.print("Please enter the x coordinate for where you would like to place your O: ");
                }
                coordinates[0] = sc.nextInt();

                //Checks that the entered coordinate is in range
                if (coordinates[0] > 3 || coordinates[0] < 1) {
                    System.out.println("Invalid input, coordinate must be 3 >= x >= 1");
                    System.out.println();

                } else {
                    running = false;
                }
            }

            System.out.println();
            running = true;

            //Getting the players desired y coordinate, takes into account that coordinates must be in range
            while (running) {

                if (playerToMove == 1) {
                    System.out.print("Please enter the y coordinate for where you would like to place your X: ");
                } else if (playerToMove == 2) {
                    System.out.print("Please enter the y coordinate for where you would like to place your O: ");
                }
                coordinates[1] = sc.nextInt();

                if (coordinates[0] > 3 || coordinates[0] < 1) {
                    System.out.println("Invalid input, coordinate must be 3 >= x >= 1");
                    System.out.println();

                } else {
                    running = false;
                }
            }

            running = true;

             truCoordinates = InterpretCoordinates(coordinates);

            //Checking to make sure that the spot the player is trying to place their X in isn't already taken
            if (board[truCoordinates[0]][truCoordinates[1]] == ' ') {

                if (playerToMove == 1) {
                    board[truCoordinates[0]][truCoordinates[1]] = 'X';
                } else if (playerToMove == 2) {
                    board[truCoordinates[0]][truCoordinates[1]] = 'O';
                }

                running0 = false;

            } else {

                System.out.println("That space is already taken");

            }
        }
    }

    /*
    Objective: Function checks all possible win conditions (for both players) and tie conditions to see if the game needs to come to an end
    Input: Recieves the char 2d array game board and an int value that corresponds to the player who we're checking to see has won
    Output: Returns an int value if someone has won, the game has been tied, or no result. Return 1 if playerOne won, 2 if playerTwo won, 3 if a tied game and -1 if no result
     */
    private static int CheckWinCondition(char[][] board, int playerToCheck) {

        int gameIsWon = -1;

        //Checking for a player 1 victory
        if (playerToCheck == 1) {
            //Checking for an X horizontal win
            if (board[1][3] == 'X' && board[1][11] == 'X' && board[1][19] == 'X') {
                gameIsWon = 1;
                return gameIsWon;
            } else if (board[5][3] == 'X' && board[5][11] == 'X' && board[5][19] == 'X') {
                gameIsWon = 1;
                return gameIsWon;
            } else if (board[9][3] == 'X' && board[9][11] == 'X' && board[9][19] == 'X') {
                gameIsWon = 1;
                return gameIsWon;
            }

            //Checking for an X vertical win
            if (board[1][3] == 'X' && board[5][3] == 'X' && board[9][3] == 'X') {
                gameIsWon = 1;
                return gameIsWon;
            } else if (board[1][11] == 'X' && board[5][11] == 'X' && board[9][11] == 'X') {
                gameIsWon = 1;
                return gameIsWon;
            } else if (board[1][19] == 'X' && board[5][19] == 'X' && board[9][19] == 'X') {
                gameIsWon = 1;
                return gameIsWon;
            }

            //Checking for an X horizontal win
            if (board[1][3] == 'X' && board[5][11] == 'X' && board[9][19] == 'X') {
                gameIsWon = 1;
                return gameIsWon;
            } else if (board[1][19] == 'X' && board[5][11] == 'X' && board[9][3] == 'X') {
                gameIsWon = 1;
                return gameIsWon;
            }


        //Checking for a player 2 victory
        } else if (playerToCheck == 2) {

            //Checking for an O horizontal win
            if (board[1][3] == 'O' && board[1][11] == 'O' && board[1][19] == 'O') {
                gameIsWon = 2;
                return gameIsWon;
            } else if (board[5][3] == 'O' && board[5][11] == 'O' && board[5][19] == 'O') {
                gameIsWon = 2;
                return gameIsWon;
            } else if (board[9][3] == 'O' && board[9][11] == 'O' && board[9][19] == 'O') {
                gameIsWon = 2;
                return gameIsWon;
            }

            //Checking for an O vertical win
            if (board[1][3] == 'O' && board[5][3] == 'O' && board[9][3] == 'O') {
                gameIsWon = 2;
                return gameIsWon;
            } else if (board[1][11] == 'O' && board[5][11] == 'O' && board[9][11] == 'O') {
                gameIsWon = 2;
                return gameIsWon;
            } else if (board[1][19] == 'O' && board[5][19] == 'O' && board[9][19] == 'O') {
                gameIsWon = 2;
                return gameIsWon;
            }

            //Checking for an O horizontal win
            if (board[1][3] == 'O' && board[5][11] == 'O' && board[9][19] == 'O') {
                gameIsWon = 2;
                return gameIsWon;
            } else if (board[1][19] == 'O' && board[5][11] == 'O' && board[9][3] == 'O') {
                gameIsWon = 2;
                return gameIsWon;
            }
        }

        //Checking for Tie Game
        if (board[1][3] != ' ' && board[1][11] != ' ' && board[1][19] != ' ' && board[5][3] != ' ' && board[5][11] != ' ' && board[5][19] != ' ' && board[9][3] != ' ' && board[9][11] != ' ' && board[9][19]!= ' ' ) {
            gameIsWon = 3;
            return gameIsWon;
        }

        return gameIsWon;
    }

    /*
    Objective: Takes the coordinates entered by the player (representing spaces on the board) and interprets them as their coordinates on the actual 3d board array
    Input: Recieves an int array of size 2 as input parameter, representative of users input choice
    Output: Returns an int array of size 2 as output, representative of real coordinates on the game board
     */
    private static int[] InterpretCoordinates(int[] coordinates) {

        int[] truCoordinates = new int[2];

        //Interpreting the players inputted coordinates as the actual board coordinates in the 2d board array
        if (coordinates[0] == 1) {

            truCoordinates[1] = 3;

            if (coordinates[1] == 1) {
                truCoordinates[0] = 1;
            } else if (coordinates[1] == 2) {
                truCoordinates[0] = 5;
            } else if (coordinates[1] == 3) {
                truCoordinates[0] = 9;
            }
        } else if (coordinates[0] == 2) {

            truCoordinates[1] = 11;

            if (coordinates[1] == 1) {
                truCoordinates[0] = 1;
            } else if (coordinates[1] == 2) {
                truCoordinates[0] = 5;
            } else if (coordinates[1] == 3) {
                truCoordinates[0] = 9;
            }

        } else if (coordinates[0] == 3) {

            truCoordinates[1] = 19;

            if (coordinates[1] == 1) {
                truCoordinates[0] = 1;
            } else if (coordinates[1] == 2) {
                truCoordinates[0] = 5;
            } else if (coordinates[1] == 3) {
                truCoordinates[0] = 9;
            }
        }

        return truCoordinates;

    }
}