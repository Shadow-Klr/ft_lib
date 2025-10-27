/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:18:29 by codespace         #+#    #+#             */
/*   Updated: 2025/10/27 18:22:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
    int i;
    int sign;
    int nb;
    
    if (!str)
        return (0);
    i = 0;
    while   ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    sign = 1;
    while (str[i] == '+' || str[i] == '-')
    {
        if  (str[i] == '-')
            sign *= -1;
        i++;
    }
    nb = 0;
    while   (ft_isdigit(str[i]))
        nb = nb * 10 + (str[i++] - '0');
    return (sign * nb);
}