#pragma once
#include <string>
#include <ctime>

using namespace std;

class HistoryObject {
private:
    string searchedString;
    time_t dateTime;

public:
    HistoryObject();
    HistoryObject(const string& searchedString);
    string getSearchedString() const;
    time_t getDateTime() const;
};

class SearchHistory {
private:
    static const int max = 100;
    HistoryObject history[max];
    int size;
public:
    SearchHistory();
    void add_search_history(const string& searchedString);
    void view_search_history() const;
    void view_frequently_searched_contacts() const;
};

