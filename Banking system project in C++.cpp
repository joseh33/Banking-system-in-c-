#include <iostream>
#include <fstream>
using namespace std;

class login {
private:
    string username;
    int password;

public:
    void setusername(string Username) {
        username = Username;
    }

    string getusername() {
        return username;
    }

    void setpassword(int Password) {
        password = Password;
    }

    int getpassword() {
        return password;
    }

    void logindetails() {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
    }
    
    bool authenticate(string enteredusername , int enteredpassword){
    	return(username == enteredusername && password == enteredpassword);
	}
  
};
class balance{
	private:
		float bal;
	public:
		balance(float initialbal = 10000) {
		bal = initialbal;
		}
		float getbal(){
		return bal;
		}
		
		void deposit(float bal){
			this->bal += bal;
		}
		
		bool withdraw(float bal){
			if(bal <=this->bal){
				this->bal -= bal;
				return true;
			}
			else {
				cout<<"Insufficient funds";
				return false;
		}
		}
};
class transaction{
	public:
		void displaybal(balance& bala){
			cout<<"Your balance is : Ksh"<<bala.getbal()<<endl;
		}
		
		void deposit(balance& bala, float bal ){
			bala.deposit(bal);
			cout<<"You have deposited "<< bal<<endl;
			displaybal(bala);
		}
		
	void withdraw(balance& bala, float bal){
		ofstream myFile("Transaction history.txt" , ios::app);
		if(bala.withdraw(bal)){
			cout<< "You have withdrawn Ksh"<<bal <<endl;
			myFile<<"You withdrawn Ksh "<<bal<<endl;
			myFile.close();
			displaybal(bala);
			}
	}

};

class transfer {
public:
      void withdraw(balance& bala, float amount , float bal ,int accNo){
     ofstream myFile("Transaction history.txt" , ios::app);
		if(bala.withdraw(bal)){
		cout<<"You have sent Ksh "<< amount <<" to "<<accNo <<endl;
		myFile<<"You sent Ksh "<< amount <<" to "<<accNo <<endl;
		myFile.close();
		}
	}
};


int main() {
	balance Balance;
    login details;
    details.logindetails();
    int choice ,accNo;
    float bal, amount;
    int option;

    if(details.authenticate("joseh" , 1616)){
		cout<<"Log in successful";
do{
        cout<<"\t\t\t========MAIN MENU========\n";
		cout<<"\t\t\t1.Check balance\t\t\t\n";
		cout<<"\t\t\t2.Transact\t\t\t\n";
		cout<<"\t\t\t3.Send money\t\t\t\n";
		cout<<"\t\t\t4.Transaction history\t\t\t\n";
		cout<<"\t\t\t5.Exit\t\t\t\n";
		
	
		cout<<"Enter your choice:";
		cin>>choice;
		transaction myobj;
		transfer obj;
		switch(choice){
			case 1:
		myobj.displaybal(Balance);
		break;
		
		case 2:
		
			cout<<"\t\t\t1.Deposit"<<endl;
			cout<<"\t\t\t2.Withdraw"<<endl;
			cout<<"Enter your option:";
			cin>>option;
			switch(option){
				case 1:
			cout<<"Enter amount you want to deposit : Ksh ";
			cin>>bal;
			myobj.deposit(Balance, bal);
			break;
		
			case 2:
				cout<<"Enter amount you want to withdraw : Ksh";
				cin>>bal;
				myobj.withdraw(Balance, bal);
				break;
			default:
				cout<<"invalid option\n";
			}
			break;
		case 3:
        cout<<"\t\t\tEnter amount to send:";
		cin>>amount;
		cout<<"\t\t\tEnter account number you want to send to:";
		cin>>accNo;
		obj.withdraw(Balance , amount , amount, accNo);
			break;
        case 4:
		{
        	ifstream myFile("Transaction history.txt");
        	string line;
        	while(getline(myFile, line)){
				cout<<line<<endl;
			}
			myFile.close();
        	break;
		}
         case 5:
        	cout<<"exiting the program...;";
        	return 0;
        	break;
        default:
        	cout<<"Invalid choice\n";
  
		}
		
	}while(choice<6);
	}else{
		cout<<"log in failed";
	}
    return 0;
}
