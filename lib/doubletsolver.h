#ifndef DOUBLET_SOLVER_H
#define DOUBLET_SOLVER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <set>
#include "min_heap.h"

class DoubletSolver
{
public:

	DoubletSolver();

	DoubletSolver(std::string start, std::string end, std::string filename);

	~DoubletSolver();

	void solve();
		/*
			Begins A* algorithm to search for quickest path
		*/

private:
	std::string start_word;
	std::string goal_word;
	unsigned int word_size;
	int expansions;
	int dictionary_size;
	std::vector<std::string> dictionary;

	std::unordered_map<std::string, std::string> parent_of;
		/*
			Stores the parent of a given word, used to backtrack and print solution
		*/

	std::unordered_map<std::string, int> g_value;
		/*
			Stores the shortest path to a given word
		*/

	std::set<std::string> closed_list;
		/*
			Once a node has been explored we add it to the closed list so we don't explore it again
		*/

	MinHeap* priority_queue;
		/*
			Will contain a set of all possible next moves and store the best at the top
		*/

	void solve_helper(std::string str);
		/*
			Evaluates possible moves and recursively makes the correct move, then calls print solution
		*/

	void print_solution(std::string str);
		/*
			Recursively prints solution once solved
		*/

	bool differs_by_one(std::string& left, std::string& right);
		/*
			Returns true if left and right only differ by one character
		*/

	int get_h_value(std::string str);
		/*
			h = heuristic value, counts the number of characters that differ from str and goal_word
		*/

	int get_priority(int g, int h);
		/*
			Priority = (g + h)(n + 1) + h ... n = word_size ... g = distance from start
		*/

	void parse_dictionary(const std::string& filename);
		/*
			Takes in a text file with one word per line and appends all words
			of equal length to the start word to our local dictionary
		*/
};

#endif