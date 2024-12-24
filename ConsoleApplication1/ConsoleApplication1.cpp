#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Базовый класс
class Detail {
protected:
    Detail() = default; // Защищенный конструктор

public:
    virtual ~Detail() = default; // Виртуальный деструктор
    virtual void info() const = 0; // Чисто виртуальная функция
};

// Производный класс
class Assembly : public Detail {
private:
    std::string name;

public:
    Assembly(const std::string& name) : name(name) {} // Конструктор

    void info() const override {
        std::cout << "Это сборка: " << name << std::endl;
    }
};

// Шаблонная дружественная функция для добавления объектов в вектор
template<typename T>
void add(std::vector<std::shared_ptr<Detail>>& storage, std::shared_ptr<T> item) {
    storage.push_back(item);
}

int main() {
    std::vector<std::shared_ptr<Detail>> storage; // Хранилище объектов

    // Создание объектов и добавление их в хранилище
    add(storage, std::make_shared<Assembly>("Сборка 1"));
    add(storage, std::make_shared<Assembly>("Сборка 2"));

    // Вывод информации о каждом объекте в хранилище
    for (const auto& item : storage) {
        item->info();
    }

    return 0; // Все ресурсы будут освобождены автоматически
}
