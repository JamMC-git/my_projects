#include <iostream>
#include <string>
#include <vector>

enum class TrafficLight {RED,YELLOW,GREEN};

TrafficLight next(TrafficLight light)
{
    switch(light){
        case TrafficLight::RED return TrafficLight::GREEN;
    }
} 

//Even without the enum class, the HttpStatus struct follows enums. 
//It uses static const to compose status codes similar to how enums above composed traffic light signals.

using namespace std;
    
struct HttpStatus {
    int code;
    string message;

    static const HttpStatus OK;
    static const HttpStatus BAD_REQUEST;
    static const HttpStatus NOT_FOUND;
    static const HttpStatus INTERNAL_SERVER_ERROR;

    bool isSuccess() const {
        // Return true if code < 400
        if(code < 400)
            return true;
        else
            return false;
    }

    void display() const {
        // Print: "CODE MESSAGE" e.g. "200 OK"
         cout << code << " " << message << endl;
    }

    static const HttpStatus* fromCode(int code) {
        // Return pointer to HttpStatus matching the code, or nullptr if not found
                for (const auto* status : values()) {
            if (status->code == code) {
                return status;
            }
        }
        return nullptr;
    }

    static const vector<const HttpStatus*>& values() {
        static vector<const HttpStatus*> v = {&OK, &BAD_REQUEST, &NOT_FOUND, &INTERNAL_SERVER_ERROR};
        return v;
    }
};

// Set correct values: OK(200, "OK"), BAD_REQUEST(400, "Bad Request"),
// NOT_FOUND(404, "Not Found"), INTERNAL_SERVER_ERROR(500, "Internal Server Error")
const HttpStatus HttpStatus::OK{200, "OK"};
const HttpStatus HttpStatus::BAD_REQUEST{400, "Bad Request"};
const HttpStatus HttpStatus::NOT_FOUND{404, "Not Found"};
const HttpStatus HttpStatus::INTERNAL_SERVER_ERROR{500, "Internal Server Error"};

int main() {
    HttpStatus::OK.display();
    HttpStatus::NOT_FOUND.display();

    cout << "Is 200 success? " << (HttpStatus::OK.isSuccess() ? "true" : "false") << endl;
    cout << "Is 404 success? " << (HttpStatus::NOT_FOUND.isSuccess() ? "true" : "false") << endl;

    const HttpStatus* found = HttpStatus::fromCode(500);
    if (found != nullptr) {
        cout << "Found by code 500: ";
        found->display();
    }
    return 0;
}
