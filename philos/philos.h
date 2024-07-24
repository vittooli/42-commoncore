/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:25:30 by volivier          #+#    #+#             */
/*   Updated: 2024/07/24 15:38:02 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

typedef struct s_data
{
    int n_phils;
    int t_die;
    int t_eat;
    int t_sleep;
    int n_meals;
    
} t_data;

int	ft_atoi(char *str);

#endif
