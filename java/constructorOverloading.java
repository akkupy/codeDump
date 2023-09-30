class Box {
	double width, height, depth;

	// constructor used when all dimensions
	// specified
	Box(double w, double h, double d)
	{
		width = w;
		height = h;
		depth = d;
	}

	// constructor used when no dimensions
	// specified
	Box() { width = height = depth = 0; }

	// constructor used when cube is created
	Box(double len) { width = height = depth = len; }

	// compute and return volume
	double volume() { return width * height * depth; }
}


public class constructorOverloading {
	public static void main(String args[])
	{
		
		// creating boxes using constructors
		Box mybox1 = new Box(10, 20, 15);
		Box mybox2 = new Box();
		Box mycube = new Box(7);

		double vol;

		// get volume of first box
		vol = mybox1.volume();
		System.out.println("Volume of mybox1 is " + vol);

		
		vol = mybox2.volume();
		System.out.println("Volume of mybox2 is " + vol);

		
		vol = mycube.volume();
		System.out.println("Volume of mycube is " + vol);
	}
}
