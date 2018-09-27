//
// Created by 王行健 on 2018/9/2.
//

#ifndef TESTING_MESSAGE_H
#define TESTING_MESSAGE_H

#endif //TESTING_MESSAGE_H

class message{
public:
    explicit message(std::string &st = " ") : content(st) { }
    message(const message&);
    message& operator = (const message&);
    ~message();
    void save(folder&);
    void remove(folder&);


private:
    std::string content;
    std::set<folder*> folders;
    void add_to_folders(const message&);
    void remove_from_folders();
};

class folder{
public:
};