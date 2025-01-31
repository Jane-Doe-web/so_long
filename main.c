#include "so_long.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        ft_putstr_fd("The number of arguments is invalid", 2);
        exit (EXIT_FAILURE);
    }
    if (ft_strlen(argv[1]) < 4 
            || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
    {
        ft_putstr_fd("The extension is invalid", 2);
        exit (EXIT_FAILURE);
    }/*
    validate_map(argv[1]);
    init_game(&program);
    parse_map(&program, argv[1]);
    start_game(&program);
    clean(&program);
    }*/

}