#include "backend.h"
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <windows.h>  

std::unordered_map<int, std::string> hotkeyMap;

void loadHotkeys() {
    std::ifstream file("config/config.json");
    if (!file) return;

    Json::Value root;
    file >> root;
    for (const auto& key : root.getMemberNames()) {
        hotkeyMap[std::stoi(key)] = root[key].asString();
    }
}

void saveHotkeys() {
    Json::Value root;
    for (const auto& [key, value] : hotkeyMap) {
        root[std::to_string(key)] = value;
    }

    std::ofstream file("config/config.json");
    file << root;
}

void switchToWindow(const std::string& windowName) {
    HWND hwnd = FindWindow(NULL, windowName.c_str());
    if (hwnd) {
        SetForegroundWindow(hwnd);
    }
}

void processHotkey(int keyCode) {
    if (hotkeyMap.find(keyCode) != hotkeyMap.end()) {
        switchToWindow(hotkeyMap[keyCode]);
    }
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
        processHotkey(kbStruct->vkCode);
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void registerHotkeys() {
    SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
}
