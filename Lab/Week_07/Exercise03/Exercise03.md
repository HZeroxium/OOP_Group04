# Exercise 03

## Table of Contents

- [Exercise 03](#exercise-03)
  - [Table of Contents](#table-of-contents)
  - [1. Briefly describe the UML diagram](#1-briefly-describe-the-uml-diagram)
    - [1.1 Enum Class `OrderStatus`](#11-enum-class-orderstatus)
    - [1.2 Class `Item`](#12-class-item)
    - [1.3 Class `Customer`](#13-class-customer)
    - [1.4 Class `Payment`](#14-class-payment)
      - [1.4.1 Class `Credit`](#141-class-credit)
      - [1.4.2 Class `Cash`](#142-class-cash)
    - [1.4.3 Class `Check`](#143-class-check)
    - [1.4.4 Class `WireTransfer`](#144-class-wiretransfer)
    - [1.5 Class `OrderDetail`](#15-class-orderdetail)
    - [1.6 Class `Order`](#16-class-order)
  - [2. Relationships between classes](#2-relationships-between-classes)
    - [2.1 Association](#21-association)
    - [2.2 Aggregation](#22-aggregation)
    - [2.3 Specialization](#23-specialization)

## 1. Briefly describe the UML diagram

### 1.1 Enum Class `OrderStatus`

This class is used to define the status of an order. It has four possible values:

- `CREATE: int = 0`: The order has been created but not yet paid.
- `SHIPPING: int = 1`: The order has been paid and is being shipped.
- `DELIVERED: int = 2`: The order has been delivered.
- `PAID: int = 3`: The order has been paid.

### 1.2 Class `Item`

This class is used to define an item. It has the following attributes:

- `weight: float`: The weight of the item.
- `description: string`: The description of the item.

Methods:

- `getPriceForQuantity(quantity: int): float`: Returns the price of the item for a given quantity.
- `getWeight(): float`: Returns the weight of the item.

### 1.3 Class `Customer`

This class is used to define a customer. It has the following attributes:

- `name: string`: The name of the customer.
- `deliveryAddress`: string: The delivery address of the customer.
- `contact: string`: The contact of the customer.
- `active: boolean`: Whether the customer is active or not.
- `orderHistory: Order[]`: The order history of the customer.

### 1.4 Class `Payment`

This class is used to define a payment method. It has the following attributes:

- `amount: float`: The amount of the payment.

#### 1.4.1 Class `Credit`

This class derives from Payment. It has the following attributes:

- `number: string`: The credit card number.
- `type: string`: The type of the credit card.
- `expireDate: date`: The expire date of the credit card.

#### 1.4.2 Class `Cash`

This class derives from Payment. It has the following attributes:

- `cashTendered: float`: The amount of cash tendered.

### 1.4.3 Class `Check`

This class derives from Payment. It has the following attributes:

- `name: string`: The name of the check.
- `bankID: string`: The bank ID of the check.

Methods:

- `authorized()`: boolean: Returns true if the check is authorized.

### 1.4.4 Class `WireTransfer`

This class derives from Payment. It has the following attributes:

- `bankID: string`: The bank ID of the wire transfer.
- `bankName: string`: The bank name of the wire transfer.

### 1.5 Class `OrderDetail`

This class is used to define an order detail. It has the following attributes:

- `qty: int`: The quantity of the order detail.
- `taxStatus: string`: The tax status of the order detail.
- `item: Item`: The item of the order detail.

Methods:

- `calculateSubTotal(): float`: Returns the subtotal of the order detail.
- `calculateWeight(): float`: Returns the weight of the order detail.

### 1.6 Class `Order`

This class is used to define an order. It has the following attributes:

- `createDate: date`: The create date of the order.
- `status: OrderStatus`: The status of the order.
- `orderDetails: OrderDetail[]`: The order details of the order.
- `customer: Customer`: The customer of the order.
- `payment: Payment`: The payment of the order.

## 2. Relationships between classes

### 2.1 Association

- `Order` and `Customer`: A customer can have many orders, and an order can only have one customer. This is a one-to-many association.
- `Order` and `OrderStatus`: An order can only have one status. This is a one-to-one association.
- `OrderDetail` and `Item`: An order detail can only have one item, and an item can exist in many order details. This is a one-to-many association.

### 2.2 Aggregation

- `Order` and `OrderDetail`: An order can have many order details, and an order detail can only exist in one order. This is a one-to-many aggregation.

### 2.3 Specialization

- `Payment` and `Credit`: A credit is a type of payment.
- `Payment` and `Cash`: A cash is a type of payment.
- `Payment` and `Check`: A check is a type of payment.
- `Payment` and `WireTransfer`: A wire transfer is a type of payment.
