#pragma warning(disable : 4996)
#include "SearchHistory.h"
#include <iostream>
#include <ctime>

using namespace std;

HistoryObject::HistoryObject(){}

HistoryObject::HistoryObject(const string& searchedString) : searchedString(searchedString), dateTime(time(nullptr)) {}

string HistoryObject::getSearchedString() const {
    return searchedString;
}

time_t HistoryObject::getDateTime() const {
    return dateTime;
}


SearchHistory::SearchHistory(){}
//SearchHistory::~SearchHistory() {
//    delete[] history;
//}

void SearchHistory::add_search_history(const string& searchedString) {
    if (size < max) {
        history[size++] = HistoryObject(searchedString);
    }
     /*   capacity *= 2;
        HistoryObject* newHistory = new HistoryObject[capacity];
        for (int i = 0; i < size; ++i) {
            newHistory[i] = history[i];
        }
        delete[] history;
        history = newHistory;
    }
    //history[size++] = HistoryObject(searchedString, dateTim*//*);*/
}

void SearchHistory::view_search_history() const {
    cout << "\nQuerries        Time\n";
    for (int i = size - 1; i >= 0; i--)
    {
        cout << history[i].getSearchedString() << "    ";
        time_t searchTime = history[i].getDateTime();
        cout << ctime(&searchTime);
    }
}


//void SearchHistory::sort_history_by_date_time() {
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (history[j].getDateTime() > history[j + 1].getDateTime()) {
//                // Swap if out of order
//                HistoryObject temp = history[j];
//                history[j] = history[j + 1];
//                history[j + 1] = temp;
//            }
//        }
//    }
//}

void SearchHistory::view_frequently_searched_contacts() const {
    int counts[max] = { 0 };
    string queries[max];
    cout << "Frequently Searched Contacts:\n";
    // Count occurrences of each query
    for (int i = 0; i < size; ++i) {
        bool found = false;
        for (int j = 0; j < max; ++j) {
            if (queries[j] == history[i].getSearchedString()) {
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            for (int j = 0; j < max; ++j) {
                if (queries[j].empty()) {
                    queries[j] = history[i].getSearchedString();
                    counts[j]++;
                    break;
                }
            }
        }
    }

    // Sort queries based on counts
    for (int i = 0; i < max - 1; ++i) {
        for (int j = 0; j < max - i - 1; ++j) {
            if (counts[j] < counts[j + 1]) {
                swap(counts[j], counts[j + 1]);
                swap(queries[j], queries[j + 1]);
            }
        }
    }

    cout << "\nTop 5 frequently searched queries:\n";
    for (int i = 0; i < min(5, size); ++i) {
        if (counts[i] == 0)
            exit(0);
        cout << queries[i] << " : " << counts[i] << " times\n";

    }
    cout << "Results of these Querries were:\n";
    for (int i = 0; i < min(5, size); ++i) {
        cout << history[i].getSearchedString() << "    ";
        time_t searchTime = history[i].getDateTime();
        cout << ctime(&searchTime);;

    }
}