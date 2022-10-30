import java.awt.*;
import java.awt.event.*;
import javax.swing.*;  
public class mouse extends Frame implements MouseListener{  
	static JLabel l;  
	mouse()
	{  
		 
	}  
	public void mouseClicked(MouseEvent e) {  
		l.setText("Mouse Clicked");  
	}  
	public void mouseEntered(MouseEvent e) {  
		l.setText("Mouse Entered");  
	}  
	public void mouseExited(MouseEvent e) {  
		l.setText("Mouse Exited");  
	}  
	public void mousePressed(MouseEvent e) {  
		l.setText("Mouse Pressed");  
	}  
	public void mouseReleased(MouseEvent e) {  
		l.setText("Mouse Released");  
	}  
	public static void main(String[] args) {  
		JFrame f = new JFrame("Mouse");
		f.setSize(300,300);  
		mouse m = new mouse();
		f.addMouseListener(m);
		JPanel p = new JPanel();
		l = new JLabel();
		p.add(l);
		f.add(p);
		f.setVisible(true); 
	}  
}  
