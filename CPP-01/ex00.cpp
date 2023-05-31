#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		while (argv[i])
		{
			int j = 0;
			while (argv[i][j])
			{
				putwchar(toupper(argv[i][j]));
				j++;
			}
			i++;
		}
		putwchar('\n');
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}