#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class node
{
public:
    int rollNo;
    string stdName;
    string depName;
    string progName;
    string Semester;
    string Shift;
    string contactNo;
    node *next;
    node(int rollno, string stdname, string depname, string progname, string semester, string shift, string contactno)
    {
        rollNo = rollno;
        stdName = stdname;
        depName = depname;
        progName = progname;
        Semester = semester;
        Shift = shift;
        contactNo = contactno;
        next = NULL;
    }
};
class List
{
public:
    node *head;
    node *tail;
    List()
    {
        head = tail = NULL;
    }
    bool rollnoExist(int rollno)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == rollno)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void insert(int rollno, string stdname, string depname, string progname, string semester, string shift, string contactno)
    {
        node *n = new node(rollno, stdname, depname, progname, semester, shift, contactno);
        if (head == NULL)
        {
            head = tail = n;
            cout << "Record for \"" << stdname << "\" has been added in System Successfully." << endl;
            return;
        }
        // For Front Insert
        // n->next = head;
        // head = n;

        // For Back Insert
        tail->next = n;
        tail = n;
        cout << "Record for \"" << stdname << "\" has been added in System Successfully." << endl;
    }
    void deleted(int rollno)
    {
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        if (head->rollNo == rollno)
        {
            head = head->next;
            delete temp;
            cout << "Record of Rollno " << rollno << " is Deleted Successfully" << endl;
            return;
        }
        while (temp->next != NULL && temp->next->rollNo != rollno)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        if (temp->next == tail)
        {
            delete tail;
            tail = temp;
            tail->next = NULL;
            cout << "Record of Rollno " << rollno << " is Deleted Successfully" << endl;
            return;
        }
        node *deletenode = temp->next;
        temp->next = deletenode->next;
        delete deletenode;
        cout << "Record of Rollno " << rollno << " is Deleted Successfully" << endl;
    }
    void updateName(int rollno, string newStdName)
    {
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == rollno)
            {
                temp->stdName = newStdName;
                cout << "Name " << newStdName << " is Updated SuccessFully!" << endl;
                return;
            }
            temp = temp->next;
        }
    }
    void updatedept(int rollno, string newdept)
    {
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == rollno)
            {
                temp->depName = newdept;
                cout << "Department " << newdept << " is Updated SuccessFully!" << endl;
                return;
            }
            temp = temp->next;
        }
    }
    void updateprogram(int rollno, string newprogram)
    {
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == rollno)
            {
                temp->progName = newprogram;
                cout << "Program " << newprogram << " is Updated SuccessFully!" << endl;
                return;
            }
            temp = temp->next;
        }
    }
    void updatesemester(int rollno, string newsemester)
    {
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == rollno)
            {
                temp->Semester = newsemester;
                cout << "Semester " << newsemester << " is Updated SuccessFully!" << endl;
                return;
            }
            temp = temp->next;
        }
    }
    void updateshift(int rollno, string newshift)
    {
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == rollno)
            {
                temp->Shift = newshift;
                cout << "Shift " << newshift << " is Updated SuccessFully!" << endl;
                return;
            }
            temp = temp->next;
        }
    }
    void updatecontactno(int rollno, string newcontactno)
    {
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == rollno)
            {
                temp->contactNo = newcontactno;
                cout << "Contact No " << newcontactno << " is Updated SuccessFully!" << endl;
                return;
            }
            temp = temp->next;
        }
    }
    void search(int rollno)
    {
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == rollno)
            {
                cout << "\n--- Student Record ---" << endl;
                cout << left
                     << "| " << setw(10) << "RollNo"
                     << "| " << setw(20) << "Name"
                     << "| " << setw(20) << "Department"
                     << "| " << setw(15) << "Program"
                     << "| " << setw(10) << "Semester"
                     << "| " << setw(10) << "Shift"
                     << "| " << setw(15) << "ContactNo"
                     << " |" << endl;

                cout << left
                     << "| " << setw(10) << temp->rollNo
                     << "| " << setw(20) << temp->stdName
                     << "| " << setw(20) << temp->depName
                     << "| " << setw(15) << temp->progName
                     << "| " << setw(10) << temp->Semester
                     << "| " << setw(10) << temp->Shift
                     << "| " << setw(15) << temp->contactNo
                     << " |" << endl;

                // Another Way to Print

                // // cout << "Student RollNo: " << temp->rollNo << endl;
                // cout << "Student Name: " << temp->stdName << endl;
                // cout << "Department: " << temp->depName << endl;
                // cout << "Program: " << temp->progName << endl;
                // cout << "Shift: " << temp->Shift << endl;
                // cout << "Contact Number: " << temp->contactNo << endl
                //      << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Record Not Found in System" << endl;
    }
    void Display()
    {
        cout << "Display: ";
        if (head == NULL)
        {
            cout << "No Record in System!" << endl;
            return;
        }
        node *temp = head;
        cout << "\n\t\t\t\t\t--- Student Record ---" << endl;
        cout << left
             << "| " << setw(10) << "RollNo"
             << "| " << setw(20) << "Name"
             << "| " << setw(20) << "Department"
             << "| " << setw(15) << "Program"
             << "| " << setw(10) << "Semester"
             << "| " << setw(10) << "Shift"
             << "| " << setw(15) << "ContactNo"
             << " |" << endl;
        while (temp != NULL)
        {
            cout << left
                 << "| " << setw(10) << temp->rollNo
                 << "| " << setw(20) << temp->stdName
                 << "| " << setw(20) << temp->depName
                 << "| " << setw(15) << temp->progName
                 << "| " << setw(10) << temp->Semester
                 << "| " << setw(10) << temp->Shift
                 << "| " << setw(15) << temp->contactNo
                 << " |" << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    List ll;
    int choose;
    while (true)
    {
        cout << "-----------Menu-----------" << endl;
        cout << "1. Insert Student Record" << endl;
        cout << "2. Delete Student Record By Rollno" << endl;
        cout << "3. Update Student Record By Rollno" << endl;
        cout << "4. Search Student Record By Rollno" << endl;
        cout << "5. Display Records" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choose: ";
        cin >> choose;
        if (choose == 1)
        {
            int rollno;
            string stdname, depname, progname, semester, shift, contactno;
            while (true)
            {
                cout << "Enter Your Rollno: ";
                cin >> rollno;
                if (ll.rollnoExist(rollno))
                {
                    cout << "Record not inserted. A record with the rollno \"" << rollno << "\" already exists." << endl;
                    continue;
                }
                else
                {
                    break;
                }
            }
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, stdname);
            cout << "Enter Department: ";
            getline(cin, depname);
            cout << "Enter Program: ";
            getline(cin, progname);
            cout << "Enter Semester: ";
            getline(cin, semester);
            while (true)
            {
                int s;
                cout << "--- Shift ---" << endl;
                cout << "1. Morning" << endl;
                cout << "2. Evening" << endl;
                cout << "Enter (1-2): ";
                cin >> s;
                cin.ignore();
                if (s == 1)
                {
                    shift = "Morning";
                    cout << "Shift = Morning" << endl;
                    break;
                }
                else if (s == 2)
                {
                    shift = "Evening";
                    cout << "Shift = Evening" << endl;
                    break;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
            cout << "Enter Contact No: ";
            getline(cin, contactno);
            ll.insert(rollno, stdname, depname, progname, semester, shift, contactno);
        }
        else if (choose == 2)
        {
            int rollno;
            cout << "Enter Your Rollno: ";
            cin >> rollno;
            ll.deleted(rollno);
        }
        else if (choose == 3)
        {
            int rollno;
            cout << "Enter Your Rollno: ";
            cin >> rollno;
            while (true)
            {
                int u;
                if (ll.rollnoExist(rollno))
                {
                    cout << "--- Update ---" << endl;
                    cout << "1. Student Name" << endl;
                    cout << "2. Department " << endl;
                    cout << "3. Program " << endl;
                    cout << "4. Semester" << endl;
                    cout << "5. Shift" << endl;
                    cout << "6. ContactNo" << endl;
                    cout << "0. Exit Back" << endl;
                    cout << "Enter (0-6): ";
                    cin >> u;
                    cin.ignore();
                    if (u == 1)
                    {
                        string newName;
                        cout << "Enter New Student Name: ";
                        getline(cin, newName);
                        ll.updateName(rollno, newName);
                    }
                    else if (u == 2)
                    {
                        string newdept;
                        cout << "Enter New Department: ";
                        getline(cin, newdept);
                        ll.updatedept(rollno, newdept);
                    }
                    else if (u == 3)
                    {
                        string newProgram;
                        cout << "Enter New Program: ";
                        getline(cin, newProgram);
                        ll.updateprogram(rollno, newProgram);
                    }
                    else if (u == 4)
                    {
                        string newSemester;
                        cout << "Enter New Semester: ";
                        getline(cin, newSemester);
                        ll.updatesemester(rollno, newSemester);
                    }
                    else if (u == 5)
                    {
                        string newShift;
                        while (true)
                        {
                            int s;
                            cout << "--- New Shift ---" << endl;
                            cout << "1. Morning" << endl;
                            cout << "2. Evening" << endl;
                            cout << "Enter (1-2): ";
                            cin >> s;
                            cin.ignore();
                            if (s == 1)
                            {
                                newShift = "Morning";
                                cout << "Shift = Morning" << endl;
                                break;
                            }
                            else if (s == 2)
                            {
                                newShift = "Evening";
                                cout << "Shift = Evening" << endl;
                                break;
                            }
                            else
                            {
                                cout << "Invalid Input" << endl;
                            }
                        }
                        ll.updateshift(rollno, newShift);
                    }
                    else if (u == 6)
                    {
                        string newContactNo;
                        cout << "Enter New Contact Number: ";
                        getline(cin, newContactNo);
                        ll.updatecontactno(rollno, newContactNo);
                    }
                    else if (u == 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                    }
                }
                else
                {
                    cout << "Roll Number not Found in Records!" << endl;
                    break;
                }
            }
        }
        else if (choose == 4)
        {
            int rollno;
            cout << "Enter Your Rollno: ";
            cin >> rollno;
            ll.search(rollno);
        }
        else if (choose == 5)
        {
            ll.Display();
        }
        else if (choose == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    return 0;
}