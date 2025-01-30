#include "main.hpp"

// Function to generate a valid 4-digit secret number
std::string generate_secret() {
    
	// boilerplate c++ rng "you just kinda need to know" type pattern
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0,9); // 0 to 9 inclusive

	std::unordered_set<int> digits;

	while(digits.size() < 4) {
		// attempt to insert an rng output
		digits.insert(dist(gen));
	}

	std::string output;
	for (int digit : digits) {
		output += std::to_string(digit);
	}

	return output;
}

// Function to validate player's guess
bool is_valid_guess(const std::string& guess) {
    
	// string length checks
	if(guess.length() != lush::bac::game_number_size || guess.empty()){
		return false;
	}

	// if the input is not strictly unique digits
	std::unordered_set<char> guess_set;

	for(char character: guess) {
		
		// if the character in the guess isn't a digit, return invalid
		if(!std::isdigit(character)) return false;
		
		// in a set, we can expect existing element as unique. so we can
		// fish out duplicates by comparing the current char with the last inserted
		// char.
		if(guess_set.find(character) != guess_set.end()) return false;

		// given that none of these fail, keep track of the unique digit for next pass
		guess_set.insert(character);
	}	

	// if the input has a leading zero
	if(guess[0] == '0'){
		return false;
	}

	return true;

}

// Calculate bulls and cows for a given guess
std::pair<int, int> get_bulls_and_cows(const std::string& secret, const std::string& guess) {
    
	int bulls = 0;

	// create remainder set to any char val that isn't marked as a bull
	std::unordered_set<char> remainder;

	// char for char compare secret to guess
	for(unsigned int i = 0; i < secret.size(); i++){

		if(secret[i] == guess[i]) {
			bulls++;
		}
		else {
			remainder.insert(secret[i]);
		}

	}

	int cows = 0;
	// for chars in guess, if its in the remainder set, cows++
	for(char character : guess) {

		if(remainder.contains(character)) {
			cows++;
		}

	}

	return std::pair<int,int>(bulls, cows);

}

int main() {
    std::string secret = generate_secret();
    int attempts = 0;
	std::string guess;
    
    std::cout << "Welcome to Bulls and Cows!\n";
    
	// Initial guess logic, leads in to game logic
	std::cout << std::endl << "Enter a 4-digit guess (unique digits, no leading zero): ";
	std::cin >> guess;
	
	// Main game logic
    while(true) {
        
		// local cycle inits
		std::pair<int,int> bulls_and_cows = {0,0};

		// Prompt user for input
		if(guess == "") {
			std::cout << "Enter a 4-digit guess: ";
			std::cin >> guess;
		}
		
		// Validate user input
		bool valid_guess = is_valid_guess(guess); 
		
		// Calculate the bulls & cows
		if(valid_guess) {
			bulls_and_cows = get_bulls_and_cows(secret, guess);
			attempts++;

			// Win condition
			if (bulls_and_cows.first == lush::bac::game_number_size) {
				std::cout	<< lush::bac::game_number_size << " bulls. "
							<< "You win! " << "Attempts: " << attempts
							<< std::endl;
				return 0;
			}
			else {
				std::cout 	<< bulls_and_cows.first << " bulls, "
							<< bulls_and_cows.second << " cow. "
							<< "Try again!"
							<< std::endl;
			}
		}
		else {
			std::cout << "Guess invalid! Please only input 4 digits without a leading zero" << std::endl;
		}

		// Empty the guess cache to prepare for the next cycle
		guess = "";

    }
}