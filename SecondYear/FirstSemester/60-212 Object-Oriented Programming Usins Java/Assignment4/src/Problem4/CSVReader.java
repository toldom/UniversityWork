package Problem4;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class CSVReader {

    File input;
    Scanner sc;

    public CSVReader(String input) {
        this.input = new File(input);
    }

    public int numberOfRows() throws FileNotFoundException {

        int lineCount = 0;
        sc = new Scanner(input);

        while(sc.hasNextLine()) {
            sc.nextLine();
            lineCount++;
        }

        sc.close();

        return lineCount;
    }

    public int numberOfFields(int row) throws FileNotFoundException {

        int commaCount = 0;
        boolean stringOpen = false;
        sc = new Scanner(input);

        for (int i = 0; i < row; i++) {
            sc.nextLine();
        }

        String desiredRow = sc.nextLine();

        for (int i = 0; i < desiredRow.length(); i++) {
            if (desiredRow.charAt(i) == ',' && !stringOpen) {
                commaCount++;
            } else if (desiredRow.charAt(i) == '\"') {
                stringOpen = !stringOpen;
            }
        }

        sc.close();

        return commaCount+1;

    }

    public String field(int row, int field) throws FileNotFoundException {

        sc = new Scanner(input);

        for (int i = 0; i < row; i++) {
            sc.nextLine();
        }

        String desiredLine = sc.nextLine();

        int firstSpot = 0;
        int secondSpot;
        boolean stringOpen = false;
        ArrayList<String> fields = new ArrayList<>();

        for (int i = 0; i < desiredLine.length(); i++) {
            if ((desiredLine.charAt(i) == ',' && !stringOpen) || i == desiredLine.length()-1) {
                secondSpot = i;
                fields.add(desiredLine.substring(firstSpot, secondSpot));
                firstSpot = secondSpot+1;
            } else if (desiredLine.charAt(i) == '\"') {
                stringOpen = !stringOpen;
            }
        }

        String desiredField = fields.get(field);
        desiredField = desiredField.replaceAll("\"", "");

        return desiredField;
    }


}
