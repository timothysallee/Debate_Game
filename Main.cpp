#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to prompt user input and return as string
string getInput(string title) {
    string input;
    cout << title << ": ";
    getline(cin, input);
    return input;
}

// Function to evaluate input and return label and category
pair<string, string> evaluateInput(string input) {
    string label = "neutral";
    string category = "";
    
    // Evaluation logic goes here, this is just a placeholder
    // In this example, every other sentence is labeled "disagree"
    static int counter = 0;
    if (counter % 2 == 0) {
        label = "disagree";
        // Prompt user for category
        cout << "Select category for disagree (1=logical error, 2=False premise): ";
        int categoryInput;
        cin >> categoryInput;
        cin.ignore();
        if (categoryInput == 1) {
            category = "logical error";
        } else if (categoryInput == 2) {
            category = "false premise";
        }
    }
    counter++;
    
    return make_pair(label, category);
}

int main() {
    // Create user profiles
    string proTitle = "Pro";
    string conTitle = "Con";
    
    // Prompt users for input
    string proInput = getInput(proTitle);
    string conInput = getInput(conTitle);
    
    // Evaluate and label input
    vector<pair<string, string>> proLabels;
    vector<pair<string, string>> conLabels;
    
    // Evaluate Pro input
    for (string sentence : proInput) {
        pair<string, string> label = evaluateInput(sentence);
        proLabels.push_back(label);
    }
    
    // Evaluate Con input
    for (string sentence : conInput) {
        pair<string, string> label = evaluateInput(sentence);
        conLabels.push_back(label);
    }
    
    // Display labeled input to each user
    cout << conTitle << " input:\n";
    for (int i = 0; i < conLabels.size(); i++) {
        cout << conLabels[i].first << " - " << conLabels[i].second << ": " << conInput[i] << endl;
    }
    cout << endl;
    
    cout << proTitle << " input:\n";
    for (int i = 0; i < proLabels.size(); i++) {
        cout << proLabels[i].first << " - " << proLabels[i].second << ": " << proInput[i] << endl;
    }
    cout << endl;
    
    // Mark sentences as defend or admit
    vector<string> defendSentences;
    for (int i = 0; i < conLabels.size(); i++) {
        if (conLabels[i].first == "disagree" && conLabels[i].second != "" && getInput(conTitle + " defend or admit? (1=defend, 2=admit): ") == "1") {
            defendSentences.push_back(conInput[i]);
        }
    }
    
    for (int i = 0; i < proLabels.size(); i++) {
        if (proLabels[i].first == "disagree" && proLabels[i].second != "" && getInput(proTitle + " defend or admit? (1=defend, 2=admit): ") == "1") {
            defendSentences.push_back(proInput[i]);
        }
    }
    
    // Display defended sentences
    cout << "Defended sentences:\n";
    for (string sentence : defendSentences) {
        cout <<
