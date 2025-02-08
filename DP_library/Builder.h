//
// Created by a1009mys on 25. 2. 8.
//

#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <vector>

// 특정 Product
class Product{
public:
    std::vector<std::string> parts_;
    void ListParts() const {
        std::cout << "Product parts: ";
        for (size_t i=0; i < parts_.size(); i++) {
            if(parts_[i]== parts_.back()) {
                std::cout << parts_[i];
            }
            else {
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

// 빌더 인터페이스
class Builder
{
public:
    virtual ~Builder(){}
    // 인터페이스이므로 마찬가지로 순수가상함수로 선언
    virtual void buildPartA() const = 0;
    virtual void buildPartB() const = 0;
    virtual void buildPartC() const = 0;
};

// Concrete 클래스 구현
class ConcreteBuilder : public Builder
{
public:
    // 생성자에서 새로운 Product를 생성하고, 소멸자에서 Product를 지워서 자원 관리
    ConcreteBuilder() { this->Reset(); }
    ~ConcreteBuilder(){ delete product; }

    void Reset(){
        this->product = new Product();
    }

    void buildPartA() const override {
        this->product->parts_.push_back("PartA1");
    }

    void buildPartB() const override {
        this->product->parts_.push_back("PartB1");
    }

    void buildPartC() const override {
        this->product->parts_.push_back("PartC1");
    }

    Product* GetProduct() {
        Product* result= this->product;
        this->Reset();
        return result;
    }
private:
    Product* product;
};

// Director는 building steps를 실행하는 역할만 함.
// 이는 특정 configuration만 build 하는 것을 도와줌.
class Director{
public:
    // 특정한 builder를 set할 수 있음
    // 즉, 추후 새로운 builder를 도입해서 확장시킬 수 있음
    void set_builder(Builder* builder){
        this->builder = builder;
    }

    // A만 만드는 함수
    void BuildMinimalViableProduct(){
        this->builder->buildPartA();
    }

    // A, B, C를 만드는 함수
    void BuildFullFeaturedProduct(){
        this->builder->buildPartA();
        this->builder->buildPartB();
        this->builder->buildPartC();
    }
private:
    Builder* builder;
};

// Client
void ClientCode()
{
    auto* director= new Director();

    ConcreteBuilder* builder = new ConcreteBuilder();
    director->set_builder(builder);
    std::cout << "One product:\n";
    director->BuildMinimalViableProduct();

    Product* p= builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Full products:\n";
    director->BuildFullFeaturedProduct();

    p= builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Customized product:\n";
    // 디렉터 없이 특정 파트만 빌드하는 것도 가능
    builder->buildPartA();
    builder->buildPartC();
    p=builder->GetProduct();
    p->ListParts();
    delete p;

    delete builder;
    delete director;
}






#endif //BUILDER_H
