// Created by Group 8
//BusSystem.cpp

#include "BusSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

/**
 * Default constructor for BusSystem.
 */
BusSystem::BusSystem() {}

/**
 * Adds a trip to the bus system.
 * @param trip The BusTrip object to add.
 */
void BusSystem::addTrip(const BusTrip& trip) {
    trips.push_back(trip);
    std::cout << "Trip added successfully: " << trip.source << " to " << trip.destination << "\n";
}

/**
 * Removes a trip from the bus system based on the given index.
 * @param index The index of the trip to remove.
 * @return true if the trip was removed successfully, false otherwise.
 */
bool BusSystem::removeTrip(int index) {
    if (index >= 0 && index < trips.size()) {
        trips.erase(trips.begin() + index);
        return true;
    }
    return false;
}

/**
 * Books a ticket for a specified trip with a given discount type.
 * @param tripIndex The index of the trip to book.
 * @param discountType The discount type for the ticket.
 */
void BusSystem::bookTicket(int tripIndex, int discountType) {
    if (tripIndex < 0 || tripIndex >= trips.size()) {
        std::cout << "Invalid trip index. Booking not processed.\n";
        return;
    }
    if (!trips[tripIndex].bookTicket(discountType)) {
        std::cout << "Failed to book ticket.\n";
    }
}

/**
 * Cancels a ticket for a specified trip.
 * @param tripIndex The index of the trip for which to cancel the ticket.
 * @return true if the cancellation was successful, false otherwise.
 */
bool BusSystem::cancelTicket(int tripIndex) {
    if (tripIndex < 0 || tripIndex >= trips.size()) {
        std::cout << "Invalid trip index. Cancellation not processed.\n";
        return false;
    }
    return trips[tripIndex].cancelTicket();
}

/**
 * Displays all the trips in the bus system.
 */
void BusSystem::displayTrips() const {
    if (trips.empty()) {
        std::cout << "No trips available.\n";
        return;
    }

    std::cout << "\nAvailable Trips:\n"
              << "------------------------------------------------------------------------------------------\n"
              << std::left << std::setw(10) << "Index" << std::setw(20) << "Source" << std::setw(20) << "Destination"
              << std::setw(10) << "Distance" << "Tickets Booked\n"
              << "------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < trips.size(); i++) {
        const auto& trip = trips[i];
        std::cout << std::left << std::setw(10) << i
                  << std::setw(20) << trip.source
                  << std::setw(20) << trip.destination
                  << std::setw(10) << trip.distance
                  << trip.ticketsBooked << '\n';
    }
    std::cout << "------------------------------------------------------------------------------------------\n";
}

/**
 * Returns the number of trips currently managed by the system.
 * @return The number of trips.
 */
size_t BusSystem::tripCount() const {
    return trips.size();
}

/**
 * Saves all trips to a specified file.
 * @param filename The path to the file where trips are saved.
 */
void BusSystem::saveTrips(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& trip : trips) {
        out << trip.source << "," << trip.destination << "," << trip.distance << ","
            << trip.driver << "," << trip.busModel << "," << trip.maxTravelers << ","
            << trip.ticketsBooked << "\n";
    }
    out.close();
}

/**
 * Loads trips from a specified file.
 * @param filename The path to the file from which to load trips.
 */
void BusSystem::loadTrips(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
        return;
    }
    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        std::string src, dest, drv, model;
        int dist, maxTrav, booked;
        getline(iss, src, ',');
        getline(iss, dest, ',');
        iss >> dist;
        iss.ignore();
        getline(iss, drv, ',');
        getline(iss, model, ',');
        iss >> maxTrav;
        iss.ignore();
        iss >> booked;

        BusTrip trip(src, dest, dist, drv, model, maxTrav);
        trip.ticketsBooked = booked;
        trips.push_back(trip);
        std::cout << "Loaded trip: " << trip.source << " to " << trip.destination << " with " << booked << " tickets booked.\n";
    }
    std::cout << "Finished loading trips.\n";
    inFile.close();
}
