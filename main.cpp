// Created by Group 8
//main.cpp

#include "BusSystem.h"
#include "UIManager.h"
#include <iostream>
#include <limits>
#include <string>

int main() {
    BusSystem system;
    system.loadTrips("C:\\Users\\DELL\\Documents\\UniDocs\\Intermediate C++\\Assignment\\team project\\trips.txt");

    UIManager ui(system);

    while (true) {
        ui.displayMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {  // Add a trip
                std::string src, dest, drv, model;
                int dist, maxTrav;

                std::cout << "Enter source: ";
                std::getline(std::cin, src);

                std::cout << "Enter destination: ";
                std::getline(std::cin, dest);

                std::cout << "Enter distance in miles: ";
                std::cin >> dist;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter driver name: ";
                std::getline(std::cin, drv);

                std::cout << "Enter bus model: ";
                std::getline(std::cin, model);

                std::cout << "Enter max travelers: ";
                std::cin >> maxTrav;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                system.addTrip(BusTrip(src, dest, dist, drv, model, maxTrav));
                std::cout << "Trip added successfully!\n";
                break;
            }
            case 2: {  // Remove a trip
                if (system.tripCount() == 0) {
                    std::cout << "No trips available to remove.\n";
                } else {
                    system.displayTrips();
                    std::cout << "Enter the index of the trip you want to remove: ";
                    int tripIndex;
                    std::cin >> tripIndex;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (system.removeTrip(tripIndex)) {
                        std::cout << "Trip removed successfully!\n";
                    } else {
                        std::cout << "Invalid trip index. Please try again.\n";
                    }
                }
                break;
            }
            case 3: {  // Book a ticket
                if (system.tripCount() == 0) {
                    std::cout << "No trips available for booking.\n";
                    break;
                }
                system.displayTrips();
                int tripIndex, discountType;
                std::cout << "Enter trip index to book: ";
                std::cin >> tripIndex;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter discount type (1: Student, 2: Military, 3: Club Member): ";
                std::cin >> discountType;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system.bookTicket(tripIndex, discountType);
                break;
            }
            case 4: {  // Display trips
                system.displayTrips();
                break;
            }
            case 5: {  // Cancel a ticket
                if (system.tripCount() == 0) {
                    std::cout << "No trips available for ticket cancellation.\n";
                    break;
                }
                system.displayTrips();
                int tripIndex;
                std::cout << "Enter trip index for ticket cancellation: ";
                std::cin >> tripIndex;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (system.cancelTicket(tripIndex)) {
                    std::cout << "Ticket cancellation successful.\n";
                } else {
                    std::cout << "Failed to cancel ticket. Please check the trip index.\n";
                }
                break;
            }
            case 6: {  // Exit program
                std::cout << "Exiting program.\n";
                system.saveTrips(
                        "C:\\Users\\DELL\\Documents\\UniDocs\\Intermediate C++\\Assignment\\team project\\trips.txt");
                return 0;
            }
            default: {  // Handle invalid choices
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }
    return 0;
}