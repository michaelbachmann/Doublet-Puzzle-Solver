#include "../lib/doubletsolver.h"

DoubletSolver::DoubletSolver() {
	start_word = "river";
	goal_word = "sweep";
	word_size = start_word.size();
	expansions = 0;
	priority_queue = new MinHeap(3);
	parse_dictionary("data/AStarTestFile.txt");
}


DoubletSolver::DoubletSolver(std::string start, std::string end, std::string filename){
	start_word = start;
	goal_word = end;
	word_size = start_word.size();
	expansions = 0;
	priority_queue = new MinHeap(3);
	parse_dictionary(filename);
}


DoubletSolver::~DoubletSolver() {
	delete priority_queue;
}


bool DoubletSolver::differs_by_one(std::string& left, std::string& right) {
	int num_diff_chars = 0;
	for (unsigned int i = 0; i < word_size; i++) {
		if (num_diff_chars > 1)  // terminate if we ever have more than 1 different characters
			return false;

		if (left[i] != right[i]) // if the characters don't match, increment num_diff_chars
			num_diff_chars++;
	}

	if (num_diff_chars == 1)
		return true;

	return false;  
}


int DoubletSolver::get_h_value(std::string str) {
	int h_value = 0;

	for (unsigned int i = 0; i < word_size; i++) {
		if (str[i] != goal_word[i]) // if the characters don't match, increment num_diff_chars
			h_value++;
	}
	return h_value;
}


int DoubletSolver::get_priority(int g, int h) {
	return ((g + h) *(word_size+1) + h);
}


void DoubletSolver::parse_dictionary(const std::string& filename) {
	std::string str;
	std::ifstream inputFile(filename.c_str());

	if (inputFile.is_open()) {  // if file opened correctly
		getline(inputFile,str);
		dictionary_size = std::stoi(str);
		str.clear();
		while (getline(inputFile,str)) {
			str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
			if (str.length() == word_size){
				std::transform(str.begin(), str.end(), str.begin(), ::tolower);
				if (str != start_word)
					dictionary.push_back(str);
			}
			str.clear();
		}

	inputFile.close();
	}
	else
		std::cerr << "FILE NOT OPENED\n";
}


void DoubletSolver::print_solution(std::string str) {
	if (str != start_word)
		print_solution(parent_of[str]);
	std::cout << str << " ";
}


void DoubletSolver::solve() {
	g_value[start_word] = 0;
	priority_queue->add(start_word,0);
	solve_helper(start_word);
}


void DoubletSolver::solve_helper(std::string str) {
	std::string consider = priority_queue->peek();
	priority_queue->remove();
	closed_list.insert(consider);
	// std::cout << consider << " ";
	if (consider == goal_word) {
		parent_of[consider] = str;
		print_solution(consider);

		std::cout << "\nexpansion = " << expansions << std::endl;
		return;
	}

	expansions++;

	for (std::vector<std::string>::iterator neighbor = dictionary.begin(); neighbor != dictionary.end(); ++neighbor)
	{
		if (differs_by_one(*neighbor, consider) && (closed_list.count(*neighbor) == 0)) {
			if (priority_queue->is_in_heap(*neighbor)) {
				if (g_value[*neighbor] > (g_value[consider] + 1) ) {
					g_value[*neighbor] = g_value[consider] + 1;
					parent_of[*neighbor] = consider;
					priority_queue->update(*neighbor, get_priority(g_value[*neighbor], get_h_value(*neighbor)));
				}
			}
			else {
				g_value[*neighbor] = g_value[consider] + 1;
				parent_of[*neighbor] = consider;
				priority_queue->add(*neighbor, get_priority(g_value[*neighbor], get_h_value(*neighbor)));
			}
		}
	}
	solve_helper(consider);
}