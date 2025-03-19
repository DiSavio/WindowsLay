#ifndef BACKEND_H
#define BACKEND_H

#include <string>
#include <unordered_map>

void loadHotkeys();
void saveHotkeys();
void registerHotkeys();
void processHotkey(int keyCode);
void switchToWindow(const std::string& windowName);

extern std::unordered_map<int, std::string> hotkeyMap;

#endif
