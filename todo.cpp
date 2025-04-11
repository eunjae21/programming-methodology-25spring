#include "todo.h"
#include <stdexcept>


int strLen(const char* str){
    int i=0, len=0;
    if(str == nullptr) return 0;
    while(str[i] != '\0'){
        len++;
        i++;
    }
    return len;
}

///

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i=0; i<MAX_TASKS; i++){
        tasks[i] = nullptr;
    }

}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i=0; i<MAX_TASKS; i++){
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int len = 0, i = 0;
    while(str[i] != '\0'){
        len ++;
        i++;
    }
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    int i=0;
    while(tasks[i] != nullptr) i++;
    if(i == MAX_TASKS){
        throw std::out_of_range("tasks are full");
    }
    else{
        int len = strLen(task);
        tasks[i] = new char[len+1];
        for(int j=0; j<len; j++){
            tasks[i][j] = task[j];
        }
        tasks[i][len] = '\0';
    }
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    int end_index = 0;
    while(tasks[end_index] != nullptr) end_index++;
    end_index -= 1;

    if(index > end_index || index < 0){
        throw std::invalid_argument("invalid index");
    }

    delete[] tasks[index];

    for(int i = index; i < end_index; i++){
        tasks[i] = tasks[i+1];
    }
    tasks[end_index] = nullptr;
}


const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = 0;

    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i] != nullptr) {
            count++;
        }
    }

    if (count == 0) return nullptr;

    const char** result = new const char*[count];

    int j = 0;
    for (int i = 0; i < MAX_TASKS; ++i) {
        if (tasks[i] != nullptr) {
            result[j++] = tasks[i];
        }
    }

    return result;
}