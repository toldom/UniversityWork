import java.util.Scanner;

public class A3Question4 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        //Generating the height map
        int[][] heightMap = ReceiveHeightMap(sc);

        //Finding highest and lowest points
        int[] highestPoint = FindHighest(heightMap);
        int[] lowestPoint = FindLowest(heightMap);

        //Displaying that data to the user
        System.out.println("The highest height is at position (" + highestPoint[0] + "," + highestPoint[1] + ") and the height value is " + heightMap[highestPoint[0]][highestPoint[1]]);
        System.out.println("The lowest height is at position (" + lowestPoint[0] + "," + lowestPoint[1] + ") and the height value is " + heightMap[lowestPoint[0]][lowestPoint[1]]);
        System.out.println();

        //Receiving the water height level, and printing the flood map to the user
        System.out.print("Please enter the height value for which areas will be flooded with water: ");
        int waterHeight = sc.nextInt();

        PrintFloodMap(heightMap, waterHeight);

        sc.close();

    }

    /*
    Objective: Find the position of lowest height in the 2D array map of height values we are given
    Input: Recieves the 2D array of int values representative of the height map as an input parameter
    Output: Returns an int array of size 2 with the i and j position for the lowest value in the height map
     */
    private static int[] FindLowest(int[][] terrainMap) {

        int[] lowestPosition = {-1, -1};
        int lowestValue = terrainMap[0][0];

        int i, j;

        for (i = 0; i < terrainMap.length; i++) {
            for (j = 0; j < terrainMap[0].length; j++) {
                if (terrainMap[i][j] < lowestValue) {
                    lowestValue = terrainMap[i][j];
                    lowestPosition[0] = i;
                    lowestPosition[1] = j;
                }
            }

        }

        return lowestPosition;

    }

    /*
    Objective: Find the position of highest height in the 2D array map fo height values we are given
    Input: Recieves the 2D array of int values representative of the height map as an input parameter
    Output: Returns an int array of size 2 with the i and j position for the highest value in the height map
     */
    private static int[] FindHighest(int[][] terrainMap) {

        int[]  highestPosition = {-1, -1};
        int highestValue = terrainMap[0][0];

        int i, j;

        for (i = 0; i < terrainMap.length; i++) {
            for (j = 0; j < terrainMap[0].length; j++) {
                if (terrainMap[i][j] > highestValue) {
                    highestValue = terrainMap[i][j];
                    highestPosition[0] = i;
                    highestPosition[1] = j;
                }
            }
        }

        return highestPosition;
    }

    /*
    Objective: Print out a flood map of * and - characters that represents which areas of the height map would get
               flooded, given a certain height for a water level
    Input: Recieves a 2D array of int values representative of the height map, and an int variable representative of
           the water level
    Output: Void function has no output, but prints the flood map to the console during execution
     */
    private static void PrintFloodMap(int[][] terrainMap, int floodHeight) {

        char[][] floodMap = new char[terrainMap.length][terrainMap[0].length];

        for (int i = 0; i < terrainMap.length; i++) {
            for (int j = 0; j < terrainMap[0].length; j++) {
                if (terrainMap[i][j] <= floodHeight) {
                    floodMap[i][j] = '*';
                } else {
                    floodMap[i][j] = '-';
                }
            }
        }

        for (char[] aFloodMap : floodMap) {
            for (int j = 0; j < floodMap[0].length; j++) {
                System.out.print(aFloodMap[j]);
            }
            System.out.println();
        }
    }

    /*
    Objective: Function recieves input for the user that will be used to build the height map. User enters the
               dimensions for the height map, and the height values at each point
    Input: Recieves scanner as a parameter
    Output: Function returns a 2D array of size specified by the user, that is populated with height information
     */
    private static int[][] ReceiveHeightMap(Scanner sc) {

        System.out.print("Please enter the value that will be the width and height of the square height map: ");
        int squareValue = sc.nextInt();
        System.out.println();

        int heightMap[][] = new int[squareValue][squareValue];

        for (int i = 0; i < squareValue; i++) {
            for (int j = 0; j < squareValue; j++) {
                System.out.print("Please enter the value of the height map at (" + i + "," + j + ") : ");
                heightMap[i][j] = sc.nextInt();
            }
            System.out.println();
        }

        return heightMap;
    }
}
