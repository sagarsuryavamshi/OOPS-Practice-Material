#include <iostream>
#include <string>
using namespace std;

enum Category { ELECTRONICS, CLOTHING, FOOD };
enum OrderStatus { CREATED, CONFIRMED, CANCELLED, DELIVERED };
enum PaymentStatus { PENDING, SUCCESS, FAILED };
enum PaymentMethod { CREDIT_CARD, UPI, CASH };

union PaymentInfo {
    int cardLast4;
    char upiID[30];
};

class Product {
private:
    int id, stock;
    string name;
    float price;
    Category category;

public:
    Product(int i, string n, float p, int s, Category c) {
        id = i;
        name = n;
        price = p;
        stock = s;
        category = c;
    }

    void displayProduct() {
        cout << id << " | " << name << " | Rs." << price
             << " | Stock: " << stock << endl;
    }

    bool checkAvailability(int q) {
        return stock >= q;
    }

    void updateStock(int q) {
        stock -= q;
    }

    int getID() {
        return id;
    }

    float getPrice() {
        return price;
    }
};

class Customer {
private:
    int id;
    string name, email, phone, address;

public:
    Customer(int i, string n, string e, string p, string a) {
        id = i;
        name = n;
        email = e;
        phone = p;
        address = a;
    }

    void displayCustomer() {
        cout << id << " | " << name << " | "
             << email << " | " << phone << " | "
             << address << endl;
    }

    void updateCustomer(string n, string e) {
        name = n;
        email = e;
    }

    int getID() {
        return id;
    }
};

struct Order {
    int orderID, customerID;
    float total;
    OrderStatus status;
    PaymentStatus payment;

    Order(int o, int c, float t) {
        orderID = o;
        customerID = c;
        total = t;
        status = CREATED;
        payment = PENDING;
    }

    void displayOrder() {
        cout << "\nOrder ID: " << orderID;
        cout << "\nCustomer ID: " << customerID;
        cout << "\nTotal: Rs." << total;
        cout << "\nStatus: " << status;
        cout << "\nPayment: " << payment << endl;
    }
};

int main() {
    Product p[3] = {
        Product(101, "Laptop", 50000, 5, ELECTRONICS),
        Product(102, "T-Shirt", 800, 10, CLOTHING),
        Product(103, "Book", 500, 3, FOOD)
    };

    Customer c[2] = {
        Customer(1, "Rahul", "rahul@gmail.com", "9876543210", "Delhi"),
        Customer(2, "Aman", "aman@gmail.com", "9876543211", "Punjab")
    };

    Order *orders[10];
    int orderCount = 0;
    int choice;

    do {
        cout << "\n\n____E-COMMERCE SYSTEM_____";
        cout << "\n1. Products";
        cout << "\n2. Customers";
        cout << "\n3. Create Order";
        cout << "\n4. Payment";
        cout << "\n5. Confirm Order";
        cout << "\n6. Cancel Order";
        cout << "\n7. Display Order";
        cout << "\n8. Update Customer";
        cout << "\n9. Deliver Order";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < 3; i++)
                p[i].displayProduct();
        }

        else if (choice == 2) {
            for (int i = 0; i < 2; i++)
                c[i].displayCustomer();
        }

        else if (choice == 3) {
            int cid, pid, qty;

            cout << "Customer ID: ";
            cin >> cid;

            if (cid < 1 || cid > 2) {
                cout << "Invalid Customer ID!";
                continue;
            }

            cout << "Product ID: ";
            cin >> pid;

            int index = -1;

            for (int i = 0; i < 3; i++) {
                if (p[i].getID() == pid)
                    index = i;
            }

            if (index == -1) {
                cout << "Invalid Product ID!";
                continue;
            }

            cout << "Quantity: ";
            cin >> qty;

            if (qty <= 0 || !p[index].checkAvailability(qty)) {
                cout << "Product out of stock or invalid quantity!";
                continue;
            }

            float total = p[index].getPrice() * qty;
            p[index].updateStock(qty);

            orders[orderCount] =
                new Order(orderCount + 1001, cid, total);

            cout << "Order Created! ID: "
                 << orderCount + 1001 << endl;

            orderCount++;
        }

        else if (choice == 4) {
            int id, method;
            cout << "Order ID: ";
            cin >> id;

            int index = id - 1001;

            if (index < 0 || index >= orderCount) {
                cout << "Invalid Order ID!";
                continue;
            }

            if (orders[index]->status == CANCELLED) {
                cout << "Cannot pay for cancelled order!";
                continue;
            }

            cout << "1. Credit Card\n2. UPI\n3. Cash\n";
            cin >> method;

            PaymentInfo info;

            if (method == CREDIT_CARD + 1) {
                cout << "Last 4 digits: ";
                cin >> info.cardLast4;

                if (info.cardLast4 < 1000 ||
                    info.cardLast4 > 9999) {
                    orders[index]->payment = FAILED;
                    cout << "Payment Failed!";
                }
                else {
                    orders[index]->payment = SUCCESS;
                    cout << "Payment Successful!";
                }
            }

            else if (method == UPI + 1) {
                cout << "UPI ID: ";
                cin >> info.upiID;

                orders[index]->payment = SUCCESS;
                cout << "Payment Successful!";
            }

            else if (method == CASH + 1) {
                orders[index]->payment = SUCCESS;
                cout << "Cash Payment Recorded!";
            }

            else {
                orders[index]->payment = FAILED;
                cout << "Invalid Payment Method!";
            }
        }

        else if (choice == 5) {
            int id;
            cout << "Order ID: ";
            cin >> id;

            int index = id - 1001;

            if (index < 0 || index >= orderCount) {
                cout << "Invalid Order ID!";
                continue;
            }

            if (orders[index]->payment != SUCCESS) {
                cout << "Cannot confirm. Payment failed or pending!";
            }
            else if (orders[index]->status == CANCELLED) {
                cout << "Cancelled order cannot be confirmed!";
            }
            else {
                orders[index]->status = CONFIRMED;
                cout << "Order Confirmed!";
            }
        }

        else if (choice == 6) {
            int id;
            cout << "Order ID: ";
            cin >> id;

            int index = id - 1001;

            if (index < 0 || index >= orderCount) {
                cout << "Invalid Order ID!";
                continue;
            }

            if (orders[index]->status == DELIVERED) {
                cout << "Delivered order cannot be cancelled!";
            }
            else {
                orders[index]->status = CANCELLED;
                cout << "Order Cancelled!";
            }
        }

        else if (choice == 7) {
            int id;
            cout << "Order ID: ";
            cin >> id;

            int index = id - 1001;

            if (index < 0 || index >= orderCount)
                cout << "Invalid Order ID!";
            else
                orders[index]->displayOrder();
        }

        else if (choice == 8) {
            int id;
            string name, email;

            cout << "Customer ID: ";
            cin >> id;

            if (id < 1 || id > 2) {
                cout << "Invalid Customer ID!";
                continue;
            }

            cout << "New Name: ";
            cin >> name;

            cout << "New Email: ";
            cin >> email;

            c[id - 1].updateCustomer(name, email);

            cout << "Customer Updated!";
        }

        else if (choice == 9) {
            int id;
            cout << "Order ID: ";
            cin >> id;

            int index = id - 1001;

            if (index < 0 || index >= orderCount) {
                cout << "Invalid Order ID!";
            }
            else if (orders[index]->status != CONFIRMED) {
                cout << "Only confirmed orders can be delivered!";
            }
            else {
                orders[index]->status = DELIVERED;
                cout << "Order Delivered!";
            }
        }

    } while (choice != 0);

    cout << "\nThank you!\n";

    return 0;
}