# Hotel Management System in C

This is a console-based Hotel Management System implemented in the C programming language. It allows users to manage room bookings, check availability, search, edit, and delete bookings via a text-based interface.

## Features
- **Text-Based UI:** Uses ASCII characters and terminal input/output for interaction.
- **Room Booking:** Allows customers to book rooms with proper validation.
- **Search Functionality:** Enables searching for bookings using room numbers.
- **Edit & Delete Options:** Update or delete existing bookings.
- **Room Availability:** Check which rooms (101–110) are currently available.
- **Data Persistence:** Bookings are saved to `bookings.txt` using file handling.
- **Input Validation:** Ensures valid room numbers, phone numbers, and other fields.
  
## Setup Prerequisites
- **Operating System:** Compatible with Windows, Linux, or macOS
- **C Compiler:** GCC, MinGW, or any standard C compiler

## Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/fariha880/Hotel-Management-in-C-language.git
2. **Navigate to the Project Directory**: bash cd hotel-management-in-c
3. **Compile the Code**: bash gcc hotel.c -o hotel

---

## Usage

1. **Run the Executable**
   bash ./hotel
2. **Menu Options**
   → Add Booking
   → View All Bookings
   → Check Room Availability
   → Search Booking by Room Number
   → Edit Booking
   → Delete Booking
   → Exit the Program
3. **Input Instructions**
   Room Number: Valid range is 101–110
   Phone Number: Must be exactly 10 digits
   Room Type: Choose from Single, Double, or Deluxe
   Number of Days: Must be a positive integer

## File Structure
hotel.c → Main C source file containing all the logic
bookings.txt → File used to store all booking data persistently
temp.txt → Temporary file used for editing and deleting bookings

## Learning Outcomes
Strengthened understanding of:
-File Handling in C
-Data Validation & Input Sanitization
-Modular Programming
-Console UI Design
Practical experience with:
-Managing persistent data
-Structs and condition-driven logic
-Real-world simulation of hotel management operations

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you'd like to contribute.

