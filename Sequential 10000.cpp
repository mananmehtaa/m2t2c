#include <iostream> // Importing standard input-output library
#include <vector>   // Importing vector library to work with vectors
#include <chrono>   // Importing library for measuring time

using namespace std; // Using standard namespace

vector<int> quicksort(vector<int> nums) // Function definition for QuickSort
{
    if (nums.size() <= 1) // Check if the vector contains only 1 or 0 elements
    {
        return nums; // Return the vector as it is already sorted
    }
    else
    {
        int pivot = nums[0];                  // Choose the first element as the pivot
        vector<int> left_nums, right;         // Create two vectors to hold the elements less than and greater than the pivot
        for (int i = 1; i < nums.size(); i++) // Loop through the remaining elements in the vector
        {
            if (nums[i] <= pivot) // If the element is less than or equal to the pivot
            {
                left_nums.push_back(nums[i]); // Add the element to the left vector
            }
            else
            {
                right.push_back(nums[i]); // Otherwise, add the element to the right vector
            }
        }
        left_nums = quicksort(left_nums);                                          // Recursively sort the left partition
        right = quicksort(right);                                                  // Recursively sort the right partition
        vector<int> sorted_nums;                                                   // Create a new vector to hold the sorted elements
        sorted_nums.reserve(left_nums.size() + right.size() + 1);                  // Reserve memory for the new vector
        sorted_nums.insert(sorted_nums.end(), left_nums.begin(), left_nums.end()); // Append the sorted left partition to the new vector
        sorted_nums.push_back(pivot);                                              // Append the pivot to the new vector
        sorted_nums.insert(sorted_nums.end(), right.begin(), right.end());         // Append the sorted right partition to the new vector
        return sorted_nums;                                                        // Return the sorted vector
    }
}

int main() // Main function
{
    vector<int> nums = {4, 2, 8, 5, 1, 3, 9, 6, 7}; // Create a vector of integers to be sorted (size = 9)

    auto start_time = chrono::steady_clock::now(); // Record the starting time of the quicksort function

    vector<int> sorted_nums = quicksort(nums); // Call the quicksort function on the vector of integers

    auto end_time = chrono::steady_clock::now(); // Record the ending time of the quicksort function

    for (int i = 0; i < sorted_nums.size(); i++) // Loop through the sorted integers
    {
        cout << sorted_nums[i] << " "; // Print each integer followed by a space
    }
    cout << endl; // Print a new line character to separate the output from the execution time

    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count(); // Calculate the execution time of the quicksort function

    cout << "Sequential execution time: " << elapsed_time << " microseconds" << endl; // Print the execution time in microseconds

    return 0; // Return 0 to indicate successful program execution
}
