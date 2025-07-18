Bus Ticketing System 
CSCI-6610-02 Intermediate Programming: C++ 

1. Introduction 
The objective of the Bus Ticketing System project is to create an advanced software platform tailored for bus transit companies, facilitating streamlined ticket bookings, trip scheduling, and discount management for passengers. The primary focus lies in optimizing the ticketing process to ensure a seamless experience for both customers and the company. By centralizing ticketing operations and implementing robust scheduling algorithms, the system aims to enhance efficiency and customer satisfaction while providing the company with valuable insights for improved service delivery.Top of Form 

2. System Overview 
The Bus Ticketing System offers an array of essential functionalities to cater to the needs of its users: 

Booking Tickets for Bus Trips:
Customers are empowered to effortlessly explore available trips across specific destinations, enabling them to cherry-pick their preferred options and seamlessly book tickets via the online platform. 

Ticket Cancellation:
Providing flexibility to customers, the system allows for hassle-free cancellation of booked tickets within the stipulated timeframe, ensuring refunds are promptly processed where applicable. 

Trip Management:
Administrators wield the capability to dynamically manage trip schedules, thereby facilitating the addition of new trips, updating trip details, and removing outdated or unavailable trips from the system. 

Discount Calculation: 
Incorporating sophisticated algorithms, the system automatically computes discounts on ticket prices, taking into account various customer eligibility criteria. Whether it's an online order, student status, military service, or membership in the BUS_TRIPS club, the system adeptly applies discounts to ensure customer satisfaction and loyalty. 

Top of Form 

3. Test Cases 

Test Case 1: Successful Ticket Booking 

Description: 
  Customer searches for available trips between two specified destinations. 
  Customer selects a preferred trip and provides their information (name, age, any applicable discounts). 
  System confirms seat availability and successfully books the ticket, issuing a confirmation message and ticket details.

Expected Outcome: 
 Ticket is correctly generated and associated with the customer. 
 Passenger count for the trip is accurately updated. 
 Customer receives clear confirmation and ticket details. 

Test Case 2: Ticket Cancellation 

 Description: 
   Customer initiates a ticket cancellation request within the allowed time frame. 
   System verifies ticket validity and cancellation eligibility. 
   System refunds any applicable charges and updates trip passenger count. 
   Customer receives confirmation of cancellation and refund details. 

Expected Outcome: 
  Ticket is successfully canceled and removed from the passenger list. 
  Customer receives appropriate refund (if applicable) and a cancellation confirmation. 
  Trip passenger count accurately reflects the cancellation. 

 

Test Case 3: Capacity Limit Reached 

 Description: 
  Customer attempts to book a ticket for a trip that has already reached its maximum passenger capacity. 
  System notifies the customer that the trip is fully booked and offers alternative trips or suggests waiting for a later schedule. 

Expected Outcome: 
  System prevents overbooking and clearly informs the customer about booking availability. 
  Customer is provided with helpful alternatives for booking. 

Test Case 4: Discount Eligibility Verification 
  Description: 
    Customer applies for a discount (e.g., student, military, bus club member) during ticket booking. 
    System validates the customer's eligibility based on provided information. 
    If eligible, the system applies the correct discount to the ticket price. 

Expected Outcome: 
    System accurately verifies discount eligibility and applies the appropriate discount. 
    Customer receives the correct ticket price with the discount applied.  

Test Case 5: Driver Assignment 
  
  Description: 
    A trip is scheduled for departure. 
    System assigns a qualified and available driver to the trip, considering their driving hours and schedule. 
  
Expected Outcome: 
    System successfully assigns a suitable driver to the trip, ensuring compliance with driver regulations. 
    Driver is notified of their assigned trip. 

4. User Guide 

1. Add a Trip
Use this option to enter a new bus trip into the system. You will need to provide specific details about the trip. 

Steps: 
Select Option 1 from the main menu. 
Enter the source city (where the trip starts). 
Enter the destination city (where the trip ends). 
Input the distance in miles between the source and destination. 
Provide the driver's name. 
Enter the bus model. 
Specify the maximum number of travelers that can be accommodated on this trip. 
Confirm your entries. A message will indicate that the trip has been successfully added. 

 

2. Remove a Trip 
Use this option to delete an existing trip from the system. This is useful for managing outdated or canceled trips. 

Steps: 
Select Option 2 from the main menu. 
You will see a list of all trips with their respective indices. Enter the index number of the trip you wish to remove. 
Confirm your choice. A message will confirm that the trip has been removed. 

 3. Book a Ticket 
This option allows you to book a ticket for any available trip. You will also choose a discount type if applicable. 

Steps: 
Select Option 3 from the main menu. 
View the list of available trips and select the trip by its index number you wish to book a ticket for. 
Choose a discount type from the options provided (1: Student, 2: Military, 3: Club Member). 
Confirm your entries. You will see the calculated base price and the discounted price. A confirmation message will show that your ticket has been booked. 

 
4. Display All Trips 
Use this option to view all currently scheduled trips. This is useful for seeing all travel options or managing trip schedules. 

Steps: 
Select Option 4 from the main menu. 
A list of all trips, including details such as source, destination, and distance, will be displayed. 

5. Exit 
Select this option to safely exit the program. 

Steps: 
Choose Option 5 from the main menu. 
Confirm your desire to exit. The program will close after a farewell message. 

5. System Implementation 
The Bus Ticketing System was crafted using the C++ programming language and embraced a modular design paradigm. Within this architecture, several modules were meticulously integrated, encompassing: 

Booking Module: This module orchestrates ticket booking and cancellation functionalities, ensuring seamless transactions for users. 

Trip Management Module: Responsible for orchestrating the scheduling and administration of bus trips, this module efficiently manages trip logistics. 

Discount Calculation Module: Employing intricate algorithms, this module determines eligibility for discounts and intelligently applies them to ticket prices, enhancing customer satisfaction. 

User Interface Module: With a focus on user experience, this module furnishes an intuitive interface, fostering user engagement and ease of interaction with the system. 

The implementation process was a collaborative effort, with each team member contributing expertise to various facets of system development. Challenges encountered were met head-on through effective communication and adept problem-solving skills, ensuring the successful realization of the Bus Ticketing System. 


6. Conclusion 

The Bus Ticketing System project stands as a pinnacle of achievement, having surpassed its lofty objectives by providing an unwaveringly robust software platform meticulously crafted to orchestrate the intricate dance of ticket bookings, trip schedules, and discount management within the dynamic realm of a bustling bus transit company. Through an exhaustive regimen of rigorous testing and unwavering collaboration, the system has been artfully woven into the fabric of operational reality, serving as a steadfast beacon of efficiency and efficacy that fulfills the diverse needs and demands of both discerning customers and the enterprising company at large. This monumental achievement stands as a testament to the indomitable spirit of innovation and the relentless pursuit of excellence that permeates every facet of its conception and execution, underscoring its indispensable role in revolutionizing the landscape of bus transit operations and elevating the standard of service to unprecedented heights. 

 
