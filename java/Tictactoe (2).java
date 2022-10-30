import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.plaf.ColorUIResource;

public class tictactoe(2)
{
    public static void main(String args[])
    {
        tictactoe t = new tictactoe();
    }
}

class tictactoe implements ActionListener
{
    int i;
    Random r = new Random();
    JFrame f = new JFrame();
    JPanel tp = new JPanel();
    JPanel bp = new JPanel();
    JLabel tfl = new JLabel();
    JButton[] b = new JButton[9];
    boolean pl;

    tictactoe()
    {
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(500,500);
        f.getContentPane().setBackground(new Color(50,50,50));
        f.setLayout(new BorderLayout());
        f.setVisible(true);

        tfl.setBackground(new Color(25,25,25));
        tfl.setForeground(new Color(25,255,0));
        tfl.setFont(new Font("Ink Free",Font.BOLD,75));
        tfl.setHorizontalAlignment(JLabel.CENTER);
        tfl.setText("Tic Tac Toe");
        tfl.setOpaque(true);

        tp.setLayout(new BorderLayout());
        tp.setBounds(0,0,800,100);

        bp.setLayout(new GridLayout(3,3));
        bp.setBackground(new Color(150,150,150));
        for(i=0;i<9;i++)
        {
            b[i] = new JButton();
            bp.add(b[i]);
            b[i].setFont(new Font("MV Boli",Font.BOLD,120));
            b[i].setFocusable(false);
            b[i].addActionListener(this);
        }
        tp.add(tfl);
        f.add(tp,BorderLayout.NORTH);
        f.add(bp);

        firstTurn();
    }

    @Override

    public void actionPerformed(ActionEvent e)
    {
        for(i=0;i<9;i++)
        {
            if(e.getSource()==b[i])
            {
                if(pl)
                {
                    if(b[i].getText()=="")
                    {
                        b[i].setForeground(new Color(255,0,0));
                        b[i].setText("X");
                        pl = false;
                        tfl.setText("O turn");
                        check();
                    }
                }
                    else
                    {
                        if(b[i].getText()=="")
                        {
                            b[i].setForeground(new Color(0,0,255));
                            b[i].setText("O");
                            pl=true;
                            tfl.setText("X turn");
                            check();
                        }
                    }
                
            }
        }
    }

    public void firstTurn()
    {
        try
        {
            Thread.sleep(2000);
        }
        catch(InterruptedException e)
        {
            e.printStackTrace();
        }

        if(r.nextInt(2)==0)
        {
            pl=true;
            tfl.setText("X turn");
        }
        else
        {
            pl=false;
            tfl.setText("O turn");
        }
    }
    public void check()
    {
        if((b[0].getText()=="X") && (b[1].getText()=="X") && (b[2].getText()=="X"))
        {
            xWins(0,1,2);
        }
        if((b[3].getText()=="X") && (b[4].getText()=="X") && (b[5].getText()=="X"))
        {
            xWins(3,4,5);
        }
        if((b[6].getText()=="X") && (b[7].getText()=="X") && (b[8].getText()=="X"))
        {
            xWins(6,7,8);
        }
        if((b[0].getText()=="X") && (b[3].getText()=="X") && (b[6].getText()=="X"))
        {
            xWins(0,3,6);
        }
        if((b[1].getText()=="X") && (b[4].getText()=="X") && (b[7].getText()=="X"))
        {
            xWins(1,4,7);
        }
        if((b[2].getText()=="X") && (b[5].getText()=="X") && (b[8].getText()=="X"))
        {
            xWins(2,5,8);
        }
        if((b[0].getText()=="X") && (b[4].getText()=="X") && (b[8].getText()=="X"))
        {
            xWins(0,4,8);
        }
        if((b[2].getText()=="X") && (b[4].getText()=="X") && (b[6].getText()=="X"))
        {
            xWins(2,4,6);
        }
        if((b[0].getText()=="O") && (b[1].getText()=="O") && (b[2].getText()=="O"))
        {
            xWins(0,1,2);
        }
        if((b[3].getText()=="O") && (b[4].getText()=="O") && (b[5].getText()=="O"))
        {
            xWins(3,4,5);
        }
        if((b[6].getText()=="O") && (b[7].getText()=="O") && (b[8].getText()=="O"))
        {
            xWins(6,7,8);
        }
        if((b[0].getText()=="O") && (b[3].getText()=="O") && (b[6].getText()=="O"))
        {
            xWins(0,3,6);
        }
        if((b[1].getText()=="O") && (b[4].getText()=="O") && (b[7].getText()=="O"))
        {
            xWins(1,4,7);
        }
        if((b[2].getText()=="O") && (b[5].getText()=="O") && (b[8].getText()=="O"))
        {
            xWins(2,5,8);
        }
        if((b[0].getText()=="O") && (b[4].getText()=="O") && (b[8].getText()=="O"))
        {
            xWins(0,4,8);
        }
        if((b[2].getText()=="O") && (b[4].getText()=="O") && (b[6].getText()=="O"))
        {
            xWins(2,4,6);
        }
        if((b[0].getText()=="O") && (b[1].getText()=="O") && (b[2].getText()=="O"))
        {
            oWins(0,1,2);
        }
        if((b[3].getText()=="O") && (b[4].getText()=="O") && (b[5].getText()=="O"))
        {
            oWins(3,4,5);
        }
        if((b[6].getText()=="O") && (b[7].getText()=="O") && (b[8].getText()=="O"))
        {
            oWins(6,7,8);
        }
        if((b[0].getText()=="O") && (b[3].getText()=="O") && (b[6].getText()=="O"))
        {
            oWins(0,3,6);
        }
        if((b[1].getText()=="O") && (b[4].getText()=="O") && (b[7].getText()=="O"))
        {
            oWins(1,4,7);
        }
        if((b[2].getText()=="O") && (b[5].getText()=="O") && (b[8].getText()=="O"))
        {
            oWins(2,5,8);
        }
        if((b[0].getText()=="O") && (b[4].getText()=="O") && (b[8].getText()=="O"))
        {
            oWins(0,4,8);
        }
        if((b[2].getText()=="O") && (b[4].getText()=="O") && (b[6].getText()=="O"))
        {
            oWins(2,4,6);
        }
    }
    public void xWins(int a,int d,int c)
    {
        b[a].setBackground(Color.green);
        b[d].setBackground(Color.green);
        b[c].setBackground(Color.green);

        for(i=0;i<9;i++)
        {
            b[i].setEnabled(false);
        }
        tfl.setText("X Wins");
    }
    public void oWins(int a,int d,int c)
    {
        b[a].setBackground(Color.green);
        b[d].setBackground(Color.green);
        b[c].setBackground(Color.green);

        for(i=0;i<9;i++)
        {
            b[i].setEnabled(false);
        }
        tfl.setText("O Wins");
    }
}