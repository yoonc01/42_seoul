#include <iostream>
#include <string>

using std::cout;
using std::string;

char	toUpper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			string str = av[i];
			for (unsigned long j = 0; j < str.length(); j++)
				cout << toUpper(str[j]);
		}
	}
	return (0);
}
