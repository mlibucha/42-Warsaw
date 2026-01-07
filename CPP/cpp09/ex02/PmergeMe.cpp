/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:12:41 by mlibucha          #+#    #+#             */
/*   Updated: 2026/01/07 14:47:14 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <cstring>


struct VNode
{
	int value;
	std::size_t id;
	VNode() : value(0), id(0) {}
	VNode(int v, std::size_t i) : value(v), id(i) {}
	bool operator<(const VNode &other) const
	{
		if (value != other.value)
			return value < other.value;
		return id < other.id;
	}
};
struct VPair
{
	VNode leader;
	VNode follower;
};

// Jacobsthal numbers J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
static std::size_t jacobsthal(std::size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	std::size_t j0 = 0, j1 = 1, jn = 0;
	for (std::size_t k = 2; k <= n; ++k)
	{
		jn = j1 + 2 * j0;
		j0 = j1;
		j1 = jn;
	}
	return jn;
}

static std::vector<std::size_t> buildInsertionOrder(std::size_t m)
{
	std::vector<std::size_t> ord;
	if (m == 0)
		return ord;
	std::size_t prev = 0;
	for (std::size_t k = 1; prev < m; ++k)
	{
		std::size_t j = jacobsthal(k);
		if (j > m)
			j = m;
		for (std::size_t t = j; t > prev; --t)
		{
			ord.push_back(t);
		}
		prev = j;
	}
	return ord;
}

static std::vector<VNode>::iterator findLeaderPos(std::vector<VNode> &chain, const VNode &leader)
{
	std::vector<VNode>::iterator it = std::lower_bound(chain.begin(), chain.end(), leader);
	while (it != chain.end() && it->value == leader.value && it->id != leader.id)
	{
		++it;
	}
	if (it == chain.end() || it->id != leader.id)
	{
		for (it = chain.begin(); it != chain.end(); ++it)
		{
			if (it->id == leader.id)
				break;
		}
	}
	return it;
}

static std::vector<VNode> fj_sort_vector_nodes(const std::vector<VNode> &elems)
{
	const std::size_t n = elems.size();
	if (n <= 1)
		return elems;
	std::vector<VPair> pairs;
	pairs.reserve(n / 2);
	bool hasStray = (n % 2) != 0;
	VNode stray;
	for (std::size_t i = 0; i + 1 < n; i += 2)
	{
		VNode a = elems[i];
		VNode b = elems[i + 1];
		if (a < b)
		{
			VPair pr;
			pr.leader = b;
			pr.follower = a;
			pairs.push_back(pr);
		}
		else
		{
			VPair pr;
			pr.leader = a;
			pr.follower = b;
			pairs.push_back(pr);
		}
	}
	if (hasStray)
		stray = elems[n - 1];
	std::vector<VNode> leaders;
	leaders.reserve(pairs.size());
	for (std::size_t i = 0; i < pairs.size(); ++i)
		leaders.push_back(pairs[i].leader);
	std::vector<VNode> mainChain = fj_sort_vector_nodes(leaders);
	std::vector<std::size_t> order = buildInsertionOrder(pairs.size());
	for (std::size_t k = 0; k < order.size(); ++k)
	{
		std::size_t idx1 = order[k] - 1;
		const VPair &pr = pairs[idx1];
		std::vector<VNode>::iterator leaderPos = findLeaderPos(mainChain, pr.leader);
		std::vector<VNode>::iterator insertEnd = leaderPos;
		std::vector<VNode>::iterator insertPos = std::lower_bound(mainChain.begin(), insertEnd, pr.follower);
		mainChain.insert(insertPos, pr.follower);
	}

	if (hasStray)
	{
		std::vector<VNode>::iterator ip = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
		mainChain.insert(ip, stray);
	}

	return mainChain;
}

struct DNode
{
	int value;
	std::size_t id;
	DNode() : value(0), id(0) {}
	DNode(int v, std::size_t i) : value(v), id(i) {}
	bool operator<(const DNode &other) const
	{
		if (value != other.value)
			return value < other.value;
		return id < other.id;
	}
};
struct DPair
{
	DNode leader;
	DNode follower;
};

static std::deque<std::size_t> buildInsertionOrderD(std::size_t m)
{
	std::deque<std::size_t> ord;
	if (m == 0)
		return ord;
	std::size_t prev = 0;
	for (std::size_t k = 1; prev < m; ++k)
	{
		std::size_t j = jacobsthal(k);
		if (j > m)
			j = m;
		for (std::size_t t = j; t > prev; --t)
			ord.push_back(t);
		prev = j;
	}
	return ord;
}

static std::deque<DNode>::iterator findLeaderPosD(std::deque<DNode> &chain, const DNode &leader)
{
	std::deque<DNode>::iterator it = std::lower_bound(chain.begin(), chain.end(), leader);
	while (it != chain.end() && it->value == leader.value && it->id != leader.id)
	{
		++it;
	}
	if (it == chain.end() || it->id != leader.id)
	{
		for (it = chain.begin(); it != chain.end(); ++it)
		{
			if (it->id == leader.id)
				break;
		}
	}
	return it;
}

static std::deque<DNode> fj_sort_deque_nodes(const std::deque<DNode> &elems)
{
	const std::size_t n = elems.size();
	if (n <= 1)
		return elems;

	std::vector<DPair> pairs;
	pairs.reserve(n / 2);
	bool hasStray = (n % 2) != 0;
	DNode stray;
	for (std::size_t i = 0; i + 1 < n; i += 2)
	{
		DNode a = elems[i];
		DNode b = elems[i + 1];
		if (a < b)
		{
			DPair pr;
			pr.leader = b;
			pr.follower = a;
			pairs.push_back(pr);
		}
		else
		{
			DPair pr;
			pr.leader = a;
			pr.follower = b;
			pairs.push_back(pr);
		}
	}
	if (hasStray)
		stray = elems[n - 1];
	std::deque<DNode> leaders;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		leaders.push_back(pairs[i].leader);
	std::deque<DNode> mainChain = fj_sort_deque_nodes(leaders);
	std::deque<std::size_t> order = buildInsertionOrderD(pairs.size());
	for (std::size_t k = 0; k < order.size(); ++k)
	{
		std::size_t idx1 = order[k] - 1;
		const DPair &pr = pairs[idx1];
		std::deque<DNode>::iterator leaderPos = findLeaderPosD(mainChain, pr.leader);
		std::deque<DNode>::iterator insertPos = std::lower_bound(mainChain.begin(), leaderPos, pr.follower);
		mainChain.insert(insertPos, pr.follower);
	}
	if (hasStray)
	{
		std::deque<DNode>::iterator ip = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
		mainChain.insert(ip, stray);
	}
	return mainChain;
}

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char **argv)
{
	vec.clear();
	deq.clear();

	if (argc < 2)
		return false;
	for (int i = 1; i < argc; ++i)
	{
		const char *s = argv[i];
		if (!s || *s == '\0')
			return false;
		if (s[0] == '+' && s[1] != '\0')
			++s;
		errno = 0;
		char *endptr = 0;
		long v = std::strtol(s, &endptr, 10);
		if (errno == ERANGE || endptr == 0 || *endptr != '\0')
			return false;
		if (v <= 0 || v > INT_MAX)
			return false;
		int val = static_cast<int>(v);
		vec.push_back(val);
		deq.push_back(val);
	}
	return !vec.empty();
}

void PmergeMe::printVector() const
{
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i + 1 < vec.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque() const
{
	for (std::size_t i = 0; i < deq.size(); ++i)
	{
		std::cout << deq[i];
		if (i + 1 < deq.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::mergeInsertSortVector()
{
	std::vector<VNode> nodes;
	nodes.reserve(vec.size());
	for (std::size_t i = 0; i < vec.size(); ++i)
		nodes.push_back(VNode(vec[i], i));
	nodes = fj_sort_vector_nodes(nodes);
	for (std::size_t i = 0; i < nodes.size(); ++i)
		vec[i] = nodes[i].value;
}

void PmergeMe::mergeInsertSortDeque()
{
	std::deque<DNode> nodes;
	for (std::size_t i = 0; i < deq.size(); ++i)
		nodes.push_back(DNode(deq[i], i));

	nodes = fj_sort_deque_nodes(nodes);

	for (std::size_t i = 0; i < nodes.size(); ++i)
		deq[i] = nodes[i].value;
}