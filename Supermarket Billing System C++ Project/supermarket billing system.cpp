#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Structure to store product details
struct Product {
    string name;
    double price;
};

// Function to display the receipt
void displayReceipt(const vector<Product>& cart, double total) {
    cout << "\n--------------------------------------\n";
    cout << "           Supermarket Receipt         \n";
    cout << "--------------------------------------\n";
    for (const Product& product : cart) {
        cout << setw(20) << left << product.name << " : " << product.price << endl;
    }
    cout << "--------------------------------------\n";
    cout << setw(20) << left << "Total Bill" << " : " << total << endl;
    cout << "--------------------------------------\n";
}

int main() {
    vector<Product> cart;
    string productName;
    double productPrice;
    double totalBill = 0.0;

    cout << "Supermarket Billing System\n";
    cout << "Enter product details (Enter 'exit' as name to stop):\n";

    while (true) {
        cout << "Product name: ";
        cin >> productName;

        // Check if the user wants to exit
        if (productName == "exit") {
            break;
        }

        cout << "Product price: ";
        cin >> productPrice;

        // Add product to the cart
        cart.push_back({productName, productPrice});

        // Update total bill
        totalBill += productPrice;
    }

    // Display the receipt
    displayReceipt(cart, totalBill);

    return 0;
}
