#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ================= STRUCTS =================

typedef struct {
    int id;
    char name[50];
    char phone[20];
} Customer;

typedef struct {
    int id;
    int customerId;
    char model[50];
    char plate[20];
} Vehicle;

typedef struct {
    int id;
    int vehicleId;
    char serviceType[50];
    char date[20];
} Service;

// ================= ARRAYS =================

Customer customers[MAX];
Vehicle vehicles[MAX];
Service services[MAX];

int cCount = 0, vCount = 0, sCount = 0;

// ================= CUSTOMER =================

void addCustomer() {
    Customer c;

    printf("Enter Customer ID: ");
    scanf("%d", &c.id);

    printf("Enter Name: ");
    scanf("%s", c.name);

    printf("Enter Phone: ");
    scanf("%s", c.phone);

    customers[cCount++] = c;

    printf("Customer added!\n");
}

void listCustomers() {
    printf("\n--- Customers ---\n");
    for(int i = 0; i < cCount; i++) {
        printf("ID: %d | Name: %s | Phone: %s\n",
               customers[i].id,
               customers[i].name,
               customers[i].phone);
    }
}

// ================= VEHICLE =================

void addVehicle() {
    Vehicle v;

    printf("Enter Vehicle ID: ");
    scanf("%d", &v.id);

    printf("Enter Customer ID: ");
    scanf("%d", &v.customerId);

    printf("Enter Model: ");
    scanf("%s", v.model);

    printf("Enter Plate Number: ");
    scanf("%s", v.plate);

    vehicles[vCount++] = v;

    printf("Vehicle added!\n");
}

void listVehicles() {
    printf("\n--- Vehicles ---\n");
    for(int i = 0; i < vCount; i++) {
        printf("ID: %d | CustomerID: %d | Model: %s | Plate: %s\n",
               vehicles[i].id,
               vehicles[i].customerId,
               vehicles[i].model,
               vehicles[i].plate);
    }
}

// ================= SERVICE =================

void addService() {
    Service s;

    printf("Enter Service ID: ");
    scanf("%d", &s.id);

    printf("Enter Vehicle ID: ");
    scanf("%d", &s.vehicleId);

    printf("Enter Service Type: ");
    scanf("%s", s.serviceType);

    printf("Enter Date: ");
    scanf("%s", s.date);

    services[sCount++] = s;

    printf("Service added!\n");
}

void listServices() {
    printf("\n--- Services ---\n");
    for(int i = 0; i < sCount; i++) {
        printf("ID: %d | VehicleID: %d | Type: %s | Date: %s\n",
               services[i].id,
               services[i].vehicleId,
               services[i].serviceType,
               services[i].date);
    }
}

// ================= SEARCH =================

void searchVehicle() {
    int id;
    printf("Enter Vehicle ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < vCount; i++) {
        if(vehicles[i].id == id) {
            printf("Found: %s (%s)\n",
                   vehicles[i].model,
                   vehicles[i].plate);
            return;
        }
    }

    printf("Vehicle not found!\n");
}

// ================= MENU =================

void menu() {
    int choice;

    while(1) {
        printf("\n===== VEHICLE SYSTEM =====\n");
        printf("1. Add Customer\n");
        printf("2. List Customers\n");
        printf("3. Add Vehicle\n");
        printf("4. List Vehicles\n");
        printf("5. Add Service\n");
        printf("6. List Services\n");
        printf("7. Search Vehicle\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addCustomer(); break;
            case 2: listCustomers(); break;
            case 3: addVehicle(); break;
            case 4: listVehicles(); break;
            case 5: addService(); break;
            case 6: listServices(); break;
            case 7: searchVehicle(); break;
            case 0: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

// ================= MAIN =================

int main() {
    menu();
    return 0;
}