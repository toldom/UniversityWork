import javax.swing.*;
import java.awt.*;

public class Question1 {

    public static void main(String[] args) {

        JFrame window = new JFrame();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setBounds(30, 30, 500, 300);
        window.getContentPane().add(new Scene1());
        window.setVisible(true);

    }

}

class Scene1 extends JComponent {

    public void paint(Graphics g) {

        //Drawing background
        g.setColor(Color.CYAN);
        g.fillRect(0, 0, 500, 300);

        //Drawing YELLOW sun
        g.setColor(Color.YELLOW);
        g.fillOval(450, -20, 90, 90);


        // STARTING NEW SHIT HERE
        //Drawing stoplight unit and stand
        g.setColor(Color.BLACK);

        g.fillRect(330, 50, 40, 100);
        g.drawLine(350, 150, 350, 300);
        g.drawLine(348, 150, 348, 300);
        g.drawLine(349, 150, 349, 300);
        g.drawLine(351, 150, 351, 300);
        g.drawLine(352, 150, 352, 300);

        //Empty Lights
        g.setColor(Color.darkGray);
        g.fillOval(340, 120, 20, 20);
        g.fillOval(340, 90, 20, 20);
        g.fillOval(340, 60, 20, 20);

        //Drawing stoplight unit and stand
        g.setColor(Color.BLACK);

        g.fillRect(130, 50, 40, 100);
        g.drawLine(150, 150, 150, 300);
        g.drawLine(148, 150, 148, 300);
        g.drawLine(149, 150, 149, 300);
        g.drawLine(151, 150, 151, 300);
        g.drawLine(152, 150, 152, 300);

        //Empty Lights
        g.setColor(Color.darkGray);
        g.fillOval(140, 120, 20, 20);
        g.fillOval(140, 90, 20, 20);
        g.fillOval(140, 60, 20, 20);


        //Drawing stoplight unit and stand
        g.setColor(Color.BLACK);

        g.fillRect(230, 50, 40, 100);
        g.drawLine(250, 150, 250, 300);
        g.drawLine(248, 150, 248, 300);
        g.drawLine(249, 150, 249, 300);
        g.drawLine(251, 150, 251, 300);
        g.drawLine(252, 150, 252, 300);

        //Empty Lights
        g.setColor(Color.darkGray);
        g.fillOval(240, 120, 20, 20);
        g.fillOval(240, 90, 20, 20);
        g.fillOval(240, 60, 20, 20);

        //Drawing RED light
        g.setColor(Color.RED);
        g.fillOval(140, 60, 20, 20);

        //Drawing ORANGE light
        g.setColor(Color.ORANGE);
        g.fillOval(240, 90, 20, 20);

        //Drawing GREEN light
        g.setColor(Color.GREEN);
        g.fillOval(340, 120, 20, 20);

        //Drawing grass
        g.fillRect(0, 250, 500, 50);
    }

}