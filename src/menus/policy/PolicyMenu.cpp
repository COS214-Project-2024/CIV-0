#include "PolicyMenu.h"
#include "menus/base/MenuManager.h"

PolicyMenu::PolicyMenu() : IMenu() {}

PolicyMenu::~PolicyMenu() {}

void PolicyMenu::display() const {}

void PolicyMenu::handleInput()
{
    sections = {
        {"New Policies",
         {{'1', "💧", "Apply new water policy"},
          {'2', "⚡", "Apply new electricity policy"}}},
        {"Policy History",
         {{'3', "📜", "Show all policy history"}}},
        {"Navigation",
         {{'q', "⬅️ ", "Back to Main Menu"}}}};
    setHeading("Policy Menu");
    clearScreen();
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            selectWaterPolicy();
            choosing = false;
            break;
        case '2':
            selectElectricityPolicy();
            choosing = false;
            break;
        case '3':
            showPolicyHistory();
            choosing = false;
            break;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            break;
        default:
            displayInvalidChoice();
        }
    }
}

void PolicyMenu::selectWaterPolicy()
{
    clearScreen();
    setHeading("Select Water Consumption Policy");
    sections = {
        {"Options",
         {{'1', "⬆️ ", "High Consumption"},
          {'2', "⬅️ ", "Normal Consumption"},
          {'3', "⬇️ ", "Low Consumption"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Policy Menu"},
          {'q', "⬅️ ", "Back to Main Menu"}}}};
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            // addPolicyToHistory("Applied High Water Consumption policy");
            governmentManager.enactWaterUsagePolicy(PolicyType::HIGH_WATER_POLICY);
            displaySuccessMessage("High Water Consumption policy applied.");
            choosing = false;
            break;
        case '2':
            // addPolicyToHistory("Applied Normal Water Consumption policy");
            governmentManager.enactWaterUsagePolicy(PolicyType::NORMAL_WATER_POLICY);
            displaySuccessMessage("Normal Water Consumption policy applied.");
            choosing = false;
            break;
        case '3':
            // addPolicyToHistory("Applied Low Water Consumption policy");
            governmentManager.enactWaterUsagePolicy(PolicyType::LOW_WATER_POLICY);
            displaySuccessMessage("Low Water Consumption policy applied.");
            choosing = false;
            break;
        case 'b':
            MenuManager::instance().setCurrentMenu(Menu::POLICY);
            choosing = false;
            return;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            return;
        default:
            displayInvalidChoice();
            break;
        }
    }
    displayPressEnterToContinue();
}

void PolicyMenu::selectElectricityPolicy()
{
    clearScreen();
    setHeading("Select Electricity Consumption Policy");
    sections = {
        {"Options",
         {{'1', "⬆️ ", "High Consumption"},
          {'2', "⬅️ ", "Normal Consumption"},
          {'3', "⬇️ ", "Low Consumption"}}},
        {"Navigation",
         {{'b', "⬅️ ", "Back to Policy Menu"},
          {'q', "⬅️ ", "Back to Main Menu"}}}};
    displayMenu();

    bool choosing = true;

    while (choosing)
    {
        char choice;
        displayChoicePrompt();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            // addPolicyToHistory("Applied High Electricity Consumption policy");
            governmentManager.enactElectricityPolicy(PolicyType::HIGH_ELECTRICITY_POLICY);
            displaySuccessMessage("High Electricity Consumption policy applied.");
            choosing = false;
            break;
        case '2':
            // addPolicyToHistory("Applied Normal Electricity Consumption policy");
            governmentManager.enactElectricityPolicy(PolicyType::NORMAL_ELECTRICITY_POLICY);
            displaySuccessMessage("Normal Electricity Consumption policy applied.");
            choosing = false;
            break;
        case '3':
            // addPolicyToHistory("Applied Low Electricity Consumption policy");
            governmentManager.enactElectricityPolicy(PolicyType::LOW_ELECTRICITY_POLICY);
            displaySuccessMessage("Low Electricity Consumption policy applied.");
            choosing = false;
            break;
        case 'b':
            MenuManager::instance().setCurrentMenu(Menu::POLICY);
            choosing = false;
            return;
        case 'q':
            MenuManager::instance().setCurrentMenu(Menu::MAIN);
            choosing = false;
            return;
        default:
            displayInvalidChoice();
            break;
        }
    }
    displayPressEnterToContinue();
}

void PolicyMenu::showPolicyHistory()
{
    clearScreen();
    setHeading("Policy History");

    std::vector<Memento *> pastPolicies = governmentManager.getAllPastPolicies();

    if (pastPolicies.empty())
    {
        std::cout << "No policies have been applied yet." << std::endl;
    }
    else
    {
        // Print a top border
        int boxWidth = 60;
        printTopBorder(boxWidth);

        // Loop through policy history and display each entry in a formatted manner
        for (size_t i = 0; i < pastPolicies.size(); ++i)
        {
            std::string entry = " " + std::to_string(i + 1) + ". " + pastPolicies[i]->getDetail();
            int padding = boxWidth - static_cast<int>(entry.size()) - 2;

            // Ensure proper alignment by adjusting padding
            std::cout << DARK_GRAY << "║ " << RESET << entry
                      << std::string(std::max(0, padding), ' ') << DARK_GRAY << " ║" << RESET << std::endl;

            if (i < pastPolicies.size() - 1)
                printSectionDivider(boxWidth); // Divider between entries
        }

        // Print a bottom border
        printBottomBorder(boxWidth);
    }

    displayPressEnterToContinue();
}
