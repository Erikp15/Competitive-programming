package gui.java;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.border.BevelBorder;
import java.awt.*;
import javax.swing.*;

/**
 *
 * @author erikp
 */
public class gui implements ActionListener {
    JFrame f = new JFrame("");
    JPanel p1 = new JPanel();
    JPanel p2 = new JPanel();
    JPanel p3 = new JPanel();
    JButton b1 = new JButton("new");
    JButton b2 = new JButton("exit");

    public gui() {
        int p1x = 50, p1y = 50, p1xe = 300, p1ye = 50;
        int p2x = p1x, p2y = p1y + p1ye, p2xe = 300, p2ye = 50;
        int p3x = p1x, p3y = p2y + p2ye, p3xe = 300, p3ye = 50;
        p1.setBackground(Color.white);
        p2.setBackground(Color.green);
        p3.setBackground(Color.red);
        p1.setBounds(p1x, p1y, p1xe, p1ye);
        p2.setBounds(p2x, p2y, p2xe, p2ye);
        p3.setBounds(p3x, p3y, p3xe, p3ye);

        b1.setBounds(p1x, 10 + p1y + p1ye + p2ye + p3ye, 70, 40);
        b1.addActionListener(this);
        b2.setBounds(p2x, 10 + 2 * p1y + p1ye + p2ye + p3ye, 70, 40);
        b2.addActionListener(this);

        f.add(b1);
        f.add(b2);
        f.add(p1);
        f.add(p2);
        f.add(p3);
        f.setSize(2 * p1x + p1xe, 4 * p1y + p1ye + p2ye + p3ye);
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b1) {
            p1.setBackground(Color.red);
            p2.setBackground(Color.blue);
            p3.setBackground(Color.white);
        }
        if (e.getSource() == b2) {
            System.exit(0);
        }
    }

    public static void main(String args[]) {
        gui test = new gui();
    }
}
