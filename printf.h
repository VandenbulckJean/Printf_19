#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fnc_data	{
	int minus;
	int zero;
	int	precision;
	int amount_precision;
	int width;
	char *string;
	char conversion;
}				t_fnc_data;

int		ft_printf(const char *, ...);
void	putstr(char *str);
int		ft_strlen(char *str);
char	*getnumberintostr(int i, int neg, unsigned long long int nb, int base, char *basestr);
char	*ft_itoa(int long long n, int base, char *basestr);
char	*ft_strjoin_back(char *s1, char *s2);
char	*ft_strjoin_front(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		isnumber(char c);
int		isinstr(char *str, char c);
int		Memory_allocation_error_free(void *to_free);

int processing_c(va_list saved_variables, t_fnc_data *data);

char 	*create_filled_string(int length, char filler);

int processing_d(va_list saved_variables, t_fnc_data *data);




#endif