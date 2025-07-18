// Created by Group 8
//DiscountManager.h

#ifndef DISCOUNTMANAGER_H
#define DISCOUNTMANAGER_H

/**
 * @brief Manages the discount calculations for different types of customers
 * within the system. It offers a static method to apply discounts based on
 * predefined discount types.
 */
class DiscountManager {
public:
    /**
     * Applies a discount to a given price based on a specified discount type.
     * This method is static, allowing it to be called without an instance of the class.
     *
     * @param price The original price before any discounts are applied.
     * @param discountType The type of discount to apply, which affects the discount rate:
     *        1 - Online orders and students receive a 15% discount.
     *        2 - Military and veterans receive a 10% discount.
     *        3 - Club members receive a 20% discount.
     * @return The price after the discount has been applied.
     */
    static double applyDiscount(double price, int discountType);
};

#endif // DISCOUNTMANAGER_H
