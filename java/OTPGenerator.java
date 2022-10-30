import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Collections;


public class OTPGenerator 
{
    public static void frame()
    {
        JFrame f = new JFrame("OTP Generator");
        JLabel l1;
        JTextField tf1;
        JButton b1;

        l1 = new JLabel("OTP is ");
        l1.setBounds(20,20,60,15);
        tf1 = new JTextField("0000");
        tf1.setBounds(70,20,100,15);
        tf1.setEditable(false);
        b1 = new JButton("create");
        b1.setBounds(40,50,100,20);

        b1.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                ArrayList<Integer> list = new ArrayList<>();
                for(int i=0;i<=9;i++)
                {
                    list.add(i);
                }
                Collections.shuffle(list);
                int otp = 0;
                otp = (list.get(0)*1000)+(list.get(1)*100)+(list.get(2)*10)+(list.get(3));
                String str = Integer.toString(otp);
                tf1.setText(str);
            }
        });
        f.add(l1);
        f.add(tf1);
        f.add(b1);
        
        f.setLayout(null);
        f.setVisible(true);
        f.setSize(400,300);

    }
    public static void main(String args[])
    {
        frame();
    }
}