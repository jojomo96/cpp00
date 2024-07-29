# include <iostream>
# include <cctype>
# include <string>

int main(const int argc, char **argv) {
	std::string output;
	if (argc == 1) {
		output += "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				output += static_cast<char>(std::toupper(argv[i][j]));
			}
			if (i < argc - 1) {
				output += " ";
			}
		}
	}
	std::cout << output << std::endl;
	return 0;
}
