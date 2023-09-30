import java.io.*;

class waveprint {

	// Function definition
	static void pattern(int wave_height,
						int wave_length)
	{
		int i, j, k, e, n, count, x;
		e = 2;
		x = 1;

		// for loop for height
		// of wave
		for (i = 0; i < wave_height; i++)
		{
			for (j = wave_height; j <= wave_height + i; j++)
				System.out.print(" ");

			// for loop for wave
			// length
			for (count = 1; count <= wave_length; count++)
			{
				// checking for intermediate
				// spaces
				for (n = (wave_height + wave_height - 2); n >= x; n--)
					System.out.print(" ");
			
				for (k = 1; k <= e; k++)
				{
					if (k == 1)
						System.out.print("/");
					else if (k == e)
						System.out.print("\\");
					else
						System.out.print(" ");
				}
			}

			// incrementing counters
			// value by two
			x = x + 2;
			e = e + 2;
			
			System.out.println();
		}
	}

	// Driver code
	public static void main(String args[])
	{
		// change value to decrease or
		// increase the height of wave
		int wave_height = 4;

		// change value to decrease or
		// increase the length of wave
		int wave_length = 4;

		pattern(wave_height, wave_length);
	}
}

// This code is contributed by Nikita Tiwari.
