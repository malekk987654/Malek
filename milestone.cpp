#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <limits>  
using namespace std;

char current_student_id[20];
char gender[10];


struct Student {
    char first[100];
    char last[100];
    char nid[20];
    char phone[20];
    char id[20];
    char program[20];
    char dob[20];
    char academic[20];
};




int compare_names(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        char c1 = *s1;
        char c2 = *s2;
        if (c1 >= 'A' && c1 <= 'Z')
            c1 = c1 + 32;
        if (c2 >= 'A' && c2 <= 'Z')
            c2 = c2 + 32;
        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
    }

    char c1 = *s1;
    char c2 = *s2;

    if (c1 >= 'A' && c1 <= 'Z')
        c1 = c1 + 32;
    if (c2 >= 'A' && c2 <= 'Z')
        c2 = c2 + 32;
    return c1 - c2;
}


int main_menu() {
    int choice = 0;
    cout << "\n===== MAIN LOBBY =====\n";
    cout << "1. Student Management\n";
    cout << "2. Course Management\n";
    cout << "3. Grades Management\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
    if (!(cin >> choice)) {
        cin.clear();

    }
    return choice;
}

int student_management_menu() {
    int choice = 0;
    cout << "\n--- Student Management ---\n";
    cout << "1. Add a new student\n";
    cout << "2. List all available students\n";
    cout << "3. Search for a listed student\n";
    cout << "4. Update student data\n";
    cout << "5. Delete student \n";
    cout << "0. Return to Main Lobby\n";
    cout << "Choice: ";
    if (!(cin >> choice)) {
        cin.clear();

    }
    return choice;
}


int add_new_student() {
    char first_name[100], last_name[100], phone_number[20], national_id[20];

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    while (true) {
        cout << "Enter the first name: ";
        cin.getline(first_name, 100);
        bool is_valid = (strlen(first_name) > 0);
        for (int i = 0; first_name[i]; i++) {
            if (!((first_name[i] >= 'A' && first_name[i] <= 'Z') || (first_name[i] >= 'a' && first_name[i] <= 'z')))
                is_valid = false;
        }
        if (is_valid) break;
        cout << "Invalid name. Letters only.\n";
    }

    while (true) {
        cout << "Enter the last name: ";
        cin.getline(last_name, 100);
        bool is_valid = (strlen(last_name) > 0);
        for (int i = 0; last_name[i]; i++) {
            if (!((last_name[i] >= 'A' && last_name[i] <= 'Z') || (last_name[i] >= 'a' && last_name[i] <= 'z')))
                is_valid = false;
        }
        if (is_valid) break;
        cout << "Invalid name. Letters only.\n";
    }


    while (true) {
        cout << "Enter National ID (14 digits, starts with 3): ";
        cin.getline(national_id, 20);
        bool is_valid = (strlen(national_id) == 14 && (national_id[0] == '3'));
        for (int i = 0; i < (int)strlen(national_id); i++) {
            if (!(national_id[i] >= '0' && national_id[i] <= '9')) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) break;
        cout << "Invalid national ID. Must be 14 digits starting 3.\n";
    }

    cout << "Enter gender (Male/Female): ";
    cin >> gender;

    while (strcmp(gender, "Male") != 0 && strcmp(gender, "Female") != 0 &&
        strcmp(gender, "female") != 0 && strcmp(gender, "male") != 0) {
        cout << "Invalid entry. Please type 'Male' or 'Female': ";
        cin >> gender;
    }


    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        cout << "Enter phone number (starts with 01, 11 digits): ";
        cin.getline(phone_number, 20);
        bool is_valid =
            (strlen(phone_number) == 11 && phone_number[0] == '0' && phone_number[1] == '1');

        for (int i = 0; i < (int)strlen(phone_number); i++) {
            if (phone_number[i] < '0' || phone_number[i] > '9') {
                is_valid = false;
                break;
            }
        }
        if (is_valid)
            break;
        cout << "Invalid phone number.\n";
    }



    int student_count = 0;
    std::ifstream infile("students.txt");
    char line[256];
    if (infile.is_open()) {
        while (infile.getline(line, sizeof(line))) {
            if (strlen(line) > 5) student_count++;
        }
        infile.close();
    }
    snprintf(current_student_id, sizeof(current_student_id), "25p%04d", student_count + 1);


    char program[10];
    cout << "enter the student program from the following options(CSE/CCE/MCT)";
    cin >> program;
    while (strcmp(program, "CSE") != 0 && strcmp(program, "CCE") != 0 && strcmp(program, "MCT") != 0)
    {
        cout << "invalid program, Please type(CCE/CSE/MCT):";
        cin >> program;
    }

    int month;
    cout << "enter your month of birth in digits:";
    cin >> month;

    while (cin.fail() || month < 1 || month>12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid month, enter a digit from 1 to 12" << endl;
        cout << "enter your month of birth in digits:";
        cin >> month;

    }
    int day;

    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        cout << "enter your birth day: ";
        cin >> day;
        while (cin.fail() || day < 1 || day > 31) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid day, enter a digit from 1 to 31" << endl;
            cout << "enter your birth day: ";
            cin >> day;
        }
        break;

    case 4: case 6: case 9: case 11:
        cout << "enter your birth day: ";
        cin >> day;
        while (cin.fail() || day < 1 || day > 30) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid day, enter a digit from 1 to 30" << endl;
            cout << "enter your birth day: ";
            cin >> day;
        }
        break;

    case 2:
        cout << "enter your birth day: ";
        cin >> day;
        while (cin.fail() || day < 1 || day > 29) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid day, enter a digit from 1 to 29" << endl;
            cout << "enter your birth day: ";
            cin >> day;
        }
        break;
    }
    int year;
    cout << "enter your year of birth : ";
    cin >> year;
    while (cin.fail() || year < 1950 || year>2009) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid year, please enter a number from 1950 to 2009" << endl << "Please enter your year of birth:";
        cin >> year;
    }

    int academic;
    cout << "enter your academic year: ";
    cin >> academic;
    while (academic < 1 || academic>4) {
        cout << "invalid academic year, please enter a number from 1 to 4" << endl << "please enter your academic year: ";
        cin >> academic;
    }



    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::ofstream outfile("students.txt", std::ios::app);
    if (outfile.is_open()) {
        outfile << first_name << "|" << last_name << "|" << national_id << "|"
            << phone_number << "|" << current_student_id << "|" << academic << "|" << program << "|"
            << day << "/" << month << "/" << year << "\n";
        outfile.close();
        return 0;
    }
    return -1;

}

int list_full_student_list() {
    std::ifstream file("students.txt");

    if (!file.is_open()) {
        std::ofstream create("students.txt", std::ios::app);
        create.close();
        cout << "No student records found (Database was empty/missing and has been initialized)." << endl;
        return 1;
    }

    char line[256];
    bool hasContent = false;
    cout << "\n--- Full Student List (By ID) ---\n";
    while (file.getline(line, 256)) {
        if (strlen(line) > 0) {
            cout << line << endl;
            hasContent = true;
        }
    }

    if (!hasContent) cout << "(The file is currently empty)" << endl;

    file.close();
    return 0;
}

int list_by_name() {
    Student list[100];
    int count = 0;

    std::ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "No records found to sort.\n";
        return 1;
    }

    char line[256];
    while (file.getline(line, 256) && count < 100) {
        if (strlen(line) < 5) continue;
        char temp_line[256];
        strcpy(temp_line, line);

        char* token = strtok(temp_line, "|");
        if (token) strcpy(list[count].first, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(list[count].last, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(list[count].nid, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(list[count].phone, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(list[count].id, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(list[count].academic, token);

        token = strtok(NULL, "|");
        if (token) strcpy(list[count].program, token);

        token = strtok(NULL, "|");
        if (token) strcpy(list[count].dob, token);


        count++;
    }
    file.close();

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare_names(list[j].first, list[j + 1].first) > 0) {
                Student temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }


    std::ofstream outfile("name.txt");
    cout << "\n--- Alphabetical Student List (A-Z) ---\n";
    for (int i = 0; i < count; i++) {
        outfile << list[i].first << "|" << list[i].last << "|"
            << list[i].nid << "|" << list[i].phone << "|"
            << list[i].id << "|" << list[i].program << "|"
            << list[i].dob << "\n";

        cout << std::left << std::setw(10) << list[i].first << setw(5) << list[i].last
            << std::setw(10) << " | ID: " << list[i].id << " | N ID: " << list[i].nid << " | Phone: " << list[i].phone;
        cout << " | program: " << list[i].program;
        cout << " | DOB: " << list[i].dob;
        cout << "\n";
    }
    outfile.close();

    cout << "\n>>> Records sorted and synced to name.txt successfully! <<<\n";
    return 0;
}

int search_student() {
    int choice = 0;
    cout << "\n--- Search student ---\n";
    cout << "1. Search by Student ID\n";
    cout << "2. Search by National ID\n";
    cout << "3. Search by Name\n";
    cout << "0. Go back\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 0) return 0;

    char search_term[100];
    cout << "Enter search term: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(search_term, 100);

    std::ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error opening students.txt\n";
        return 1;
    }

    bool found = false;
    char line[256];
    while (file.getline(line, 256)) {
        char temp_line[256];
        strcpy(temp_line, line);

        char first[100], last[100], nid[20], phone[20], id[20], program[20], gender[20], academic[20], dob[20], gpa[20];

        char* token = strtok(temp_line, "|");
        if (token) strcpy(first, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(last, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(nid, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(phone, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(id, token); else continue;

        token = strtok(NULL, "|");
        if (token) strcpy(academic, token);

        token = strtok(NULL, "|");
        if (token) strcpy(program, token);

        token = strtok(NULL, "|");
        if (token) strcpy(dob, token);


        bool match = false;
        if (choice == 1 && strcmp(id, search_term) == 0) match = true;
        else if (choice == 2 && strcmp(nid, search_term) == 0) match = true;
        else if (choice == 3 && (strstr(first, search_term) || strstr(last, search_term))) match = true;

        if (match) {
            cout << "\n>>> Student Found <<<\n";
            cout << "Name: " << first << " " << last << "\n";
            cout << "National ID: " << nid << "\n";
            cout << "Phone: " << phone << "\n";
            cout << "Student ID: " << id << "\n";
            cout << "Level: " << academic << "\n";
            cout << "Program: " << program << "\n";
            cout << "DOB: " << dob << "\n";
            found = true;
            if (choice != 3) break;
        }
    }
    if (!found) cout << "No student matching '" << search_term << "' was found.\n";
    file.close();
    return 0;
}

int update_student() {
    char target_id[20];
    cout << "enter student id";
    cin >> target_id;
    std::ifstream file("students.txt");
    std::ofstream updated("updated_students.txt");

    char first[100], last[100], nid[20], phone[20], id[20], program[20], gender[20], academic[20], dob[20], gpa[20];

    if (!file.is_open()) {
        cout << "error file not opening";
        return 1;
    }
    bool found = false;
    char line[256];
    while (file.getline(line, 256)) {
        char temp_line[256];
        strcpy(temp_line, line);
        char* token = strtok(temp_line, "|");
        if (token) strcpy(first, token);
        token = strtok(NULL, "|");
        if (token) strcpy(last, token);

        token = strtok(NULL, "|");
        if (token) strcpy(nid, token);

        token = strtok(NULL, "|");
        if (token) strcpy(phone, token);

        token = strtok(NULL, "|");
        if (token) strcpy(id, token);

        token = strtok(NULL, "|");
        if (token) strcpy(academic, token);

        token = strtok(NULL, "|");
        if (token) strcpy(program, token);

        token = strtok(NULL, "|");
        if (token) strcpy(dob, token);
        if (strcmp(target_id, id) == 0) {
            found = true;
            int choice;
            cout << "which field do you want to update?" << endl
                << "1. Phone number" << endl << "2. Program" << endl << "3.Academic level" << endl << "4.cancel";
            cin >> choice;
            switch (choice) {
            case 1:
                char new_phone[20];
                cout << "enter new phone";
                cin >> new_phone;
                while (strlen(new_phone) != 11 || new_phone[0] != '0' || new_phone[1] != '1') {
                    cout << "invalid phone number, enter a valid phone number: ";
                    cin >> new_phone;
                }
                strcpy(phone, new_phone);
                break;

            case 2:
                char new_program[20];
                cout << "enter new program";
                cin >> new_program;
                while (strcmp(new_program, "CSE") != 0 && strcmp(new_program, "CCE") != 0 && strcmp(new_program, "MCT") != 0) {
                    cout << "invalid program, enter a valid program: ";
                    cin >> new_program;
                }
                strcpy(program, new_program);
                break;

            case 3:
                char new_academic[20];
                cout << "enter new academic level";
                cin >> new_academic;
                while (strcmp(new_academic, "1") != 0 && strcmp(new_academic, "2") != 0 && strcmp(new_academic, "3") != 0 && strcmp(new_academic, "4") != 0) {
                    cout << "invalid academic level, enter a valid academic level: ";
                    cin >> new_academic;
                }
                strcpy(academic, new_academic);
                break;


            case 4:
                break;
            default:
                cout << "invalid choice, no changes made.\n";
                break;
            }
            updated << first << "|" << last << "|" << nid << "|"
                << phone << "|" << id << "|" << academic << "|" << program << "|"
                << dob << "\n";
        }
        else {
            updated << line << "\n";
        }
    }
    file.close();
    updated.close();
    ofstream clear_file("students.txt");
    clear_file.close();
    ifstream updated_read("updated_students.txt");
    ofstream final_write("students.txt", std::ios::app);
    while (updated_read.getline(line, 256)) {
        final_write << line << "\n";
    }
    updated_read.close();
    final_write.close();
    if (!found)
        cout << "student not found ";
    else
        cout << "student updated successfully ";
    return 0;
}

int delete_student() {
    char target_id[20];
    cout << "enter student id";
    cin >> target_id;

    ifstream file("students.txt");
    ofstream updated("updated_students.txt");
    char first[100], last[100], nid[20], id[20], phone[20], program[20], gender[20], academic[20], dob[20], gpa[20];
    if (!file.is_open()) {
        cout << "error opening file";
        return 1;
    }
    bool found = false;
    char line[256];
    while (file.getline(line, 256)) {
        char temp_line[256];
        strcpy(temp_line, line);
        char* token = strtok(temp_line, "|");

        if (token) strcpy(first, token);
        token = strtok(NULL, "|");

        if (token) strcpy(last, token);
        token = strtok(NULL, "|");

        if (token) strcpy(nid, token);
        token = strtok(NULL, "|");

        if (token) strcpy(phone, token);
        token = strtok(NULL, "|");


        if (token) strcpy(id, token);
        token = strtok(NULL, "|");


        if (token) strcpy(academic, token);

        token = strtok(NULL, "|");
        if (token) strcpy(program, token);

        token = strtok(NULL, "|");
        if (token) strcpy(dob, token);
        token = strtok(NULL, "|");

        if (strcmp(target_id, id) == 0) {
            found = true;
            cout << "student deleted successfully ";
        }
        else {

            updated << line << "\n";
        }
    }
    file.close();
    updated.close();

    ofstream clear_file("students.txt");
    clear_file.close();

    ifstream updated_read("updated_students.txt");
    ofstream final_write("students.txt", std::ios::app);

    while (updated_read.getline(line, 256)) {

        final_write << line << "\n";
    }

    updated_read.close();
    final_write.close();

    if (!found)
        cout << "student not found ";
    return 0;
}


struct Course {
    char code[10];
    char title[100];
    int hours;
};

int add_new_course() {

    char coursecode[10];
    char coursename[100];
    int credithour;

    while (true) {

        std::ofstream createFile("courses.txt", std::ios::app);
        createFile.close();
        cout << "Enter course code (e.g., CSE141): ";
        cin >> coursecode;

        bool isValidFormat = true;
        if (strlen(coursecode) != 6) {
            isValidFormat = false;
        }
        else {
            for (int i = 0; i < 3; i++) {
                if (!(coursecode[i] >= 'A' && coursecode[i] <= 'Z'))
                    isValidFormat = false;
            }
            for (int i = 3; i < 6; i++) {
                if (!(coursecode[i] >= '0' && coursecode[i] <= '9'))
                    isValidFormat = false;
            }
        }

        if (!isValidFormat) {
            cout << "Invalid format! Code must be 3 letters followed by 3 digits.\n";
            continue;
        }


        ifstream infile("courses.txt");
        bool isDuplicate = false;
        char line[256];
        if (infile.is_open()) {
            while (infile.getline(line, 256)) {
                if (strstr(line, coursecode) != NULL) {
                    isDuplicate = true;
                    break;
                }
            }
            infile.close();
        }

        if (isDuplicate) {
            cout << "Error: Course code " << coursecode << " already exists!\n";
        }
        else {
            break;
        }
    }

    cout << "Enter course name: ";
    cin.ignore(1000, '\n');
    cin.getline(coursename, 100);


    while (true) {
        cout << "Enter credit hours (2-4): ";
        cin >> credithour;
        if (credithour >= 2 && credithour <= 4) break;
        cout << "Invalid! Credit hours must be between 2 and 4.\n";
    }


    ofstream outfile("courses.txt", ios::app);
    if (outfile.is_open()) {
        outfile << coursecode << "|" << coursename << "|" << credithour << "\n";
        outfile.close();
        return 0;
    }
    return -1;
}

int view_courses() {
    ifstream file("courses.txt");
    if (!file.is_open()) {
        cout << "No courses found (Database was empty/missing and has been initialized)." << endl;
        ofstream createFile("courses.txt", ios::app);
        createFile.close();
        return 1;
    }
    char line[256];
    bool hasContent = false;
    cout << "\n--- Available Courses ---\n";
    while (file.getline(line, 256)) {
        if (strlen(line) > 0) {
            cout << line << endl;
            hasContent = true;
        }
    }
    if (!hasContent) cout << "(The file is currently empty)" << endl;
    file.close();
    return 0;
}
int update_course() {
    char coursecode[10], scode[10], credithour[10], coursename[100];
    cout << "Enter course code to update: ";
    cin >> scode;


    ifstream infile("courses.txt");
    ofstream updated("updated_courses.txt");

    if (!infile.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }
    bool found = false;
    char line[256];
    while (infile.getline(line, 256)) {
        char temp[256];
        strcpy(temp, line);
        char* token = strtok(temp, "|");
        strcpy(coursecode, token);
        token = strtok(NULL, "|");
        strcpy(coursename, token);
        token = strtok(NULL, "|");
        strcpy(credithour, token);
        if (strcmp(coursecode, scode) == 0) {
            found = true;
            int choice;
            cout << "which field do you want to update?" << endl
                << "1. Course code " << endl << "2. Course name " << endl << "3.Credit hours" << endl << "4.cancel";
            cin >> choice;
            switch (choice) {
            case 1: {
                char new_code[10];
                cout << "enter the new course code: ";
                cin >> new_code;
                while (true) {
                    bool isValidFormat = true;

                    if (strlen(new_code) != 6) {
                        isValidFormat = false;
                    }
                    else {
                        for (int i = 0; i < 3; i++) {
                            if (!(new_code[i] >= 'A' && new_code[i] <= 'Z'))
                                isValidFormat = false;
                        }
                        for (int i = 3; i < 6; i++) {
                            if (!(new_code[i] >= '0' && new_code[i] <= '9'))
                                isValidFormat = false;
                        }
                    }



                    for (int i = 3; i < 6; i++) {
                        if (!(new_code[i] >= '0' && new_code[i] <= '9'))
                            isValidFormat = false;
                    }

                    if (!isValidFormat) {

                        cout << "Invalid format! Code must be 3 letters followed by 3 digits.\n";

                        cout << "Enter new course code: ";
                        cin >> new_code;
                    }
                    else {
                        strcpy(coursecode, new_code);

                        break;

                    }
                } break;


                if (!found) {
                    cout << "Course not found!\n";
                    return -1;
                }



                return 0;
            }
            case 2: {
                char new_name[100];
                cout << "enter the new course name: ";
                cin.ignore(1000, '\n');
                cin.getline(new_name, 100);
                strcpy(coursename, new_name);
                break;
            }
            case 3: {
                char new_credithour[2];
                cout << "enter the new credit hour: ";
                cin >> new_credithour;


                if (new_credithour[0] >= '2' && new_credithour[0] <= '4') {
                    strcpy(credithour, new_credithour);
                    break;
                }
                else {
                    cout << "Invalid! Credit hours must be between 2 and 4.\n";
                    cout << "Enter new credit hours: ";
                    cin >> new_credithour;
                }
                break;
            }
            }
            updated << coursecode << "|" << coursename << "|" << credithour << "\n";
        }

        else {
            updated << line << "\n";
        }
    }
    infile.close();
    updated.close();
    ofstream clear_file("courses.txt");
    clear_file.close();
    ifstream updated_read("updated_courses.txt");
    ofstream final_write("courses.txt", std::ios::app);
    while (updated_read.getline(line, 256)) {
        final_write << line << "\n";
    }
    updated_read.close();
    final_write.close();
    if (!found)
        cout << "course not found ";
    else
        cout << "course updated successfully ";
    return 0;
}
int delete_course() {
    char coursecode[10], scode[10];
    cout << "Enter course code to delete: ";
    cin >> scode;
    ifstream infile("courses.txt");
    ofstream updated("updated_courses.txt");
    if (!infile.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }
    bool found = false;
    char line[256];
    while (infile.getline(line, 256)) {
        char temp[256];
        strcpy(temp, line);
        char* token = strtok(temp, "|");
        strcpy(coursecode, token);
        if (strcmp(coursecode, scode) == 0) {
            found = true;
            cout << "course deleted successfully ";
        }
        else {
            updated << line << "\n";
        }
    }
    infile.close();
    updated.close();
    std::ofstream clear_file("courses.txt");
    clear_file.close();
    ifstream updated_read("updated_courses.txt");
    ofstream final_write("courses.txt", std::ios::app);
    while (updated_read.getline(line, 256)) {
        final_write << line << "\n";
    }
    updated_read.close();
    final_write.close();
    if (!found)
        cout << "course not found ";
    return 0;
}


int enter_student_grade() {
    char sstudent_id[20];
    bool student_valid = false;


    while (!student_valid) {
        cout << "Enter student ID (or type 'cancel' to go back): ";
        cin >> sstudent_id;

        if (strcmp(sstudent_id, "cancel") == 0) return 0;

        ifstream file("students.txt");
        if (!file.is_open()) {
            cout << "Error opening students.txt file.\n";
            return 1;
        }

        char line[256];
        char student_id[20];
        while (file.getline(line, 256)) {
            char temp_line[256];
            strcpy(temp_line, line);
            char* token = strtok(temp_line, "|");
            token = strtok(NULL, "|");
            token = strtok(NULL, "|");
            token = strtok(NULL, "|");
            token = strtok(NULL, "|");
            if (token) strcpy(student_id, token);

            if (strcmp(student_id, sstudent_id) == 0) {
                student_valid = true;
                break;
            }
        }
        file.close();

        if (!student_valid) {
            cout << "Student not found in database. Please try again.\n";
        }
    }

    char ccode[10];
    bool valid_course = false;


    while (!valid_course) {
        cout << "Enter course code (or type 'cancel' to go back): ";
        cin >> ccode;

        if (strcmp(ccode, "cancel") == 0) return 0;


        ifstream cfile("courses.txt");
        if (!cfile.is_open()) {
            cout << "Error opening courses.txt file.\n";
            return 1;
        }

        bool course_found = false;
        char cline[256];
        char course_code[10];
        while (cfile.getline(cline, 256)) {
            char temp_cline[256];
            strcpy(temp_cline, cline);
            char* ctoken = strtok(temp_cline, "|");
            if (ctoken) strcpy(course_code, ctoken);

            if (strcmp(ccode, course_code) == 0) {
                course_found = true;
                break;
            }
        }
        cfile.close();

        if (!course_found) {
            cout << "Course not found in the system. Please try again.\n";
            continue;
        }


        ifstream gfile_in("grades.txt");
        bool already_graded = false;

        if (gfile_in.is_open()) {
            char gline[1024];
            while (gfile_in.getline(gline, 1024)) {
                char temp_gline[1024];
                strcpy(temp_gline, gline);

                char* token = strtok(temp_gline, "|");

                if (token != nullptr && strcmp(token, sstudent_id) == 0) {


                    while ((token = strtok(NULL, "|")) != nullptr) {
                        if (strcmp(token, ccode) == 0) {
                            already_graded = true;
                            break;
                        }
                    }
                    break;
                }
            }
            gfile_in.close();
        }

        if (already_graded) {
            cout << ">>> Error: A grade for course " << ccode << " is already added for this student. <<<\n";
        }
        else {
            valid_course = true;
        }
    }

    // Input Grades
    int grade_1, grade_2, total_g;
    char letter_g;

    cout << "Enter mid-term course grade: ";
    cin >> grade_1;
    while (cin.fail() || grade_1 < 0 || grade_1 > 40) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid grade, enter a number from 0 to 40: ";
        cin >> grade_1;
    }

    cout << "Enter final course grade: ";
    cin >> grade_2;
    while (cin.fail() || grade_2 < 0 || grade_2 > 60) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid grade, enter a number from 0 to 60: ";
        cin >> grade_2;
    }

    total_g = grade_1 + grade_2;
    if (total_g >= 90) letter_g = 'A';
    else if (total_g >= 80) letter_g = 'B';
    else if (total_g >= 70) letter_g = 'C';
    else if (total_g >= 60) letter_g = 'D';
    else letter_g = 'F';


    ifstream in("grades.txt");
    ofstream out("temp.txt");
    bool student_updated = false;

    if (in.is_open()) {
        char line[1024];
        while (in.getline(line, 1024)) {
            char copy[1024];
            strcpy(copy, line);
            char* id_token = strtok(copy, "|");

            if (id_token != nullptr && strcmp(id_token, sstudent_id) == 0) {

                out << line << "|" << ccode << "|" << grade_1 << "|" << grade_2 << "|" << total_g << "|" << letter_g << "\n";
                student_updated = true;
            }
            else {

                out << line << "\n";
            }
        }
        in.close();
    }

    if (!student_updated) {
        out << sstudent_id << "|" << ccode << "|" << grade_1 << "|" << grade_2 << "|" << total_g << "|" << letter_g << "\n";
    }
    out.close();


    ofstream rewrite("grades.txt");
    ifstream temp("temp.txt");
    char rewrite_line[1024];
    while (temp.getline(rewrite_line, 1024)) {
        rewrite << rewrite_line << "\n";
    }
    temp.close();
    rewrite.close();

    cout << "\n>>> Grade added successfully! <<<\n";

    return 0;
}


int view_all_students_grades() {

    ifstream file("grades.txt");

    if (!file.is_open()) {
        cout << "error opening grades file";
        return 1;
    }

    char line[256];

    bool found = false;

    cout << "\n===== ALL STUDENTS GRADES =====\n";

    while (file.getline(line, 256)) {

        if (strlen(line) > 0) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No grades available.\n";
    }

    file.close();

    return 0;
}
double calculate_gpa() {

    char target_id[20];

    cout << "Enter student ID: ";
    cin >> target_id;

    ifstream grades_file("grades.txt");

    if (!grades_file.is_open()) {
        cout << "Error opening grades file.\n";
        return -1;
    }

    char line[1024];
    bool found = false;

    while (grades_file.getline(line, 1024)) {

        char temp[1024];
        strcpy(temp, line);

        char* token = strtok(temp, "|");


        if (token && strcmp(token, target_id) == 0) {

            found = true;

            double total_quality_points = 0.0;
            int total_credit_hours = 0;


            while (true) {

                char course_code[20];
                char letter_grade;


                token = strtok(NULL, "|");
                if (!token)
                    break;

                strcpy(course_code, token);

                token = strtok(NULL, "|");

                token = strtok(NULL, "|");

                token = strtok(NULL, "|");

                token = strtok(NULL, "|");

                if (!token)
                    break;

                letter_grade = token[0];



                ifstream course_file("courses.txt");

                int credit_hours = 0;

                if (course_file.is_open()) {

                    char course_line[256];

                    while (course_file.getline(course_line, 256)) {

                        char course_temp[256];
                        strcpy(course_temp, course_line);

                        char* ctoken = strtok(course_temp, "|");

                        if (ctoken && strcmp(ctoken, course_code) == 0) {

                            ctoken = strtok(NULL, "|");
                            ctoken = strtok(NULL, "|");

                            if (ctoken)
                                credit_hours = atoi(ctoken);

                            break;
                        }
                    }

                    course_file.close();
                }


                double points = 0.0;

                switch (letter_grade) {

                case 'A':
                    points = 4.0;
                    break;

                case 'B':
                    points = 3.0;
                    break;

                case 'C':
                    points = 2.0;
                    break;

                case 'D':
                    points = 1.0;
                    break;

                case 'F':
                    points = 0.0;
                    break;
                }

                total_quality_points += points * credit_hours;
                total_credit_hours += credit_hours;
            }

            if (total_credit_hours == 0) {
                cout << "No credit hours found.\n";
                return 0;
            }

            double gpa = total_quality_points / total_credit_hours;

            cout << "\n===== GPA RESULT =====\n";
            cout << "Student ID: " << target_id << endl;
            cout << "Cumulative GPA: "
                << fixed << setprecision(2)
                << gpa << endl;

            grades_file.close();

            return gpa;
        }
    }

    grades_file.close();

    if (!found)
        cout << "Student not found.\n";

    return -1;
}


void generate_transcript() {
    char target_id[20];
    cout << "Enter student ID: ";
    cin >> target_id;


    ifstream sfile("students.txt");
    if (!sfile.is_open()) {
        cout << "Error opening students.txt\n";
        return;
    }

        char first[100], last[100], program[20], level[20];
        bool student_found = false;
        char line[256];

        while (sfile.getline(line, 256)) {
            char temp[256];
            strcpy(temp, line);

            char* t = strtok(temp, "|");
            if (t) strcpy(first, t);

            t = strtok(NULL, "|"); if (t) strcpy(last, t);
            t = strtok(NULL, "|");
            t = strtok(NULL, "|");
            t = strtok(NULL, "|");

            if (t && strcmp(t, target_id) == 0) {
                student_found = true;
                t = strtok(NULL, "|"); if (t) strcpy(level, t);
                t = strtok(NULL, "|"); if (t) strcpy(program, t);
                break;
            }
        }
        sfile.close();

        if (!student_found) {
            cout << "Student not found.\n";
            return;
        }


        char full_name[200];
        strcpy(full_name, first);
        strcat(full_name, " ");
        strcat(full_name, last);

        char prog_level[100];
        strcpy(prog_level, "Program: ");
        strcat(prog_level, program);
        strcat(prog_level, " | Level: ");
        strcat(prog_level, level);


        struct TempCourse {
            char code[10];
            char title[100];
            int credits;
        } course_list[50];

        int course_count = 0;
        ifstream cfile("courses.txt");
        if (cfile.is_open()) {
            char cline[256];
            while (cfile.getline(cline, 256) && course_count < 50) {
                char tcline[256];
                strcpy(tcline, cline);
                char* ct = strtok(tcline, "|");
                if (ct) strcpy(course_list[course_count].code, ct);

                ct = strtok(NULL, "|"); if (ct) strcpy(course_list[course_count].title, ct);
                ct = strtok(NULL, "|");
                if (ct) {
                    if (ct[0] == '4') course_list[course_count].credits = 4;
                    else if (ct[0] == '3') course_list[course_count].credits = 3;
                    else if (ct[0] == '2') course_list[course_count].credits = 2;
                    else course_list[course_count].credits = 0;
                    course_count++;
                }
            }
            cfile.close();
        }

        struct TranscriptRow {
            char code[20];
            char title[100];
            int credits;
            char grade;
            double points;
        } t_rows[50];

        int row_count = 0;
        double total_points = 0.0;
        int total_credits = 0;

        ifstream gfile("grades.txt");
        if (gfile.is_open()) {
            char gline[1024];
            while (gfile.getline(gline, 1024)) {
                char tgline[1024];
                strcpy(tgline, gline);
                char* gt = strtok(tgline, "|");

                if (gt && strcmp(gt, target_id) == 0) {
                    gt = strtok(NULL, "|");
                    while (gt) {
                        strcpy(t_rows[row_count].code, gt);
                        strtok(NULL, "|");
                        strtok(NULL, "|");
                        strtok(NULL, "|");
                        char* glet = strtok(NULL, "|");
                        if (!glet) break;

                        t_rows[row_count].grade = glet[0];

                        t_rows[row_count].credits = 0;
                        strcpy(t_rows[row_count].title, "Unknown Course");
                        for (int i = 0; i < course_count; i++) {
                            if (strcmp(course_list[i].code, t_rows[row_count].code) == 0) {
                                t_rows[row_count].credits = course_list[i].credits;
                                strcpy(t_rows[row_count].title, course_list[i].title);
                                break;
                            }
                        }


                        double p = 0.0;
                        switch (t_rows[row_count].grade) {
                        case 'A': p = 4.0; break;
                        case 'B': p = 3.0; break;
                        case 'C': p = 2.0; break;
                        case 'D': p = 1.0; break;
                        case 'F': p = 0.0; break;
                        }
                        t_rows[row_count].points = p;

                        total_points += (p * t_rows[row_count].credits);
                        total_credits += t_rows[row_count].credits;
                        row_count++;

                        gt = strtok(NULL, "|");
                    }
                    break;
                }
            }
            gfile.close();
        }

        double gpa;

        if (total_credits > 0) {
            gpa = total_points / total_credits;
        }
        else {
            gpa = 0.0;
        }

        cout << "\n";
        cout << "                                 STUDENT TRANSCRIPT                                   \n";
        cout << "======================================================================================\n";
        cout << "   Student ID: " << left << setw(69) << target_id << "\n";
        cout << "   Name: " << left << setw(75) << full_name << "\n";
        cout << "   " << left << setw(81) << prog_level << "\n";
        cout << "======================================================================================\n";
        cout << "   Course      Title                                       Credits    Grade    Pts\n";
        cout << "======================================================================================\n";

        for (int i = 0; i < row_count; i++) {
            cout << "   " << left << setw(11) << t_rows[i].code
                << "   " << left << setw(41) << t_rows[i].title
                << "   " << left << setw(8) << t_rows[i].credits
                << "     " << left << setw(4) << t_rows[i].grade
                << "   " << fixed << setprecision(1) << left << setw(3) << t_rows[i].points << "\n";
        }

        cout << "======================================================================================\n";
        cout << "   Total Credit Hours: " << left << setw(61) << total_credits << "  \n";
        cout << "   Cumulative GPA: " << left << setw(65) << fixed << setprecision(2) << gpa << "  \n";
    }

    int main() {
        bool program_running = true;
        while (program_running) {
            int main_choice = main_menu();
            switch (main_choice) {
            case 1: {
                bool sm_running = true;
                while (sm_running) {
                    int sm_choice = student_management_menu();
                    switch (sm_choice) {
                    case 1:
                        if (add_new_student() == 0) {
                            cout << "\n>>> Student added successfully! <<<\n";
                            cout << ">>> Generated Student ID: " << current_student_id << " <<<\n";
                        }
                        break;
                    case 2:
                        int listing;
                        cout << "1. List alphabetically by name (Saves to name.txt)\n";
                        cout << "2. List all students by ID (Original File)\n";
                        cout << "Choice: ";
                        cin >> listing;
                        if (listing == 1) {
                            list_by_name();
                        }
                        else if (listing == 2) {
                            list_full_student_list();
                        }
                        else {
                            cout << "Invalid input.\n";
                        }
                        break;
                    case 3:
                        search_student();
                        break;
                    case 4:
                        update_student();
                        break;
                    case 5:
                        delete_student();
                        break;
                    case 0:
                        sm_running = false;
                        break;
                    default:
                        cout << "Invalid choice.\n";
                    }
                }
                break;
            }
            case 2: {
                bool cm_running = true;
                while (cm_running) {
                    int choix = 0;

                    cout << "\n--- Course Management ---\n";
                    cout << "1. Add a new course\n";
                    cout << "2. View all available courses\n";
                    cout << "3. Update course\n";
                    cout << "4. Delete course\n";
                    cout << "0. Return to Main Lobby\n";
                    cout << "Choice: ";
                    cin >> choix;

                    switch (choix) {
                    case 1:
                        if (add_new_course() == 0) {
                            cout << "\n>>> Course added successfully! <<<\n";
                        }
                        break;
                    case 2:
                        view_courses();
                        break;
                    case 3:
                        update_course();
                        break;
                    case 4:
                        delete_course();
                        break;
                    case 0:
                        cm_running = false;
                        break;
                    default:
                        cout << "Invalid choice.\n";
                    }
                }
                break;
            }
            case 3: {
                bool gm_running = true;
                while (gm_running) {
                    int choice;
                    cout << "\n=== Grades Management ===\n" <<
                        "1. Enter Student Grades \n" <<
                        "2. View Student Grades \n" <<
                        "3. Calculate GPA \n" <<
                        "4. Generate Transcript\n" <<
                        "0. Back to Main Menu\n" <<
                        "Enter your choice: ";

                    cin >> choice;
                    switch (choice) {
                    case 1:
                        enter_student_grade();
                        break;
                    case 2:
                        view_all_students_grades();
                        break;
                    case 3:
                        calculate_gpa();
                        break;
                    case 4:
                        generate_transcript();
                        break;
                    case 5:
                    case 0:
                        gm_running = false;
                        break;
                    default:
                        cout << "Invalid choice.\n";
                    }
                }
                break;
            }
            case 0:
                program_running = false;
                break;
            default:
                cout << "Invalid choice.\n";
            }
        }
        return 0;
    }