#include <iostream>
#include <message.h>

void message::save(folder &f){
    folder.insert(&f);
    f.add_message(this);
}

void message::remove(folder &f){
    folder.erase(&f);
    f.remove_message(this);
}

void message::add_to_folder(const message &m){
    for (auto f : m.folders)
        f->add_message(this);
}

message::message(const message &m) :
        content(m.content), folders(m.folders) {
    add_to_folders(m);
}

void message::remove_from_folders(){
    for (auto f : folders)
        f->remove_message(this);
}

message::~message(){
    remove_from_folders();
}

message& message:: operator=(const message &rhs){
    remove_from_folder();
    content = rhs.content;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

void swap(massage &lhs, message &rhs){
    using std::swap;
    for (auto f : lhs.folders)
        f->remove_message();
    for (auto f : rhs.folders)
        f->remove_message();
    swap(lhs.folders, rhs.folders);
    swap(lhs.content, rhs.content);
    for (auto f : lhs.folders)
        f->add_message(&lhs);
    for (auto f : rhs.folders)
        f->add_message(&rhs);
    }

