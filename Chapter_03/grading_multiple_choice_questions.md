#include <iostream>
#include <vector>

int main() {
    // 2D vector storing student answers (Rows: Students 0-7, Columns: Questions 0-5)
    std::vector<std::vector<char>> answers = {
        {'A', 'B', 'A', 'C', 'C', 'D'},  // Student 0
        {'D', 'B', 'A', 'B', 'C', 'A'},  // Student 1
        {'E', 'D', 'D', 'A', 'C', 'B'},  // Student 2
        {'C', 'B', 'A', 'E', 'D', 'C'},  // Student 3
        {'A', 'B', 'D', 'C', 'C', 'D'},  // Student 4
        {'B', 'B', 'E', 'C', 'C', 'D'},  // Student 5
        {'B', 'B', 'A', 'C', 'C', 'D'},  // Student 6
        {'E', 'B', 'E', 'C', 'C', 'D'}   // Student 7
    };

    // 1D vector storing the answer key
    std::vector<char> keys = {'D', 'B', 'D', 'C', 'C', 'D'};

    // Iterate through each student
    for (size_t i = 0; i < answers.size(); ++i) {
        int correct_count = 0;

        // Compare each answer to the corresponding key
        for (size_t j = 0; j < answers[i].size(); ++j) {
            if (answers[i][j] == keys[j]) {
                correct_count++;
            }
        }

        // Display results
        std::cout << "Student " << i << "'s correct count is " << correct_count << std::endl;
    }

    return 0;
}
