// Include necessary libraries
#include <iostream>
#include <vector>
#include <chrono>

// Use the standard namespace
using namespace std;

// Define a function to perform quicksort on a vector of integers
vector<int> quicksort(vector<int> nums)
{
    // Check if the vector is empty or contains only one element
    if (nums.size() <= 1)
    {
        // If it is, return the vector as it is already sorted
        return nums;
    }
    else
    {
        // Choose the first element as the pivot
        int pivot = nums[0];
        // Create two vectors to hold the elements less than and greater than the pivot
        vector<int> left_nums, right;
        // Partition the list into elements less than or greater than the pivot
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= pivot)
            {
                left_nums.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
        // Recursively sort the left and right partitions
        left_nums = quicksort(left_nums);
        right = quicksort(right);
        // Combine the sorted left partition, pivot, and sorted right partition
        vector<int> sorted_nums;
        sorted_nums.reserve(left_nums.size() + right.size() + 1);
        sorted_nums.insert(sorted_nums.end(), left_nums.begin(), left_nums.end());
        sorted_nums.push_back(pivot);
        sorted_nums.insert(sorted_nums.end(), right.begin(), right.end());
        return sorted_nums;
    }
}

// Define the main function
int main()
{
    // Create a vector of integers to be sorted
    vector<int> nums = {4, 2, 8, 5, 1, 3, 9, 6, 7};

    // Record the starting time of the quicksort function
    auto start_time = chrono::steady_clock::now();

    // Call the quicksort function on the vector of integers
    vector<int> sorted_nums = quicksort(nums);

    // Record the ending time of the quicksort function
    auto end_time = chrono::steady_clock::now();

    // Print the sorted integers
    for (int i = 0; i < sorted_nums.size(); i++)
    {
        cout << sorted_nums[i] << " ";
    }
    cout << endl;

    // Calculate the execution time of the quicksort function
    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    cout << "Sequential execution time: " << elapsed_time << " microseconds" << endl;

    // Return 0 to indicate successful program execution
    return 0;
}
