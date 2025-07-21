#include <iostream>
#include <vector>
using namespace std;

// Make a struct to store task info
struct Task {
    string title;
    bool done;
};

// Function to show all tasks
void showTasks(const vector<Task>& myTasks) {
    cout << "\n------ MY TO-DO LIST ------\n";
    if (myTasks.empty()) {
        cout << "Nothing here yet!\n";
    } else {
        for (int i = 0; i < myTasks.size(); i++) {
            cout << (i+1) << ". " << myTasks[i].title;
            if (myTasks[i].done)
                cout << " [Done]";
            else
                cout << " [Pending]";
            cout << endl;
        }
    }
    cout << "--------------------------\n";
}

// Function to add task
void addNewTask(vector<Task>& myTasks) {
    string t;
    cout << "Write your task: ";
    cin.ignore(); // ignore leftover newline
    getline(cin, t);
    myTasks.push_back({t, false});
    cout << "Task added!\n";
}

// Function to mark as done
void completeTask(vector<Task>& myTasks) {
    if (myTasks.empty()) {
        cout << "No tasks to mark.\n";
        return;
    }
    int n;
    cout << "Which task number is done? ";
    cin >> n;
    if (n < 1 || n > myTasks.size()) {
        cout << "Invalid number!\n";
    } else {
        myTasks[n-1].done = true;
        cout << "Nice! Marked as done.\n";
    }
}

// Function to delete task
void deleteTask(vector<Task>& myTasks) {
    if (myTasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }
    int n;
    cout << "Which task number to delete? ";
    cin >> n;
    if (n < 1 || n > myTasks.size()) {
        cout << "Invalid number!\n";
    } else {
        myTasks.erase(myTasks.begin() + (n-1));
        cout << "Task deleted.\n";
    }
}

int main() {
    vector<Task> myTasks;
    int choice;

    do {
        cout << "\n=== SIMPLE TO-DO APP ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addNewTask(myTasks);
                break;
            case 2:
                showTasks(myTasks);
                break;
            case 3:
                completeTask(myTasks);
                break;
            case 4:
                deleteTask(myTasks);
                break;
            case 5:
                cout << "Goodbye! :)\n";
                break;
            default:
                cout << "Invalid option, try again!\n";
        }
    } while(choice != 5);

    return 0;
}
