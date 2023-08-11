#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cctype>

std::string selectRandomWord() {
    std::vector<std::string> words = {"computer", "language", "flash", "memory", "laptop", "rwanda", "kigali", "cpp", "hy"};
    srand(time(0));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

void displayGameInfo(int remainingGuesses, const std::string& guessedLetters) {
    std::cout << "You have " << remainingGuesses << " guesses left.\n";
    std::cout << "Available letters: ";
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (guessedLetters.find(ch) == std::string::npos) {
            std::cout << ch << " ";
        }
    }
    std::cout << "\n";
}

void displaySecretWord(const std::string& secretWord, const std::string& guessedLetters) {
    for (char letter : secretWord) {
        if (guessedLetters.find(letter) != std::string::npos || !std::isalpha(letter)) {
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << "\n";
}

char getGuess(const std::string& guessedLetters, int& warnings, int& remainingGuesses) {
    char guess;
    std::cout << "Guess a letter: ";
    std::cin >> guess;
    guess = std::tolower(guess);
    
    if (!std::isalpha(guess)) {
        if (warnings > 0) {
            std::cout << "Please enter a valid letter. You have " << warnings << " warning(s) left.\n";
            --warnings;
        } else {
            std::cout << "Please enter a valid letter. You've used all your warnings.\n";
            --remainingGuesses; // Deduct a guess
        }
    } else if (guessedLetters.find(guess) != std::string::npos) {
        std::cout << "You've already guessed that letter.\n";
    }
    
    return guess;
}
int main() {
    std::string secretWord = selectRandomWord();
    int totalUniqueLetters = 0;
    for (char letter : secretWord) {
        if (std::isalpha(letter)) {
            totalUniqueLetters++;
        }
    }
    
    int remainingGuesses = 6;
    int warnings = 3;
    std::string guessedLetters;
    
    std::cout << "Welcome to Hangman!\n";
    
    while (remainingGuesses > 0) {
        displayGameInfo(remainingGuesses, guessedLetters);
        
        std::cout << "Secret Word: ";
        displaySecretWord(secretWord, guessedLetters);
        
        char guess = getGuess(guessedLetters, warnings, remainingGuesses);
        
        if (!std::isalpha(guess) || guessedLetters.find(guess) != std::string::npos) {
            continue;
        }
        
        guessedLetters += guess;
        
        if (secretWord.find(guess) != std::string::npos) {
            std::cout << "Correct guess!\n";
        } else {
            std::cout << "Incorrect guess.\n";
            if (std::string("aeiou").find(guess) != std::string::npos) {
                remainingGuesses -= 2;
            } else {
                remainingGuesses -= 1;
            }
        }
        
        bool foundAllLetters = true;
        for (char letter : secretWord) {
            if (std::isalpha(letter) && guessedLetters.find(letter) == std::string::npos) {
                foundAllLetters = false;
                break;
            }
        }
        
        if (foundAllLetters) {
            int score = remainingGuesses * totalUniqueLetters;
            std::cout << "Congratulations, you've guessed the word: " << secretWord << "!\n";
            std::cout << "Your score: " << score << "\n";
            break;
        }
    }
    
    if (remainingGuesses == 0) {
        std::cout << "Sorry, you're out of guesses. The secret word was: " << secretWord << "\n";
    }
    
    return 0;
}
