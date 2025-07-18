// Created by Group 8
//UIManager.h

#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "BusSystem.h"

// Manages the user interface and interaction with the system.
class UIManager {
private:
    BusSystem& system; // Reference to the BusSystem object

public:
    /**
     * @brief Constructs a UIManager object with a reference to the BusSystem.
     *
     * @param sys The BusSystem object to interact with.
     */
    explicit UIManager(BusSystem& sys);

    /**
     * @brief Displays the main menu of the Bus Ticketing System.
     */
    void displayMenu();

    /**
     * @brief Processes user input and performs corresponding actions based on the chosen menu option.
     */
    void processUserInput();
};

#endif
