#include <iostream>
#include <map>
#include <string>

using namespace std;
class AddressBook {
public:
    //struct for Address
    struct Address {
        string street;
        string city;
        string country;

        //Typdef for the struct itself
        typedef Address AddressType;
    };

    //Nested class for Contact
    class Contact {
    public: 
        //Typedef for a map from string to Address
        typedef map<string, Address::AddressType> AddressMap;

        void addAddress(const string& label, const Address::AddressType& address) {
            addresses[label] = address;
        }

        void removeAddress(const string& label) {
            addresses.erase(label);
        }

        void displayAddresses() const {
            for(const auto& pair : addresses) {
                cout << "Label: " << pair.first
                     << ", Street: " << pair.second.street
                     << ", City: " << pair.second.city
                     << ", Country: " << pair.second.street
                     << endl;
            }
        }

    private:
        AddressMap addresses;
        
    };

    //Typedef for a map of string to Contact
    typedef map<string, Contact> ContactMap;

    void addContact(const string& name) {
        contacts[name] = Contact();
    }

    void removeContact(const string& name) {
        contacts.erase(name);
    }

    Contact& getContact(const string& name) {
        return contacts[name];
    }

    void displayContacts() const {
        for(const auto& pair : contacts) {
            cout << "Contact: " << pair.first << endl;
            pair.second.displayAddresses();
        }
    }

private:
    ContactMap contacts;
};

int main() {
    AddressBook addressBook;

    //Adding Contacts
    addressBook.addContact("John Doe");
    addressBook.addContact("Jane Smith");

    //Adding addresses to Contacts
    AddressBook::Address address1 = {"123 Main St", "Anytown", "AnyCountry"};
    AddressBook::Address address2 = {"456 Elm St", "Othertown", "Othercountry"};

    addressBook.getContact("John Doe").addAddress("Home", address1);
    addressBook.getContact("Jane Smith").addAddress("Work", address2);
    addressBook.getContact("Jane Smith").addAddress("Home", address2);

    //Displaying all contacts and their addresses
    cout << "Address Book:" << endl;
    addressBook.displayContacts();

    //Removing an address from a contact
    addressBook.getContact("Jane Smith").removeAddress("Work");

    //Removing a contact
    addressBook.removeContact("Jane Smith");

    cout << "\nUpdated Address Book:\n" << endl;
    addressBook.displayContacts();

    return 0;
}