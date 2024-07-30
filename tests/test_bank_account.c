#include <stdio.h>
#include <stdlib.h>
#include "../munit/munit.h"
#include "../include/bank_account.h"

static MunitResult
BankAccount_test(const MunitParameter params[], void* data) {
	UNUSED(params);
	UNUSED(data);
	BankAccount* pAccount = (BankAccount*)data;
	int balance;

	while(1)
	{
		printf("입금할 금액을 입력하시오 : ");
		scanf("%d",&balance);
		deposit(pAccount, balance);
		printf("출금할 금액을 입력하시오 : ");
		scanf("%d",&balance);
		withdraw(pAccount, balance);
		munit_assert_int(pAccount->balance, >=, 0);
	}

    return MUNIT_OK;
}

static void* BankAccount_setup(const MunitParameter params[], void* user_data) {
	UNUSED(params);
	UNUSED(user_data);
	BankAccount* pAccount = (BankAccount*)user_data;
	printf("\n");

    return (void*)pAccount;
}

static void BankAccount_tear_down(void* fixture) {
	UNUSED(fixture);
}

// static char* first_params[] = {
//   "1", "2", "3", "4","5",NULL
// };

// static char* second_params[] = {
//   "11", "12", "13", "14","15",NULL
// };

// static char* third_params[] = {
//   "21", "22", "23", "24","25",NULL
// };

// static MunitParameterEnum BankParams[] = {
//   { "first", first_params },
//   { "second", second_params },
//   { "third", third_params },
//   { NULL, NULL },
// };

static MunitTest Bank_Account_tests[] = {
    {
        "/bankAccount",
        BankAccount_test,
        BankAccount_setup,
        BankAccount_tear_down,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite test_suite = {
    "/Bank_Account",
    Bank_Account_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	BankAccount account;
	init_account(&account);
	return munit_suite_main(&test_suite, (void*)&account, argc, argv);
}