#include<iostream>
using namespace std;
struct teams {
	teams* next;
	int id;
	string name;
	string president;

};
teams* head = NULL;

void addteam(int IDt, string nameteam, string presidentname) {
	teams* t1 = new teams;
	t1->id = IDt;
	t1->name = nameteam;
	t1->president = presidentname;
	t1->next = NULL;
	if (head == NULL) {
		head = t1;
	}
	else {
		teams* end = head;
		while (end->next != NULL) {
			end = end->next;
		}
		end->next = t1;
	}
}
void display() {
	if (head == NULL) {
		cout << "no teams to display" << endl;
	}
	else {
		teams* temp = head;
		while (temp != NULL) {
			cout << "the  teams is :" << temp->name << endl;
			temp = temp->next;
		}

	}


}
int search(int IDt) {
	teams* s = head;
	int pos = 1;
	while (s != NULL) {
		if (s->id == IDt) {
			cout << " the pos of team is:" << pos << endl;
			pos++;
			s = s->next;
		}
		
	}
	return -1;
}
struct players {
	int id;
	int salary;
	int age;
	string name;
	string team;
	char position;
	players* next;

};
players* start = NULL;
void  addplayer(int IDp, int sal, int ageP, string namep, string teamP, char posp) {
	players* p1 = new players;
	p1->id = IDp;
	p1->salary = sal;
	p1->age = ageP;
	p1->name = namep;
	p1->team = teamP;
	p1->position = posp;
	p1->next = NULL;
	if (start == NULL) {
		start = p1;
	}
	else {
		players* tail = start;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = p1;
	}

}
void removeAT(int ID) {
	players* tmp = start, * deletep;
	while (tmp->id != ID) {
		tmp = tmp->next;

		deletep = tmp;
		cout << deletep->id << " the player is deleted " << endl;
		delete deletep;

	}


}
int searchP(string namep) {
	players* f = start;
	int pos = 1;
	while (f != NULL) {
		if (f->name == namep) {
			cout << "the player found at pos: " << pos << endl;
			pos++;
			f = f->next;
		}
		
	}
	return -1;
}
void displayP() {
	if (start == NULL) {
		cout << "no players to display" << endl;
	}
	else {
		players* t = start;
		while (t != NULL) {
			cout << "the data of players is : " << " the id: " << t->id << "\n";
			cout<< " the name : " << t->name << "\n"<< endl;
			t = t->next;
		}
	}



}

void main() {

	int id;
	int age;
	int salary;
	string name;
	string team;
	string president;
	char pos;
	char choise;
	int choose;


	while (true) {

		cout << "/***********************************/" << endl;;
		cout << "choose 1 for team , 2 for players" << endl;
		cin >> choose;
		
			if (choose == 1) {

				while (true)
				{
					cout << "/t*********************************/" << endl;
					cout << "\t\tenter a for add new team \n";
					cout << "\t\tenter s for search about team \n";
					cout << "\t\tenter d for dispaly all teams\n";
					cout << "\t\tenter e for exit \n";
					cout << "/t************************************/" << endl;
					cout << "enter your choise : " << endl;
					cin >> choise;
					switch (choise) {
					case'a':
						cout << "enter the IDT " << endl;
						cin >> id;
						cout << "enter the name of team" << endl;
						cin >> name;
						cout << "enter the president " << endl;
						cin >> president;
						addteam(id, name, president);
						break;
					case's':
						cout << "enter the id for search" << endl;
						cin >> id;
						search(id);
						break;
					case'd':
						display();
						break;
					case'e':
						exit(0);
						break;
					default:
						cout << "wrong choise, try again" << endl;

					}


				}
			}



			else if (choose == 2) {
				while (true) {

					cout << "/***********************************/" << endl;
					cout << "\t\tenter p for add  player\n";
					cout << "\t\tenter r for remove player\n";
					cout << "\t\tenter s for search about player\n";
					cout << "\t\tenter t for display\n";
					cout << "\t\tenter e for exit\n";
					cout << "/*****************************************/" << endl;
					cout << "enter your choise: " << endl;
					cin >> choise;

					switch (choise) {
					case'p':

						cout << "enter id:" << endl;
						cin >> id;
						cout << "enter the name:" << endl;
						cin >> name;
						cout << "enter team" << endl;
						cin >> team;
						cout << "enter age" << endl;
						cin >> age;
						cout << "enter salary" << endl;
						cin >> salary;
						cout << "enter position" << endl;
						cin >> pos;

						addplayer(id, salary, age, name, team, pos);
						cout << "the player is added Successfully" << endl;

						break;
					case'r':
						cout << "enter the id for player" << endl;
						cin >> id;
						removeAT(id);
						break;
					case's':
						cout << "enter the name of player" << endl;
						cin >> name;
						searchP(name);
						break;
					case't':
						displayP();
						break;
					case'e':
						exit(0);
						break;
					default:
						cout << "wrong choise, try again" << endl;
					}
				}
			}

			else
				cout << "wrong choise" << endl;

		
	}


}


	
	


