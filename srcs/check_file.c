#include "../includes/fdf.h"

int	get_ymax(char *filename)
{
	int		fd;
	char	c;
	int		ymax;

	ymax = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	while (read(fd, &c, 1) == 1)
  		if (c == '\n')
			ymax++;
	return (ymax);
}
int	main(void)
{
	printf("%d", get_ymax("maps/42.fdf"));
	return (0);
}
