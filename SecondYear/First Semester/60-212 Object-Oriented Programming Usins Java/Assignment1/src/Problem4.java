//Object Oriented Programming Using Java
//Assignment 1 - Problem 4
//Marcus Toldo
//Thursday, September 28, 2017

import java.net.URL;
import javax.swing.JOptionPane;
import javax.swing.ImageIcon;

public class Problem4 {

    public static void main(String[] args) throws Exception {

        URL imageLocation = new URL("http://horstmann.com/java4everyone/duke.gif");
        JOptionPane.showMessageDialog(null, "Greetings from internet land", "Peace among worlds", JOptionPane.PLAIN_MESSAGE, new ImageIcon(imageLocation));

    }
}