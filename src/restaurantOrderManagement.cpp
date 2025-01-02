#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int maxMenuItems = 50;
const int maxOrders = 100;

struct MenuItem
{
    int itemId;
    char name[50];
    double price;
};

struct Order
{
    int orderId;
    int tableNumber;
    int itemIds[maxMenuItems];
    int itemQuantities[maxMenuItems];
    int itemCount;
    double discount;
    char status[20];
};

class Restaurant
{
private:
    MenuItem menu[maxMenuItems];
    Order orders[maxOrders];
    
    int menuItemCount;
    int orderCount;
    
    int generateOrderId()
    {
        int id = 1;
        return id++;
    }
    
public:
    Restaurant() : menuItemCount(0), orderCount(0) {}
    
    void addMenuItem()
    {
        if(menuItemCount >= maxMenuItems)
        {
            cout << "Can't add more items" << endl;
        }
        
        MenuItem item;
        item.itemId = menuItemCount + 1;
        
        cout << "Enter item name: ";
        cin.ignore();
        cin.getline(item.name, 50);
        
        cout << "Enter Item Price: ";
        cin >> item.price;
        menu[menuItemCount++] = item;
        
        cout << "Item added" << endl;
    }
    
    void displayMenu()
    {
        if(menuItemCount == 0)
        {
            cout << "Menu is empty" << endl;
            return;
        }
        
        cout << endl << "Menu:" << endl;
        cout << "ID\tName\t\tPrice" << endl;
        
        for (int i = 0; i < menuItemCount; i++)
        {
            cout << menu[i].itemId << "\t" << menu[i].name << "\t\t" << menu[i].price << endl;
        }
    }
    
    void placeOrder()
    {
        if(menuItemCount == 0)
        {
            cout << "Menu is empty" << endl;
            return;
        }
        
        if(orderCount >= maxOrders)
        {
            cout << "Can't place more orders" << endl;
            return;
        }
        
        Order order;
        order.orderId = generateOrderId();
        
        cout << "Enter table number: ";
        cin >> order.tableNumber;
        
        cout << "Enter number of items in order: ";
        cin >> order.itemCount;
        
        if(order.itemCount > maxMenuItems)
        {
            cout << "Too many items in order" << endl;
            return;
        }
        
        for (int i = 0; i < order.itemCount; i++)
        {
            cout << "Enter item ID: ";
            cin >> order.itemIds[i];
            
            cout << "Enter quantity: ";
            cin >> order.itemQuantities[i];
        }
        
        cout << "Enter discout: ";
        cin >> order.discount;
        strcpy(order.status, "Pending");
        orders[orderCount++] = order;
        
        cout << "Order placed" << endl;
    }
    
    void displayOrders()
    {
        if(orderCount == 0)
        {
            cout << "No order placed" << endl;
            return;
        }
        
        cout << endl << "Orders: " << endl;
        
        for (int i = 0; i < orderCount; i++)
        {
            cout << "Order ID: " << orders[i].orderId << endl;
            cout << "Table Number: " << orders[i].tableNumber << endl;
            cout << "Items: " << endl;
            
            for (int j = 0; j < orders[i].itemCount; j++)
            {
                cout << "  Item ID: " << orders[i].itemIds[j]
                << ", Quantity: " << orders[i].itemQuantities[j] << endl;
            }
            
            cout << "Discount: " << orders[i].discount << endl;
            cout << "Status: " << orders[i].status << endl << endl;
        }
    }
    
    void completeOrder()
    {
        if (orderCount == 0)
        {
            cout << "No order placed" << endl;
            return;
        }
        
        int orderId;
        cout << "Enter Order ID to mark as completed: ";
        cin >> orderId;
        
        for (int i = 0; i < orderCount; i++)
        {
            if (orders[i].orderId == orderId)
            {
                strcpy(orders[i].status, "Completed");
                cout << "Order ID " << orderId << " marked as completed" << endl;
                return;
            }
        }
        
        cout << "Order ID not found" << endl;
    }
    
    void generateReceipt()
    {
        if (orderCount == 0)
        {
            cout << "No order placed" << endl;
            return;
        }
        
        int orderId;
        cout << "Enter Order ID to generate receipt: ";
        cin >> orderId;
        
        for (int i = 0; i < orderCount; i++)
        {
            if (orders[i].orderId == orderId)
            {
                double total = 0;
                cout << endl << "Receipt for Order ID " << orderId << ": " << endl;
                cout << "Table Number: " << orders[i].tableNumber << endl;
                cout << "Items:" << endl;
                
                for (int j = 0; j < orders[i].itemCount; j++)
                {
                    int itemId = orders[i].itemIds[j];
                    int quantity = orders[i].itemQuantities[j];
                    double price = 0;
                    
                    for (int k = 0; k < menuItemCount; k++)
                    {
                        if (menu[k].itemId == itemId)
                        {
                            price = menu[k].price;
                            
                            cout << "  " << menu[k].name << " x" << quantity << " at $" << price
                            << " each" << endl;
                            break;
                        }
                    }
                    
                    total += price * quantity;
                }
                
                total -= orders[i].discount;
                cout << "Discount: " << orders[i].discount << endl;
                cout << "Total: " << total << endl << endl;
                return;
            }
        }
        cout << "Order ID not found" << endl;
    }
    
    void saveToFile(const char* filename)
    {
        ofstream file(filename);
        
        if (!file)
        {
            cout << "Error saving menu to file" << endl;
            return;
        }
        
        file << menuItemCount << endl;
        
        for (int i = 0; i < menuItemCount; i++)
        {
            file << menu[i].itemId << " " << menu[i].name << " " << menu[i].price << endl;
        }
        
        file.close();
    }
    
    
    void loadFromFile(const char* filename)
    {
        ifstream file(filename);
        
        if (!file)
        {
            cout << "No existing menu found" << endl;
            return;
        }
        
        file >> menuItemCount;
        
        for (int i = 0; i < menuItemCount; i++)
        {
            file >> menu[i].itemId;
            file.ignore();
            file.getline(menu[i].name, 50);
            file >> menu[i].price;
        }
        
        file.close();
    }
};


int main ()
{
    Restaurant system;
    int choice;
    
    do
    {
        cout << endl << "--- Restaurant Order Management System ---" << endl;
        cout << "1. Add Menu Item" << endl;
        cout << "2. Display Menu" << endl;
        cout << "3. Place Order" << endl;
        cout << "4. Display Orders" << endl;
        cout << "5. Complete Order" << endl;
        cout << "6. Generate Receipt" << endl;
        cout << "7. Exit" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                system.addMenuItem();
                break;
            case 2:
                system.displayMenu();
                break;
            case 3:
                system.placeOrder();
                break;
            case 4:
                system.displayOrders();
                break;
            case 5:
                system.completeOrder();
                break;
            case 6:
                system.generateReceipt();
                break;
            case 7:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    } while (choice != 7);
    
    return 0;
}
