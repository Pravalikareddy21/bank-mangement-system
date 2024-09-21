#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000
#define MAX_LOANS 100
typedef struct {
 char name [50];
 char pan [11]; 
 char Aadhar [13];
  float balance;
  bool has Loan;
  float loan Amount;
 float Loan Balance;
} Customer;
 typedef struct {
 Customer;
  float amount;
  char type [50];
  time_t time;
  } Transaction;
  typedef struct {
  float amount;    
  int duration;
  float interest;
  float monthly Installment;
  bool is Active;
  char type [50];
  } Loan;
  Customer customers [MAX_CUSTOMERS];
  Transaction transactions [MAX_TRANSACTIONS];
  Loan loans [MAX_LOANS];
  int Num Customers = 0;
  int Num Transactions = 0;
  int Num Loans = 0;
  bool validate PAN (const char *pan) {
  return true;
 }
  bool validate Aadhaar (const char *Aadhaar) {   
return true;
}
void add Transaction (Customer, float amount, const char *type) {
Transaction new Transaction;
 New Transaction. Customer = customer;
 New Transaction. Amount = amount;
 strcpy(new Transaction. type, type);
 New Transaction. time = time (NULL);     
transactions [Num Transactions] = new Transaction;
 Num Transactions++;
 }
void generate Daily Report(Customer customer) {
print f("----- Daily Transaction Report -----\n");
print f("Customer Name: %s\n", customer.name);
print f("PAN: %s\n", customer. Pan);
print f("Aadhaar: %s\n", customer. Aadhar);
print f("Current Balance: %.2f\n", customer. Balance);
print f("Recent Transactions:\n");
time_t current Time = time (NULL);
struct Tm *current Date = local time (&current Time);    
int count = 0;
int I;
 for (I = 0; I < Num Transactions; I++) {
 if (strcmp(transactions[I]. customer. Pan, customer. Pan) == 0) {
 struct Tm *transaction Date = local time(&transactions[I]. time);           
 if (current Date->t m _ day == transaction Date->t m _m day &&
 current Date->Tm_Mon == transaction Date->Tm_Mon &&
 current Date->Tm_year == transaction Date->Tm_year) {
 print f("%.2f (%s) - %02d: %02d: %02d\n", transactions[I]. amount,           transactions[I]. type,
 transaction Date->Tm_hour, transaction Date->Tm_min, transaction Date->Tm_sec);
   count++;
   }
   }
   }  
   if (count == 0) {
   print f("No recent transactions today.\n");
    }
   }
void generate Weekly Report (Customer customer) {
 print f("----- Weekly Transaction Report -----\n");
 print f("Customer Name: %s\n", customer.name);
 print f("PAN: %s\n", customer. Pan);
 print f("Aadhaar: %s\n", customer. Aadhar);
 print f("Current Balance: %.2f\n", customer. Balance);
 print f("Recent Transactions:\n");
    
    time_t current Time = time (NULL);
    struct Tm *current Date = local time (&current Time);   
    int count = 0;
    int I;
    for (I = 0; I < Num Transactions; I++) {
    if (strcmp(transactions[I]. customer. Pan, customer. Pan) == 0) {
     struct Tm *transaction Date = local time(&transactions[I]. time);       
     int days Diff = diff time (current Time, transactions[I]. time) / (60 * 60 *   24);            
     if (days Diff <= 7) {
    print f("%.2f (%s) - %02d: %02d: %02d\n", transactions[I]. amount, transactions[I]. type,
 transaction Date->Tm_hour, transaction Date->Tm_min, transaction Date->Tm_sec);
   count++;
    }
    }
    }
    if (count == 0) {
    print f("No recent transactions in the past week.\n");
    }
    }
 
void generate Monthly Report (Customer customer) {
 print f("----- Monthly Transaction Report -----\n");
 print f("Customer Name: %s\n", customer.name);
 print f("PAN: %s\n", customer. Pan);
 print f("Aadhaar: %s\n", customer. Aadhar);
 print f("Current Balance: %.2f\n", customer. Balance);
 print f("Recent Transactions:\n");  
 time_t current Time = time (NULL);
 struct Tm *current Date = local time (&current Time);   
 int count = 0;
 int I;
  for (I = 0; I < Num Transactions; I++) {
  if (strcmp(transactions[I]. customer. Pan, customer. Pan) == 0) {
  struct Tm *transaction Date = local time(&transactions[I]. time);         
  int days Diff = diff time (current Time, transactions[I]. time) / (60 * 60 * 24);          
   if (days Diff <= 30) {
 print f("%.2f (%s) - %02d: %02d: %02d\n", transactions[I]. amount, transactions[I]. type,
 transaction Date->Tm_hour, transaction Date->Tm_min, transaction Date->Tm_sec);
  count++;
   }
   }
    } 
   if (count == 0) {
   print f("No recent transactions in the past month.\n");
    }
   }
  void apply Loan (Customer *customer) {
   if (customer->has Loan) {
   print f("You already have an active loan.\n");
   return;
    }
  Loan new Loan;
  print f("Loan Type: ");
  scan f(" %[^\n]", new Loan. Type);
  print f("Loan Amount: ");
  scan f("%f", &new Loan. Amount);
  print f("Loan Duration (in months): ");
  scan f("%d", &new Loan. Duration);  
    print f("Interest Rate: ");
    scan f("%f", &new Loan. interest Rate);
    float interest = (new Loan. Amount * new Loan. Duration * new Loan. interest Rate) / 100;
    New Loan. monthly Installment = (new Loan. Amount + interest) / new Loan. Duration;
    New Loan .is Active = true; 
    customer->has Loan = true;
    customer->loan Amount = new Loan. Amount;
    customer->loan Balance = new Loan. Amount; 
    loans [Num Loans] = loan;
    Num Loans++;
    print f("Loan applied successfully.\n");
}
   void collect Loan (Customer *customer) {
    if (! customer->has Loan) {
   print f("You don't have an active loan.\n");
    return;
    }
    float installment = customer->loan Balance / customer->loan Amount * loans->monthly Installment;
    print f("Collecting Loan Installment: %.2f\n", installment);
    customer->Loan Balance -= installment;
    customer->balance += installment;
    add Transaction (*customer, -1 * installment, "Loan Installment");
    if (customer->Loan Balance <= 0) {
        customer->has Loan = false;
        print f("Loan fully paid.\n");
    }
}
void save Customer Details () {
    FILE *file = f open("customer_details.text", "w");
    if (file == NULL) {
        print f("Failed to open the file for writing.\n");
        return;
    }
    int I;
    for (I = 0; I < Num Customers; I++) {
        fprintf(file, "Customer Name: %s\n", customers[I].name);
        fprintf(file, "PAN: %s\n", customers[I]. pan);
        fprintf(file, "Aadhaar: %s\n", customers[I]. Aadhar);
        fprintf(file, "Balance: %.2f\n", customers[I]. balance);
        fprintf(file, "Has Loan: %s\n", customers[I]. has Loan? "Yes": "No");
        fprintf(file, "Loan Amount: %.2f\n", customers[I]. loan Amount);
        fprintf(file, "Loan Balance: %.2f\n", customers[I]. loan Balance);
        fprintf(file, "\n");
    }
    f close(file);
    print f("Customer details saved to file.\n");
}
 
int main () {
    int choice;
    do {
        print f ("----- Bank Management System -----\n");
        print f ("1. Add Customer\n");
        print f ("2. Perform Transaction\n");
        print f ("3. Generate Daily Report\n");
        print f ("4. Generate Weekly Report\n");
        print f ("5. Generate Monthly Report\n");
        print f ("6. Apply for Loan\n");
        print f ("7. Collect Loan Installment\n");
        print f ("8. Save Customer Details to File\n");
        print f ("9. Exit\n");
        print f("Enter your choice: ");
        scan f("%d", &choice);
        switch (choice) {
            case 1: {
                if (Num Customers == MAX_CUSTOMERS) {
                    print f("Maximum customer limit reached.\n");
                    break;
                }
                
                Customer new Customer;
                print f("Customer Name: ");
                scan f(" %[^\n]", newCustomer.name);
                print f("PAN: ");
                scan f(" %[^\n]", new Customer. Pan);
                if (! validate PAN (new Customer. Pan)) {
                    print f("Invalid PAN number.\n");
                    break;
                }
                print f("Aadhaar: ");
                scan f(" %[^\n]", new Customer. Aadhar);
                if (! validate Aadhaar (new Customer. Aadhar)) {
                    print f("Invalid Aadhaar number.\n");
                    break;
                }
                print f("Initial Balance: ");
                scan f("%f", &new Customer. Balance);
                New Customer. has Loan = false;
                New Customer. Loan Amount = 0;
                New Customer. Loan Balance=0;   
                customers [Num Customers] = new Customer;
                Num Customers++;
             
                print f("Customer added successfully.\n");
                break;
            }
            case 2: {
                char pan [11];
                print f("Enter PAN: ");
                scan f(" %[^\n]", pan);  
                int I;
                for (I = 0; I < Num Customers; I++) {
                    if (strcmp(customers[I]. pan, pan) == 0) {
                        float amount;
                        print f("Enter Amount: ");
                        scan f("%f", &amount);
                        char type [50];
                        print f("Enter Transaction Type: ");
                        scan f(" %[^\n]", type);
                        if (strcmp(type, "credit") == 0) {
                            customers[I]. balance += amount;
                        } else if (strcmp(type, "debit") == 0) {
                            if (customers[I]. balance >= amount) {
                                customers[I]. balance -= amount;
                            } else {
                                print f("Insufficient balance.\n");
                                break;
                            }
                        } else {
                            print f("Invalid transaction type.\n");
                            break;
                        }
                        add Transaction(customers[I], amount, type);
                        print f("Transaction completed successfully.\n");
                        break;
                    }
                }
                if (I == Num Customers) {
                    print f("Customer not found.\n");
                }
                break;
        }
            case 3: {
                char pan [11];
                print f("Enter PAN: ");
                scan f(" %[^\n]", pan);       
                int I;
                for (I = 0; I < Num Customers; I++) {
                    if (strcmp(customers[I]. pan, pan) == 0) {
                        Generate Daily Report(customers[I]);
                        break;
                    }
                }
                if (I == Num Customers) {
                    print f("Customer not found.\n");
                }
                break;
            }
            case 4: {
                char pan [11];
                print f("Enter PAN: ");
                scan f(" %[^\n]", pan);  
                int I;
                for (I = 0; I < Num Customers; I++) {
                    if (strcmp(customers[I]. pan, pan) == 0) {
                        Generate Weekly Report(customers[I]);
                        break;
                    }
                }
                if (I == Num Customers) {
                    print f("Customer not found.\n");
                }
                break;
         }
            case 5: {
                char pan [11];
                print f("Enter PAN: ");
                scan f(" %[^\n]”, pan);      
                int I;
                for (I = 0; I < Num Customers; I++) {
                    if (strcmp(customers[I]. pan, pan) == 0) {
                        Generate Monthly Report(customers[I]);
                        break;
                    }
                }
                if (I == Num Customers) {
                    print f("Customer not found.\n");
                }  
                break;
            }
            case 6: {
                char pan [11];
                print f("Enter PAN: ");
                scan f(" %[^\n]", pan);
                int I;
                for (I = 0; I < Num Customers; I++) {
                    if (strcmp(customers[I]. pan, pan) == 0) {
                        apply Loan(&customers[I]);
                        break;
                    }
                }
                if (I == Num Customers) {
                    print f("Customer not found.\n");
                }
                break;
            }
            case 7: {
                char pan [11];
                print f("Enter PAN: ");
                scan f(" %[^\n]", pan);  
                int I;
                for (I = 0; I < Num Customers; I++) {
                    if (strcmp(customers[I]. pan, pan) == 0) {
                        collect Loan(&customers[I]);
                        break;
                    }
                }
                if (I == Num Customers) {
                    print f("Customer not found.\n");
                }
                break;
            }
            case 8: {
                Save Customer Details ();
                break;
            }
            case 9: {
                print f("Exiting...\n");
                break;
            }
            default:
                print f("Invalid choice. Please try again.\n");
        }
        print f("\n");
    } while (choice! =9);
    return 0;
}
