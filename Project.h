#pragma once
#pragma once
#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Welcome();

class User {
public:
    void Register();
    void Login();
    void user();
};

class Administrator
{
public:
    void StudentMenu();
    void FacultyMenu();
    void NonFacultyMenu();
    void AddMenuItem();
    void RemoveMenuItem();
    void ManageInventory();
    void ManageDiscountPromotion();
    void ViewOrderHistory();
    void AddNotification();
    void RemoveNotification();
    void RateMenuItem();
    void DisplayFromFile();
    void ViewUserFromFile(const string& filename, int startCustomer, int endCustomer);
    void ViewMenultemsFromFile();
    void ViewOrdersFromFile();
    void ViewRatingsFromFile();
    void ViewPaymentsFromFile();
    void CalculateMonthlyEarnings();
    void Logout();
    void option();
};

class CafeStaff
{
public:
    void FacultyMenu();
    void NonFacultyMenu();
    void StudentMenu();
    void ViewMenu();
    void AddMenuItem();
    void RemoveMenuItem();
    void ProcessOrder();
};

class Customer
{
public:
    void FacultyMenu();
    void NonFacultyMenu();
    void StudentMenu();
    void ViewMenu();
    void PlaceOrder();
    void ViewOrderHistory();
    void Logout();
    void Option();
private:
    static const int MAX_ORDERS = 12;
    std::string orderHistory[MAX_ORDERS];
    int orderCount;
};


#endif