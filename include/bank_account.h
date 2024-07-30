#ifndef __BANK_ACCOUNT__
#define __BANK_ACCOUNT__

#define UNUSED(x) (void)(x)

typedef struct BankAccount_t{
	int balance;
}BankAccount;

void init_account(BankAccount* pAccount);
void deposit(BankAccount* pAccount, int balance);
void withdraw(BankAccount* pAccount, int balance);

#endif