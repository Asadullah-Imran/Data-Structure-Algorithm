#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value, weight;

    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Descending order
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int W, vector<Item> &items) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Total value of items in the knapsack

    for (auto &item : items) {
        if (item.weight <= W) {
            // Take the whole item
            totalValue += item.value;
            W -= item.weight;
        } else {
            // Take a fraction of the item
            totalValue += item.value * ((double)W / item.weight);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Capacity of knapsack
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // Value, Weight

    cout << "Maximum value in the knapsack: " << fractionalKnapsack(W, items) << endl;

    return 0;
}
