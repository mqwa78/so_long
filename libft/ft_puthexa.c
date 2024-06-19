
#include <unistd.h>
#include <stdio.h>

void    ft_putchar(int c)
{   
    (unsigned char)c;
    write(1, &c, 1);
}

/*void	ft_putupper_hexa(unsigned int n)
{
    char    *base;

    base = "0123456789ABCDEF";
	if (n >= 16)
		ft_putupper_hexa(n / 16);
	ft_putchar(base[n % 16]);
}*/

int main(void)
{   
    /*printf("%X\n", -42);
    printf("%X\n", 42);
    printf("%X\n", 0);
    printf("%X\n", 2147483647);
    printf("%X\n", -2147483648);
    printf("%X\n", 4294967295);
    ft_putupper_hexa(-42);
    ft_putchar('\n');
    ft_putupper_hexa(42);
    ft_putchar('\n');
    ft_putupper_hexa(0);
    ft_putchar('\n');
    ft_putupper_hexa(2147483647);
    ft_putchar('\n');
    ft_putupper_hexa(-2147483648);
    ft_putchar('\n');
    ft_putupper_hexa(4294967295);
    ft_putchar('\n');*/
    ft_putchar(300);
    ft_putchar('\n');
    printf("%c\n", 300);
    ft_putchar(-1);
    ft_putchar('\n');
    printf("%c\n", -1);
    ft_putchar(-1000);
    ft_putchar('\n');
    printf("%c\n", -1000);
    ft_putchar(10000);
    ft_putchar('\n');
    printf("%c\n", 10000);
    
    return (0);
}