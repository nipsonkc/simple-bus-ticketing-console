// Created by Group 8
//TicketManager.h

#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include "BusTrip.h"
#include <vector>

/**
 * @brief Manages ticket bookings and stores information regarding all tickets issued.
 * Provides functionalities to book trips and display bookings.
 */
class TicketManager {
private:
    std::vector<BusTrip> bookedTrips;  ///< List of all booked trips.

public:
    /**
     * Books a trip and adds it to the list of booked trips.
     *
     * @param trip The BusTrip object representing the trip to be booked.
     * @param price The price at which the trip is booked.
     */
    void bookTrip(const BusTrip& trip, double price);

    /**
     * Displays all currently booked trips. Each trip is displayed with
     * its source and destination.
     */
    void displayBookings() const;
};

#endif // TICKETMANAGER_H
