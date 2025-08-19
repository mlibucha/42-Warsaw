/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:52:55 by e                 #+#    #+#             */
/*   Updated: 2025/08/17 14:11:22 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	typedef void (Harl::*ComplaintFunction)(void);
	struct ComplaintLevel {
		std::string level;
		ComplaintFunction function;
	};
	static ComplaintLevel levels[4];
public:
	void complain(std::string level);
};

#endif