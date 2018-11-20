void	ft_arrdel(char **arr)
{
	int i;

	i = 0;
	while (*arr)
	{
		free(**arr);
		*arr++;
	}
}