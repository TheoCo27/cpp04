/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:11:56 by tcohen            #+#    #+#             */
/*   Updated: 2025/02/14 14:22:14 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	private:
	std::string ideas[100];
	public:
	Brain(void);
	Brain(const Brain &copy);
	Brain& operator=(const Brain &copy);
	~Brain(void);
};