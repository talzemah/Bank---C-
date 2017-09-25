#include <iostream>
using namespace std;

#include "Account.h"
#include "Address.h"
#include "Bank.h"
#include "Branch.h"
#include "Client.h"
#include "Deposit.h"
#include "Person.h"
#include "Transaction.h"
#include "Transfer.h"
#include "Withraw.h"
#include "Worker.h"
#include "WorkerClient.h"

int main(int argc, const char * argv[])
{
	cout << "Welcome to our Bank !!!" << endl;

	Bank bank("Israel Bank", 1);

	Branch jerusalemBranch(Address("Jerusalem", "yafo", 92, 9200092), 10, "Jerusalem");
	Branch telAvivBranch(Address("Tel Aviv", "Alenbi", 64, 6400064), 20, "Tel Aviv");

	
	time_t temp = time(0);

	tm *date1 = localtime(&temp);
	date1->tm_year = 91;
	date1->tm_mon = 0;
	date1->tm_mday = 1;

	tm *date2 = localtime(&temp);
	date2->tm_year = 100;
	date2->tm_mon = 0;
	date2->tm_mday = 1;

	Client client1("Client 1", 111111111, mktime(date1), Address("Jerusalem", "yafo", 93, 9300093));
	Client client2("Client 2", 222222222, mktime(date2), Address("Tel Aviv", "Alenbi", 65, 6500065));

	Worker worker1("worker1", 10001, mktime(date1), Address("Jerusalem", "yafo", 94, 9400094), 8000);
	Worker worker2("worker2", 20001, mktime(date2), Address("Tel Aviv", "Alenbi", 66, 6600066), 12000);
	
	WorkerClient workerClient1("workerClient1", 10002, mktime(date1), Address("Jerusalem", "yafo", 95, 9500095));
	WorkerClient workerClient2("workerClient2", 20002, mktime(date2), Address("Tel Aviv", "Alenbi", 67, 6700067));

	Account account1(100);
	Account account2(101);
	Account account3(102);
	Account account4(103);

	client1.addAccount(account1);
	client2.addAccount(account2);
	workerClient1.addAccount(account3);
	workerClient2.addAccount(account4);

	jerusalemBranch.addClient(client1);
	jerusalemBranch.addWorker(worker1);
	jerusalemBranch.addWorkerClient(workerClient1);

	telAvivBranch.addClient(client2);
	telAvivBranch.addWorker(worker2);
	telAvivBranch.addWorkerClient(workerClient2);

	bank.addBranch(telAvivBranch);
	bank.addBranch(jerusalemBranch);

	bank.paySalaries();
	bank.payBonus();
	bank.alertOnOverdraft();
	bank.alertOnOverBalance();


	account1.checkBalance();
	account2.deposit(300);
	account3.withraw(200);
	account4.transfer(600, account2); // same branch

	system("pause");

} // end main