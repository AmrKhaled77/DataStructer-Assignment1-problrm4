#include <iostream>
#include <string>
using namespace std;

// Guest class to store guest information
class guest {
    string name;
    string contact;
    string date;
public:
    guest(); // Default constructor
    guest(string n, string c, string d); // Parameterized constructor
    void display_guest(); // Display guest details
    void update_inv(const string& input); // Update guest invitation date
    string get_name(); // Get guest name
    string get_contact(); // Get guest contact information
    string get_date(); // Get guest invitation date
    void set_date(string date); // Set a new date for the guest
};

static int no_guests; // Static variable to track the number of guests

// Iftar_Manager class to manage guests
class Iftar_Manager {
    static const int MAX_GUESTS = 50;
    guest guestlist[MAX_GUESTS]; // Array to store guest objects
public:
    Iftar_Manager(); // Constructor
    void add_guest(const guest& someone); // Add a guest to the list
    void display_guests(); // Display all guests
    void update_guests(const string& name, const string& date); // Update guest invitation date
    void send_reminder(const string& date); // Send reminders for iftar
    void sort_guests(); // Sort guests by date
    void remove_guest(const string& name); // Remove a guest by name
};

Iftar_Manager::Iftar_Manager() {
    // Default constructor implementation
}

// Guest class constructors
guest::guest() {
    name = "";
    contact = "";
    date = "";
}

guest::guest(string n, string c, string d) {
    this->name = n;
    this->contact = c;
    this->date = d;
}

// Getters for guest information
string guest::get_name() {
    return this->name;
}

string guest::get_contact() {
    return this->contact;
}

string guest::get_date() {
    return this->date;
}

// Setter for updating guest invitation date
void guest::set_date(string d) {
    this->date = d;
}

// Display guest details
void guest::display_guest() {
    cout << "Name: " << this->name << endl;
    cout << "Contact Info: " << this->contact << endl;
    cout << "Date in Ramadan: " << this->date << endl;
}

// Update guest invitation date
void guest::update_inv(const string& input) {
    this->date = input;
}

// Add a guest to the list
void Iftar_Manager::add_guest(const guest& someone) {
    guestlist[no_guests] = someone;
    no_guests++;
}

// Display all guests
void Iftar_Manager::display_guests() {
    for (int i = 0; i < no_guests; i++) {
        cout << "\nGuest " << i << ":\n";
        guestlist[i].display_guest();
        cout << "=====================\n";
    }
}

// Update the invitation date of a specific guest
void Iftar_Manager::update_guests(const string& name, const string& date) {
    for (int i = 0; i < no_guests; i++) {
        if (guestlist[i].get_name() == name) {
            guestlist[i].set_date(date);
        }
    }
}

// Sort guests based on their invitation date
void Iftar_Manager::sort_guests() {
    for (int i = 0; i <=no_guests - 1; i++) {
        for (int j = 0; j <no_guests - i - 1; j++) {
            string tempD = guestlist[j].get_date();
            string tempD2 = guestlist[j + 1].get_date();

            int tempDint = stoi(tempD.substr(0, 2));
            int tempDint2 = stoi(tempD2.substr(0, 2));

            int tempMint = stoi(tempD.substr(3, 2));
            int tempMint2 = stoi(tempD2.substr(3, 2));

            int tempYint = stoi(tempD.substr(6));
            int tempYint2 = stoi(tempD2.substr(6));

            if (tempYint > tempYint2 ||
                (tempYint == tempYint2 && tempMint > tempMint2) ||
                (tempYint == tempYint2 && tempMint == tempMint2 && tempDint > tempDint2)) {
                guest temp = guestlist[j];
                guestlist[j] = guestlist[j + 1];
                guestlist[j + 1] = temp;
            }
        }
    }
}

// Remove a guest by name
void Iftar_Manager::remove_guest(const string& name) {
    for (int i = 0; i < no_guests; i++) {
        if (guestlist[i].get_name() == name) {
            for (int j = i; j < no_guests - 1; j++) {
                guestlist[j] = guestlist[j + 1];
            }
            no_guests--;
            return;
        }
    }
}

// Send reminders for guests with a specific invitation date
void Iftar_Manager::send_reminder(const string& date) {
    for (int i = 0; i <= no_guests; i++) {
        string literal = guestlist[i].get_date();
        if (literal == date) {
            cout << guestlist[i].get_name() << " Don't forget Iftar on " << date << " !\n";
        }
    }
}

int main() {
    Iftar_Manager manager;

    // Creating and adding guests
    manager.add_guest({"omar", "omar@gmail.com", "25/3/2025"});
    manager.add_guest({"hassan", "hassan@gmail.com", "24/3/2025"});
    manager.add_guest({"hannan", "hannan@gmail.com", "25/1/2025"});
    manager.add_guest({"lojy", "lojy@gmail.com", "25/3/2005"});
    manager.add_guest({"Ahmed", "Ahmed@gmail.com", "25/3/2005"});

    // Displaying initial guest list
    manager.display_guests();

    // Sorting and displaying sorted guests
    cout << "\nSorted List\n";
    manager.sort_guests();
    manager.display_guests();

    // Sending reminders and updating/removing guests
    manager.send_reminder("25/3/2005");
    manager.remove_guest("lojy");
    manager.update_guests("omar", "29/4/2007");

    // Final guest list
    manager.display_guests();
}

