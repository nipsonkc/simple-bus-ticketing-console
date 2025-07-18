// Created by Group 8
//BusTrip.cpp

#include "BusTrip.h"
#include <iostream>

/**
 * Constructor for a BusTrip object.
 * Initializes a new bus trip with specified details.
 *
 * @param src The starting location of the trip.
 * @param dest The destination of the trip.
 * @param dist The distance of the trip in miles.
 * @param drv The name of the driver.
 * @param model The model of the bus.
 * @param maxTrav The maximum number of travelers allowed on the trip.
 */
BusTrip::BusTrip(std::string src, std::string dest, int dist, std::string drv, std::string model, int maxTrav)
        : source(src), destination(dest), distance(dist), driver(drv), busModel(model), maxTravelers(maxTrav), ticketsBooked(0) {}

/**
 * Calculates the base price of a trip based on distance.
 *
 * @return The base price calculated at a rate of $0.05 per mile.
 */
double BusTrip::calculateBasePrice() const {
    return distance * 0.05; // Cost per mile
}

/**
 * Applies a discount to the given price based on the discount type.
 *
 * @param price The initial price before the discount.
 * @param discountType The type of discount to apply:
 *                     1 - Students and Online Orders (15% discount)
 *                     2 - Military and Veterans (10% discount)
 *                     3 - Club Members (20% discount)
 * @return The price after applying the discount.
 */
double BusTrip::applyDiscount(double price, int discountType) const {
    switch (discountType) {
        case 1: // Students and Online Orders
            return price * 0.85;
        case 2: // Military and Veterans
            return price * 0.90;
        case 3: // Club Members
            return price * 0.80;
        default:
            return price;
    }
}

/**
 * Books a ticket for the trip if available, applying any applicable discounts.
 *
 * @param discountType The discount type to apply when booking the ticket.
 * @return true If the ticket was successfully booked.
 * @return false If no tickets are available (i.e., the trip is fully booked).
 */
bool BusTrip::bookTicket(int discountType) {
    if (ticketsBooked < maxTravelers) {
        double basePrice = calculateBasePrice();
        double finalPrice = applyDiscount(basePrice, discountType);
        std::cout << "Booking for trip from " << source << " to " << destination << "\n"
                  << "Base price: $" << basePrice << "\n"
                  << "Discounted price: $" << finalPrice << "\n";
        ticketsBooked++;
        return true;
    }
    std::cout << "No more tickets available for this trip.\n";
    return false;
}

/**
 * Cancels a previously booked ticket for the trip, if any are available to cancel.
 *
 * @return true If a ticket was successfully cancelled.
 * @return false If no tickets were available to cancel.
 */
bool BusTrip::cancelTicket() {
    if (ticketsBooked > 0) {
        ticketsBooked--;
        std::cout << "Ticket cancellation successful.\n";
        return true;
    }
    std::cout << "No tickets to cancel.\n";
    return false;
}
