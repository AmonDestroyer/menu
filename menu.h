#ifndef Menu_h
#define Menu_h

#include <Arduino.h>
#include <string.h>

#define MAX_NAME_LENGTH 16
#define MAX_ITEMS 10

typedef void (*MenuFunction)();

struct MenuItem {
    String name;
    MenuFunction function;
};

/**
 * @brief Menu class that can hold and loop through menu items
 *
 * A menu object will hold menu items. Menu items can be circularly
 * looped through. An item can then be selected or the next one can
 * be seelcted.
 *
 * @author Adam Case
 */
class Menu {
private:
    /**
     * @brief Item member max name length
     * 
     * The maximum length of the name for an item member.
     */
    int maxNameLength;
    /**
     * @brief Current selected item
     *
     * Index of the currently selected menu item.
     */
    int currentIndex;
    /**
     * @brief Total count of the number of menu items
     *
     * Contains the count for the total number of items held in the
     * menu object.
     */
    int itemCount;
    /**
     * @brief Array of all menu items
     *
     * Contains an array of menu items that is at most MAX_ITEMS size.
     */
    MenuItem items[MAX_ITEMS];
    //Utilizing Menu Item pointer allocating MAX_ITEMS on construction
    // MenuItem *items
    // then use malloc in the constructor
    // Sketch uses 6064 bytes (18%) of program storage space. Maximum is 32256 bytes.
    // Global variables use 446 bytes (21%) of dynamic memory, leaving 1602 bytes for local variables. Maximum is 2048 bytes.
    //Utilizing Preallocated memory
    // MenuItem items[MAX_ITEMS]
    // Sketch uses 6224 bytes (19%) of program storage space. Maximum is 32256 bytes.
    // Global variables use 602 bytes (29%) of dynamic memory, leaving 1446 bytes for local variables. Maximum is 2048 bytes.

    /* I am curious as to why the dynamically allocated memory
    takes less storage space (160 bytes) and mem space (156 bytes)
    This doesn't make sense to me if they are both allocated the
    same amount (MAX_ITEMS) in my outputs above.

    I would assume that malloc does some optimization?
    */

public:
    /**
     * @brief Constructor for the Menu class
     * 
     * @param[in] maxNameLength The maximum length for a menu item name
     * @param[in] maxItems The maximum number of items in a menu
     * 
     * Will construct an empty menu that can contain at most MAX_ITEMS menu items.
     */
    Menu(int maxNameLength=MAX_NAME_LENGTH, int maxItems=MAX_ITEMS);
    /**
     * @brief Adds a menu item to the menu
     *
     * Will create a menu item given a menu item name and menu void function. This
     * item will be appended at the end of the current menu list.
     *
     * @param[in] name Name of the menu item
     * @param[in] function Void function for the menu to execute when the menu item 
     * is selected.
     */
    void addItem(const String &name, MenuFunction function);
    /**
     * @brief Returns the name of the currently selected item
     *
     * @return name of the current item
     */
    const String &getCurrentItemName();
    /**
     * @brief Returns the name of the next item following the current item
     * 
     * @return name of the item following the current item
     */
    const String &getNextItemName();
    /**
     * @brief Selects the next item in the menu item list
     * 
     */
    void selectNextItem();
    /**
     * @brief Selects the previous item in the menu item list
     * 
     */
    void selectPreviousItem();
    /**
     * @brief Performs function of item in the menu relative
     * to the currently selected item.
     * 
     * @param[in] index The index of the item relative to currently
     * menu item.
     */
    void executeItemFunction(int index=0);
    /**
     * @brief Resets the menu current index
     * 
     */
    void resetIndex();
};

#endif
