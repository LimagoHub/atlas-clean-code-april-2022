package de.limago;

import java.awt.*;
import java.awt.event.*;

public class Fenster extends Frame{


    public Fenster()  {

        setSize(300, 300);
        addWindowListener(new MyWindowListener());
        Button button = new Button("Drück mich");
        button.addActionListener((ActionEvent e)->{ausgabe();});
        add(button);
    }

    public static void main(String[] args) {
	    new Fenster().setVisible(true);
    }

    private void ausgabe() {
        System.out.println("Drück mich");
    }

    private void beenden() {
        dispose();
    }

    class MyWindowListener extends WindowAdapter {
        @Override
        public void windowClosing(WindowEvent e) {
           beenden();
        }
    }

//    class MyActionListener implements ActionListener {
//
//        @Override
//        public void actionPerformed(ActionEvent e) {
//           ausgabe();
//        }
//    }
}
