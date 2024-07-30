#include <stdio.h>
#include "../include/bank_account.h"

void init_account(BankAccount* pAccount) {
    pAccount->balance = 0;

}
void deposit(BankAccount* pAccount, int balance) {
    pAccount->balance += balance;
}
void withdraw(BankAccount* pAccount, int balance) {
    pAccount->balance -= balance;
}