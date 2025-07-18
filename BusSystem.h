// Created by Group 8
//BusSystem.h

#ifndef BUSSYSTEM_H
#define BUSSYSTEM_H

#include "BusTrip.h"
#include <vector>
#include <string>

/**
 * @brief Manages a collection of BusTrips, providing functionalities to add,
 * remove, book tickets for, and cancel tickets on trips.
 * It also includes methods to display trips and manage trip data persistence.
 */
class BusSystem {
private:
    std::vector<BusTrip> trips;  ///< Container for storing all bus trips.

public:
    /**
     * @brief Constructs a new Bus System object.
     */
    BusSystem();

    /**
     * @brief Adds a new bus trip to the system.
     *
     * @param trip A BusTrip object representing the trip to be added.
     */
    void addTrip(const BusTrip& trip);

    /**
     * @brief Removes a trip from the system based on its index.
     *
     * @param index The index of the trip to be removed.
     * @return true If the trip was successfully removed.
     * @return false If the index is out of bounds, indicating removal failure.
     */
    bool removeTrip(int index);

    /**
     * @brief Books a ticket for a specific trip, applying a discount if applicable.
     *
     * @param tripIndex The index of the trip for which to book a ticket.
     * @param discountType The type of discount to apply (e.g., student, military).
     */
    void bookTicket(int tripIndex, int discountType);

    /**
     * @brief Attempts to cancel a ticket for a specific trip.
     *
     * @param tripIndex The index of the trip for which to cancel a ticket.
     * @return true If the ticket was successfully cancelled.
     * @return false If the cancellation failed (e.g., invalid index).
     */
    bool cancelTicket(int tripIndex);

    /**
     * @brief Displays all the trips in the system to the standard output.
     */
    void displayTrips() const;

    /**
     * @brief Returns the number of trips currently managed by the system.
     *
     * @return size_t The number of trips.
     */
    size_t tripCount() const;

    /**
     * @brief Saves all current trips to a specified file.
     *
     * @param filename The path to the file where trips will be saved.
     */
    void saveTrips(const std::string& filename) const;

    /**
     * @brief Loads trips from a specified file into the system.
     *
     * @param filename The path to the file from which to load trips.
     */
    void loadTrips(const std::string& filename);
};

#endif // BUSSYSTEM_H
