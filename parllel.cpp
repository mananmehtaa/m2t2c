#include <iostream> // Header file for input/output stream
#include <vector>   // Header file for vectors
#include <omp.h>    // Header file for OpenMP library

using namespace std;

vector<int> quicksort_parallel(vector<int> nums)
{ // Function definition for parallel quicksort
    if (nums.size() <= 1)
    { // Check if the input vector is empty or contains only one element
        // If the list is empty or contains only one element, it is already sorted
        return nums; // Return the sorted vector
    }
    else
    {
        // Choose the first element as the pivot
        int pivot = nums[0];          // Assign the first element of the input vector as the pivot
        vector<int> left_nums, right; // Define two vectors for left and right partitions respectively
        // Partition the list into elements less than or greater than the pivot
        for (int i = 1; i < nums.size(); i++)
        { // Iterate over the input vector from the second element
            if (nums[i] <= pivot)
            {                                 // Check if the current element is less than or equal to the pivot
                left_nums.push_back(nums[i]); // Add the current element to the left partition
            }
            else
            {                             // Otherwise, the current element is greater than the pivot
                right.push_back(nums[i]); // Add the current element to the right partition
            }
        }
// Recursively sort the left and right partitions using OpenMP parallel sections
#pragma omp parallel sections // Start parallel sections block
        {
#pragma omp section // Start a section to sort the left partition
            {
                left_nums = quicksort_parallel(left_nums); // Sort the left partition recursively
            }
#pragma omp section // Start a section to sort the right partition
            {
                right = quicksort_parallel(right); // Sort the right partition recursively
            }
        } // End parallel sections block
        // Combine the sorted left partition, pivot, and sorted right partition
        vector<int> sorted_nums;                                                   // Define a vector to store the sorted elements
        sorted_nums.reserve(left_nums.size() + right.size() + 1);                  // Reserve memory for the sorted vector
        sorted_nums.insert(sorted_nums.end(), left_nums.begin(), left_nums.end()); // Add the sorted left partition to the sorted vector
        sorted_nums.push_back(pivot);                                              // Add the pivot to the sorted vector
        sorted_nums.insert(sorted_nums.end(), right.begin(), right.end());         // Add the sorted right partition to the sorted vector
        return sorted_nums;                                                        // Return the sorted vector
    }
}

int main()
{ // Main function
    // Prompt the user for input
    int n;                                            // Define a variable to store the number of integers to sort
    cout << "Enter the number of integers to sort: "; // Prompt the user to enter the number of integers to sort
    cin >> n;                                         // Read the number of integers from the user
    vector<int> nums(n);                              // Define a vector to store the input integers
    cout << "Enter the integers to sort:" << endl;    // Prompt the user to enter the integers to sort
    for (int i = 0; i < n; i++)
    {                   // Iterate over the input integers
        cin >> nums[i]; // Read the integer from the user and add it to the input vector
    }

    // Sort the input integers in parallel using quicksort
    double start_time = omp_get_wtime(); // Get the start time of the parallel quick
    // Define a vector of integers and call the function quicksort_parallel to sort it
    vector<int> sorted_nums = quicksort_parallel(nums);

    // Get the end time of the parallel quicksort algorithm execution
    double end_time = omp_get_wtime();

    // Output the sorted integers to the console
    cout << "Sorted integers: ";
    for (int i = 0; i < sorted_nums.size(); i++)
    {
        cout << sorted_nums[i] << " ";
    }

    // Output the execution time of the parallel quicksort algorithm to the console
    cout << endl;
    cout << "Execution time: " << end_time - start_time << " seconds" << endl;

    // Return 0 to indicate successful program execution
    return 0;
}
