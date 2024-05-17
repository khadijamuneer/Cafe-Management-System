#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PROJECT.h"
using namespace std;

void Welcome()
{
    cout << "***********************************************************************************************************************" << endl;
    cout << endl;
    cout << "                           Welcome to Aurora Aromas Cafe" << endl;
    cout << "             Embark on a Flavor Odyssey at Aurora Aromas Co. – Where Every Sip is an Adventure!" << endl;
    cout << endl;
    cout << "***********************************************************************************************************************" << endl;
}

// ***************************************************************************
//                  	      User Class                                     *
// ***************************************************************************


// ***************************************************************************
//                        Rejister                                           *
// ***************************************************************************
void User::Register()
{
    string UserID;
    string UserName;
    string Password;
    string UserType;
    cout << "Enter UserID: ";
    cin >> UserID;

    cout << "Enter UserName: ";
    cin >> UserName;

    cout << "Enter Password: ";
    cin >> Password;


    // Open the file in append mode and store user details
    ofstream outFile(UserType + "_data.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "UserID: " << UserID << "\n";
        outFile << "UserName: " << UserName << "\n";
        outFile << "Password: " << Password << "\n";
        outFile.close();
        cout << "Registration successful.\n";
    }
    else {
        cerr << "Error opening file for registration.\n";
    }
}

// ***************************************************************************
//                        Login                                              *
// ***************************************************************************

void User::Login() {
    string UserID;
    string UserName;
    string Password;
    string UserType;
    cout << "Enter UserName: ";
    cin >> UserName;

    cout << "Enter Password: ";
    cin >> Password;

    // Open the file and check for user credentials
    ifstream inFile(UserType + "_data.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find("UserName: " + UserName) != string::npos &&
            getline(inFile, line) && line.find("Password: " + Password) != string::npos) {
            found = true;
            break;
        }
    }

    inFile.close();

    if (found) {
        cout << "Login successful. Welcome, " << UserName << "!\n";
    }
    else {
        cout << "Login successful. Welcome, " << UserName << "!\n";
    }
}

// ***************************************************************************
//                          User                                             *
// ***************************************************************************


void User::user()
{
    int choice;
    cout << "Do you want to Login or Register?" << endl;
    cout << "Enter 1 to register" << endl;
    cout << "Enter 2 to Login" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        Register();
        break;
    case 2:
        Login();
        break;
    default:
        cout << "Invalid choice.\n";
        break;
    }
}

// ***************************************************************************
//                  	Administrator Class                                  *
// ***************************************************************************

// ***************************************************************************
//                      Faculty Menu                                         *
// ***************************************************************************

void Administrator::FacultyMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Lamonade", "Cheese Pasta", "Beef Burger",
                                     "Fries", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }

}

// ***************************************************************************
//                     Non Faculty Menu                                      *
// ***************************************************************************

void Administrator::NonFacultyMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Salad", "Roll Parhata", "Lemon Margarita", "Cheese Pasta", "Beef Burger",
                                     "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        std::cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }

}

// ***************************************************************************
//                      Student Menu                                         *
// ***************************************************************************

void Administrator::StudentMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Zinger Roll Parhata", "Fries", "Cheese Pasta", "Beef Burger",
                                     "Loaded Fries", "Karachi Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }
}

// ***************************************************************************
//                       Add Menu                                            *
// ***************************************************************************

void Administrator::AddMenuItem()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Mint Margarita", "Cheese Pasta", "Beef Burger",
                                      "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;

    // Get user input for the new item
    cout << "Enter the name of the new item: ";
    string newItem;
    getline(cin, newItem);

    // Get user input for the price of the new item
    cout << "Enter the price of the new item: ";
    int newPrice;
    cin >> newPrice;

    // Add the new menu item
    if (menuSize < maxMenuSize) {
        menu[menuSize] = newItem;
        prices[menuSize] = newPrice;
        menuSize++;
        cout << "Item added successfully!\n";
    }
    else {
        cout << "Menu is full. Cannot add more items.\n";
    }
}

// ***************************************************************************
//                       Remove Menu                                         *
// ***************************************************************************

void Administrator::RemoveMenuItem()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Mint Margarita", "Cheese Pasta", "Beef Burger",
                                      "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;

    // Get user input to remove item
    cout << "Enter the name of the item to remove: ";
    string Itemremove;
    getline(cin, Itemremove);


    // Remove the item
    if (menuSize < maxMenuSize) {
        menu[menuSize] = Itemremove;
        menuSize--;
        cout << "Item removed successfully!\n";
    }
}

// ***************************************************************************
//                        Manage Inventory                                   *
// ***************************************************************************

const int MAX_ITEMS = 10;
string items[MAX_ITEMS];
int quantities[MAX_ITEMS];

void InitializeStock() {
    items[0] = "Coffee";
    items[1] = "Tea";
    items[2] = "Sandwich";
    items[3] = "Cake";
    items[4] = "Juice";
    items[5] = "Salad";
    items[6] = "Burger";
    items[7] = "Smoothie";
    items[8] = "Cookies";
    items[9] = "Water";

    // Initialize quantities to a specific value
    for (int i = 0; i < MAX_ITEMS; ++i) {
        quantities[i] = 10;  // Set an initial quantity (e.g., 10) for each item
    }
}

void DisplayStock() {
    cout << setw(15) << "Item" << setw(15) << "Quantity" << endl;
    for (int i = 0; i < MAX_ITEMS; ++i) {
        cout << setw(15) << items[i] << setw(15) << quantities[i] << endl;
    }
}

void UpdateStock() {
    string itemName;
    int quantity;

    cout << "Enter item name: ";
    cin >> itemName;

    // Check if the item exists
    int index = -1;
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (items[i] == itemName) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Enter quantity to add/update (-1 to stop): ";
        while (true) {
            cin >> quantity;
            if (quantity == -1) {
                cout << "Exiting stock update.\n";
                return;  // Terminate the function
            }

            // Update the quantity
            quantities[index] += quantity;

            cout << "Stock updated successfully! Enter another quantity (-1 to stop): ";
        }
    }
    else {
        cout << "Item not found in the stock." << endl;
    }
}

void Administrator::ManageInventory() {
    InitializeStock();

    int choice;
    do {
        cout << "\n1. Update Stock\n2. Display Stock\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            UpdateStock();
            break;
        case 2:
            DisplayStock();
            break;
        case 3:
            cout << "Exiting inventory management.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// ***************************************************************************
//                      Manage Discunt Promotions                            *
// ***************************************************************************

const int maxMenuSize = 12;
string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Mint Margarita", "Cheese Pasta", "Beef Burger",
                                   "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };
int discounts[maxMenuSize] = { 0 }; // Initial discounts are set to zero

void DisplayMenuWithDiscounts() {
    cout << "Menu with Discounts:\n";
    for (int i = 0; i < maxMenuSize; ++i) {
        cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\tDiscount:" << discounts[i] << "%\n";
    }
}

void CreateOrUpdateDiscount() {
    int menuItem;
    int discount;

    cout << "Enter the menu item number to create/update discount: ";
    cin >> menuItem;

    if (menuItem >= 1 && menuItem <= maxMenuSize) {
        cout << "Enter the discount percentage for " << menu[menuItem - 1] << ": ";
        cin >> discount;

        discounts[menuItem - 1] = discount;
        cout << "Discount updated successfully!\n";
    }
    else {
        cout << "Invalid menu item number.\n";
    }
}

void RemoveDiscount() {
    int menuItem;

    cout << "Enter the menu item number to remove discount: ";
    cin >> menuItem;

    if (menuItem >= 1 && menuItem <= maxMenuSize) {
        discounts[menuItem - 1] = 0;
        cout << "Discount removed successfully!\n";
    }
    else {
        cout << "Invalid menu item number.\n";
    }
}

void Administrator::ManageDiscountPromotion() {

    int choice;

    do {
        cout << "\n1. Display Menu with Discounts\n";
        cout << "2. Create/Update Discount\n";
        cout << "3. Remove Discount\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            DisplayMenuWithDiscounts();
            break;
        case 2:
            CreateOrUpdateDiscount();
            break;
        case 3:
            RemoveDiscount();
            break;
        case 4:
            cout << "Exiting discount and promotion management.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// ***************************************************************************
//                      View Order History                                   *
// ***************************************************************************

void Administrator::ViewOrderHistory() {
    const int maxOrders = 3;
    string itemNames[maxOrders] = { "Burger", "Rics", "Tea" };
    int quantities[maxOrders] = { 2, 1, 3 };
    double totalPrices[maxOrders] = { 25.0, 15.5, 40.75 };

    if (maxOrders == 0) {
        cout << "No order history available.\n";
    }
    else {
        cout << "Order History:\n";
        for (int i = 0; i < maxOrders; ++i) {
            cout << "Item: " << itemNames[i] << "\n";
            cout << "Quantity: " << quantities[i] << "\n";
            cout << "Total Price: $" << totalPrices[i] << "\n";
            cout << "------------------------\n";
        }
    }
}


// ***************************************************************************
//                      Add Notifications                                    *
// ***************************************************************************


void Administrator::AddNotification()
{
    int notification;
    cout << "Enter the notification you want to display" << endl;
    cin >> notification;
}

// ***************************************************************************
//                     Remove Notifications                                  *
// ***************************************************************************

void Administrator::RemoveNotification() {
    const size_t maxNotifications = 3;
    string notifications[maxNotifications] = {
        "New order received for Table 1: Coffee and Croissant",
        "Reservation reminder: Table 3 at 7:00 PM",
        "Out of stock: Cappuccino and Blueberry Muffin"
    };
    size_t numNotifications = maxNotifications;

    if (numNotifications == 0) {
        cout << "No notifications to display.\n";
        return;
    }

    // Display notifications
    cout << "Notifications:\n";
    for (size_t i = 0; i < numNotifications; ++i) {
        cout << i + 1 << ". " << notifications[i] << "\n";
    }

    // Ask the user to remove a notification
    cout << "Enter the number of the notification to remove (0 to cancel): ";
    size_t choice;
    cin >> choice;

    if (choice == 0 || choice > numNotifications) {
        cout << "No notification removed.\n";
    }
    else {
        // Remove the selected notification
        for (size_t i = choice - 1; i < numNotifications - 1; ++i) {
            notifications[i] = notifications[i + 1];
        }
        --numNotifications;
        cout << "Notification removed.\n";
    }

    // Display updated notifications
    cout << "Updated Notifications:\n";
    for (size_t i = 0; i < numNotifications; ++i) {
        cout << notifications[i] << "\n";
    }
}

// ***************************************************************************
//                      Rate Menu Item                                       *
// ***************************************************************************

void Administrator::RateMenuItem() {
    FacultyMenu();
    cout << "Enter the number of the item you want to rate: ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > maxMenuSize) {
        cout << "Invalid choice.\n";
        return;
    }

    // Adjusting for array indexing
    int index = choice - 1;

    // Get user's rating and feedback
    cout << "Enter your rating (1 to 5): ";
    int rating;
    cin >> rating;

    if (rating < 1 || rating > 5) {
        cout << "Invalid rating. Ratings should be between 1 and 5.\n";
        return;
    }

    cout << "Enter your feedback: ";
    string feedback;
    cin.ignore(); // Clear the input buffer
    getline(cin, feedback);

    // Display confirmation message
    cout << "Thank you for rating the item!\n";
    cout << "You rated " << menu[index] << " with " << rating << " stars.\n";
    cout << "Feedback: " << feedback << "\n";
}

// ***************************************************************************
//                     Display From File                                     *
// ***************************************************************************

void Administrator::DisplayFromFile() {
    string filename = "admin_data.txt"; // File containing specific administrative data

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    cout << "Administrative Data from File:\n";

    while (!inputFile.eof()) {
        string line;
        getline(inputFile, line);

        // Display the data
        cout << line << "\n";
    }

    inputFile.close();
}

// ***************************************************************************
//                  	View Users From File                                 *
// ***************************************************************************

void Administrator::ViewUserFromFile(const string& filename, int startCustomer, int endCustomer) {
    // Writing sample customer data to the file
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << "Ali 25 ali@example.com\n";
        outputFile << "Sara 30 sara@example.com\n";
        outputFile << "John 22 john@example.com\n";
        outputFile << "Aisha 28 aisha@example.com\n";
        outputFile << "Ahmed 35 ahmed@example.com\n";
        outputFile.close();
    }
    else {
        cout << "Error creating file.\n";
        return;
    }

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    cout << "Customer Data from File (Customers " << startCustomer << " to " << endCustomer << "):\n";

    int customerCount = 0;
    string name, email;
    int age;

    while (!inputFile.eof() && customerCount < endCustomer) {
        // Read data from the file
        inputFile >> name >> age >> email;

        // Display the data for the specified range of customers
        if (customerCount >= startCustomer - 1) {
            cout << "Name: " << name << "\n";
            cout << "Age: " << age << "\n";
            cout << "Email: " << email << "\n";
            cout << "------------------------\n";
        }

        ++customerCount;
    }

    inputFile.close();
}

// ***************************************************************************
//                  	View Menu Items From File                            *
// ***************************************************************************



// Function to write menu items to a file and view them
void  Administrator::ViewMenultemsFromFile() {
    FacultyMenu();
    int menuSize = 12;
    string filename = "menu_data.txt";

    // Writing menu items to the file
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cout << "Error creating file: " << filename << "\n";
        return;
    }

    for (int i = 0; i < menuSize; ++i) {
        outputFile << menu[i] << " " << prices[i] << "\n";
    }

    outputFile.close();

    // Viewing menu items from the file
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    cout << "Menu Items from File:\n";

    int itemIndex = 0;
    while (!inputFile.eof() && itemIndex < menuSize) {
        // Read data from the file
        inputFile >> menu[itemIndex] >> prices[itemIndex];

        // Display menu item details
        cout << itemIndex + 1 << ". " << menu[itemIndex] << "\tRs:" << prices[itemIndex] << "\n";

        ++itemIndex;
    }

    inputFile.close();
}

// ***************************************************************************
//                  	View Orders From File                                *
// ***************************************************************************

void Administrator::ViewOrdersFromFile() {
    const int maxOrderSize = 4; // Number of orders to view
    string orders[maxOrderSize]; // Array to store order information

    string filename = "orders_data.txt";

    // Writing orders to the file
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cout << "Error creating file: " << filename << "\n";
        return;
    }

    // Default orders for demonstration
    outputFile << "Burger with Fries and Cola\n";
    outputFile << "Pizza with Garlic Bread\n";
    outputFile << "Chicken Wings\n";

    cout << "Enter information for the remaining " << maxOrderSize - 3 << " orders:\n";
    for (int i = 3; i < maxOrderSize; ++i) {
        cout << "Order " << i + 1 << ":\n";
        getline(cin, orders[i]); // Assuming one line of order information
        outputFile << orders[i] << "\n";
    }

    outputFile.close();

    // Viewing orders from the file
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    cout << "Orders Information from File:\n";

    int orderIndex = 0;
    while (!inputFile.eof() && orderIndex < maxOrderSize) {
        // Read data from the file
        getline(inputFile, orders[orderIndex]);

        // Display order details
        cout << "Order " << orderIndex + 1 << ": " << orders[orderIndex] << "\n";

        ++orderIndex;
    }

    inputFile.close();
}

// ***************************************************************************
//                  	View Ratings From File                               *
// ***************************************************************************

void Administrator::ViewRatingsFromFile() {
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Mint Margarita", "Cheese Pasta", "Beef Burger",
                                 "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };
    int ratings[maxMenuSize];
    string feedback[maxMenuSize];

    string filename = "ratings_data.txt";

    // Writing default ratings and feedback to the file
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cout << "Error creating file: " << filename << "\n";
        return;
    }

    // Default ratings and feedback for demonstration
    outputFile << "Tea\tRating: 4\tFeedback: Good\n";
    outputFile << "Coffee\tRating: 3\tFeedback: Okay\n";
    outputFile << "Roll Parhata\tRating: 5\tFeedback: Excellent\n";

    cout << "Provide ratings and feedback for the remaining menu items:\n";
    for (int i = 3; i < maxMenuSize; ++i) {
        cout << "Menu Item: " << menu[i] << "\n";
        cout << "Rating (1-5): ";
        cin >> ratings[i];
        cin.ignore(); // Ignore the newline character in the input buffer
        cout << "Feedback: ";
        getline(cin, feedback[i]);

        outputFile << menu[i] << "\tRating: " << ratings[i] << "\tFeedback: " << feedback[i] << "\n";
    }

    outputFile.close();

    // Viewing ratings and feedback from the file
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    cout << "Ratings and Feedback from File:\n";

    while (!inputFile.eof()) {
        string line;
        getline(inputFile, line);
        cout << line << "\n";
    }

    inputFile.close();
}

// ***************************************************************************
//                  	View Payements From File                             *
// ***************************************************************************

void Administrator::ViewPaymentsFromFile() {
    string filename = "payments_data.txt";

    // Writing previous payment details to the file
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cout << "Error creating file: " << filename << "\n";
        return;
    }

    // Default payment details for demonstration
    outputFile << "Payment ID: 001\tAmount: $50\tDate: 2023-01-15\n";
    outputFile << "Payment ID: 002\tAmount: $75\tDate: 2023-02-20\n";
    outputFile << "Payment ID: 003\tAmount: $100\tDate: 2023-03-25\n";

    outputFile.close();

    // Viewing previous payment details from the file
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    cout << "Previous Payment Details from File:\n";

    while (!inputFile.eof()) {
        string line;
        getline(inputFile, line);
        cout << line << "\n";
    }

    inputFile.close();
}

// ***************************************************************************
//                  	Calculate Monthly Earnings                           *
// ***************************************************************************

void Administrator::CalculateMonthlyEarnings()
{

    string filename = "payments_data.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        return;
    }

    double totalEarnings = 0.0;

    cout << "Payment Records and Monthly Earnings:\n";

    while (!inputFile.eof()) {
        string line;
        getline(inputFile, line);

        // Display payment record
        cout << line << "\n";

        // Extract amount from the payment record and accumulate total earnings
        size_t amountPos = line.find("Amount: $");
        if (amountPos != string::npos) {
            size_t endPos = line.find("\t", amountPos);
            if (endPos != string::npos) {
                string amountStr = line.substr(amountPos + 9, endPos - amountPos - 9);
                double amount = stod(amountStr);
                totalEarnings += amount;
            }
        }
    }

    inputFile.close();

    cout << "Total Monthly Earnings: $" << totalEarnings << "\n";

}

// ***************************************************************************
//                  	          Logout                                     *
// ***************************************************************************

void Administrator::Logout() {
    cout << "Goodbye! Have a great day It was really nice having you here!\n";
}

void Administrator::option()
{
    int option;
    cout << "For whom you want to check the details?" << endl;
    cout << "1. Faculty" << endl;
    cout << "2. Non Faculty" << endl;
    cout << "3. Student" << endl;
    cin >> option;
    switch (option)
    {
    case 1:

        cout << "What you want to do from following?" << endl;
        cout << "Welcome Administrator! How may I help you " << endl << "Which of the following function do you want to perform" << endl;
        cout << "1. Do you want to view Menu?" << endl;
        cout << "2. Do you want to add something to the menu?" << endl;
        cout << "3. Do you want to remove something to the menu?" << endl;
        cout << "4. Do you want to do manage inventory?" << endl;
        cout << "5. Do you want to manage discount promotion?" << endl;
        cout << "6. Do you want to view order history?" << endl;
        cout << "7. Do you want to add notification?" << endl;
        cout << "8. Do you want to remove notification?" << endl;
        cout << "9. Do you want to rate menu item?" << endl;
        cout << "10. Do you want to Display from file?" << endl;
        cout << "11. Do you want to view user from file?" << endl;
        cout << "12. Do you want to view menu items from file?" << endl;
        cout << "13. Do you want to view orders from file?" << endl;
        cout << "14. Do you want to view ratings from file?" << endl;
        cout << "15. Do you want to view payments from file?" << endl;
        cout << "16. Do you want to calculate monthly earnings?" << endl;
        cout << "17. Do you want to logout?" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "Here is the menu" << endl;
            Administrator::FacultyMenu();
            break;
        case 2:
            AddMenuItem();
            break;
        case 3:
            RemoveMenuItem();
            break;
        case 4:
            ManageInventory();

            break;
        case 5:
            ManageDiscountPromotion();
            break;
        case 6:
            ViewOrderHistory();
            break;
        case 7:
            AddNotification();
            break;
        case 8:
            RemoveNotification();
            break;
        case 9:
            RateMenuItem();
            break;
        case 10:
            DisplayFromFile();
            break;
        case 11:
            ViewUserFromFile("customer_data.txt", 3, 4);
            break;
        case 12:
            ViewMenultemsFromFile();
            break;
        case 13:
            ViewOrdersFromFile();
            break;
        case 14:
            ViewRatingsFromFile();
            break;
        case 15:
            ViewPaymentsFromFile();
        case 16:
            CalculateMonthlyEarnings();
            break;
        case 17:
            Logout();
            break;

        }
    case 2:
        cout << "What you want to do from following?" << endl;
        cout << "Welcome Administrator! How may I help you " << endl << "Which of the following function do you want to perform" << endl;
        cout << "1. Do you want to view Menu?" << endl;
        cout << "2. Do you want to add something to the menu?" << endl;
        cout << "3. Do you want to remove something to the menu?" << endl;
        cout << "4. Do you want to do manage inventory?" << endl;
        cout << "5. Do you want to manage discount promotion?" << endl;
        cout << "6. Do you want to view order history?" << endl;
        cout << "7. Do you want to add notification?" << endl;
        cout << "8. Do you want to remove notification?" << endl;
        cout << "9. Do you want to rate menu item?" << endl;
        cout << "10. Do you want to Display from file?" << endl;
        cout << "11. Do you want to view user from file?" << endl;
        cout << "12. Do you want to view menu items from file?" << endl;
        cout << "13. Do you want to view orders from file?" << endl;
        cout << "14. Do you want to view ratings from file?" << endl;
        cout << "15. Do you want to view payments from file?" << endl;
        cout << "16. Do you want to calculate monthly earnings?" << endl;
        cout << "17. Do you want to logout?" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "Here is the menu" << endl;
            NonFacultyMenu();
            break;
        case 2:
            AddMenuItem();
            break;
        case 3:
            RemoveMenuItem();
            break;
        case 4:
            ManageInventory();
            break;
        case 5:
            ManageDiscountPromotion();
            break;
        case 6:
            ViewOrderHistory();
            break;
        case 7:
            AddNotification();
            break;
        case 8:
            RemoveNotification();
            break;
        case 9:
            RateMenuItem();
            break;
        case 10:
            DisplayFromFile();
            break;
        case 11:
            ViewUserFromFile("customer_data.txt", 3, 4);
            break;
        case 12:
            ViewMenultemsFromFile();
            break;
        case 13:
            ViewOrdersFromFile();
            break;
        case 14:
            ViewRatingsFromFile();
            break;
        case 15:
            ViewPaymentsFromFile();
        case 16:
            CalculateMonthlyEarnings();
            break;
        case 17:
            Logout();
            break;

        }
    case 3:
        cout << "What you want to do from following?" << endl;
        cout << "Welcome Administrator! How may I help you " << endl << "Which of the following function do you want to perform" << endl;
        cout << "1. Do you want to view Menu?" << endl;
        cout << "2. Do you want to add something to the menu?" << endl;
        cout << "3. Do you want to remove something to the menu?" << endl;
        cout << "4. Do you want to do manage inventory?" << endl;
        cout << "5. Do you want to manage discount promotion?" << endl;
        cout << "6. Do you want to view order history?" << endl;
        cout << "7. Do you want to add notification?" << endl;
        cout << "8. Do you want to remove notification?" << endl;
        cout << "9. Do you want to rate menu item?" << endl;
        cout << "10. Do you want to Display from file?" << endl;
        cout << "11. Do you want to view user from file?" << endl;
        cout << "12. Do you want to view menu items from file?" << endl;
        cout << "13. Do you want to view orders from file?" << endl;
        cout << "14. Do you want to view ratings from file?" << endl;
        cout << "15. Do you want to view payments from file?" << endl;
        cout << "16. Do you want to calculate monthly earnings?" << endl;
        cout << "17. Do you want to logout?" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "Here is the menu" << endl;
            StudentMenu();
            break;
        case 2:
            AddMenuItem();
            break;
        case 3:
            RemoveMenuItem();
            break;
        case 4:
            ManageInventory();
            break;
        case 5:
            ManageDiscountPromotion();
            break;
        case 6:
            ViewOrderHistory();
            break;
        case 7:
            AddNotification();
            break;
        case 8:
            RemoveNotification();
            break;
        case 9:
            RateMenuItem();
            break;
        case 10:
            DisplayFromFile();
            break;
        case 11:
            ViewUserFromFile("customer_data.txt", 3, 4);
            break;
        case 12:
            ViewMenultemsFromFile();
            break;
        case 13:
            ViewOrdersFromFile();
            break;
        case 14:
            ViewRatingsFromFile();
            break;
        case 15:
            ViewPaymentsFromFile();
        case 16:
            CalculateMonthlyEarnings();
            break;
        case 17:
            Logout();
            break;

        }

    }
}



// ***************************************************************************
//                  	Cafe Staff Class                                     *
// ***************************************************************************

// ***************************************************************************
//                      Faculty Menu                                         *
// ***************************************************************************

void CafeStaff::FacultyMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Lamonade", "Cheese Pasta", "Beef Burger",
                                     "Fries", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }

}

// ***************************************************************************
//                     Non Faculty Menu                                      *
// ***************************************************************************

void CafeStaff::NonFacultyMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Salad", "Roll Parhata", "Lemon Margarita", "Cheese Pasta", "Beef Burger",
                                     "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        std::cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }

}

// ***************************************************************************
//                      Student Menu                                         *
// ***************************************************************************

void CafeStaff::StudentMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Zinger Roll Parhata", "Fries", "Cheese Pasta", "Beef Burger",
                                     "Loaded Fries", "Karachi Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }
}

// ***************************************************************************
//                         View Menu                                         *
// ***************************************************************************

void CafeStaff::ViewMenu() {
    int option;
    cout << "Select any menu" << endl;
    cout << "1.FacultyMenu" << endl;
    cout << "2. StudentMenu" << endl;
    cout << "3.NonFacultyMenu" << endl;
    cin >> option;
    if (option == 1) {
        FacultyMenu();
    }
    else if (option == 2) {
        StudentMenu();
    }
    if (option == 3) {
        NonFacultyMenu();
    }

}

// ***************************************************************************
//                       Add Menu                                            *
// ***************************************************************************

void CafeStaff::AddMenuItem()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Mint Margarita", "Cheese Pasta", "Beef Burger",
                                      "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;

    // Get user input for the new item
    cout << "Enter the name of the new item: ";
    string newItem;
    getline(cin, newItem);

    // Get user input for the price of the new item
    cout << "Enter the price of the new item: ";
    int newPrice;
    cin >> newPrice;

    // Add the new menu item
    if (menuSize < maxMenuSize) {
        menu[menuSize] = newItem;
        prices[menuSize] = newPrice;
        menuSize++;
        cout << "Item added successfully!\n";
    }
    else {
        cout << "Menu is full. Cannot add more items.\n";
    }
}

// ***************************************************************************
//                       Remove Menu                                         *
// ***************************************************************************

void CafeStaff::RemoveMenuItem()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Mint Margarita", "Cheese Pasta", "Beef Burger",
                                      "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;

    // Get user input to remove item
    cout << "Enter the name of the item to remove: ";
    string Itemremove;
    cin.ignore();
    getline(cin, Itemremove);


    // Remove the item
    bool itemFound = false;
    for (int i = 0; i < menuSize; ++i) {
        if (menu[i] == Itemremove) {
            // Shift items to fill the gap
            for (int j = i; j < menuSize - 1; ++j) {
                menu[j] = menu[j + 1];
                prices[j] = prices[j + 1];
            }

            // Decrease the menu size
            menuSize--;

            // Set itemFound to true
            itemFound = true;

            // Break out of the loop since the item is found and removed
            break;
        }
    }

    if (itemFound) {
        cout << "Item removed successfully!\n";
    }
    else {
        cout << "Item not found. Nothing removed.\n";
    }
}

// ***************************************************************************
//                       Process Order                                       *
// ***************************************************************************

void CafeStaff::ProcessOrder() {

    int choice;

    do {
        cout << "Menu Management System" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Add Item" << endl;;
        cout << "3. Remove Item" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ViewMenu();
            break;
        case 2:
            AddMenuItem();
            break;
        case 3:
            RemoveMenuItem();
            break;
        case 4:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

}

// ***************************************************************************
//                       Customer Class                                      *
// ***************************************************************************

// ***************************************************************************
//                      Faculty Menu                                         *
// ***************************************************************************

void Customer::FacultyMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Roll Parhata", "Lamonade", "Cheese Pasta", "Beef Burger",
                                     "Fries", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }

}

// ***************************************************************************
//                     Non Faculty Menu                                      *
// ***************************************************************************

void Customer::NonFacultyMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Salad", "Roll Parhata", "Lemon Margarita", "Cheese Pasta", "Beef Burger",
                                     "Zinger Roll Parhata", "Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        std::cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }

}

// ***************************************************************************
//                      Student Menu                                         *
// ***************************************************************************

void Customer::StudentMenu()
{
    const int maxMenuSize = 12;
    string menu[maxMenuSize] = { "Tea", "Coffee", "Zinger Roll Parhata", "Fries", "Cheese Pasta", "Beef Burger",
                                     "Loaded Fries", "Karachi Biryani", "Palao", "Cheesecake", "Mutton Korma", "Chicken Tikka Masala" };

    int prices[maxMenuSize] = { 70, 120, 180, 220, 180, 280, 180, 180, 180, 180, 180, 180 };

    int menuSize = maxMenuSize;
    cout << "Menu:\n";
    for (int i = 0; i < menuSize; ++i) {
        cout << i + 1 << ". " << menu[i] << "\tRs:" << prices[i] << "\n";
    }
}

// ***************************************************************************
//                         View Menu                                         *
// ***************************************************************************

void Customer::ViewMenu() {
    int option;
    cout << "Select any menu" << endl;
    cout << "1.FacultyMenu" << endl;
    cout << "2. StudentMenu" << endl;
    cout << "3.NonFacultyMenu" << endl;
    cin >> option;
    if (option == 1) {
        FacultyMenu();
        StudentMenu();
        NonFacultyMenu();
    }
    else if (option == 2) {
        StudentMenu();
    }
    if (option == 3) {
        NonFacultyMenu();
    }

}

// *************************
//                         Place Order                                       *
// *************************



void Customer::PlaceOrder()
{

    string user_type;
    cout << "Please input your status:" << endl;
    cout << " 1. Student" << endl;
    cout << " 2. Faculty" << endl;
    cout << " 3. Non-Faculty" << endl;
    cin >> user_type;


    cout << "Placing order for " << user_type << std::endl;


    cout << "Enter the item number you want to order: ";
    int itemNumber;
    cin >> itemNumber;


    if (user_type == "student" && (itemNumber < 1 || itemNumber > 12))
    {
        cout << "Invalid item number. Exiting." << endl;
        return;
    }
    else if (user_type == "faculty" && (itemNumber < 1 || itemNumber > 12))
    {
        cout << "Invalid item number. Exiting." << endl;
        return;
    }
    else if (user_type == "non-faculty" && (itemNumber < 1 || itemNumber > 12))
    {
        cout << "Invalid item number. Exiting." << endl;
        return;
    }


    string itemName;
    if (user_type == "student") {
        switch (itemNumber) {
        case 1:
            itemName = "Tea";
            break;
        case 2:
            itemName = "Coffee";
            break;
        case 3:
            itemName = "Zinger Roll Parhata";
            break;
        case 4:
            itemName = "Mayo Fries";
            break;
        case 5:
            itemName = "Alfredo Pasta";
            break;
        case 6:
            itemName = "Chicken Burger";
            break;
        case 7:
            itemName = "Loaded Fries";
            break;
        case 8:
            itemName = "Karachi Biryani";
            break;
        case 9:
            itemName = "Palao";
            break;
        case 10:
            itemName = "Cheesecake";
            break;
        case 11:
            itemName = "Mutton Korma";
            break;
        case 12:
            itemName = "Chicken Tikka Masala";
            break;
        }
    }


    else if (user_type == "faculty") {
        switch (itemNumber)
        {
        case 1:
            itemName = "Tea";
            break;
        case 2:
            itemName = "Coffee";
            break;
        case 3:
            itemName = "Roll Parhata";
            break;
        case 4:
            itemName = "Lemonade";
            break;
        case 5:
            itemName = "Cheese Pasta";
            break;
        case 6:
            itemName = "Beef Burger";
            break;
        case 7:
            itemName = " Fries";
            break;
        case 8:
            itemName = " Biryani";
            break;
        case 9:
            itemName = "Palao";
            break;
        case 10:
            itemName = "Cheesecake";
            break;
        case 11:
            itemName = "Mutton Korma";
            break;
        case 12:
            itemName = "Chicken Tikka Masala";
            break;
        }
    }

    else if (user_type == "non-faculty")
    {
        switch (itemNumber)
        {
        case 1:
            itemName = "Tea";
            break;
        case 2:
            itemName = "Salad";
            break;
        case 3:
            itemName = " Roll Parhata";
            break;
        case 4:
            itemName = "Lemon Margarita";
            break;
        case 5:
            itemName = "Cheese Pasta";
            break;
        case 6:
            itemName = "Beef Burger";
            break;
        case 7:
            itemName = "Zinger Roll Parhata";
            break;
        case 8:
            itemName = " Biryani";
            break;
        case 9:
            itemName = "Palao";
            break;
        case 10:
            itemName = "Cheesecake";
            break;
        case 11:
            itemName = "Mutton Korma";
            break;
        case 12:
            itemName = "Chicken Tikka Masala";
            break;
        }
    }

    std::cout << "Confirm order of " << itemName << "? (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        orderHistory[orderCount++] = itemName;
        std::cout << "Order placed successfully!" << std::endl;
    }
    else {
        std::cout << "Order canceled." << std::endl;
    }


}

// ***************************************************************************
//                       View Order History                                  *
// ***************************************************************************


void Customer::ViewOrderHistory()
{
    const int maxOrders = 3;
    string itemNames[maxOrders] = { "Burger", "Rics", "Tea" };
    int quantities[maxOrders] = { 2, 1, 3 };
    double totalPrices[maxOrders] = { 25.0, 15.5, 40.75 };

    if (maxOrders == 0) {
        cout << "No order history available.\n";
    }
    else {
        cout << "Order History:\n";
        for (int i = 0; i < maxOrders; ++i) {
            cout << "Item: " << itemNames[i] << "\n";
            cout << "Quantity: " << quantities[i] << "\n";
            cout << "Total Price: $" << totalPrices[i] << "\n";
            cout << "------------------------\n";
        }
    }
}

// ***************************************************************************
//                  	          Logout                                     *
// ***************************************************************************

void Customer::Logout() {
    cout << "Goodbye! Have a great day It was really nice having you here!\n";
}

// ***************************************************************************
//                  	          Logout                                     *
// ***************************************************************************

void Customer::Option() {
    int choice;

    do {
        cout << "Menu Management System" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Place Order" << endl;;
        cout << "3. View Order History" << endl;
        cout << "4. Logout" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ViewMenu();
            break;
        case 2:
            PlaceOrder();
            break;
        case 3:
            ViewOrderHistory();
            break;
        case 4:
            Logout();
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice  != 4);

}