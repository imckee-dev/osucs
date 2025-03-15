#include "room.h"

using namespace std;

//Room Implementation


Room::~Room() {
    if (e != nullptr) {
        delete e;
    } 
}

void Room::set_event(Event* new_event) {
    if (e != nullptr) {
        delete e;
    }
    this->e = new_event;
}

Event* Room::get_event() const {
    return e;
}

