#include <stdio.h>

void check_repeat(char *s1, char *o)
{
	int	i;
	int	sign = 0;
	int	j;
	i = 0;
	while (s1[i])
	{	
		j = 0;
		while (o[j])
		{
			if (o[j] == s1[i])
			{
				sign = 1;
				break;
			}
			j++;
		}
		if (sign == 0)
			o[j] = s1[i];
		i++;
	}
}
			
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	char	s[256] = {'\0'};
	check_repeat(argv[1], s);
	check_repeat(argv[2], s);
	printf("%s", s);

}
