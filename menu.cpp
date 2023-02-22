#include "menu.h"

Menu::Menu(int maxNameLength, int maxItems=MAX_ITEMS) {
    this->maxNameLength = maxNameLength;
    this->itemCount = 0;
    this->currentIndex = 0;
}

void Menu::addItem(const String &name, MenuFunction function) {
    if (itemCount < MAX_ITEMS) {
        items[itemCount].name = name;
        items[itemCount].function = function;
        itemCount++;
    }
}

const String &Menu::getCurrentItemName() {
    return items[currentIndex].name;
}

const String &Menu::getNextItemName() {
    return items[(currentIndex + 1) % itemCount].name;
}

void Menu::selectNextItem() {
    currentIndex = (currentIndex + 1) % itemCount;
}

void Menu::selectPreviousItem() {
    currentIndex = (currentIndex - 1 + itemCount) % itemCount;
}

void Menu::executeItemFunction(int index) {
    int itemIndex = (currentIndex + index) % itemCount;
    items[itemIndex].function();
}

void Menu::resetIndex() {
    currentIndex = 0;
}