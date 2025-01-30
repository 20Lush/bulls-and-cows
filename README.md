Here's a fun challenge: Implement the classic "Bulls and Cows" game, where the player tries to guess a 4-digit secret number with unique digits. For each guess:

1. **Bulls** = Correct digits in the right position  
2. **Cows** = Correct digits in the wrong position  

### Requirements:
- Generate a 4-digit secret number with unique digits (no leading zero)
- Validate player input (must be 4 unique digits, no leading zero)
- Calculate bulls and cows after each guess
- Track number of attempts until success
- Use only standard library features and console I/O

### Example Output:
```
Enter a 4-digit guess (unique digits, no leading zero): 1234
2 bulls, 1 cow. Try again!
Enter a 4-digit guess: 5678
0 bulls, 1 cow. Try again!
...
```

### Key Concepts to Practice:
- Random number generation with constraints
- Input validation and error handling
- String/character manipulation
- STL containers (sets, vectors)
- Algorithm design (bulls/cows calculation)
- Code organization into functions

### Starter Code Skeleton:
```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

// Function to generate a valid 4-digit secret number
std::string generate_secret() {
    // Your implementation here
}

// Function to validate player's guess
bool is_valid_guess(const std::string& guess) {
    // Your validation logic here
}

// Calculate bulls and cows for a given guess
std::pair<int, int> get_bulls_and_cows(const std::string& secret, const std::string& guess) {
    // Your calculation logic here
}

int main() {
    std::string secret = generate_secret();
    int attempts = 0;
    
    std::cout << "Welcome to Bulls and Cows!\n";
    
    while(true) {
        // Your game loop implementation here
    }
}
```

### Challenge Tier:
1. Add difficulty levels (e.g., 3-digit numbers for easier mode)
2. Track high scores between sessions (using file I/O)
3. Add hints after N failed attempts
4. Create an AI opponent that plays against you

This problem tests your ability to handle multiple constraints, work with strings/numbers, and design clean logic flows – all common in technical interviews. It's also fun to play when finished!

# Solution

see ./executable/src/main.cpp

# Usage

1. Launch my dev container
2. cd to ./scripts/
3. run ./get_dependencies.sh
4. run ./compile.sh
5. exec installed executable

compiled in gcc, dev container lacks gdb debugger though :(