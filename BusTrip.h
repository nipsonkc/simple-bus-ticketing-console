// Created by Group 8
//BusTrip.h

#ifndef BUSTRIPT_H
#define BUSTRIPT_H

#include <string>

/**
 * @brief Represents an individual bus trip, encapsulating all relevant data
 * and behaviors such as booking and cancellation of tickets.
 */
class BusTrip {
public:
    std::string source;       ///< Starting location of the bus trip.
    std::string destination;  ///< Destination of the bus trip.
    int distance;             ///< Distance of the trip in miles.
    std::string driver;       ///< Name of the bus driver.
    std::string busModel;     ///< Model of the bus used for the trip.
    int maxTravelers;         ///< Maximum number of travelers allowed on this trip.
    int ticketsBooked;        ///< Current number of tickets booked.

    /**
     * Constructor that initializes a bus trip with specified details.
     *
     * @param src Source location of the trip.
     * @param dest Destination of the trip.
     * @param dist Distance of the trip in miles.
     * @param drv Name of the driver.
     * @param model Model of the bus.
     * @param maxTrav Maximum number of passengers that can be accommodated.
     */
    BusTrip(std::string src, std::string dest, int dist, std::string drv, std::string model, int maxTrav);

    /**
     * Calculates the base price of the trip based on its distance.
     *
     * @return The base fare for the trip, calculated as a fixed rate per mile.
     */
    double calculateBasePrice() const;

    /**
     * Applies a discount to the base fare based on the type of discount.
     *
     * @param price The original price of the ticket.
     * @param discountType The type of discount to apply.
     * @return The discounted price after applying the specified discount type.
     */
    double applyDiscount(double price, int discountType) const;

    /**
     * Attempts to book a ticket for this trip, applying a discount if applicable.
     *
     * @param discountType The type of discount to apply to the ticket.
     * @return true If the ticket was successfully booked, false if the trip is fully booked.
     */
    bool bookTicket(int discountType);

    /**
     * Cancels a previously booked ticket, if any.
     *
     * @return true If a ticket was successfully cancelled, false if no tickets were booked.
     */
    bool cancelTicket();
};

#endif // BUSTRIPT_H
