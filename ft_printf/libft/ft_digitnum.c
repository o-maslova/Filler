int ft_digitnum(int num)
{
	int i;

	i = 1;
	while (num / 10 > 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}