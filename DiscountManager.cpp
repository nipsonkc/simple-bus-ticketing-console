// Created by Group 8
//DiscountManager.cpp

#include "DiscountManager.h"

/**
 * Applies a discount to a given price based on the type of discount specified.
 *
 * @param price The original price from which the discount will be applied.
 * @param discountType The type of discount to apply:
 *        1 - Online orders and students receive a 15% discount.
 *        2 - Military and veterans receive a 10% discount.
 *        3 - Club members receive a 20% discount.
 * @return The price after the discount has been applied.
 */
double DiscountManager::applyDiscount(double price, int discountType) {
    switch (discountType) {
        case 1:
            return price * 0.85; // Online orders and students
        case 2:
            return price * 0.90; // Military and veterans
        case 3:
            return price * 0.80; // Club members
        default:
            return price; // No discount applied if an unrecognized type is passed
    }
}
