//
// Created by yang zhengtao on 2021/8/22.
//

#ifndef TEST_LAPTOP_PROTOTYPEWORK_H
#define TEST_LAPTOP_PROTOTYPEWORK_H
#include <stdio.h>
class WorkModel{
public:
    char* model_name_;
    void SetModelName(char *name){
        this->model_name_ = name;
    }
};

class PrototypeWork{
public:
    PrototypeWork(){}
    virtual PrototypeWork *clone() = 0;
    ~PrototypeWork(){
        printf("Deconstruct PrototypeWork\n");
    }
};

class ConcreteWork:public PrototypeWork{
public:
    ConcreteWork(){}
    ~ConcreteWork(){
        printf("Deconstruct ConcreteWork\n");
    }
    ConcreteWork(char *name, int id_num, char *model_name){
        this->name_ = name;
        this->id_num_ = id_num;
        this->work_model_ptr_ = new WorkModel();
        this->work_model_ptr_->SetModelName(model_name);
    }

    ConcreteWork* clone(){
        ConcreteWork *work_ptr = new ConcreteWork();
        work_ptr->SetName(name_);
        work_ptr->SetIdNum(id_num_);
        work_ptr->SetModel(work_model_ptr_);
        return work_ptr;
    }
    void SetName(char* name){this->name_ = name;}

    void SetIdNum(int id_num){this->id_num_ = id_num;}

    void SetModel(WorkModel * work_model){this->work_model_ptr_ = work_model;}

    void PrintWorkInfo(){
        printf("name: %s\t\n", name_);
        printf("id_num: %d\t\n", id_num_);
        printf("model name: %s\t\n", work_model_ptr_->model_name_);
    }

private:
    char *name_;
    int id_num_;
    WorkModel *work_model_ptr_;
};

#endif //TEST_LAPTOP_PROTOTYPEWORK_H
