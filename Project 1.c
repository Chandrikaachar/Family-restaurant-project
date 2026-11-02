#include <stdio.h>

struct Order
{
    int item;
    int price;
    int quantity;
    int amount;
};

int main()
{
    struct Order orders[100];

    char name[50], mobile[15];

    int choice, quantity;
    int count = 0, i;
    int total = 0;
    float gst, grand_total;

    printf("\n==================================\n");
    printf("       FAMILY RESTAURANT\n");
    printf("==================================\n");

    printf("Enter customer name: ");
    scanf(" %49[^\n]", name);

    printf("Enter mobile number: ");
    scanf("%14s", mobile);

    while(1)
    {
        printf("\n========== FOOD MENU ==========\n");

        printf("\n--- SOUTH INDIAN ---\n");
        printf("1. Idli              Rs.30\n");
        printf("2. Masala Dosa       Rs.60\n");
        printf("3. Vada              Rs.25\n");
        printf("4. Pongal            Rs.50\n");

        printf("\n--- NORTH INDIAN ---\n");
        printf("5. Paneer Butter Masala Rs.150\n");
        printf("6. Butter Naan       Rs.40\n");
        printf("7. Veg Biryani       Rs.120\n");
        printf("8. Fried Rice        Rs.100\n");

        printf("\n--- SNACKS ---\n");
        printf("9. Sandwich          Rs.60\n");
        printf("10. French Fries     Rs.80\n");

        printf("\n--- DESSERTS & DRINKS ---\n");
        printf("11. Ice Cream        Rs.50\n");
        printf("12. Gulab Jamun      Rs.40\n");
        printf("13. Coffee           Rs.25\n");
        printf("14. Fresh Juice      Rs.60\n");

        printf("\n15. Generate Bill\n");
        printf("16. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                orders[count].item = 1;
                orders[count].price = 30;
                break;

            case 2:
                orders[count].item = 2;
                orders[count].price = 60;
                break;

            case 3:
                orders[count].item = 3;
                orders[count].price = 25;
                break;

            case 4:
                orders[count].item = 4;
                orders[count].price = 50;
                break;

            case 5:
                orders[count].item = 5;
                orders[count].price = 150;
                break;

            case 6:
                orders[count].item = 6;
                orders[count].price = 40;
                break;

            case 7:
                orders[count].item = 7;
                orders[count].price = 120;
                break;

            case 8:
                orders[count].item = 8;
                orders[count].price = 100;
                break;

            case 9:
                orders[count].item = 9;
                orders[count].price = 60;
                break;

            case 10:
                orders[count].item = 10;
                orders[count].price = 80;
                break;

            case 11:
                orders[count].item = 11;
                orders[count].price = 50;
                break;

            case 12:
                orders[count].item = 12;
                orders[count].price = 40;
                break;

            case 13:
                orders[count].item = 13;
                orders[count].price = 25;
                break;

            case 14:
                orders[count].item = 14;
                orders[count].price = 60;
                break;

            case 15:
                goto BILL;

            case 16:
                printf("Thank you! Visit again.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
                continue;
        }

        if(count >= 100)
        {
            printf("Maximum orders reached!\n");
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        if(quantity <= 0)
        {
            printf("Invalid quantity!\n");
            continue;
        }

        orders[count].quantity = quantity;

        orders[count].amount =
        orders[count].price * quantity;

        printf("Order added successfully!\n");

        count++;
    }

    BILL:

    if(count == 0)
    {
        printf("No items ordered!\n");
        return 0;
    }

    printf("\n==================================\n");
    printf("          FAMILY RESTAURANT\n");
    printf("==================================\n");

    printf("Customer Name : %s\n", name);
    printf("Mobile Number : %s\n", mobile);

    printf("----------------------------------\n");
    printf("ITEM             QTY  PRICE  AMOUNT\n");
    printf("----------------------------------\n");

    for(i = 0; i < count; i++)
    {
        switch(orders[i].item)
        {
            case 1:
                printf("Idli             ");
                break;
            case 2:
                printf("Masala Dosa      ");
                break;
            case 3:
                printf("Vada             ");
                break;
            case 4:
                printf("Pongal           ");
                break;
            case 5:
                printf("Paneer Masala    ");
                break;
            case 6:
                printf("Butter Naan      ");
                break;
            case 7:
                printf("Veg Biryani      ");
                break;
            case 8:
                printf("Fried Rice       ");
                break;
            case 9:
                printf("Sandwich         ");
                break;
            case 10:
                printf("French Fries     ");
                break;
            case 11:
                printf("Ice Cream        ");
                break;
            case 12:
                printf("Gulab Jamun      ");
                break;
            case 13:
                printf("Coffee           ");
                break;
            case 14:
                printf("Fresh Juice      ");
                break;
        }

        printf("%-5d %-6d %d\n",
        orders[i].quantity,
        orders[i].price,
        orders[i].amount);

        total = total + orders[i].amount;
    }

    gst = total * 5.0 / 100;

    grand_total = total + gst;

    printf("----------------------------------\n");

    printf("Total Amount : Rs.%d\n", total);
    printf("GST (5%%)     : Rs.%.2f\n", gst);
    printf("Grand Total  : Rs.%.2f\n", grand_total);

    printf("\n========== PAYMENT ==========\n");

    printf("1. Cash\n");
    printf("2. UPI\n");
    printf("3. Card\n");

    printf("Select payment method: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Payment Method: Cash\n");
            break;

        case 2:
            printf("Payment Method: UPI\n");
            break;

        case 3:
            printf("Payment Method: Card\n");
            break;

        default:
            printf("Invalid payment method!\n");
            break;
    }

    printf("\n==================================\n");
    printf("    THANK YOU FOR VISITING US!\n");
    printf("       VISIT AGAIN\n");
    printf("==================================\n");

    return 0;
}
