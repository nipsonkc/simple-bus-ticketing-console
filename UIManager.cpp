// Created by Group 8
//UIManager.cpp

#include "UIManager.h"
#include <iostream>
#include <limits>
#include <string>

/**
 * @brief Constructs a UIManager object with a reference to the BusSystem.
 *
 * @param sys The BusSystem object to interact with.
 */
UIManager::UIManager(BusSystem& sys) : system(sys) {}

/**
 * @brief Displays the main menu of the Bus Ticketing System.
 */
void UIManager::displayMenu() {
    std::cout << "\n=================================\n"
              << "        Bus Ticketing System       \n"
              << "=================================\n"
              << "1. Add a Trip\n"
              << "2. Remove a Trip\n"
              << "3. Book a Ticket\n"
              << "4. Display All Trips\n"
              << "5. Cancel a Ticket\n"  // Newly added menu option for ticket cancellation
              << "6. Exit\n"
              << "=================================\n"
              << "Enter your choice: ";
}

/**
 * @brief Processes user input and performs corresponding actions based on the chosen menu option.
 */
void UIManager::processUserInput() {
    int choice;
    std::cout << "\nPlease select an option: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the newline character left in the input buffer

    switch(choice) {
        case 1: { // Add a trip
            std::string source, destination, driver, busModel;
            int distance, maxTravelers;

            std::cout << "Enter source: ";
            std::getline(std::cin, source);

            std::cout << "Enter destination: ";
            std::getline(std::cin, destination);

            std::cout << "Enter distance (miles): ";
            std::cin >> distance;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter driver's name: ";
            std::getline(std::cin, driver);

            std::cout << "Enter bus model: ";
            std::getline(std::cin, busModel);

            std::cout << "Enter max travelers: ";
            std::cin >> maxTravelers;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            BusTrip newTrip(source, destination, distance, driver, busModel, maxTravelers);
            system.addTrip(newTrip);
            std::cout << "Trip added successfully!\n";
            break;
        }
        case 2: { // Remove trip
            if (system.tripCount() == 0) {
                std::cout << "No trips available to remove.\n";
                break;
            }
            int tripIndex;
            std::cout << "Enter trip index to remove: ";
            std::cin >> tripIndex;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            system.removeTrip(tripIndex);
            std::cout << "Trip removed successfully!\n";
            break;
        }
        case 3: { // Book a ticket
            if (system.tripCount() == 0) {
                std::cout << "No trips available for booking.\n";
                break;
            }
            int tripIndex, discountType;
            std::cout << "Enter trip index to book: ";
            std::cin >> tripIndex;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter discount type (1: Student, 2: Military, 3: Club Member): ";
            std::cin >> discountType;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            system.bookTicket(tripIndex, discountType);
            std::cout << "Ticket booked successfully!\n";
            break;
        }
        case 4: // Display trips
            system.displayTrips();
            break;
        case 5: { // Cancel trips
            int tripIndex;
            std::cout << "Enter trip index to cancel ticket: ";
            std::cin >> tripIndex;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (system.cancelTicket(tripIndex)) {
                std::cout << "Ticket cancellation successful.\n";
                system.saveTrips("C:\\Users\\DELL\\Documents\\UniDocs\\Intermediate C++\\Assignment\\team project\\trips.txt");  // Save immediately after successful cancellation
            } else {
                std::cout << "Failed to cancel ticket. Please check the trip index.\n";
            }
            break;
        }
        case 6: // Exit program
            std::cout << "Exiting program.\n";
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}
