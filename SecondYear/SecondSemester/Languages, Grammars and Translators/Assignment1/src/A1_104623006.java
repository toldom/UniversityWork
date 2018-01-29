/*

Languages, Grammars and Translators
Assignment 1
Marcus Toldo - 104623006
Friday, February 2, 2018

 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.io.*;

public class A1_104623006 {

    public static void main(String[] args) {

        //Defining variables
        int userExpressions = 0;
        File outputFile;

        //Default C expressions that are to not be included "custom" user expressions
        ArrayList<String> doNotInclude = new ArrayList<>(Arrays.asList("int", "char", "float", "double", "long", "bool", "boolean",
                "public", "static", "unsigned", "signed", "short", "printf", "if", "else", "elseif", "do", "while", "return", "main"));

        try {
            //Creating the file reader based on specified input file
            String input = new Scanner(new File(args[0])).useDelimiter("\\Z").next();

            //Running the input through a function that removes unnecessary substrings
            input = RemoveThingsFromInput(input);

            //Setting the REGEX, pattern and matcher
            String REGEX = "\\b_*[A-Za-z][A-Za-z0-9_]*\\b";
            Pattern p = Pattern.compile(REGEX);
            Matcher m = p.matcher(input);

            //Incrementing the userExpressions counter when a pattern is matched
            while (m.find()) {
                if (!doNotInclude.contains(m.group())) {
                    userExpressions++;
                    doNotInclude.add(m.group());
                }
            }

            //Creating and writing to the output file, based on the input file
            if (args[0].charAt(2) == '1') {
                outputFile = new File("A11_output.txt");
            } else if (args[0].charAt(2) == '2') {
                outputFile = new File("A12_output.txt");
            }else if (args[0].charAt(2) == '3') {
                outputFile = new File("A13_output.txt");
            }else if (args[0].charAt(2) == '4') {
                outputFile = new File("A14_output.txt");
            } else if (args[0].charAt(2) == '5') {
                outputFile = new File("A15_output.txt");
            } else {
                System.out.println("Error creating output file");
                return;
            }

            //Printing the output to the text file
            PrintWriter writer = new PrintWriter(outputFile);
            String outputString = "distinct/unique identifiers: " + userExpressions;
            writer.print(outputString);

            writer.close();

        } catch (FileNotFoundException error) {
            System.out.println("Error: File not recognized");
        }
    }

    /*
    Objective: Take the input string and remove any substrings/characters that cause an undesired output
    Input: Recieves the input string as an input parameter
    Output: Returns the input string after having been modified within the function
     */
    private static String RemoveThingsFromInput(String input) {

        //Declaring variables
        int hold = -1;
        String substring;

        //Loop runs for the length of the whole input string, resets to the beginning of the string when a substring is removed
        for (int i = 0; i < input.length(); i++) {
                if (input.charAt(i) == '"' && hold == -1) {
                    hold = i;
                } else if (input.charAt(i) == '"') {
                    substring = input.substring(hold, i+1);
                    input = input.replace(substring, "");

                    //When a substring is removed, hold variable and loop incrementation is reset
                    hold = -1;
                    i=0;
                }
            }
        return input;
    }
}