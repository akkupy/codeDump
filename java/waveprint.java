import java.awt.*;
import javax.swing.*;

public class WavePrint extends JPanel 
{
	int SCALEFACTOR = 200;
	int cycles;
	int points;
	double[] sines;
	int[] pts;

	public  void setCycles(int cycles) 
	{
		this.cycles = cycles;
		this.points = SCALEFACTOR * cycles * 2;
		this.sines = new double[points];
		for (int i = 0; i < points; i++) 
		{
			double radians = (Math.PI / SCALEFACTOR) * i;
			this.sines[i] = Math.sin(radians);
		}
	}

	public void paintComponent(Graphics g) 
	{
		int maxWidth = getWidth();
		double hstep = (double) maxWidth / (double) points;
		int maxHeight = getHeight();
		pts = new int[points];
		for (int i = 0; i < points; i++)
		{
			pts[i] = (int) (sines[i] * maxHeight / 2 * .75 + maxHeight / 2);
		}
		g.setColor(Color.BLACK);
		for (int i = 1; i < points; i++) 
		{
			int x1 = (int) ((i - 1) * hstep);
			int x2 = (int) (i * hstep);
			int y1 = pts[i - 1];
			int y2 = pts[i];
			g.drawLine(x1, y1, x2, y2);
		}
	}

	public static void main(String[] args) 
	{
		JFrame frame = new JFrame("Wave Pattern");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setBackground(Color.green);
		frame.setSize(250, 250);

		WavePrint sw = new WavePrint();
		sw.setCycles(5);
		frame.add(sw);
		frame.setVisible(true);
	}
}
