#include "super_header.h"

int main()
{
    ft_printf("This is testing ft_printf function.\n");
    char    str[]   = "12345";
    int     res     = ft_atoi(str);
    ft_printf("This is testing ft_atoi from libft : %d\n", res);
    return (0);
}
