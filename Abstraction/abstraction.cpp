#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DataExporter {
public:
    virtual ~DataExporter() {}

    bool validate(const vector<string>& data) {
        
        // Return false and print "Export failed: No data to export." if data is empty
        // Return true and print "Validation passed. Exporting N records." otherwise
        if(data.empty())
        {
            cout << "FALIED" << endl;
            return false;
        }
        else
        {
            return true;
        }
    }

    virtual void exportData(const vector<string>& data) = 0;
};

class CSVExporter : public DataExporter {
public:
    void exportData(const vector<string>& data) override {
        // Call validate(data) first. If validation fails, return early.
        if(!validate(data))
        {
            return;
        }
        // Otherwise, print CSV format: "CSV: Alice,Bob,Charlie"
        cout << "CSV: \"";
        for(string name : data)
            cout << name;
        cout << "\""<< endl;

    }
};

class JSONExporter : public DataExporter {
public:
    void exportData(const vector<string>& data) override {
        // Call validate(data) first. If validation fails, return early.
        if(!validate(data))
        {
            return;
        }

        // Otherwise, print JSON array format: JSON: ["Alice", "Bob", "Charlie"]
        cout << "JSON: [\"";
        for(string name : data)
            cout << name;
        cout << "\"]" << endl;
    }
};

int main() {
    CSVExporter csv;
    csv.exportData({"Alice", "Bob", "Charlie"});

    cout << endl;

    JSONExporter json;
    json.exportData({"Alice", "Bob", "Charlie"});

    cout << endl;

    csv.exportData({}); // Should fail validation
    return 0;
}
