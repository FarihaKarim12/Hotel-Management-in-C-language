#include <stdio.h>
 
#include <string.h>

 
struct Booking {
    int roomNumber;
    char name[50];
    char phone[15];
    char roomType[20];
    int days;
};

 
int isValidRoomNumber(int roomNumber) {
    return (roomNumber >= 101 && roomNumber <= 110);   
}

 
int isValidPhoneNumber(char *phone) {
    if (strlen(phone) != 10) return 0;   
    for (int i = 0; i < 10; i++) {
        if (phone[i] < '0' || phone[i] > '9') {  
            return 0;
        }
    }
    return 1;
}

 
int isValidRoomType(char *roomType) {
    return (strcmp(roomType, "Single") == 0 || strcmp(roomType, "Double") == 0 || strcmp(roomType, "Deluxe") == 0);
}

 
int isValidDays(int days) {
    return (days > 0);    
}

 
void addBooking() {
    struct Booking b;
    FILE *fp = fopen("bookings.txt", "a");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

     
    do {
        printf("Enter Room Number (101-110): ");
        scanf("%d", &b.roomNumber);
        if (!isValidRoomNumber(b.roomNumber)) {
            printf("Invalid Room Number! Please enter a number between 101 and 110.\n");
        }
    } while (!isValidRoomNumber(b.roomNumber));

   
    do {
        printf("Enter Customer Name: ");
        scanf(" %[^\n]", b.name);
        if (strlen(b.name) == 0) {
            printf("Name cannot be empty. Please enter a valid name.\n");
        }
    } while (strlen(b.name) == 0);

    
    do {
        printf("Enter Phone Number (10 digits): ");
        scanf("%s", b.phone);
        if (!isValidPhoneNumber(b.phone)) {
            printf("Invalid phone number! Please enter a 10-digit phone number.\n");
        }
    } while (!isValidPhoneNumber(b.phone));

     
    do {
        printf("Enter Room Type (Single/Double/Deluxe): ");
        scanf("%s", b.roomType);
        if (!isValidRoomType(b.roomType)) {
            printf("Invalid room type! Please enter Single, Double, or Deluxe.\n");
        }
    } while (!isValidRoomType(b.roomType));

   
    do {
        printf("Enter Number of Days: ");
        scanf("%d", &b.days);
        if (!isValidDays(b.days)) {
            printf("Invalid number of days! Please enter a positive number.\n");
        }
    } while (!isValidDays(b.days));

    fwrite(&b, sizeof(struct Booking), 1, fp);
    fclose(fp);

    printf("Booking added successfully!\n");
}

 
void viewAllBookings() {
    struct Booking b;
    FILE *fp = fopen("bookings.txt", "r");

    if (fp == NULL) {
        printf("No bookings found.\n");
        return;
    }

    printf("\n--- All Bookings ---\n");
    while (fread(&b, sizeof(struct Booking), 1, fp)) {
        printf("Room: %d | Name: %s | Phone: %s | Type: %s | Days: %d\n",
               b.roomNumber, b.name, b.phone, b.roomType, b.days);
    }

    fclose(fp);
}

 
void checkAvailability() {
    int allRooms[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int totalRooms = 10;
    int booked[10] = {0};

    struct Booking b;
    FILE *fp = fopen("bookings.txt", "r");

    if (fp != NULL) {
        while (fread(&b, sizeof(struct Booking), 1, fp)) {
            for (int i = 0; i < totalRooms; i++) {
                if (allRooms[i] == b.roomNumber) {
                    booked[i] = 1;
                }
            }
        }
        fclose(fp);
    }

    printf("\n--- Available Rooms ---\n");
    for (int i = 0; i < totalRooms; i++) {
        if (booked[i] == 0) {
            printf("Room %d is available.\n", allRooms[i]);
        }
    }
}

  
void searchBooking() {
    int roomNo, found = 0;
    struct Booking b;
    FILE *fp = fopen("bookings.txt", "r");

    if (fp == NULL) {
        printf("No bookings found.\n");
        return;
    }

    printf("Enter Room Number to Search: ");
    scanf("%d", &roomNo);

    while (fread(&b, sizeof(struct Booking), 1, fp)) {
        if (b.roomNumber == roomNo) {
            printf("Room: %d | Name: %s | Phone: %s | Type: %s | Days: %d\n",
                   b.roomNumber, b.name, b.phone, b.roomType, b.days);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No booking found for room %d.\n", roomNo);

    fclose(fp);
}

 
void editBooking() {
    int roomNo, found = 0;
    struct Booking b;
    FILE *fp = fopen("bookings.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Room Number to Edit: ");
    scanf("%d", &roomNo);

    while (fread(&b, sizeof(struct Booking), 1, fp)) {
        if (b.roomNumber == roomNo) {
            printf("Enter New Customer Name: ");
            scanf(" %[^\n]", b.name);
            printf("Enter New Phone Number: ");
            scanf("%s", b.phone);
            printf("Enter New Room Type: ");
            scanf("%s", b.roomType);
            printf("Enter New Number of Days: ");
            scanf("%d", &b.days);
            found = 1;
        }
        fwrite(&b, sizeof(struct Booking), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (found)
        printf("Booking updated successfully.\n");
    else
        printf("Booking not found.\n");
}

 
void deleteBooking() {
    int roomNo, found = 0;
    struct Booking b;
    FILE *fp = fopen("bookings.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Room Number to Delete: ");
    scanf("%d", &roomNo);

    while (fread(&b, sizeof(struct Booking), 1, fp)) {
        if (b.roomNumber != roomNo) {
            fwrite(&b, sizeof(struct Booking), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (found)
        printf("Booking deleted successfully.\n");
    else
        printf("Booking not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add Booking\n");
        printf("2. View All Bookings\n");
        printf("3. Check Room Availability\n");
        printf("4. Search Booking\n");
        printf("5. Edit Booking\n");
        printf("6. Delete Booking\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBooking(); break;
            case 2: viewAllBookings(); break;
            case 3: checkAvailability(); break;
            case 4: searchBooking(); break;
            case 5: editBooking(); break;
            case 6: deleteBooking(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
