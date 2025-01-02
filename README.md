# **Restaurant Order Management System**

**Description**  
A command-line system to manage restaurant operations including menu management, order placement, tracking, and receipt generation. The system allows saving and loading menu items to/from files for persistent storage, making it a robust solution for restaurant order management.

---

## **Table of Contents**

1. [Features](#features)  
2. [How It Works](#how-it-works)  
3. [Installation](#installation)  
4. [Technologies Used](#technologies-used)  
5. [Future Enhancements](#future-enhancements)

---

## **Features**

### **1. Menu Management**
- Add new menu items with name, price, and ID.  
- Display all menu items in a formatted list.  
- Save and load menu items to/from a file for persistent storage.  

### **2. Order Management**
- Place orders by selecting items from the menu and specifying quantities.  
- Track orders with details like table number, items, quantities, discounts, and status.  
- Mark orders as completed when served.  

### **3. Receipt Generation**
- Generate and display a detailed receipt for a specific order.  
- Calculate total price with discounts applied.  

### **4. File Management**
- Save menu items to a file (`menu.txt`) and reload them for future use.  

---

## **How It Works**

### **Menu Management**  
1. Add items to the menu by specifying their name and price.  
2. Save the menu to a file for persistent storage or load existing menu data.  
3. View all menu items in a structured format.  

### **Order Placement**  
1. Place orders by selecting menu items and quantities.  
2. Specify a table number and optional discount for the order.  
3. Track and display all placed orders with their details.  

### **Order Completion and Receipt**  
1. Mark an order as completed when it is served.  
2. Generate a receipt for a specific order, displaying:  
   - Items ordered with quantities and prices.  
   - Discounts applied and total amount payable.  

### **File Management**  
- Save the menu for future use and load it upon restarting the system.  

---

## **Installation**

Follow these steps to set up and run the Restaurant Order Management System locally:

1. Clone the repository:
   ```bash
   git clone <repo-url>
   cd RestaurantOrderManagementSystem
   ```

2. Compile the program:
   ```bash
   g++ -o restaurant_system restaurantOrderManagement.cpp
   ```

3. Run the program:
   ```bash
   ./restaurant_system
   ```

---

## **Example Menu**

```plaintext
--- Restaurant Order Management System ---
1. Add Menu Item
2. Display Menu
3. Place Order
4. Display Orders
5. Complete Order
6. Generate Receipt
7. Exit
Enter your choice:
```

---

## **Technologies Used**

- **Language**: C++  
- **Libraries**: `<iostream>`, `<fstream>`, `<cstring>`  

---

## **Future Enhancements**

- Add functionality to delete menu items.  
- Extend system to support multiple payment methods (cash, card, etc.).  
- Introduce reporting tools to analyze sales and revenue.  
- Implement a graphical user interface (GUI) for improved usability.  
- Add database integration to handle larger datasets.  

---
