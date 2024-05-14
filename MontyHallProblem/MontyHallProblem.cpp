#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

const int TRIALS = 1000;

void noSwitching() {
    int totalCorrect = 0;
    srand(time(NULL));

    for (int i = 0; i < TRIALS; i++) {
        int correctAnswer = (rand() % 3) + 1;
        int aiChoice = (rand() % 3) + 1;

        if (aiChoice == correctAnswer) {
            totalCorrect++;
        }
    }

    std::cout << "Correct Answers (without switching): " << totalCorrect << std::endl;

}

void yesSwitching() {

    int totalCorrect = 0;
    srand(time(NULL));
    
    for (int i = 0; i < TRIALS; i++) {
        int correctAnswer = (rand() % 3) + 1;
        int aiChoice = (rand() % 3) + 1;

        // Monty Hall always reveals a door that is not the correct answer and not the AI's initial choice
        int revealedDoor;
        do {
            revealedDoor = (rand() % 3) + 1;
        } while (revealedDoor == correctAnswer || revealedDoor == aiChoice);

        int newChoice;
        do {
            newChoice = (rand() % 3) + 1;
        } while (newChoice == aiChoice || newChoice == revealedDoor);
        
        if (newChoice == correctAnswer) {
            totalCorrect++;
        }
    }
        std::cout << "Correct Answers (with switching): " << totalCorrect << std::endl;

}

int main()
{
    std::cout << "Total Trials: " << TRIALS << std::endl;
    noSwitching();
    yesSwitching();


   
}

