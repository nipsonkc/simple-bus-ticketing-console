// Created by Group 8
//TicketManager.cpp

#include "TicketManager.h"
#include <iostream>

/**
 * Books a trip and records it in the list of booked trips.
 * Outputs the booking details to the standard output.
 *
 * @param trip The BusTrip object representing the trip to book.
 * @param price The price at which the trip is booked.
 */
void TicketManager::bookTrip(const BusTrip& trip, double price) {
    bookedTrips.push_back(trip);
    std::cout << "Trip booked from " << trip.source << " to " << trip.destination
              << " at a price of $" << price << ".\n";
}

/**
 * Displays all currently booked trips to the standard output.
 * Lists each trip by showing the source and destination locations.
 */
void TicketManager::displayBookings() const {
    if (bookedTrips.empty()) {
        std::cout << "No trips currently booked.\n";
        return;
    }
    for (const auto& trip : bookedTrips) {
        std::cout << "Trip from " << trip.source << " to " << trip.destination << "\n";
    }
}
